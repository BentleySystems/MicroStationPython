import os
import sys
import pytest
from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *

TEXT_SNIPPET_NAME_PREFIX = "TextSnippetTest"
FONT_NAME = "Arial Black"

def CreateSnippetInSourceFile(textSnippetName, dgnfile):
    styleName = str(sys._getframe().f_lineno)
    myStyle = DgnTextStyle(styleName, dgnfile)
    assert None != myStyle

    font = DgnFontManager.FindSystemFont(FONT_NAME)
    assert None != font

    myStyle.SetFontProperty (TextStyleProperty.eTextStyle_Font, font)
    assert BentleyStatus.eSUCCESS == myStyle.Add ()

    dictModel = dgnfile.GetDictionaryModel()
    textBlock = TextBlock(myStyle, dictModel)

    assert None != textBlock

    textBlock.AppendText (str(sys._getframe().f_lineno))

    snippet = DgnTextSnippet.Create(textSnippetName, dgnfile)
    assert None != snippet

    snippet.SetSnippetText (textBlock)
    snippet.SetName (textSnippetName)

    status = snippet.Add ()
    if status == BentleyStatus.eERROR:
        assert BentleyStatus.eSUCCESS == DgnTextSnippet.Delete (textSnippetName, dgnfile)
        return None
           
    #DgnTextSnippet 'Add(DgnFileP file = NULL)' should ideally set the element ID on the snippet. However that does not happen.
    #Once this issue is addressed, the following line should be included in the test.
    #assert (snippet.GetID () == 0)  #DgnTextSnippet.Add(DgnFileP file = NULL) failed to set element ID for the text snippet;

    if (snippet.GetID () == 0):
        snippet = DgnTextSnippet.GetByName (textSnippetName, dgnfile);
        
    return snippet

@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_RemapTextSnippetTest(initDgnPlatformHost, loadDgnFile, createTempDgnFileWithSeed):
    fileSrc = os.environ['MSPYTEMPDATA']+ os.path.basename(__file__).split('.')[0] + str(sys._getframe().f_lineno)+'.dgn'
    srcDgnFile = createTempDgnFileWithSeed (fileSrc, loadDgnFile)

    snippetName = TEXT_SNIPPET_NAME_PREFIX + str(sys._getframe().f_lineno)
    sourceSnippet =  CreateSnippetInSourceFile(snippetName, srcDgnFile)
    assert None != sourceSnippet

    srcDictModel = srcDgnFile.GetDictionaryModel()
    assert None != srcDictModel

    eeh = EditElementHandle (sourceSnippet.GetID(),srcDictModel)
    assert None != eeh

    fileTarget = os.environ['MSPYTEMPDATA'] + os.path.basename(__file__).split('.')[0] + str(sys._getframe().f_lineno)+'.dgn'
    BeFileName.BeDeleteFile (fileTarget)
    doc = DgnDocument.CreateForLocalFile(fileTarget)
    assert doc != None
    srcDgnFile.DoSaveTo(fileTarget)

    #Create a new DgnFile instance for testing ElementCopyContext.DoCopy()
    targetDgnFile = DgnFile(doc, DgnFileOpenMode.eReadWrite)
    targetDgnFile.LoadDgnFile ()
    targetDgnFile.FillDictionaryModel ()

    assert fileTarget == repr(targetDgnFile.GetFileName())

    targetDictModel = targetDgnFile.GetDictionaryModel()
    assert None != targetDictModel

    #Copy a dictionary element from one dgn file to another dgn file
    copier = ElementCopyContext(targetDictModel)
    assert None != copier

    status = copier.DoCopy(eeh)
    assert BentleyStatus.eSUCCESS == status
    
    copier.SetDestinationModelRef(None)
    if targetDgnFile.HasPendingChanges():
       targetDgnFile.ProcessChanges (DgnSaveReason.eApplInitiated)
 
    assert targetDictModel == eeh.GetDgnModel()

    destinationSnippet = DgnTextSnippet.GetByID (eeh.GetElementId (), targetDgnFile)
    assert None != destinationSnippet

