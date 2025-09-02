# MicroStationPython
## About

Welcome to the MicroStation Python binding implementation.

## Build
To build the MicroStation Python binding you need the following :
  1. An Installation of the MicroStation SDK and all its preqrequisites. This is obtainable via registering with the Bentley Developer Network. Please ensure the SDK examples all build before proceeding here. Whilst the MicroStation Python project is in active development you will need the latest MicroStation SDK starting with the MicroStation 2024 SDK. As we proceed we will potentially need to add new functionality to the SDK to support features in the MicroStation Python implementation, so if you discover issues with building the code please verify you have the latest released MicroStation SDK
  2. An installation of [Boost version 1.8.2](https://www.boost.org/users/history/version_1_82_0.html)

Once you have these you will need to set some extra environment variables in your MicroStation SDK Developer Shell these are :

    BMAKE_OPT= -I<Location of build/PublicSDK> -I <Location of SDK Includes>
    BB_DEFAULT_TOOLSET=VS2022
    SrcRoot=<Location of MicrostationPython source code>C:\src\MicroStationPython\
    OutRoot=<Location of the build artifacts>
    PythonDir=<Location of Python installation>
    BoostInclude=<Location of boost headers>

An example of this is :

  set BMAKE_OPT= -I C:\src\MicroStationPython\build\PublicSDK\ -I C:\MicroStation2024SDK\include\
  set BB_DEFAULT_TOOLSET=VS2022  
  set SrcRoot=C:\src\MicroStationPython\
  set OutRoot=C:\out\MicroStationPython\
  set PythonDir=C:\Python312\
  set BoostInclude=c:\boost\boost_1_82_0\

Once you have these set in your environment you can do :

   cd \MicrostationPython

   bmake MSPython

This will build the artifcats associated with each .mke file and place them in the OutRoot\Win64\build\MSPython directory.

## Contact

Post any questions on the Bentley Communities Programming Forum

## Contribution

If you would like to contribute by either adding fixes, new bindings or examples please post on Bentley Communities and read CONTRIBUTING.md