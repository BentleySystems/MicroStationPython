# $Copyright: (c) 2024 Bentley Systems, Incorporated. All rights reserved. $

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
    """
    Handle the event when the window is closing.

    This function is called when the window's close button is clicked. It 
    destroys the root window, effectively closing the application.

    :param root: The root window of the Tkinter application.
    :type root: tkinter.Tk
    """
    root.destroy()

def select(text, index):
    """
    Opens a file dialog to select or save an Excel file and updates the given text widget with the selected file path.
    :param text: The Tkinter text widget to update with the selected file path.
    :type text: tkinter.Text
    :param index: Determines the type of file dialog to open. If 0, opens a save dialog; otherwise, opens an open dialog.
    :type index: int
    """
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
    """
    Starts the process based on the provided file path and index.
    Depending on the index value, this function either verifies the database path or selects the database file.
    If the file path is not provided, it shows an informational message.
    If the index is 0, it extracts item types to an Excel file and updates the database.
    If the index is not 0, it repopulates items from an Excel file, sends a key-in command to update fields, and updates the design file.
    
    :param file_path: The path to the file to be processed.
    :type file_path: str
    :param index: The index to determine the operation mode (0 for database update, non-0 for design file update).
    :type index: int
    """
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
    """
    Open the specified file for editing if it exists, otherwise show an info message.

    :param file_path: The path to the file to be edited.
    :type file_path: str
    """
    if os.path.isfile(file_path):
        os.startfile(file_path)
    else:
        messagebox.showinfo("Info", "Please select database file to edit")

def titleBlockManager():
    """
    Initializes and runs the Title Block Manager GUI.
    This function creates a Tkinter window with various widgets to manage title blocks.
    It includes labels, a combobox, text field, and buttons for selecting actions, 
    starting processes, and editing the database. The window is set to be always on top 
    and handles the window close event with a custom function.
    Widgets:
        - Label for action selection.
        - Label for database selection.
        - Read-only combobox for choosing between "Export to database" and "Import from database".
        - Disabled text field for displaying selected database path.
        - Button for selecting a database path.
        - Button for starting the selected action.
        - Button for editing the database.
    The function runs an update loop to keep the GUI responsive and processes input 
    from the PyCadInputQueue.
    Note:
        The function assumes the existence of `on_closing`, `select`, `start`, and `edit` 
        functions, as well as the `PyCadInputQueue` module.
    """
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