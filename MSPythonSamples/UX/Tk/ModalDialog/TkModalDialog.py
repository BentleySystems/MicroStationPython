# $Copyright: (c) 2024 Bentley Systems, Incorporated. All rights reserved. $

import os
import win32gui
import win32process

import tkinter as tk
from tkinter import filedialog, messagebox

from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyDgnView import *
from MSPyMstnPlatform import *

'''
Simple Modal Dialog Example which demonstrates a tkinter modal dialog containing text and button to open a file picker,
to allow a user to select a raster file, then create a raster attachment.
'''

METERTOINCH = 39.37007874
FIGDPI = 100
FACTOR = 0.5

'''
Function to attach the image
'''
def AttachRaster (fileName, fullPath, modelRef, extentInch=DPoint2d(6.4, 4.8), ptLocaton=DPoint3d(0.0, 0.0, 0.0)):
    """
    Attaches a raster image to a model reference.
    
    :param fileName: The name of the raster file.
    :type fileName: str
    :param fullPath: The full path to the raster file.
    :type fullPath: str
    :param modelRef: The model reference to which the raster will be attached.
    :type modelRef: ModelReference
    :param extentInch: The extent of the raster in inches, defaults to DPoint2d(6.4, 4.8).
    :type extentInch: DPoint2d, optional
    :param ptLocaton: The location point where the raster will be attached, defaults to DPoint3d(0.0, 0.0, 0.0).
    :type ptLocaton: DPoint3d, optional
    
    :return: True if the raster was successfully attached, False otherwise.
    :rtype: bool
    """
    # Create a moniker from the raw data (file name and full path)
    moniker = DgnDocumentMoniker.CreateFromRawData(fileName, fullPath, None, "", False, None)
    if moniker is None:   # check if the moniker was successfully created
        return False

    modelInfo = modelRef.GetModelInfo()  # get the model information from the reference
    scaleFactor = modelInfo.GetUorPerMeter();  # get the scale factor (UOR per meter)

    extentInUOR = DPoint2d()   # initialize an empty point for UOR coordinates
    extentInUOR.x = scaleFactor * extentInch.x / METERTOINCH   # calculate the X coordinate in UOR units
    extentInUOR.y = scaleFactor * extentInch.y / METERTOINCH  # calculate the Y coordinate in UOR units

    pixelNumX = extentInch.x * FIGDPI   # convert the X coordinate to pixels
    pixelNumY = extentInch.y * FIGDPI   # convert the Y coordinate to pixels

    uorsPerPixelX = extentInUOR.x / pixelNumX  # calculate the scale factor in UORs per pixel (X)
    uorsPerPixelY = extentInUOR.y / pixelNumY  # calculate the scale factor in UORs per pixel (Y)

    rasterTransform = Transform()   # initialize a transformation matrix
    rasterTransform.SetTranslation(ptLocaton)  # set the translation part of the matrix
    rasterTransform.ScaleMatrixColumns (uorsPerPixelX, uorsPerPixelY, 1.0)   # scale the matrix

    eeh = EditElementHandle()   # create an edit element handle
    status = IRasterAttachmentEdit.CreateRasterAttachment(eeh, None, moniker, rasterTransform, extentInUOR, modelRef)   # create a raster attachment
    if BentleyStatus.eSUCCESS != status:  # check the status
        return False

     # add the raster attachment to the cache
    if BentleyStatus.eSUCCESS != eeh.AddToModel():   # check the result of adding to the model
        return False

    return True   # return success

