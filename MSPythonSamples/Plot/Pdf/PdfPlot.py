# -*- coding: utf-8 -*-
'''
/*--------------------------------------------------------------------------------------+
| $Copyright: (c) 2024 Bentley Systems, Incorporated. All rights reserved. $
+--------------------------------------------------------------------------------------*/
'''
import math
from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyMstnPlatform import *

'''
print the currently loaded design file independent of the MicroStation print dialog application.
'''
def PrintToPDF():
       # Create a print description instance.
       printref = PrintDescriptionRef.Create()
       printDesc = printref.GetP()

       # Initialize the print description to use the PDF printer driver
       # configuration and the active MicroStation environment.
       printDesc.InitializeFromTCB ("pdf.pltcfg")

       # Maximize the print size to the currently selected paper size.
       printDesc.Maximize()

       # Create the PDF save path.
       emptyDir = WString ()
       ConfigurationManager.GetLocalTempDirectory (emptyDir,"")
       tempFileName = "Sample.pdf"
       fileSpec = str (emptyDir) + str (tempFileName)
       BeFileName.BeDeleteFile (fileSpec)
       
       # Create the PDF file.
       printDesc.Print(fileSpec)

       print (fileSpec + str(" generated"))
       
if __name__ == "__main__":
    print("pdf plot started")
    PrintToPDF()
    print("pdf plot end")

