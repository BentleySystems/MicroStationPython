import win32com.client as win32

# Example of how to use the Microstation COM API to create a Line. 
# Note: Running this sample need to install lib win32com

msApp = win32.Dispatch('MicrostationDGN.Application')
inputQueue = msApp.CadInputQueue
inputQueue.SendKeyIn ('PLACE LINE CONSTRAINED')
startPt = win32.Record ('Point3d', msApp)
startPt.X = 0.0
startPt.Y = 0.0
startPt.Z = 0.0
inputQueue.SendDataPoint (startPt, 2)
endPt = win32.Record ('Point3d', msApp)
endPt.X = startPt.X + 10000.0
endPt.Y = startPt.Y + 10000.0
endPt.Z = 0.0
inputQueue.SendDataPoint (endPt, 2)
inputQueue.SendReset()



