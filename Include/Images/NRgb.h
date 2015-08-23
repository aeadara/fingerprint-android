#ifndef N_RGB_H_INCLUDED
#define N_RGB_H_INCLUDED

#include <Core/NTypes.h>

#ifdef N_CPP
extern "C"
{
#endif

struct NRgb_
{
	NByte Red;
	NByte Green;
	NByte Blue;
};
#ifndef N_RGB_HPP_INCLUDED
typedef struct NRgb_ NRgb;
#endif

N_DECLARE_TYPE(NRgb)

NResult N_API NRgbToStringN(const struct NRgb_ * pValue, HNString hFormat, HNString * phValue);
NResult N_API NRgbToStringA(const struct NRgb_ * pValue, const NAChar * szFormat, HNString * phValue);
#ifndef N_NO_UNICODE
NResult N_API NRgbToStringW(const struct NRgb_ * pValue, const NWChar * szFormat, HNString * phValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NRgbToString(const NRgb * pValue, const NChar * szFormat, HNString * phValue);
#endif
#define NRgbToString N_FUNC_AW(NRgbToString)

#ifdef N_CPP
}
#endif

#endif // !N_RGB_H_INCLUDED
