# $Copyright: (c) 2024 Bentley Systems, Incorporated. All rights reserved. $

import math
from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyMstnPlatform import *

'''
Example demonstrating how to print the currently loaded design file independent of the MicroStation print dialog application.
'''
def PrintToPDF():
       """
       Generates a PDF file from the current MicroStation environment.
       This function initializes the print description to use the PDF printer driver
       configuration, maximizes the print size to the currently selected paper size,
       and creates a PDF file in the local temporary directory.
       Steps:
       1. Create a print description instance.
       2. Initialize the print description with the PDF printer driver configuration.
       3. Maximize the print size.
       4. Create the PDF save path.
       5. Delete any existing file with the same name.
       6. Create the PDF file.
       7. Print the file path of the generated PDF.
       
       :raises Exception: If there is an error during the PDF generation process.
       """
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

