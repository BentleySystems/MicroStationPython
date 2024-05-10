import tkinter as tk
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

s_root  = None
s_clock = None

def on_closing ():
    global s_root
    s_root.destroy()

def update():
    s_clock.config(text=time.strftime("%I:%M:%S"))
    s_clock.after(1000,update)

def main ():
    global s_root
    global s_clock
    s_root  = tk.Tk()
    s_root.geometry("400x100")
    s_root.config(bg='black')
    s_root.protocol("WM_DELETE_WINDOW", on_closing)
    s_clock = tk.Label(s_root, background = 'black',foreground = 'white', font = ('arial', 40, 'bold'))
    s_clock.pack()
    update()
    s_root.title('clock')
    while tk._default_root != None :
        s_root.update ()
        PyCadInputQueue.PythonMainLoop()    

if __name__ == "__main__":
    main ()