#ifndef NE_EXTRACTOR_PARAMS_H_INCLUDED
#define NE_EXTRACTOR_PARAMS_H_INCLUDED

#include <Core/NParameters.h>

#ifdef N_CPP
extern "C"
{
#endif

#define NEEP_DEINTERLACE         10001
#define NEEP_INNER_BOUNDARY_FROM 10002
#define NEEP_INNER_BOUNDARY_TO   10003
#define NEEP_OUTER_BOUNDARY_FROM 10004
#define NEEP_OUTER_BOUNDARY_TO   10005

#define NEEP_USE_FLEXIBLE_BOUNDARY_MODEL 10006

#define NEEP_TEMPLATE_SIZE       10160

typedef enum NeeTemplateSize_
{
	neetsCompact = 0,
	neetsNormal = 128,
} NeeTemplateSize;

N_DECLARE_TYPE(NeeTemplateSize)

#ifdef N_CPP
}
#endif

#endif // !NE_EXTRACTOR_PARAMS_H_INCLUDED
