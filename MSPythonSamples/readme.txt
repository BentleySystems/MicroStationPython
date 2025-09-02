[0]File: MSPythonSamples\3DModeling\SolidModification\SolidModification.py
'''
Samples demonstrating how to modify solid
Prerequisite: Open MSPythonSamples\\data\\SolidModeling.dgn  
'''

[1]File: MSPythonSamples\ChangeGlassColor\GlassColorDarkerToLighter.py
'''
Running this sample needs to open GlassColor.dgn.
This sample demonstrates how to change the glass panels color from darker to lighter from the top row to bottom row.
'''

[2]File: MSPythonSamples\ChangeGlassColor\GlassColorRandom.py
'''
Running this sample needs to open GlassColor.dgn.
this sample demonstrates how to change the glass panels with random color and transparency.
'''

[3]File: MSPythonSamples\ChangeGlassColor\GlassColorWithQtDialog.py
'''
Running this sample needs to open GlassColor.dgn.
This sample demonstrates how to change the glass panels with PyQt UI.
Drag the red box in middle to change color of the glasses.
Right click on the 3 red boxes on left, middle or right to pick different color with QColorDialog.
'''

[4]File: MSPythonSamples\COM\PlaceLine.py
'''
Example demonstrating how to use the Microstation COM API to create a Line. 
Note: Running this sample need to install lib win32com
'''

[5]File: MSPythonSamples\DgnElements\AcsExample.py
'''
Sample demonstrating how to create acs
'''

[6]File: MSPythonSamples\DgnElements\ArcExample.py
'''
Example demonstrating how to create a set of arcs
'''

[7]File: MSPythonSamples\DgnElements\CreateSections.py
'''
Run the sample on CreateSections.dgn with No WorkSet.
The sample demonstrates following steps:
Identify an element by type(line string), level and color, 
creating multiple sections at intervals along the line string using specific drawing seed, 
and for each section increment the name by 1.
Interval can be set in the script.
'''

[8]File: MSPythonSamples\DgnElements\CreateTextNodes.py
'''
Sample demonstrating how to create text block
''' 

[9]File: MSPythonSamples\DgnElements\CreationExample.py
'''
Samples demonstrating how to create elements: line, linestring, arc, ellipse, rasterattachment,dgnattachment, acs, namedgroup
''' 

[10]File: MSPythonSamples\DgnElements\DgnAttachmentExample.py
'''
Sample demonstrating how to create a DGN attachment in an active model.
''' 

[11]File: MSPythonSamples\DgnElements\DrawBSPLine.py
'''
Sample demonstrating how to create a B-spline curve element.
'''

[12]File: MSPythonSamples\DgnElements\DrawCircles.py
'''
Sample demonstrating how to Draw a set of circles with default parameters.
'''

[13]File: MSPythonSamples\DgnElements\DrawCurve.py
'''
Sample demonstrating how to create a curve element.
'''

[14]File: MSPythonSamples\DgnElements\DrawElementWithArguments.py
'''
 Sample demonstrating how to pass arguments to python script. 
 
 In Python, you can use sys.argv to handle command line arguments passed to a Python script.
 argv[0] is the script name, so you can get your own arguments begin from argv[1].
 This sample shows how to draw Line or Circle with different arguments.
 1. Draw Line:
      argument1: Pass "Line" to draw a line
      argument2: x coordinate of line start point
      argument3: y coordinate of line start point
      argument4: z coordinate of line start point
      argument5: x coordinate of line end point
      argument6: y coordinate of line end point
      argument7: z coordinate of line end point
    So you can pass "Line 0 0 0 10 10 10" as the arguments from Python Manager then run it to draw a line from (0, 0, 0) to (10, 10, 10).
 2. Draw Circle:
      argument1: Pass "Circle" to draw a circle
      argument2: x coordinate of circle center point
      argument3: y coordinate of circle center point
      argument4: z coordinate of circle center point
      argument5: radius of circle
    So you can pass "Circle 0 0 0 10" as the arguments from Python Manager then run it to draw a circle at (0, 0, 0) with radius 10.
 3. Pass any other arguments format will be invalid and it will print a message "Arguments error!"
'''

[15]File: MSPythonSamples\DgnElements\DrawGroupedHole.py
'''
Sample demonstrating how to create a Grouped Hole element.
'''

[16]File: MSPythonSamples\DgnElements\DrawLine.py
'''
Sample demonstrating how to Draw a set of lines with default parameters.
'''

[17]File: MSPythonSamples\DgnElements\DrawMultiLine.py
'''
Sample demonstrating how to create a multi-line element.
'''

