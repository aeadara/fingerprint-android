#ifndef _BIOAPI_H_INCLUDED
#define _BIOAPI_H_INCLUDED

#include "bioapi_type.h"
#include "bioapi_err.h"

// The following ifdef block allows to build either DLL (BioAPI Framework) that 
// exports the API functions or an application that imports them. 
// The application should not have the BIOAPI_EXPORTS defined
#ifdef BIOAPI_EXPORTS
#define DLLAPI DllExport
#else
#define DLLAPI DllImport
#endif

#include "bioapi_api.h"

#define BioAPI_MAJOR    2
#define BioAPI_MINOR    0

#endif  /* _BIOAPI_H_INCLUDED */
