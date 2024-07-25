#---------------------------------------------------------------------------------------------
#  Copyright (c) Bentley Systems, Incorporated. All rights reserved.
#  See LICENSE.md in the repository root for full copyright notice.
#---------------------------------------------------------------------------------------------
import os
import pytest
from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyDgnView import *
from MSPyMstnPlatform import *


# To get output from this test you need to connect a gps device to Microstation. 
# This can be done with an android phone, running the "Bluetooth GPS Output app". Run the App, enable it and make it discoverable then connect it to the PC as a bluetooth device.
# Then in the windows Bluetooth & Devices -> Devices -> More Bluetooth settings. It will open a dialog, select the COM Ports tab, you should see an entry
# COM? Outgoing PC'SPP slave' this is the com port to use in the GPS Settings dialog along with the device type "NMEA-Compatible" Once its all connected the Status
# Tab of the GPS Dialog should stream data. Run this python app to see the output

@pytest.mark.skip(reason="Needs GPS Connected")
def test_GPS ():
    gps = IGlobalPositionSource.GetGlobalPositionSource ()
    
    print (f'GPS Available {gps.GPSAvailable ()}')
    count = 0

    while (gps.GPSAvailable () and count < 20):
        data = GlobalPositionData ()
        gps.GetLatestPositionData (data)
        print (f'longitude {data.longitude}')
        print (f'latitude {data.latitude}')
        print (f'elevation {data.elevation}')
        print (f'UTCTicks {data.UTCTicks}')
        print (f'fixDimension {data.fixDimension}')
        print (f'PDOP {data.PDOP}')
        print (f'HDOP {data.HDOP}')
        print (f'VDOP {data.VDOP}')
        print (f'heading {data.heading}')
        print (f'velocity {data.velocity}')
        count += 1


#if __name__ == "__main__":
#    test_GPS ()