#ifndef FIR_FINGER_H_INCLUDED
#define FIR_FINGER_H_INCLUDED

#include <Biometrics/Standards/BdifTypes.h>
#include <Images/NImage.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(FirFinger, NObject)

#ifdef N_CPP
}
#endif

#include <Biometrics/Standards/FIRecord.h>
#include <Biometrics/Standards/FirFingerView.h>

#ifdef N_CPP
extern "C"
{
#endif

#define FIRF_MAX_FINGER_VIEW_COUNT 255

N_DEPRECATED("function is deprecated")
NResult N_API FirFingerCalculateSize(BdifStandard standard, NInt fingerViewCount, const NSizeType * arFingerViewSizes, NSizeType * pSize);

#define FIRF_PROCESS_FIRST_FINGER_VIEW_ONLY 0x00001000
N_DEPRECATED("function is deprecated")
NResult N_API FirFingerGetFingerViewCount(HFirFinger hFinger, NInt * pValue);
N_DEPRECATED("function is deprecated")
NResult N_API FirFingerGetFingerViewEx(HFirFinger hFinger, NInt index, HFirFingerView * phValue);
N_DEPRECATED("function is deprecated")
NResult N_API FirFingerGetFingerViewCapacity(HFirFinger hFinger, NInt * pValue);
N_DEPRECATED("function is deprecated")
NResult N_API FirFingerSetFingerViewCapacity(HFirFinger hFinger, NInt value);
N_DEPRECATED("function is deprecated")
NResult N_API FirFingerAddFingerViewN(HFirFinger hFinger, NUShort horzLineLength, NUShort vertLineLength, HNBuffer hImageData,
	NUInt flags, HFirFingerView * phFingerView);
N_DEPRECATED("function is deprecated")
NResult N_API FirFingerAddFingerView(HFirFinger hFinger, NUShort horzLineLength, NUShort vertLineLength, const void * pImageData, NSizeType imageDataLength,
	NUInt flags, HFirFingerView * phFingerView);
N_DEPRECATED("function is deprecated")
NResult N_API FirFingerAddFingerViewFromNImage(HFirFinger hFinger, HNImage hImage, NUInt flags, HFirFingerView * phFingerView);
N_DEPRECATED("function is deprecated")
NResult N_API FirFingerRemoveFingerView(HFirFinger hFinger, NInt index);
N_DEPRECATED("function is deprecated")
NResult N_API FirFingerClearFingerViews(HFirFinger hFinger);
N_DEPRECATED("function is deprecated")
NResult N_API FirFingerGetPosition(HFirFinger hFinger, BdifFPPosition * pValue);
N_DEPRECATED("function is deprecated")
NResult N_API FirFingerSetPosition(HFirFinger hFinger, BdifFPPosition value);

#ifdef N_CPP
}
#endif

#endif // !FIR_FINGER_H_INCLUDED
