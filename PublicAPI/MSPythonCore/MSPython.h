/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\PublicAPI\MSPython.h $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#pragma once

//__PUBLISH_SECTION_START__
#if !defined (MSPYTHONDLL_EXPORT)
//__PUBLISH_SECTION_END__
#ifdef __MSPYTHONDLL_BUILD__
#define MSPYTHONDLL_EXPORT EXPORT_ATTRIBUTE
#else
//__PUBLISH_SECTION_START__
#define MSPYTHONDLL_EXPORT IMPORT_ATTRIBUTE
#endif
//__PUBLISH_SECTION_END__
#endif

