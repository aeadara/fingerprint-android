#ifndef NF_RECORD_V1_H_INCLUDED
#define NF_RECORD_V1_H_INCLUDED

#include <Biometrics/NFRecord.h>

#ifdef N_CPP
extern "C"
{
#endif

#define NFRecordGetMaxSizeV1(minutiaFormat, minutiaCount, coreCount, deltaCount, doubleCoreCount, boWidth, boHeight, pSize) \
	NFRecordGetMaxSize(1, NFalse, minutiaFormat, minutiaCount, nfrctNone, coreCount, deltaCount, doubleCoreCount, boWidth, boHeight, pSize)

#define NFRecordGetSizeV1(hRecord, flags, pValue) NObjectGetSize(hRecord, NFR_SAVE_V1 | (flags), pValue)
#define NFRecordSaveToMemoryV1(hRecord, pBuffer, bufferSize, flags, pSize) NObjectSaveToMemoryDst(hRecord, pBuffer, bufferSize, NFR_SAVE_V1 | (flags), pSize)

#ifdef N_CPP
}
#endif

#endif // !NF_RECORD_V1_H_INCLUDED
