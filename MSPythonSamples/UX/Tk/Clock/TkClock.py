#---------------------------------------------------------------------------------------------
#  Copyright (c) Bentley Systems, Incorporated. All rights reserved.
#  See LICENSE.md in the repository root for full copyright notice.
#---------------------------------------------------------------------------------------------
import tkinter as tk
import time
import os
from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyDgnView import *
from MSPyMstnPlatform import *

'''
# Simple Clock Example which demonstrates a tkinter UX item containing a clock which doesnt block
# the execution of Microstations input loop.
#
# Using tkinter.mainloop will not return out of the loop until the tkinter UX item is closed, this blocks
# the main application thread of Microstation. The underlying Tcl UX event loop does not expose any capabilities to register handlers through 
# python and as such this cannot be corrected from within Microstation Code.
# 
# To workaround this use the tkinter.update method instead, this will return after processing all the tkinter UX events, then we can execute
# a Microstation function mdlInput_pythonMainLoop to process the main input loop of Microstation.
'''

s_root  = None
s_clock = None

def on_closing ():
    """
    Handle the event when the window is being closed.

    This function destroys the root window, effectively closing the application.
    It uses the global variable `s_root` to reference the root window.
    """
    global s_root
    s_root.destroy()

def update():
    """
    Update the clock display with the current time.

    This function updates the text of the `s_clock` widget to the current time
    formatted as hours, minutes, and seconds (HH:MM:SS). It then schedules
    itself to be called again after 1000 milliseconds (1 second) to continuously
    update the time display.

    :return: None
    """
    s_clock.config(text=time.strftime("%I:%M:%S"))
    s_clock.after(1000,update)

def main ():
    """
    Main function to create and run a Tkinter-based clock application.
    This function initializes the Tkinter root window, sets its properties,
    creates a clock display using a Tkinter Label widget, and runs an infinite
    loop to update the clock and handle user input.
    Global Variables:
    -----------------
    s_root : tk.Tk
        The Tkinter root window.
    s_clock : tk.Label
        The Tkinter Label widget used to display the clock time.
    Functions:
    ----------
    on_closing():
        Handles the window close event.
    update():
        Updates the clock display with the current time.
    Notes:
    ------
    The function runs an infinite loop to continuously update the clock and
    handle user input using the `PyCadInputQueue.PythonMainLoop()` function.
    """
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