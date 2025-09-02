from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyMstnPlatform import *

import debugpy
debugpy.listen(('0.0.0.0',5678), in_process_debug_adapter=True)
print("Waiting for debugger attach")
debugpy.wait_for_client()
debugpy.breakpoint()    

''' Get the existing report with the given name from the given design file. '''    
def GetExistingReport(reportName):
    '''
    Get the existing report with the given name from the given design file.

    :param dgnFile: The design file.
    :type dgnFile: DgnFile
    :param reportName: The name of the report.
    :type reportName: str
    :return: The existing report definition.
    :rtype: ReportDefinition

    '''

    dgnFile = ISessionMgr.GetActiveDgnFile()
    if not dgnFile:
        print("Failed to get active DGN file.")
        return None    
    print(f"Report collection type: {type(dgnFile)}")

    reportCollection = ReportDefinitionCollection(dgnFile)
    if not reportCollection:
        print("Failed to get report collection.")
        return None

    searchReport = WString(reportName)
    for i in range(0, reportCollection.Count):
        reportDef = reportCollection.GetReportDefinitionAt(i)
        if reportDef and reportDef.DisplayLabel == searchReport:
            return reportDef

    return None

''' Print the report definition. '''    
def PrintReportDefinition(reportDef):
    '''
    Print the report definition

    :param reportDef: The report.
    :type reportDef: ReportDefinition

    '''

    if not reportDef:
        return
        
    print (f"reportDef Name={reportDef.Name} DisplayLabel={reportDef.DisplayLabel} NodeType={reportDef.NodeType} type={type(reportDef)}")
    rDefNode = ReportDefinitionNode (reportDef)
    print (f"ReportDefinitionNode Name={rDefNode.Name} DisplayLabel={rDefNode.DisplayLabel} type={type(rDefNode)}")

    return
    
    #selScope = rDefNode.GetSelectionScopeOption()

    #rDefNodeCat = rDefNode.Category()
    #print (f"ReportDefinitionNode Category={rDefNodeCat} type={type(rDefNodeCat)}")

    print (f"reportDef ChildNodes {reportDef.ChildNodes}")
    children = reportDef.ChildNodes
    print ("ChildNodes: Count=", children.__len__())
    for j in range(0, children.__len__()):
        c0 = children[j]
        print (f"Child Name={c0.Name} DisplayLabel={c0.DisplayLabel} NodeType={c0.NodeType} type={type(c0)}")
        
    columnsNode = reportDef.GetChildByName("_COLUMN_GROUP_")
    if columnsNode is None:
        print("Child _COLUMN_GROUP_ is NONE")
    else:
        print (f"Found Columns child node Name={columnsNode.Name} DisplayLabel={columnsNode.DisplayLabel} type={type(columnsNode)}")
        cgn = ColumnGroupNode(columnsNode)
        print (f"ColumnGroupNode type={type(cgn)}")

        columns = columnsNode.ChildNodes
        if columns is None:
            print("Columns is NONE")
        else:
            print ("Columns: Count=", columns.__len__())
            for k in range(0, columns.__len__()):
                col0 = columns[k]
                print (f"Column Name={col0.Name} DisplayLabel={col0.DisplayLabel} NodeType={col0.NodeType} type={type(col0)}")
                colDef = ColumnDefinitionNode(col0)
                fo = colDef.GetFormattingOptions
                print (f"Column Def Name={colDef.Name} DisplayLabel={colDef.DisplayLabel} NumAccessors={colDef.NumAccessors} FormattingOptions={fo} type={type(colDef)}")
#                def GetAccessors(self: MSPyDgnPlatform.ColumnDefinitionNode) -> MSPyDgnPlatform.ReportColumnAccessorArray:
#    SetAccessors(self: MSPyDgnPlatform.ColumnDefinitionNode, accessors: MSPyDgnPlatform.ReportColumnAccessorArray) -> bool

                acc = colDef.GetAccessors()
                if not acc is None:
                    print (f"Found columnDef Accessors")
                    print (f"acc type={type(acc)}")
                    for a in range(0, acc.__len__()):
                        acc0 = acc[a]
                        print (f"acc0 type={type(acc0)}")
                        acc1 = acc[a].ArrayAccessor
                        print (f"acc1 type={type(acc1)}")
                        acc2 = acc0.GetAccessor()
                        print (f"acc2 type={type(acc2)}")
                        print (f"SchemaName={acc2.SchemaName} ClassName={acc2.ClassName} AccessString={acc2.AccessString}")
                
                #print (f"SelectionScopeOption {reportDef.SelectionScopeOption}")
                #cat = reportDef.Category
                #if not cat is None:
                #    print (f"Found category")
                #print ("Report collection: ColumnCount=", reportDef.GetColumnCount())
                #cn = reportDef.GetChildNodes()    def GetChildNodes(self: MSPyDgnPlatform.ECReportNode) -> MSPyDgnPlatform.ECReportNodePtrArray:
                #columnGrpNode = reportDef.GetColumnGroupNode()

''' Print the report definitions in the given report collection. '''    
def PrintReportDefinitions(rc):
    '''
    Print the report definitions in the given report collection.

    :param rc: The report collection.
    :type rc: ReportDefinitionCollection

    '''

    if not rc:
        return

    print(f"Report collection type: {type(rc)}")
    print ("Report collection: Count=", rc.Count)

    for i in range(0, rc.__len__()):
        reportDef = rc.GetReportDefinitionAt(i)
        print(f"reportDef type: {type(reportDef)}")
        if not reportDef is None:
            PrintReportDefinition (reportDef)


if __name__ == "__main__":
    print("Script start...")

    reportCategoryName = "FortLauderdaleBridgeProject"
    reportName = "RoadsAffectedByBridgeProject"
    #reportName = "ChrisManualCreation"
    
    rpt = GetExistingReport(reportName)
    if rpt is None:
        print(f"Failed to get report {reportName}")
    else:
        print(f"Found report {reportName}")
        PrintReportDefinition(rpt)

    print("Script end...")
