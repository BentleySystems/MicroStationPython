from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyDgnView import *
from MSPyMstnPlatform import *
 

def GetCellText(table, cellIdx):
    txtTblCell = table.GetCell(cellIdx)
    foundTextBlock = txtTblCell.GetTextBlock() 
    foundString = foundTextBlock.ToString()
    print (foundString.GetWCharCP())


def ReadTable():
    global dgn_model

    elementId = 1119

    eh = ElementHandle(elementId, dgn_model)
    txtTable = TextTableHandler.GetInstance().ExtractTextTable (eh)

    cellCollection = txtTable.GetCellCollection()
    for cell in cellCollection:
        foundIndex = cell.GetIndex()
        GetCellText (txtTable, foundIndex)

    if (txtTable != None):
        print(f"Table Columns : {txtTable.GetColumnCount()}")
        print(f"Table Rows    : {txtTable.GetRowCount()}")
        cellIdx = TableCellIndex(2, 0)
        GetCellText (txtTable, cellIdx)
        cellIdx = TableCellIndex(2, 1)
        GetCellText (txtTable, cellIdx)

    return True


def main():
    global ACTIVEMODEL
    global dgn_model
    global dgn_file
    global uor

    # Globals
    ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
    dgn_model = ACTIVEMODEL.GetDgnModel()
    dgn_file = dgn_model.GetDgnFile()
    model_info = dgn_model.GetModelInfo()
    uor = model_info.GetUorPerStorage()    

    if True != ReadTable():
        print("Returned False...")


if __name__ == "__main__":
    print ("***** Read Table Element *****")
    main()

