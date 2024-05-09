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
    def __init__(self):
        super().__init__()
        self.setWindowTitle("Microstation PyQt5 TestApp")
        self.setStyleSheet ( 'background-color: #444444;' )
        self.setGeometry (0,0,240,80)
        self.setWindowFlags (Qt.WindowStaysOnTopHint)
        
        self.label = QLabel (time.strftime("%I:%M:%S"), self)
        self.label.setStyleSheet ('color:white;')
        self.label.setFont (QFont ("Arial", 40))
        self.label.adjustSize ()
        self.timer = QTimer (self)
        self.timer.timeout.connect (self.updateClock)
        self.timer.start (1000)

    def updateClock(self):
        self.label.setText (time.strftime("%I:%M:%S"))


def updateMstn ():
    PyCadInputQueue.PythonMainLoop()

if __name__ == "__main__":
    app = QApplication.instance()
    
    if app is None: 
        app = QApplication(sys.argv)
    window = MainWindow()
    window.show()
    timer = QTimer()
    timer.timeout.connect(updateMstn)
    timer.start()
    app.exec()
