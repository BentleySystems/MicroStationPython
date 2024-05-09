#---------------------------------------------------------------------------------------------
#  Copyright (c) Bentley Systems, Incorporated. All rights reserved.
#  See LICENSE.md in the repository root for full copyright notice.
#---------------------------------------------------------------------------------------------
import os
import subprocess
import sys
import time


#----------------------------------------------------------------------------------------------------------------------------------------------------
def retryCommand():
    initialDelay = 0
    retryDelay = 1000
    maxRetries = 10
    command = []

    USAGE_STR = "Usage: <script> [--initialDelay=-0] [--retryDelay=1000] [--maxRetries=10] COMMAND"
    
    for iArg in range(1, len(sys.argv)):
        arg = sys.argv[iArg]
        if arg.startswith("--"):
            if arg.split("=")[0] == "--initialDelay":
                initialDelay = int(arg.split("=")[1])
                continue

            if arg.split("=")[0] == "--retryDelay":
                retryDelay = int(arg.split("=")[1])
                continue

            if arg.split("=")[0] == "--maxRetries":
                maxRetries = int(arg.split("=")[1])
                continue
            
            print(USAGE_STR)
            return 1

        command = sys.argv[iArg:]
        break

    # Initial delay
    if initialDelay > 0:
        time.sleep(initialDelay / 1000.0)

    # Main loop
    currRetry = 0
    while currRetry < maxRetries:
        currRetry += 1

        print("INFO: running '{0}'...".format(" ".join(command)))
        sys.stdout.flush()
        retCode = subprocess.call(command)
        if 0 == retCode:
            return 0
        
        print("INFO: attempt {0}, command returned {1}, waiting to retry...".format(currRetry, retCode))
        time.sleep(retryDelay / 1000.0)

    print("ERROR: command '{0}' was never successful.".format(" ".join(command)))
    return 1

#----------------------------------------------------------------------------------------------------------------------------------------------------
if __name__ == '__main__':
    sys.exit(retryCommand())