'''
Function to define the size and location of the output image
'''
def GetImageSizeLocation():
    """
    Calculate the size and location of an image in the active viewport.
    This function retrieves the active view set from the view manager, gets the selected viewport,
    and calculates the extent of the image in the viewport based on the view's origin, delta vector,
    and rotation vector.
    
    Returns:
        tuple: A tuple containing:
            - uorExtentPt (DPoint2d): The calculated extent point.
            - startPt (DPoint3d): The origin point of the view.
    
    Notes:
        - If the viewport is None, the function returns an empty point.
        - The extent in the Y direction is calculated by multiplying the extent in the X direction by a constant factor.
    """
    # Get the active view set from the view manager
    vSet = IViewManager.GetActiveViewSet()
    # Get the selected viewport from the view set
    viewport = vSet.GetSelectedViewport()

    uorExtentPt = DPoint2d()  # initialize an empty point

    if viewport is None:  # check if the viewport is None
        return uorExtentPt  # if so, return the empty point

    # Get the view information from the viewport
    viewInfo = viewport.GetViewInfo()
    # Get the origin of the view (starting point)
    startPt = viewInfo.GetOrigin()

    delta =  viewInfo.GetDelta()  # get the delta vector
    viewRot = viewInfo.GetRotation()  # get the rotation vector

    # Initialize three vectors for the view rotation
    viewXVec = DVec3d()
    viewYVec = DVec3d()
    viewZVec = DVec3d()

    # Get the X, Y, and Z components of the view rotation
    viewRot.GetRow (viewXVec, 0)
    viewRot.GetRow (viewYVec, 1)
    viewRot.GetRow (viewZVec, 2)

    # Initialize an end point
    endPoint = DPoint3d()
    # Set the initial values of the end point to (0,0,0)
    endPoint.Init(0,0,0)
    # Calculate the end point by summing the start point and delta vector
    endPoint.SumOf(startPt,  viewXVec, delta.x, viewYVec, delta.y, viewZVec, delta.z)

    uorExtentPt.x = (endPoint.x - startPt.x) / 3.0  # calculate the extent in X
    uorExtentPt.y = uorExtentPt.x * FACTOR  # calculate the extent in Y

    return uorExtentPt, startPt  # return the calculated point and starting point

def on_closing ():
    """
    Handle the event when the modal dialog is requested to close.

    This function destroys the default Tkinter root window, effectively 
    closing the application.
    """
    tk._default_root.destroy()

'''
Function to open a file picker
'''
def show_dialog(text):
    """
    Display a file dialog for selecting a raster file and update the provided text widget with the selected file path.
    
    :param text: The text widget to be updated with the selected file path.
    :type text: tkinter.Text
    """
    # Define a function to display a dialog for selecting a raster file
    
    file_path = filedialog.askopenfilename(initialdir="/", title="Select raster file", filetypes=[("All Files", "*.*")])  # open file dialog with default directory and file type filters
    if not os.path.isfile(file_path):  # check if the selected path is a valid file
        on_closing()  # call the on_closing function to handle window close event
        return  # exit the function if the selected path is not a valid file
    
    text.config(state="normal")  # enable text widget for editing
    text.delete("1.0", tk.END)  # clear the text widget
    text.insert(tk.END, file_path)  # insert the selected file path into the text widget
    text.config(state="disabled")  # disable text widget to prevent further editing

def attach(file_path):
    """
    Attach a raster file to the active design model.
    
    :param file_path: The path to the raster file to be attached.
    :type file_path: str
    :raises FileNotFoundError: If the provided file path does not point to a valid file.
    
    This function performs the following steps:
    1. Checks if the provided file path is valid.
    2. Displays an info message box if the file path is invalid.
    3. Calls the `on_closing` function to handle the window close event.
    4. Retrieves the base name of the selected file.
    5. References the active design model.
    6. Gets the size and location of an image.
    7. Retrieves information about the active design model.
    8. Converts the image width and height from meters to inches.
    9. Attaches the raster file to the active design model.
    
    :returns: None
    """

    if not os.path.isfile(file_path):  # check if the selected path is a valid file
        messagebox.showinfo("Info", "Please select a raster file to attach")   # show an info message box with a prompt
        return  # exit the function if the selected path is not a valid file

    on_closing()  # call the on_closing function to handle window close event
    
    file_name = os.path.basename(file_path)  # get the base name of the selected file (i.e., the file name without directory)
    ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef   # reference to the active design model
    uorExtentPt, imageOrg = GetImageSizeLocation()  # get the size and location of an image
    
    modelInfo = ACTIVEMODEL.GetModelInfo()   # get information about the active design model
    imageWidth  = uorExtentPt.x / modelInfo.GetUorPerMeter() * METERTOINCH  # convert image width from meters to inches
    imageHeight = uorExtentPt.y / modelInfo.GetUorPerMeter() * METERTOINCH   # convert image height from meters to inches
    AttachRaster(file_name, file_path, ISessionMgr.ActiveDgnModelRef, DPoint2d(imageWidth, imageHeight), imageOrg)  # attach the raster file

