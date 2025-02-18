# -*- coding: utf-8 -*-
'''
/*--------------------------------------------------------------------------------------+
| $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
+--------------------------------------------------------------------------------------*/
'''
import os

import tkinter as tk
from tkinter import filedialog, messagebox, ttk

from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyDgnView import *
from MSPyMstnPlatform import *

import sys

folderPath = os.path.join(os.path.dirname(os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))), 'Misc', 'ExchangeDataBetweenExcelAndItemType')
if folderPath not in sys.path:
    sys.path.insert(0, folderPath)

from ExtractItemTypesToExcel import *
from RepopulateItemsFromExcel import *

'''
Dialog Example which demonstrates a tkinter modaless dialog containing text, combobox, labels and buttons.
It allows a user to extract title block information to an Excel file, edit the title block information in Excel,
and re-populate the title block Item Types with the new information.
Running this sample needs to open ExchangeDataBetweenExcelAndItemType.dgn or other design file includes title block item.
It depends on 'ExtractItemTypesToExcel.py' and 'RepopulateItemsFromExcel.py' located in 3rdPyLibs/ExchangeDataBetweenExcelAndItemType.
Action:
    -Export to database: click '...' button to select database file saving path, then click 'Start' button,
                         it would extract title block information to an Excel file.
    -Import from database: click '...' button to select database file, then click 'Edit Database' button to open it and edit,
                           then click 'Start' button, it would re-populate the title block Item Types with the new information.
'''

def on_closing(root):
    root.destroy()

def select(text, index):
    if index == 0:
        file_path = filedialog.asksaveasfilename(initialfile="TitleBlock.xlsx", filetypes=[("Excel Workbook", "*.xlsx")], defaultextension=".xlsx")
    else:
        file_path = filedialog.askopenfilename(initialdir="/", title="Select database", filetypes=[("Excel Workbook", "*.xlsx")])

    if not file_path:
        return

    text.config(state="normal")
    text.delete("1.0", tk.END)
    text.insert(tk.END, file_path)
    text.config(state="disabled")

def start(file_path, index):
    if index == 0:
        msg = "Please verify database path"
    else:
        msg = "Please select database file"

    if not file_path:
        messagebox.showinfo("Info", msg)
        return

    if index == 0:
        ExtractItemTypesToExcel(file_path)
        messagebox.showinfo("Info", "Database updated!")
    else:
        RepopulateItemsFromExcel(file_path)
        PyCadInputQueue.SendKeyin("field update all")
        messagebox.showinfo("Info", "Design file updated!")

def edit(file_path):
    if os.path.isfile(file_path):
        os.startfile(file_path)
    else:
        messagebox.showinfo("Info", "Please select database file to edit")

def titleBlockManager():
    root = tk.Tk()
    root.title("Title Block Manager")
    root.attributes("-topmost", 1)
    root.protocol("WM_DELETE_WINDOW", lambda: on_closing(root))

    labelAct = tk.Label(root, text="Action: ", anchor="e")
    labelAct.grid(sticky="e")

    labelData = tk.Label(root, text="Database: ", anchor="e")
    labelData.grid(row=1, column=0, sticky="e")

    combo_box = ttk.Combobox(root, state="readonly")
    combo_box["values"] = ("Export to database", "Import from database")
    combo_box.current(0)
    combo_box.grid(row=0, column=1, sticky="w")

    text = tk.Text(root, height=1, width=35)
    text.insert(tk.END, "")
    text.config(state="disabled")
    text.grid(row=1, column=1, sticky="w")

    buttonSelect = tk.Button(root, text="...", height=1, command=lambda: select(text, combo_box.current()))
    buttonSelect.grid(row=1, column=2)

    buttonStart = tk.Button(root, text="Start", height=1, width=12, command=lambda: start(text.get("1.0", "end-1c"), combo_box.current()))
    buttonStart.grid(row=2, column=1, sticky="w")

    buttonEdit = tk.Button(root, text="Edit Database", height=1, width=12, command=lambda: edit(text.get("1.0", "end-1c")))
    buttonEdit.grid(row=2, column=1)

    while tk._default_root != None:
        root.update()
        PyCadInputQueue.PythonMainLoop()

if __name__ == "__main__":  # check if this script is being run directly (not imported as a module)
    titleBlockManager()