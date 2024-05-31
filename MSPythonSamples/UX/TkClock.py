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
    # Declare two global variables
    global s_root
    global s_clock
    
    # Create a Tkinter root window and set its geometry
    s_root  = tk.Tk()
    s_root.geometry("400x100")
    
    # Set the background color of the root window to black
    s_root.config(bg='black')
    
    # Define a function for handling window close events
    s_root.protocol("WM_DELETE_WINDOW", on_closing)
    
    # Create a Tkinter Label widget for displaying the clock time
    s_clock = tk.Label(s_root, background = 'black',foreground = 'white', font = ('arial', 40, 'bold'))
    
    # Pack the label widget into the root window
    s_clock.pack()
    
    # Call the update function to initialize the clock
    update()
    
    # Set the title of the root window to "clock"
    s_root.title('clock')
    
    # Run an infinite loop for updating the clock and handling user input
    while tk._default_root != None :
        # Update the root window to reflect any changes (e.g., clock time updates)
        s_root.update ()
        
        # Run the Python main event loop to handle user input and perform other tasks
        PyCadInputQueue.PythonMainLoop()

if __name__ == "__main__":
    main ()