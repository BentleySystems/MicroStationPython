import tkinter
import time
import os
from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyDgnView import *
from MSPyMstnPlatform import *

#
# Simple Clock Example which demonstrates a tkinter UX item containing a clock which doesnt block
# the execution of Microstations input loop.
#
# Using tkinter.mainloop will not return out of the loop until the tkinter UX item is closed, this blocks
# the main application thread of Microstation. The underlying Tcl UX event loop does not expose any capabilities to register handlers through 
# python and as such this cannot be corrected from within Microstation Code.
# 
# To workaround this use the tkinter.update method instead, this will return after processing all the tkinter UX events, then we can execute
# a Microstation function mdlInput_pythonMainLoop to process the main input loop of Microstation.
#


def on_closing ():
	root.destroy()

def update():
    clock.config(text=time.strftime("%I:%M:%S"))
    clock.after(1000,update)

if __name__ == "__main__":
    root= Tk()
    root.geometry("400x100")
    root.config(bg='black')
    root.protocol("WM_DELETE_WINDOW", on_closing)
    clock = Label(root, background = 'black',foreground = 'white', font = ('arial', 40, 'bold'))
    clock.pack()
    update()
    root.title('clock')
    while tkinter._default_root != None :
        root.update ()
        PyCadInputQueue.PythonMainLoop()