[18]File: MSPythonSamples\DgnElements\DrawRoundRectangles.py
'''
Sample demonstrating how to draw a set of round-rectangles with default parameters.
'''

[19]File: MSPythonSamples\DgnElements\ElementsToDisplaySet.py
'''
Sample demonstrating how to select elements in the active DGN model by the specified level name and  create display set by its level number
Prerequisite : Run the sample on DisplaySetExample.dgn 
'''

[20]File: MSPythonSamples\DgnElements\EllipseExample.py
'''
Example demonstrating how to create multiple ellipses in the active DGN model.
'''

[21]File: MSPythonSamples\DgnElements\LineExample.py
'''
This sample demonstrates how to changes the color, linestyle, weight, and level of an element
'''

[22]File: MSPythonSamples\DgnElements\LineStringExample.py
'''
Sample demonstrating how to create an element by calling its handler's 'create' method.
'''

[23]File: MSPythonSamples\DgnElements\MeasureAngleExample.py
'''
Sample demonstrating how to measure the angles between segments of a line string.
'''

[24]File: MSPythonSamples\DgnElements\MeasureDistanceExample.py
'''
Sample demonstrating how to measure distance.
'''

[25]File: MSPythonSamples\DgnElements\NamedGroupExample.py
'''
This sample demonstrates how to create a named group
'''

[26]File: MSPythonSamples\DgnElements\PlaceCellFromLibrary.py
'''
Example demonstrating how to place Cell
Prerequisite : Run the sample on PlaceCell.dgn
'''

[27]File: MSPythonSamples\DgnElements\QueryRasterElement.py
'''
Sample demonstrating how to list and query raster elements in a model
'''

[28]File: MSPythonSamples\DgnElements\RasterAttachmentExample.py
'''
Sample demonstrating how to create Raster Attachment
'''

[29]File: MSPythonSamples\DgnElements\SelectCellElementByName.py
'''
This sample demonstrates how to select cell elements by name
'''

[30]File: MSPythonSamples\DgnElements\SelectElementByArea.py
'''
This sample demonstrates how to select elements by area
'''

[31]File: MSPythonSamples\DgnElements\SelectElementByColor.py
'''
This sample demonstrates how to select elements by color
'''

[32]File: MSPythonSamples\DgnElements\SelectElementByItemType.py
'''
This sample demonstrates how to select elements by item type
'''

[33]File: MSPythonSamples\DgnElements\SelectElementByLength.py
'''
This sample demonstrates how to select elements by Length
'''

[34]File: MSPythonSamples\DgnElements\SelectElementByLevelName.py
'''
This sample demonstrates how to select elements by level name
'''

[35]File: MSPythonSamples\DgnElements\SelectElementByLevelNumber.py
'''
This sample demonstrates how to select elements by level number
'''

[36]File: MSPythonSamples\DgnElements\SelectElementByLineStyle.py
'''
This sample demonstrates how to select elements by line style
'''

[37]File: MSPythonSamples\DgnElements\SelectElementByPerimeter.py
'''
This sample demonstrates how to select elements by perimeter
'''

[38]File: MSPythonSamples\DgnElements\SelectElementByRGBColor.py
'''
This sample demonstrates how to select elements by RGB color.
'''

[39]File: MSPythonSamples\DgnElements\SelectElementByType.py
'''
This sample demonstrates how to select elements of a specific type
'''

[40]File: MSPythonSamples\DgnElements\SelectElementByVolume.py
'''
This sample demonstrates how to select elements based on their volume.
'''

[41]File: MSPythonSamples\DgnElements\SelectElementByWeight.py
'''
This sample demonstrates how to Selects and highlights all graphical elements in the active model that match the specified weight
'''

[42]File: MSPythonSamples\DgnElements\SelectElementsOnLevelByColor.py
'''
This sample demonstrates how to selects elements based on their level and color
'''

[43]File: MSPythonSamples\DgnElements\SelectSharedCellElementByName.py
'''
This sample demonstrates how to select shared cell elements in the active model that match the given cell name
'''

[44]File: MSPythonSamples\DgnElements\Reference\Reference.py
'''
This sample demonstrates how to add key-in commands and use those commands to attach, detach and rotate a dgn attachment
'''

[45]File: MSPythonSamples\DgnModel\CreateModifyModel.py
'''
Sample demonstrating how to create a model and change its type
''' 

[46]File: MSPythonSamples\DgnTool\ElementCopyTool.py
'''
Example demonstrating how to use DgnElementSetTool to write a basic COPY ELEMENT tool.
'''

