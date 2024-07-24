#---------------------------------------------------------------------------------------------
#  Copyright (c) Bentley Systems, Incorporated. All rights reserved.
#  See LICENSE.md in the repository root for full copyright notice.
#---------------------------------------------------------------------------------------------
import sys
import PyQt5
from PyQt5.QtWidgets import *
from PyQt5.QtWidgets import QMainWindow, QApplication
from PyQt5.QtCore import QTimer, Qt
from PyQt5.QtGui import QFont, QWindow
import time

import os
from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyDgnView import *
from MSPyMstnPlatform import *


#
# Simple Clock Example which demonstrates a PyQt5 UX window containing a clock which doesnt block
# the execution of Microstations input loop.
#
# Using app.exec will not return out of the loop until the PyQt5 window is closed, this blocks
# the main application thread of Microstation. Qt is a C based Ux framework who's timers will execute in the main event loop for the UX framework
#
# Registering a timer with a 0 start interval will cause the timer method to execute every time the Qt Windows event loop finishes. Calling PyCadInputQueue.PythonMainLoop 
# from the timer will allow Microstation's input loop to execute allowing use of the Microstation UX whilst the Qt window is displayed.
#
# 
#

def dump(obj):
  for attr in dir(obj):
    print("obj.%s = %r" % (attr, getattr(obj, attr)))

class MainWindow(QMainWindow):
    # Initialize the main window class
    def __init__(self):
        # Call the parent class's constructor to initialize the main window
        super().__init__()
        
        # Set the title of the main window
        self.setWindowTitle("Microstation PyQt5 TestApp")
        
        # Set the background color of the main window
        self.setStyleSheet (
            'background-color: #444444;'  # hex code for dark gray
        )
        
        # Set the size of the main window (x, y, width, height)
        self.setGeometry (
            0,  # initial x-coordinate
            0,  # initial y-coordinate
            240,  # width in pixels
            80   # height in pixels
        )
        
        # Make the main window stay on top of other windows
        self.setWindowFlags (Qt.WindowStaysOnTopHint)
        
        # Create a QLabel widget for displaying the clock time
        self.label = QLabel (
            time.strftime("%I:%M:%S"),  # format string for time display
            self  # parent widget is the main window
        )
        
        # Set the text color of the label to white
        self.label.setStyleSheet ('color:white;')
        
        # Set the font of the label to Arial with size 40
        self.label.setFont (
            QFont ("Arial", 40)  # font family and size
        )
        
        # Adjust the size of the label widget to fit its contents
        self.label.adjustSize ()
        
        # Create a QTimer object for updating the clock time
        self.timer = QTimer (self)
        
        # Connect the timer's timeout signal to the updateClock method
        self.timer.timeout.connect (self.updateClock)
        
        # Start the timer with an interval of 1 second (1000 milliseconds)
        self.timer.start (1000)

    def updateClock(self):
        self.label.setText (time.strftime("%I:%M:%S"))


def updateMstn ():
    PyCadInputQueue.PythonMainLoop()

if __name__ == "__main__":  # check if this script is being run directly (not imported as a module)
    app = QApplication.instance()   # get the existing application instance, if any
    
    if app is None:  # check if no application instance exists
        app = QApplication(sys.argv)   # create a new application instance with command-line arguments
    
    window = MainWindow()   # create an instance of the main window class
    window.show()   # show the main window
    
    timer = QTimer()   # create a QTimer object for updating the clock time
    timer.timeout.connect(updateMstn)  # connect the timer's timeout signal to the updateMstn function
    timer.start()   # start the timer with an interval of 1 second (1,000 milliseconds)
    
    app.exec()  # run the application's event loop until the window is closed
