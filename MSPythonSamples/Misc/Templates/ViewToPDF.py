from MSPyBentley import *
from MSPyECObjects import *
from MSPyBentleyGeom import *
from MSPyDgnPlatform import *
from MSPyDgnView import *
from MSPyMstnPlatform import *

def generate_pdf_plot():
    try:
        # Create a print description instance
        printref = PrintDescriptionRef.Create()
        printDesc = printref.GetP()

        # Initialize the print description to use the PDF printer driver configuration
        printDesc.InitializeFromTCB("pdf.pltcfg")

        # Maximize the print size to the currently selected paper size
        printDesc.Maximize()

        # Create the PDF save path
        emptyDir = WString()
        ConfigurationManager.GetLocalTempDirectory(emptyDir, "")
        tempFileName = "CurrentViewPlot.pdf"
        fileSpec = str(emptyDir) + str(tempFileName)
        BeFileName.BeDeleteFile(fileSpec)

        # Create the PDF file
        printDesc.Print(fileSpec)

        print(f"PDF generated at: {fileSpec}")

    except Exception as e:
        print(f"An error occurred: {e}")

# Call the function to generate the PDF plot
generate_pdf_plot()