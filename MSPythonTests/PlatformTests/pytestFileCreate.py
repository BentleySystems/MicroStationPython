#---------------------------------------------------------------------------------------------
#  Copyright (c) Bentley Systems, Incorporated. All rights reserved.
#  See LICENSE.md in the repository root for full copyright notice.
#---------------------------------------------------------------------------------------------
import os

def pytest_create():
    cfgFullFilename = os.path.dirname(os.path.abspath(__file__)) + os.path.sep + 'pytest.ini'
    tmpDgnFolder = os.getenv('USERPROFILE') + '\\AppData\\Local\\MSPyTestFiles\\'
    tmpDgnFolder = tmpDgnFolder.replace('\\','/')
    os.makedirs(tmpDgnFolder, exist_ok=True)
    testDataFolder  = os.path.dirname(os.path.abspath(__file__)) + os.path.sep + 'data\\'
    testDataFolder  = testDataFolder.replace('\\','/')
 
    cfgFile = open(cfgFullFilename, 'w')
    cfgFile.writelines('[pytest]\n')
    cfgFile.writelines('env =\n')
    cfgFile.writelines('    MSPYTESTDATA=' + testDataFolder + '\n')
    cfgFile.writelines('    MSPYTEMPDATA=' + tmpDgnFolder + '\n')
    cfgFile.writelines('addopts = -s\n')
    cfgFile.writelines('markers =\n')
    cfgFile.writelines('    debugTest: for filtering out tests with usage of @pytest.mark.debugTest or pytestmark = pytest.mark.debugTest\n')
    cfgFile.close()

if __name__ == "__main__":
    pytest_create()

