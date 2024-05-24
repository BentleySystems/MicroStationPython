# -*- coding: utf-8 -*-
'''
/*--------------------------------------------------------------------------------------+
| $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
+--------------------------------------------------------------------------------------*/
'''
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
    moniker = DgnDocumentMoniker.CreateFromRawData(fileName, fullPath, None, "", False, None)
    if moniker is None:
        return False

    modelInfo   = modelRef.GetModelInfo()
    scaleFactor = modelInfo.GetUorPerMeter();

    extentInUOR = DPoint2d()
    extentInUOR.x = scaleFactor * extentInch.x / METERTOINCH
    extentInUOR.y = scaleFactor * extentInch.y / METERTOINCH

    pixelNumX = extentInch.x * FIGDPI
    pixelNumY = extentInch.y * FIGDPI

    uorsPerPixelX = extentInUOR.x / pixelNumX
    uorsPerPixelY = extentInUOR.y / pixelNumY

    rasterTransform = Transform()
    rasterTransform.SetTranslation(ptLocaton)
    rasterTransform.ScaleMatrixColumns (uorsPerPixelX, uorsPerPixelY, 1.0)

    eeh = EditElementHandle()
    status = IRasterAttachmentEdit.CreateRasterAttachment(eeh, None, moniker, rasterTransform, extentInUOR, modelRef)
    if BentleyStatus.eSUCCESS != status:
        return False

    # add the raster attachment to the cache
    if BentleyStatus.eSUCCESS != eeh.AddToModel():
        return False

    return True

'''
Function to define the size and location of the output image
'''
def GetImageSizeLocation():
    vSet = IViewManager.GetActiveViewSet()
    viewport = vSet.GetSelectedViewport()

    uorExtentPt = DPoint2d()

    if viewport is None:
        return uorExtentPt

    viewInfo = viewport.GetViewInfo()
    startPt = viewInfo.GetOrigin()

    delta =  viewInfo.GetDelta()
    viewRot = viewInfo.GetRotation()

    viewXVec = DVec3d()
    viewYVec = DVec3d()
    viewZVec = DVec3d()

    viewRot.GetRow (viewXVec, 0)
    viewRot.GetRow (viewYVec, 1)
    viewRot.GetRow (viewZVec, 2)

    endPoint = DPoint3d()
    endPoint.Init(0,0,0)
    endPoint.SumOf(startPt,  viewXVec, delta.x, viewYVec, delta.y, viewZVec, delta.z)

    uorExtentPt.x = (endPoint.x - startPt.x) / 3.0
    uorExtentPt.y = uorExtentPt.x * FACTOR

    return uorExtentPt, startPt

def on_closing ():
    tk._default_root.destroy()

'''
Function to open a file picker
'''
def show_dialog(text):
    file_path = filedialog.askopenfilename(initialdir="/", title="Select raster file", filetypes=[("All Files", "*.*")])
    if not os.path.isfile(file_path):
        on_closing()
        return

    text.config(state="normal")
    text.delete("1.0", tk.END)
    text.insert(tk.END, file_path)
    text.config(state="disabled")

def attach(file_path):
    if not os.path.isfile(file_path):
        messagebox.showinfo("Info", "Please select a raster file to attach")
        return

    on_closing()
    file_name = os.path.basename(file_path)
    ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
    uorExtentPt, imageOrg = GetImageSizeLocation()

    modelInfo = ACTIVEMODEL.GetModelInfo()
    imageWidth  = uorExtentPt.x / modelInfo.GetUorPerMeter() * METERTOINCH #inch
    imageHeight = uorExtentPt.y / modelInfo.GetUorPerMeter() * METERTOINCH #inch
    AttachRaster(file_name, file_path, ISessionMgr.ActiveDgnModelRef, DPoint2d(imageWidth, imageHeight), imageOrg)

def get_all_windows():
    MShwnd = win32gui.GetForegroundWindow()
    current_process_id = win32process.GetWindowThreadProcessId(MShwnd)[1]

    def callback(hwnd, windows):
        if win32gui.IsWindow(hwnd) and win32gui.IsWindowEnabled(hwnd) and win32gui.GetParent(hwnd) == 0:
            _, found_process_id = win32process.GetWindowThreadProcessId(hwnd)
            if found_process_id == current_process_id:
                windows.append(hwnd)
        return True

    windows = []
    win32gui.EnumWindows(callback, windows)
    return MShwnd, windows

def doModal():
    MShwnd, windows = get_all_windows()
    for hwnd in windows:
        win32gui.EnableWindow(hwnd, False)

    root = tk.Tk()
    root.title("Attach Raster")
    root.attributes("-topmost", 1)
    root.protocol("WM_DELETE_WINDOW", on_closing)

    text = tk.Text(root, height=1, width=110)
    text.insert(tk.END, "Select a raster file to attach")
    text.config(state="disabled")
    text.grid()

    buttonSelect = tk.Button(root, text="...", height=1, command=lambda: show_dialog(text))
    buttonSelect.grid(row=0, column=1)

    buttonAttach = tk.Button(root, text="Attach", height=1, command=lambda: attach(text.get("1.0", "end-1c")))
    buttonAttach.grid(row=1)

    root.mainloop()

    for hwnd in windows:
        win32gui.EnableWindow(hwnd, True)
    win32gui.SetForegroundWindow(MShwnd)

doModal()