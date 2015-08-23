#ifndef N_MEDIA_FORMAT_H_INCLUDED
#define N_MEDIA_FORMAT_H_INCLUDED

#include <Media/NMediaTypes.h>
#include <Core/NExpandableObject.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(NMediaFormat, NExpandableObject)

NResult N_API NMediaFormatGetMediaType(HNMediaFormat hFormat, NMediaType * pValue);
NResult N_API NMediaFormatGetMediaSubtype(HNMediaFormat hFormat, NUInt * pValue);
NResult N_API NMediaFormatSetMediaSubtype(HNMediaFormat hFormat, NUInt value);

NResult N_API NMediaFormatIsCompatibleWith(HNMediaFormat hFormat, HNMediaFormat hOtherFormat, NBool * pResult);

#ifdef N_CPP
}
#endif

#endif // !N_MEDIA_FORMAT_H_INCLUDED