def get_all_windows():
    """
    Get the foreground window and all top-level windows belonging to the same process.
    This function retrieves the handle of the currently active (foreground) window and enumerates 
    all top-level windows that belong to the same process as the foreground window.
    
    :return: A tuple containing the handle of the foreground window and a list of handles of all 
             top-level windows belonging to the same process.
    :rtype: tuple (int, list of int)
    """
    # Get the foreground window (i.e., the currently active window)
    MShwnd = win32gui.GetForegroundWindow()
    
    current_process_id = win32process.GetWindowThreadProcessId(MShwnd)[1]  # get the process ID of the foreground window

    def callback(hwnd, windows):  # define a callback function to enumerate all windows
        if win32gui.IsWindow(hwnd) and win32gui.IsWindowEnabled(hwnd) and win32gui.GetParent(hwnd) == 0:  # check if the window is enabled and has no parent (i.e., it's not a child window)
            _, found_process_id = win32process.GetWindowThreadProcessId(hwnd)  # get the process ID of the current window
            if found_process_id == current_process_id:  # check if the process ID matches the foreground window
                windows.append(hwnd)  # append the window handle to the list of windows
        return True

    windows = []  # initialize an empty list to store all window handles
    win32gui.EnumWindows(callback, windows)  # enumerate all windows using the callback function
    return MShwnd, windows  # return the foreground window and the list of all windows

def doModal():
    """
    Displays a modal dialog using Tkinter, disables all other windows while the dialog is open,
    and re-enables them once the dialog is closed.
    The dialog allows the user to select a raster file to attach.
    The function performs the following steps:
    1. Disables all open windows.
    2. Creates a Tkinter window with a title "Attach Raster".
    3. Adds a Text widget with a prompt message.
    4. Adds a button to open a file selection dialog.
    5. Adds a button to attach the selected file.
    6. Runs the Tkinter event loop.
    7. Re-enables all previously disabled windows and restores the original foreground window.
    :return: None
    """
     # Get all window handles and disable them
    MShwnd, windows = get_all_windows()  # get the foreground window and a list of all window handles
    for hwnd in windows:  # iterate through each window handle
        win32gui.EnableWindow(hwnd, False)  # disable the window

    root = tk.Tk()  # create a Tkinter window (root)
    root.title("Attach Raster")  # set the title of the window
    root.attributes("-topmost", 1)  # set the window to be always on top
    root.protocol("WM_DELETE_WINDOW", on_closing)  # define what happens when the window is closed

    text = tk.Text(root, height=1, width=110)  # create a Text widget with a fixed height and width
    text.insert(tk.END, "Select a raster file to attach")  # insert some initial text
    text.config(state="disabled")  # disable the text widget
    text.grid()  # place the text widget in the window

    buttonSelect = tk.Button(root, text="...", height=1, command=lambda: show_dialog(text))  # create a Button with a ... text and a callback to show_dialog
    buttonSelect.grid(row=0, column=1)  # place the button in the window

    buttonAttach = tk.Button(root, text="Attach", height=1, command=lambda: attach(text.get("1.0", "end-1c")))  # create a Button with an Attach text and a callback to attach
    buttonAttach.grid(row=1)  # place the button in the window

    root.mainloop()  # run the Tkinter event loop (mainloop)

    for hwnd in windows:  # iterate through each window handle again
        win32gui.EnableWindow(hwnd, True)  # re-enable the window
    win32gui.SetForegroundWindow(MShwnd)  # set the foreground window to the original one

if __name__ == "__main__":  # check if this script is being run directly (not imported as a module)
    doModal()