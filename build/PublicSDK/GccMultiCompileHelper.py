#---------------------------------------------------------------------------------------------
#  Copyright (c) Bentley Systems, Incorporated. All rights reserved.
#  See LICENSE.md in the repository root for full copyright notice.
#---------------------------------------------------------------------------------------------

import multiprocessing
import threading
import os
import queue
import subprocess
import sys
import time

printLock = threading.Lock()

#-------------------------------------------------------------------------------------------
# bsimethod
#-------------------------------------------------------------------------------------------
def printFlush(msg):
    printLock.acquire()
    print(msg)
    sys.stdout.flush()
    printLock.release()

#========================================================================================
#  @bsiclass                                                                   10/2015
#========================================================================================
class CommandJob:
    def __init__(self, command, resultList, lock):
        self.m_command = command
        self.m_resultList = resultList
        self.m_lock = lock

    def GetCommand(self):
        return self.m_command

    def AppendResult(self, result):
        self.m_lock.acquire()
        self.m_resultList.append(result)
        self.m_lock.release()

#-------------------------------------------------------------------------------------------
# bsimethod
#-------------------------------------------------------------------------------------------
def runCommand (args):
    workQueue = args

    while True:
        job = workQueue.get()
        command = job.GetCommand()

        compiland = command[len (command) - 1]
        
        printFlush(compiland)
        
        proc = subprocess.Popen (command, stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
        
        # Format of output:
        #   [0] return code
        #   [1] compiland path
        #   [2] all other compiler output

        output = [compiland]

        procStdOutLine = proc.stdout.readline ()
        while procStdOutLine:
            output.append (procStdOutLine.strip ())
            procStdOutLine = proc.stdout.readline ()
        
        retVal = proc.wait ()
        
        output.insert (0, retVal)

        job.AppendResult(output)
        workQueue.task_done()

#-------------------------------------------------------------------------------------------
# bsimethod
#-------------------------------------------------------------------------------------------
def multiCompile (compilerCommand, commonArgs, compilands):

    printFlush('Now Compiling...')

    commands = list ()
    for compiland in compilands:
        command = [compilerCommand]

        for commonArg in commonArgs:
            command.append (commonArg)

        command.append (compiland)
        
        commands.append (command)

    #----------------------------------------------------------------------------------------------

    numProcs = multiprocessing.cpu_count()
    workQueue = queue.Queue()
    results = []
    resultsLock = threading.Lock()
    
    for _ in range(numProcs):
        t = threading.Thread(target=runCommand, args=[workQueue])
        t.daemon = True
        t.start()

    for command in commands:
        workQueue.put(CommandJob(command, results, resultsLock))

    while not workQueue.empty():
        time.sleep(1)

    workQueue.join()

    #----------------------------------------------------------------------------------------------

    anyFailures = False

    for result in results:
        # See runCommand procedure for format of result

        didThisResultFail = (result[0] != 0)

        if didThisResultFail:
            anyFailures = True

        if len (result) < 3 and not didThisResultFail:
            continue

        printFlush('')
        printFlush('********************************************************************************')
        
        if didThisResultFail:
            printFlush('Error(s) for {0}:'.format (result[1]))
        else:
            printFlush('Message(s) / Warning(s) for {0}:'.format (result[1]))

        printFlush('********************************************************************************')

        for line in result[2:]:
            printFlush(line)

    printFlush('')
            
    if anyFailures:
        return 1

    return 0

#-------------------------------------------------------------------------------------------
# bsimethod
#-------------------------------------------------------------------------------------------
def main ():
    
    if len (sys.argv) < 3:
        printFlush('Expected at least the compiler command and a response file as parameters')
        return 1

    otherArgs = list ()
    responseFileArg = None
    compilerArg = sys.argv[1]

    for argv in sys.argv[2:]:
        if argv.startswith ('@'):
            responseFileArg = argv[1:]
        else:
            otherArgs.append (argv)

    if not responseFileArg:
        printFlush('Expected a response file parameter')
        return 1

    compilands = []
    with open (responseFileArg) as responseFile:
        for responseFileLine in responseFile.readlines ():
            for compilandPath in responseFileLine.split ():
                compilands.append (compilandPath)

    printFlush('')
    printFlush('Compiler Command:')
    printFlush(compilerArg)
    printFlush('')
    printFlush('Common Compiler Options:')
    printFlush(otherArgs)
    printFlush('')

    return multiCompile (compilerArg, otherArgs, compilands)

#-------------------------------------------------------------------------------------------
if __name__ == '__main__':
    exit (main ())