[47]File: MSPythonSamples\DgnTool\ElementFlood.py
'''
Example demonstrating how to use DgnRegionElementTool to write a CREATE REGION by FLOOD tool.

The base class handles collecting the region boundary from the elements in the view
or selection set. The sub-class is responsible for doing something with the new region
and optionally processing the original elements that comprise the boundary.
'''

[48]File: MSPythonSamples\DgnTool\ElementModifier.py
'''
Example demonstrating how to use DgnElementSetTool to write a MODIFY ELEMENT tool.
This tool will move the closest vertex on a line or linestring.
'''

[49]File: MSPythonSamples\DgnTool\ElementMover.py
'''
Example demonstrating how to use DgnElementSetTool to write a basic MOVE ELEMENT tool.
'''

[50]File: MSPythonSamples\DgnTool\ElementRotateTool.py
'''
Example demonstrating how to use DgnElementSetTool to write a basic ROTATE ELEMENT tool.
'''

[51]File: MSPythonSamples\DgnTool\ElementScaleTool.py
'''
Example demonstrating how to use DgnElementSetTool to write a basic SCALE ELEMENT tool.
'''

[52]File: MSPythonSamples\DgnTool\ExampleViewTool.py
'''
Example demonstrating how to use DgnViewTool to write a viewing tool.

A simple viewing tool example that zooms the view and centers the accept.
Demonstrates using IndexedViewSet and IViewManager to update the view.
By default a DgnViewTool will exit on a reset button event.

'''

[53]File: MSPythonSamples\DgnTool\LineCreatorWithQtToolSettingDialog.py
'''
This sample demonstrates how to create a DgnPrimitiveTool with a tool setting dialog implemented using PyQt5.
'''

[54]File: MSPythonSamples\DgnTool\LineCreatorWithToolSettingDialog.py
'''
This sample demonstrates how to create a DgnPrimitiveTool with a tool setting dialog implemented using tkinter.
'''

[55]File: MSPythonSamples\DgnTool\MeshTools\MeshToolCreateMesh.py
'''
Sample demonstrating how to create a mesh element baseed on DgnElementSetTool.
'''

[56]File: MSPythonSamples\DgnTool\MeshTools\MeshTools.py
'''
This sample demonstrates how to add a key-in command and use that command to launch a DgnElementSetTool, which creates a mesh element.
'''

[57]File: MSPythonSamples\DgnTool\PolyfaceTool\PolyfaceCreateTool.py
'''
Sample demonstrating how to create a DgnElementSetTool in python and create a mesh element with the tool.
'''

[58]File: MSPythonSamples\DgnTool\PolyfaceTool\PolyfaceTool.py
'''
This sample demonstrates how to add a key-in command and use that command to launch a DgnElementSetTool
'''

[59]File: MSPythonSamples\DgnTool\TextExample\TextExample.py
'''
Sample demonstrating how to create text with 4 different styles.
'''

[60]File: MSPythonSamples\DgnTool\TextExample\TextExampleCreateText.py
'''
Sample demonstrating how to create a text node element with single or multiple lines of text
'''

[61]File: MSPythonSamples\DgnTool\TextExample\TextExampleCreateTextStyles.py
'''
Sample demonstrating how to create a text Style based on the provided style name
'''

[62]File: MSPythonSamples\EC\Dump\ECDumpUtility.py
'''
Sample demonstrating how to dump EC data for selected element
'''

[63]File: MSPythonSamples\EC\Schema\ECXSchema.py
'''
Sample demonstrating how to export Schema files of active dgn file to a txt file
'''

[64]File: MSPythonSamples\GeospatialContext\GeospatialContextConnection.py
'''
Example demonstrating how to create or obtain a Geospatial Context connection to an ArcGIS Server
'''

[65]File: MSPythonSamples\GeospatialContext\GeospatialContextUtilities.py
''' 
Example demonstrating how to Create a fence from a named boundary. 
'''

[66]File: MSPythonSamples\GeospatialContext\QueryAndDisplayProjectArea.py
'''
Example showing Geospatial Context query and display of a project area in Fort Lauderdale, Florida.

1. Create a named boundary from lat/long bounding box around Fort Lauderdale, Florida
2. Connect to Esri ArcGIS server URL: https://ca.dep.state.fl.us/arcgis/rest/services/OpenData/STATEWIDE_LU_2004_2013/MapServer/3
3. Query features from the server within the named boundary
4. Create a display rule set with display rules to display areas in two colors:
    a. Green - Areas suitable for infrastructure
    b. Red - Areas to be preserved
5. Create a display style that uses the display rule set
6. Assign the display style to the current view
7. Fit the named boundary in the view
'''

