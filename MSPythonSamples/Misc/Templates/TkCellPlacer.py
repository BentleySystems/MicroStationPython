from MSPyBentley import *
from MSPyECObjects import *
from MSPyBentleyGeom import *
from MSPyDgnPlatform import *
from MSPyDgnView import *
from MSPyMstnPlatform import *
import tkinter as tk
from tkinter import filedialog, simpledialog

class CellPlacementTool(DgnPrimitiveTool):
    def __init__(self, toolId, cellName, libraryPath):
        super().__init__(toolId, 0)
        self.cellName = cellName
        self.libraryPath = libraryPath
        self.m_self = self

    def _OnPostInstall(self):
        AccuSnap.GetInstance().EnableSnap(True)
        DgnPrimitiveTool._OnPostInstall(self)

    def _OnDataButton(self, ev):
        origin = ev.GetPoint()
        scale = DPoint3d(1, 1, 1)
        rotMatrix = RotMatrix()
        rotMatrix.InitIdentity()

        # Attach the cell library
        celLibraryName = BeFileName(self.libraryPath)
        Cell.AttachLibrary(fileName=BeFileName(), inputName=celLibraryName, defaultDir=os.path.dirname(self.libraryPath), fromKeyin=0)

        # Find the cell in the library
        searchAll = 1  # => 0=no, 1=yes w/o messages, 2=yes w/ messages
        retVal, library = Cell.FindCell(None, self.cellName, searchAll)
        if BentleyStatus.eSUCCESS != retVal:
            print(f"Error finding cell {self.cellName} in library")
            return

        # Place the cell
        try:
            result = Cell.PlaceCell(
                origin=origin,
                scale=scale,
                trueScale=True,
                rotMatrix=rotMatrix,
                attributes=0,
                ggroup=0,
                relativeMode=False,
                baseLevel=0,
                sharedFlag=0,
                cellName=self.cellName,
                library=library
            )
        except Exception as e:
            print(f"Error placing cell: {e}")

    def _OnResetButton(self, ev):
        self._OnRestartTool()
        return True

    def _OnRestartTool(self):
        CellPlacementTool.InstallNewInstance(self.GetToolId(), self.cellName, self.libraryPath)

    @staticmethod
    def InstallNewInstance(toolId, cellName, libraryPath):
        tool = CellPlacementTool(toolId, cellName, libraryPath)
        tool.InstallTool()

def select_cell_library_and_name():
    root = tk.Tk()
    root.withdraw()  # Hide the root window

    library_path = filedialog.askopenfilename(title="Select Cell Library", filetypes=[("Cell Library", "*.cel")])
    if not library_path:
        print("No library selected.")
        return

    cell_name = simpledialog.askstring("Cell Name", "Enter the cell name:")
    if not cell_name:
        print("No cell name entered.")
        return

    CellPlacementTool.InstallNewInstance(1, cell_name, library_path)

if __name__ == "__main__":
    select_cell_library_and_name()