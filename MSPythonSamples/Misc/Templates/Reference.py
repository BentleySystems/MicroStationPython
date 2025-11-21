from MSPyBentley import *
from MSPyECObjects import *
from MSPyBentleyGeom import *
from MSPyDgnPlatform import *
from MSPyDgnView import *
from MSPyMstnPlatform import *
import tkinter as tk
from tkinter import filedialog, simpledialog

def prompt_for_file():
    """
    Prompts the user to select a DGN file.

    :return: The path to the selected DGN file.
    :rtype: str
    """
    root = tk.Tk()
    root.withdraw()  # Hide the root window
    file_path = filedialog.askopenfilename(
        title="Select a DGN file",
        filetypes=[("DGN files", "*.dgn")]
    )
    root.destroy()
    return file_path

def prompt_for_attachment_settings():
    """
    Prompts the user for attachment settings.

    :return: A tuple containing the model name, logical name, and scale.
    :rtype: tuple
    """
    root = tk.Tk()
    root.withdraw()  # Hide the root window
    model_name = simpledialog.askstring("Input", "Enter the model name:")
    logical_name = simpledialog.askstring("Input", "Enter the logical name:")
    scale = simpledialog.askfloat("Input", "Enter the scale:")
    root.destroy()
    return model_name, logical_name, scale

def attach_dgn_file(file_path, model_name, logical_name, scale):
    """
    Attaches a DGN file as a reference attachment to the active DGN model.

    :param file_path: The path to the DGN file to be attached.
    :type file_path: str
    :param model_name: The name of the model to be attached.
    :type model_name: str
    :param logical_name: The logical name for the attachment.
    :type logical_name: str
    :param scale: The scale for the attachment.
    :type scale: float
    """
    ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
    if ACTIVEMODEL is None:
        print("No active DGN model found.")
        return

    moniker = DgnDocumentMoniker.CreateFromFileName(file_path)
    if moniker is None:
        print("Failed to create moniker from file path.")
        return

    ret = ACTIVEMODEL.CreateDgnAttachment(moniker, model_name, False)
    if BentleyStatus.eSUCCESS != ret[0]:
        print("Failed to create DGN attachment.")
        return

    attachment = ret[1]
    attachment.SetLogicalName(logical_name)
    attachment.SetStoredScale(scale)

    if BentleyStatus.eSUCCESS != attachment.WriteToModel():
        print("Failed to write attachment to model.")
        return

    print("DGN file attached successfully.")

def main():
    file_path = prompt_for_file()
    if not file_path:
        print("No file selected.")
        return

    model_name, logical_name, scale = prompt_for_attachment_settings()
    if not model_name or not logical_name or scale is None:
        print("Invalid attachment settings.")
        return

    attach_dgn_file(file_path, model_name, logical_name, scale)

if __name__ == "__main__":
    main()