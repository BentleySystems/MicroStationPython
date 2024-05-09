import os
import time
from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyDgnView import *
from MSPyMstnPlatform import *

class MyModalEventHandler(IPyModalDialogEvents):

    ''' Callback when a modal Microstation dialog is opened ''' 
    def OnDialogOpened (self, dialogBoxName):
        time.sleep (1)
        return PyMsdDialogBoxResult.ePyMsdDialogBoxResultOK
        
    ''' Callback when a modal Microstation dialog is closed ''' 
    def OnDialogClosed (delf, dialogBoxName, result):
        pass

''' Show an error in Microstations status bar in the last test a dialog is opened ''' 
def test_ShowErrorMessage ():

    modalEvents = MyModalEventHandler ()
    MessageCenter.ShowErrorMessage ('ShowErrorMessage : Brief Only','', False)
    MessageCenter.ShowErrorMessage ('ShowErrorMessage : Brief and Detailed','Detailed Message', False)
    PyEventsHandler.AddModalDialogEventsHandler (modalEvents)
    MessageCenter.ShowErrorMessage ('ShowErrorMessage : Brief and Detailed + MessageBox','Detailed Message', True)
    PyEventsHandler.RemoveModalDialogEventsHandler (modalEvents)

''' Show an info in Microstations status bar in the last test a dialog is opened ''' 
def test_ShowInfoMessage ():

    modalEvents = MyModalEventHandler ()
    MessageCenter.ShowInfoMessage ('ShowInfoMessage : Brief Only','', False)
    MessageCenter.ShowInfoMessage ('ShowInfoMessage : Brief and Detailed','Detailed Message', False)
    PyEventsHandler.AddModalDialogEventsHandler (modalEvents)
    MessageCenter.ShowInfoMessage ('ShowInfoMessage : Brief and Detailed + MessageBox','Detailed Message', True)
    PyEventsHandler.RemoveModalDialogEventsHandler (modalEvents)

''' Show a debug in Microstations status bar in the last test a dialog is opened ''' 
def test_ShowDebugMessage ():

    modalEvents = MyModalEventHandler ()
    MessageCenter.ShowDebugMessage ('ShowDebugMessage : Brief Only','', False)
    MessageCenter.ShowDebugMessage ('ShowDebugMessage : Brief and Detailed','Detailed Message', False)
    PyEventsHandler.AddModalDialogEventsHandler (modalEvents)
    MessageCenter.ShowDebugMessage ('ShowDebugMessage : Brief and Detailed + MessageBox','Detailed Message', True)
    PyEventsHandler.RemoveModalDialogEventsHandler (modalEvents)

''' Set the command name in Microstations status bar ''' 
def test_StatusCommand ():
    MessageCenter.StatusCommand = 'StatusBar Command Test'

''' Set the command prompt in Microstations status bar ''' 
def test_StatusPrompt ():
    MessageCenter.StatusPrompt = 'StatusBar Prompt Test'

''' Set the message in Microstations status bar ''' 
def test_StatusMessage ():
    MessageCenter.StatusMessage = 'StatusBar Message Test'

''' Set the warning message in Microstations status bar ''' 
def test_StatusWarning ():
    MessageCenter.StatusWarning = 'StatusBar Warning Test'

#if __name__ == "__main__":
    #test_ShowErrorMessage ()
    #test_ShowInfoMessage ()
    #test_ShowDebugMessage ()
    #test_StatusCommand ()
    #test_StatusPrompt ()
    #test_StatusMessage ()
    #test_StatusWarning ()