[67]File: MSPythonSamples\GeospatialContext\QueryServerConnection.py
'''
Sample demonstrating how to query features  from a Geospatial Context server connection
'''

[68]File: MSPythonSamples\ImageLib\SaveViewportToImage\SaveViewportToImage.py
'''
This sample demonstrates how to save a screenshot of the active view to a PNG file.
'''

[69]File: MSPythonSamples\ItemType\Attach\ItemTypeAttachDetach.py
'''
This sample demonstrates how to add key-in commands and use those commands to attach or detach item type
'''

[70]File: MSPythonSamples\ItemType\CRUD\ItemTypeCRUD.py
'''
This sample demonstrates how to add key-in commands and use those commands to create, read, update and delete item type.
'''

[71]File: MSPythonSamples\ItemType\Custom\ItemTypeCustomProperty.py
'''
This sample demonstrates how to add key-in commands and use those commands to add custom property to item type.
'''

[72]File: MSPythonSamples\Macro\GetInput.py
'''
This sample demonstrates how to use GetInput(keyin, data point etc.). (Used: GetInput)
1. Set Command and data point as the expected input.
2. Wait for the input. (PyCadInputQueue.GetInput will wait for user input.)
3. Print the input received by type.
'''

[73]File: MSPythonSamples\Macro\GroupHole.py
'''
This sample demonstrates creating group hole by selecting outer and inner boundary. (Used:SendCommand, SendDataPointForLocate, SendDataPoint)
1. Invoke "Group Hole" Command.
2. Select outer and inner boundary element.
'''

[74]File: MSPythonSamples\Macro\PlaceLine.py
'''
This sample demos how to invoke the command by keyin. (Used: SendKeyin, SendDataPoint, SendReset)
1. Invoke "Place Line" Command.
2. Input 2 points.
'''

[75]File: MSPythonSamples\Misc\ShowElementAmountWithPandasBar.py
'''
Running this sample needs libraries pandas and matplotlib installed.
This sample uses library pandas to create a bar chart image . 
The image is attached in the active model as a raster element, and shows 
the element amount as per type.
'''

[76]File: MSPythonSamples\Misc\AppData\AppData.py
'''
Example demonstrating how to use DgnModelAppData to listen for events in a DgnModel
'''

[77]File: MSPythonSamples\Misc\Debugging\VSCode\DebugPlaceLine.py
'''
Sample demonstrating how to debug a Python script using Debugpy in MicroStation
''' 

[78]File: MSPythonSamples\Misc\ExchangeDataBetweenExcelAndItemType\ExtractItemTypesToExcel.py
'''
Example demonstrating how to extract Item Types and export them into excel.

Running this sample needs to open ExchangeDataBetweenExcelAndItemType.dgn or other design
file includes title block item.
Command file 'Extract Item Types to Excel.txt' and 'Repopulate Items from Excel.txt' would
be used within Batch Processor.
'Extract Item Types to Excel.txt' would extract title block information to an Excel file.
User can edit the title block information in Excel, then use 'Repopulate Items from Excel.txt'
to re-populate the title block Item Types with the new information. 
'''

[79]File: MSPythonSamples\Misc\ExchangeDataBetweenExcelAndItemType\RepopulateItemsFromExcel.py
'''
Samples demonstrating how to repopulate item type data to excel
'''

[80]File: MSPythonSamples\ParametricModeling\BoltAndNut.py
'''
Sample demonstrating how to create bolts, nuts, screws using parametric solid
'''

[81]File: MSPythonSamples\ParametricModeling\Constraint2d.py
'''
Sample demonstrating how to create 2D constraints
''' 

[82]File: MSPythonSamples\ParametricModeling\Constraint3d.py
'''
Sample demonstrating how to create fixed constraint for first cube, then create parallel and distance constraint for 2 faces of 2 cubes
Prerequisite: Open MSPythonSamples\\data\\Constraint3d.dgn to run this sample
'''

[83]File: MSPythonSamples\ParametricModeling\I-beam.py
'''
Example demonstrating how to create I-beam profile with 2D constraint
''' 

[84]File: MSPythonSamples\ParametricModeling\ParametricCell.py
'''
Example demonstrating how to create and place parametric cell
'''

[85]File: MSPythonSamples\ParametricModeling\ParametricSolid.py
'''
Example demonstrating how to create a cylinder by extruding a circle
''' 