@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_DgnTextSnippetCollectionAndIteratorTest(initDgnPlatformHost, loadDgnFile, createTempDgnFileWithSeed):
    fileSrc = os.environ['MSPYTEMPDATA']+ os.path.basename(__file__).split('.')[0] + str(sys._getframe().f_lineno)+'.dgn'
    srcDgnFile = createTempDgnFileWithSeed (fileSrc, loadDgnFile)

    snippetName = "CollectionAndIteratorTest0"
    snippet0 = DgnTextSnippet.Create(snippetName, srcDgnFile)
    assert None != snippet0
    assert BentleyStatus.eSUCCESS == snippet0.Add()
    snippetName = "CollectionAndIteratorTest1"
    snippet1 = DgnTextSnippet.Create(snippetName, srcDgnFile)
    assert None != snippet1
    assert BentleyStatus.eSUCCESS == snippet1.Add()
    snippetName = "CollectionAndIteratorTest2"
    snippet2 = DgnTextSnippet.Create(snippetName, srcDgnFile)
    assert None != snippet2
    assert BentleyStatus.eSUCCESS == snippet2.Add()
    collection = DgnTextSnippetCollection(srcDgnFile)
    assert collection != None

    #1)Call to next(snipIter) will make the previous iterator invalid. 
    #  See the definition DgnTextSnippetIterator::++, which always sets m_current = NULL at begining
    #2)DgnTextSnippet::GetSnippetText has a bug which causes a crash when access to property SnippetText (Fixed)
    snipIter = iter(collection)
    snippet = next(snipIter)
    assert snippet0.GetName() == snippet.GetName()

    snippet = next(snipIter)
    assert snippet1.GetName() == snippet.GetName()

    snippet = next(snipIter)
    assert snippet2.GetName() == snippet.GetName()

    propMask = snippet.Compare(snippet2)
    assert None != propMask
    assert True == propMask.AnyBitSet()

@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_DgnTextSnippetReplaceTest(initDgnPlatformHost, loadDgnFile, createTempDgnFileWithSeed):
    fileSrc = os.environ['MSPYTEMPDATA'] + os.path.basename(__file__).split('.')[0] + str(sys._getframe().f_lineno)+'.dgn'
    srcDgnFile = createTempDgnFileWithSeed (fileSrc, loadDgnFile)

    ret = srcDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    snippetName = "CopyValuesTest1"
    snippet1 = DgnTextSnippet.Create(snippetName, srcDgnFile)
    assert None != snippet1
    assert BentleyStatus.eSUCCESS == snippet1.Add()
    styleName = str(sys._getframe().f_lineno)
    myStyle = DgnTextStyle(styleName, srcDgnFile)
    assert BentleyStatus.eSUCCESS == myStyle.Add()
    textBlock = TextBlock(myStyle, ret[0])
    assert None != textBlock
    snippetString = "CopyValuesTest"
    textBlock.AppendText(snippetString)
    assert BentleyStatus.eSUCCESS == snippet1.SetSnippetText(textBlock)
    assert BentleyStatus.eSUCCESS == snippet1.Replace()
    collection = DgnTextSnippetCollection(srcDgnFile)
    assert collection != None

    snipIter = iter(collection)
    snippet  = next(snipIter)
    snippetText = snippet.GetSnippetText()
    assert None != snippetText
    assert snippetText.ToString() == (WString)(snippetString)

@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_DgnTextSnippetCopyValuesTest(initDgnPlatformHost, loadDgnFile, createTempDgnFileWithSeed):
    fileSrc = os.environ['MSPYTEMPDATA'] + os.path.basename(__file__).split('.')[0] + str(sys._getframe().f_lineno)+'.dgn'
    srcDgnFile = createTempDgnFileWithSeed (fileSrc, loadDgnFile)

    snippetName = "CopyValuesTest1"
    snippet1 = DgnTextSnippet.Create(snippetName, srcDgnFile)
    assert None != snippet1
    assert BentleyStatus.eSUCCESS == snippet1.Add()

    snippetName = "CopyValuesTest2"
    snippet2 = DgnTextSnippet.Create(snippetName, srcDgnFile)
    assert None != snippet2
    assert BentleyStatus.eSUCCESS == snippet2.Add()
    
    # Chech names are different
    assert 1 != (snippet1.GetName() == snippet2.GetName())
    snippet1.CopyValues(snippet2)
    # After copy, check names are same
    assert 1 == (snippet1.GetName() == snippet2.GetName())

@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_SetCategoryTest(initDgnPlatformHost, loadDgnFile, createTempDgnFileWithSeed):
    fileSrc = os.environ['MSPYTEMPDATA'] + os.path.basename(__file__).split('.')[0] + str(sys._getframe().f_lineno)+'.dgn'
    srcDgnFile = createTempDgnFileWithSeed (fileSrc, loadDgnFile)

    snippetName = "CategoryTestSnippet"
    snippet = DgnTextSnippet.Create(snippetName, srcDgnFile)
    assert None != snippet
    assert BentleyStatus.eSUCCESS == snippet.Add()

    categoryName = "CategoryTestCategory"
    category = DgnTextSnippetCategory(categoryName, srcDgnFile)
    assert None != category
    assert BentleyStatus.eSUCCESS == category.Add()

    assert BentleyStatus.eSUCCESS == snippet.SetCategory(category)
    category1 = snippet.GetCategory()
    assert None != category1

