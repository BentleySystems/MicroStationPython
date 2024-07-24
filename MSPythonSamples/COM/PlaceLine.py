#---------------------------------------------------------------------------------------------
#  Copyright (c) Bentley Systems, Incorporated. All rights reserved.
#  See LICENSE.md in the repository root for full copyright notice.
#---------------------------------------------------------------------------------------------
import win32com.client as win32

# Example of how to use the Microstation COM API to create a Line. 
# Note: Running this sample need to install lib win32com

msApp = win32.Dispatch('MicrostationDGN.Application') # Dispatch the Microstation DGN application

inputQueue = msApp.CadInputQueue # Get the Cad Input Queue object

inputQueue.SendKeyIn ('PLACE LINE CONSTRAINED') # Send the 'PLACE LINE CONSTRAINED' command to Microstation DGN

startPt = win32.Record ('Point3d', msApp) # Create a new Point3d record object

startPt.X = 0.0 # Set the X-coordinate of the start point
startPt.Y = 0.0 # Set the Y-coordinate of the start point
startPt.Z = 0.0 # Set the Z-coordinate of the start point

inputQueue.SendDataPoint (startPt, 2) # Send the start point as a data point to Microstation DGN

endPt = win32.Record ('Point3d', msApp) # Create another new Point3d record object

endPt.X = startPt.X + 10000.0 # Set the X-coordinate of the end point, 10,000 units beyond the start point
endPt.Y = startPt.Y + 10000.0 # Set the Y-coordinate of the end point
endPt.Z = 0.0 # Set the Z-coordinate of the end point

inputQueue.SendDataPoint (endPt, 2) # Send the end point as a data point to Microstation DGN

inputQueue.SendReset() # Reset the input queue