[86]File: MSPythonSamples\ParametricModeling\PSampUtility.py
''' Utility functions'''

[87]File: MSPythonSamples\ParametricModeling\VariableAndVariation.py
'''
Examples demonstrates how to CRUD variables
'''

[88]File: MSPythonSamples\Plot\Pdf\PdfPlot.py
'''
Example demonstrating how to print the currently loaded design file independent of the MicroStation print dialog application.
'''

[89]File: MSPythonSamples\SystemCallbacks\ChangeTrackCallbacks.py
'''
Sample demonstrating how to use the ChangeTracking callback API
'''

[90]File: MSPythonSamples\SystemCallbacks\HistoryCallbacks.py
'''
Sample demonstrating how to use the HistoryCallback  API
'''

[91]File: MSPythonSamples\SystemCallbacks\InputCallbacks.py
'''
Sample demonstrating how the input callbacks work in python
'''

[92]File: MSPythonSamples\SystemCallbacks\LocateCallbacks.py
'''Sample demonstrating how the locate callbacks work in python'''

[93]File: MSPythonSamples\SystemCallbacks\StateCallbacks.py
'''
Sample demonstrating how state callback works in Python
'''

[94]File: MSPythonSamples\SystemCallbacks\SystemCallbacks.py
'''
Sample demonstrating how system callback works in Python
'''

[95]File: MSPythonSamples\SystemCallbacks\ViewCallbacks.py
'''
Sample demonstrating how view callback works in Python
'''

[96]File: MSPythonSamples\UX\Qt\Clock\PyQtClock.py
'''
# Simple Clock Example which demonstrates a PyQt5 UX window containing a clock which doesnt block
# the execution of Microstations input loop.
#
# Using app.exec will not return out of the loop until the PyQt5 window is closed, this blocks
# the main application thread of Microstation. Qt is a C based Ux framework who's timers will execute in the main event loop for the UX framework
#
# Registering a timer with a 0 start interval will cause the timer method to execute every time the Qt Windows event loop finishes. Calling PyCadInputQueue.PythonMainLoop 
# from the timer will allow Microstation's input loop to execute allowing use of the Microstation UX whilst the Qt window is displayed.
'''

[97]File: MSPythonSamples\UX\Terminal\Terminal.py
'''
Sample demonstrating how to run a Python terminal in MicroStation
'''

[98]File: MSPythonSamples\UX\Tk\Clock\TkClock.py
'''
# Simple Clock Example which demonstrates a tkinter UX item containing a clock which doesnt block
# the execution of Microstations input loop.
#
# Using tkinter.mainloop will not return out of the loop until the tkinter UX item is closed, this blocks
# the main application thread of Microstation. The underlying Tcl UX event loop does not expose any capabilities to register handlers through 
# python and as such this cannot be corrected from within Microstation Code.
# 
# To workaround this use the tkinter.update method instead, this will return after processing all the tkinter UX events, then we can execute
# a Microstation function mdlInput_pythonMainLoop to process the main input loop of Microstation.
'''

[99]File: MSPythonSamples\UX\Tk\ModalDialog\TkModalDialog.py
'''
Simple Modal Dialog Example which demonstrates a tkinter modal dialog containing text and button to open a file picker,
to allow a user to select a raster file, then create a raster attachment.
'''

[100]File: MSPythonSamples\UX\Tk\TitleBlockMgr\TkTitleBlockManager.py
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

[101]File: MSPythonSamples\View\ViewGroupExample.py
'''
This example provides the following operations for view groups.

Add view group
Delete view group
Rename view group(Edit name in list)
Apply view group(Double click).
'''

[102]File: MSPythonSamples\View\ViewInfoExample.py
'''
ViewInfoExample demonstrates use of ViewInfo related APIs.

Load this sample, View info dialog will be opened automatically.

This example provides the following operations for view groups.

Display detailed view info.
Reset view info.
'''

[103]File: MSPythonSamples\View\ViewToolExample.py
'''
This sample allows for exact sizing of MicroStation's standard views.  View size can be
specified with an absolute pixel size (widthxheight) or by a ratio.  What
this enables you to create a view's raster images of an exact size (640x480, 1024x768, etc.).
Normally when doing a File->Save As you can only specify the width or the height of the
output image...the other value is computed by taking the value you entered
and multiplying it by the current view ratio.  Now you can set what the
current views ratio is so images will be the size you want without having
to muck about trying to stretch views to get the right size.

This sample also shows a way to localize the UI strings using a json file.
'''