@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_AddSubCategoryTest(initDgnPlatformHost, loadDgnFile, createTempDgnFileWithSeed):
    fileSrc = os.environ['MSPYTEMPDATA'] + os.path.basename(__file__).split('.')[0] + str(sys._getframe().f_lineno)+'.dgn'
    srcDgnFile = createTempDgnFileWithSeed (fileSrc, loadDgnFile)

    rootCategoryName = "RootCategory"
    rootCategory = DgnTextSnippetCategory(rootCategoryName, srcDgnFile)
    assert None != rootCategory
    assert BentleyStatus.eSUCCESS == rootCategory.Add()

    subCategoryName = "SubCategory"
    subCategory = DgnTextSnippetCategory(subCategoryName, srcDgnFile)
    assert None != subCategory
    assert BentleyStatus.eSUCCESS == subCategory.Add()

    subCategory1 = DgnTextSnippetCategory(subCategoryName, srcDgnFile)
    assert None != subCategory1
    assert BentleyStatus.eSUCCESS == subCategory1.Add()

    assert BentleyStatus.eSUCCESS == rootCategory.AddSubCategory(subCategory)
    assert 1 == len(rootCategory.GetSubCategories())
    assert BentleyStatus.eERROR == rootCategory.AddSubCategory(subCategory1)
    assert 1 == len(rootCategory.GetSubCategories())

@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_BuildCategoryTreeTest(initDgnPlatformHost, loadDgnFile, createTempDgnFileWithSeed):
    fileSrc = os.environ['MSPYTEMPDATA'] + os.path.basename(__file__).split('.')[0] + str(sys._getframe().f_lineno)+'.dgn'
    srcDgnFile = createTempDgnFileWithSeed (fileSrc, loadDgnFile)

    rootCategoryName = "RootCategory"
    rootCategory = DgnTextSnippetCategory(rootCategoryName, srcDgnFile)
    assert None != rootCategory
    assert BentleyStatus.eSUCCESS == rootCategory.Add()

    subCategoryName = "Level1_Category1"
    subCategory1 = DgnTextSnippetCategory(subCategoryName, srcDgnFile)
    assert None != subCategory1
    assert BentleyStatus.eSUCCESS == subCategory1.Add()

    subCategoryName = "Level1_Category2"
    subCategory2 = DgnTextSnippetCategory(subCategoryName, srcDgnFile)
    assert None != subCategory2
    assert BentleyStatus.eSUCCESS == subCategory2.Add()

    subCategoryName = "Level2_Category11"
    subCategory11 = DgnTextSnippetCategory(subCategoryName, srcDgnFile)
    assert None != subCategory11
    assert BentleyStatus.eSUCCESS == subCategory11.Add()

    subCategoryName = "Level2_Category12"
    subCategory12 = DgnTextSnippetCategory(subCategoryName, srcDgnFile)
    assert None != subCategory12
    assert BentleyStatus.eSUCCESS == subCategory12.Add()

    subCategoryName = "Level2_Category21"
    subCategory21 = DgnTextSnippetCategory(subCategoryName, srcDgnFile)
    assert None != subCategory21
    assert BentleyStatus.eSUCCESS == subCategory21.Add()

    assert BentleyStatus.eSUCCESS == rootCategory.AddSubCategory(subCategory1)
    assert BentleyStatus.eSUCCESS == rootCategory.AddSubCategory(subCategory2)
    assert BentleyStatus.eSUCCESS == subCategory1.AddSubCategory (subCategory11)
    assert BentleyStatus.eSUCCESS == subCategory1.AddSubCategory (subCategory12)
    assert BentleyStatus.eSUCCESS == subCategory2.AddSubCategory (subCategory21)

    categories = DgnTextSnippetCategoryPtrArray()
    assert BentleyStatus.eSUCCESS == DgnTextSnippetCategory.BuildCategoryTreeFromFile(categories, srcDgnFile)
    assert 1 == len(categories)
    assert 2 == len(categories[0].GetSubCategories())
    assert 2 == len((categories[0].GetSubCategories())[0].GetSubCategories())
    assert 1 == len((categories[0].GetSubCategories())[1].GetSubCategories())

@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_RemoveSubCategoryTest(initDgnPlatformHost, loadDgnFile, createTempDgnFileWithSeed):
    fileSrc = os.environ['MSPYTEMPDATA'] + os.path.basename(__file__).split('.')[0] + str(sys._getframe().f_lineno)+'.dgn'
    srcDgnFile = createTempDgnFileWithSeed (fileSrc, loadDgnFile)

    rootCategoryName = "RootCategory"
    rootCategory = DgnTextSnippetCategory(rootCategoryName, srcDgnFile)
    assert None != rootCategory
    assert BentleyStatus.eSUCCESS == rootCategory.Add()
    subCategoryName = "SubCategory"
    subCategory = DgnTextSnippetCategory(subCategoryName, srcDgnFile)
    assert None != subCategory
    assert BentleyStatus.eSUCCESS == subCategory.Add()
    
    assert BentleyStatus.eSUCCESS == rootCategory.AddSubCategory(subCategory)
    assert 1 == len(rootCategory.GetSubCategories())
    assert BentleyStatus.eSUCCESS == rootCategory.RemoveSubCategory((WString)(subCategoryName))
    assert BentleyStatus.eSUCCESS == len(rootCategory.GetSubCategories())

@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_RenameCategoryTest(initDgnPlatformHost, loadDgnFile, createTempDgnFileWithSeed):
    fileSrc = os.environ['MSPYTEMPDATA'] + os.path.basename(__file__).split('.')[0] + str(sys._getframe().f_lineno)+'.dgn'
    srcDgnFile = createTempDgnFileWithSeed (fileSrc, loadDgnFile)

    rootCategoryName = "RootCategory"
    rootCategory = DgnTextSnippetCategory(rootCategoryName, srcDgnFile)
    assert None != rootCategory
    assert BentleyStatus.eSUCCESS == rootCategory.Add()

    assert rootCategory.SetName((WString)("RenamedRootCategory"))
    renamedRootCategoryName = rootCategory.GetName()
    assert BentleyStatus.eSUCCESS == (renamedRootCategoryName.CompareTo((WString)("RenamedRootCategory")))

@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_GetTextFavoritesTest(initDgnPlatformHost, loadDgnFile, createTempDgnFileWithSeed):
    fileSrc = os.environ['MSPYTEMPDATA'] + os.path.basename(__file__).split('.')[0] + str(sys._getframe().f_lineno)+'.dgn'
    srcDgnFile = createTempDgnFileWithSeed (fileSrc, loadDgnFile)

    snippetName = "CategoryTestSnippet"
    snippet1 = DgnTextSnippet.Create(snippetName, srcDgnFile)
    assert None != snippet1
    assert BentleyStatus.eSUCCESS == snippet1.Add()

    snippetName = "CategoryTestSnippet1"
    snippet2 = DgnTextSnippet.Create(snippetName, srcDgnFile)
    assert None != snippet2
    assert BentleyStatus.eSUCCESS == snippet2.Add()

    categoryName = "CategoryTestCategory"
    category = DgnTextSnippetCategory(categoryName, srcDgnFile)
    assert None != category
    assert BentleyStatus.eSUCCESS == category.Add()

    assert BentleyStatus.eSUCCESS == snippet1.SetCategory(category)
    assert BentleyStatus.eSUCCESS == snippet1.Replace()
    assert BentleyStatus.eSUCCESS == snippet2.SetCategory(category)
    assert BentleyStatus.eSUCCESS == snippet2.Replace()

    snippets = DgnTextSnippetPtrArray()
    assert BentleyStatus.eSUCCESS == DgnTextSnippetCategory.GetTextFavorites(snippets, category, srcDgnFile)
    assert 2 == len(snippets)

@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_GetParentCategoryTest(initDgnPlatformHost, loadDgnFile, createTempDgnFileWithSeed):
    fileSrc = os.environ['MSPYTEMPDATA'] + os.path.basename(__file__).split('.')[0] + str(sys._getframe().f_lineno)+'.dgn'
    srcDgnFile = createTempDgnFileWithSeed (fileSrc, loadDgnFile)

    rootCategoryName = "RootCategory"
    rootCategory = DgnTextSnippetCategory(rootCategoryName, srcDgnFile)
    assert None != rootCategory
    assert BentleyStatus.eSUCCESS == rootCategory.Add()

    subCategoryName = "SubCategory"
    subCategory = DgnTextSnippetCategory(subCategoryName, srcDgnFile)
    assert None != subCategory
    assert BentleyStatus.eSUCCESS == subCategory.Add()
    assert BentleyStatus.eSUCCESS == rootCategory.AddSubCategory(subCategory)
    assert 1 == len(rootCategory.GetSubCategories())

    parentCategory = subCategory.GetParentCategory()
    assert None != parentCategory
    parentCategoryName = parentCategory.GetName()
    assert BentleyStatus.eSUCCESS == parentCategoryName.CompareTo ((WString)("RootCategory"))
