#ifndef N_SMART_CARDS_COMMANDS_H_INCLUDED
#define N_SMART_CARDS_COMMANDS_H_INCLUDED

#include <SmartCards/ApduClass.h>
#include <SmartCards/ApduInstruction.h>
#include <SmartCards/ApduStatus.h>
#include <IO/NBuffer.h>
#ifdef N_MSVC
	#pragma warning(push)
	#pragma warning(disable: 4201)
	#ifdef N_WINDOWS_CE
		#pragma warning(disable: 4214 4115)
	#endif
#endif
#if defined(N_APPLE)
#include <PCSC/wintypes.h>
#include <PCSC/winscard.h>
#else
#include <winscard.h>
#endif
#ifdef N_MSVC
	#pragma warning(pop)
#endif

#ifdef N_CPP
extern "C"
{
#endif

NResult N_API SCardGetT0Pci(const SCARD_IO_REQUEST * * ppValue);
NResult N_API SCardGetT1Pci(const SCARD_IO_REQUEST * * ppValue);
NResult N_API SCardGetRawPci(const SCARD_IO_REQUEST * * ppValue);

NResult N_API SCardTransmitN(SCARDHANDLE hCard, LPCSCARD_IO_REQUEST pioSendPci, HNBuffer hSendBuffer,
	LPSCARD_IO_REQUEST pioRecvPci, HNBuffer hRecvBuffer, NSizeType * pRecvLength);

NResult N_API SCardTransmitApduN(SCARDHANDLE hCard, ApduClass_ cls, ApduInstruction_ instruction, NByte p1, NByte p2, NBool isExtended,
	HNBuffer hData, HNBuffer hResponseData, NSizeType * pNr, ApduStatus_ * pStatus);
NResult N_API SCardTransmitApdu(SCARDHANDLE hCard, ApduClass_ cls, ApduInstruction_ instruction, NByte p1, NByte p2, NBool isExtended,
	const void * pData, NSizeType nc, void * pResponseData, NSizeType ne, NSizeType * pNr, ApduStatus_ * pStatus);

NResult N_API SCardControlN(SCARDHANDLE hCard, DWORD dwControlCode, HNBuffer hInBuffer, HNBuffer hOutBuffer, NSizeType * pBytesReturned);
NResult N_API SCardControlDWordN(SCARDHANDLE hCard, DWORD dwControlCode, DWORD in, HNBuffer hOutBuffer, NSizeType * pBytesReturned);
NResult N_API SCardControlDWord(SCARDHANDLE hCard, DWORD dwControlCode, DWORD in, BYTE * pOutBuffer, DWORD outBufferSize, DWORD * pBytesReturned);
NResult N_API SCardControlAsDWordN(SCARDHANDLE hCard, DWORD dwControlCode, HNBuffer hInBuffer, DWORD * pOut);
NResult N_API SCardControlAsDWord(SCARDHANDLE hCard, DWORD dwControlCode, const BYTE * pInBuffer, DWORD inBufferSize, DWORD * pOut);
NResult N_API SCardControlDWordAsDWord(SCARDHANDLE hCard, DWORD dwControlCode, DWORD in, DWORD * pOut);

NResult N_API SCardGetAttribN(SCARDHANDLE hCard, DWORD dwAttrId, HNBuffer hAttr, NSizeType * pReturnedLength);
NResult N_API SCardGetAttribAsBufferN(SCARDHANDLE hCard, DWORD dwAttrId, HNBuffer * phAttr);

NResult N_API SCardGetAttribAsStringN(SCARDHANDLE hCard, DWORD dwAttrId, HNString * phAttr);
#ifndef N_NO_ANSI_FUNC
NResult N_API SCardGetAttribAsStringA(SCARDHANDLE hCard, DWORD dwAttrId, NAChar * szAttr, NInt * pLength);
#endif
#ifndef N_NO_UNICODE
NResult N_API SCardGetAttribAsStringW(SCARDHANDLE hCard, DWORD dwAttrId, NWChar * szAttr, NInt * pLength);
#endif
#ifdef N_DOCUMENTATION
NResult N_API SCardGetAttribAsString(SCARDHANDLE hCard, DWORD dwAttrId, NChar * szAttr, NInt * pLength);
#endif
#define SCardGetAttribAsString N_FUNC_AW(SCardGetAttribAsString)

NResult N_API SCardGetAttribAsByte(SCARDHANDLE hCard, DWORD dwAttrId, BYTE * pAttr);
NResult N_API SCardGetAttribAsDWord(SCARDHANDLE hCard, DWORD dwAttrId, DWORD * pAttr);

NResult N_API SCardSetAttribN(SCARDHANDLE hCard, DWORD dwAttrId, HNBuffer hAttr);

NResult N_API SCardSetAttribAsStringN(SCARDHANDLE hCard, DWORD dwAttrId, HNString hAttr);
#ifndef N_NO_ANSI_FUNC
NResult N_API SCardSetAttribAsStringA(SCARDHANDLE hCard, DWORD dwAttrId, const NAChar * szAttr, NInt attrLength);
#endif
#ifndef N_NO_UNICODE
NResult N_API SCardSetAttribAsStringW(SCARDHANDLE hCard, DWORD dwAttrId, const NWChar * szAttr, NInt attrLength);
#endif
#ifdef N_DOCUMENTATION
NResult N_API SCardSetAttribAsString(SCARDHANDLE hCard, DWORD dwAttrId, const NChar * szAttr, NInt attrLength);
#endif
#define SCardSetAttribAsString N_FUNC_AW(SCardSetAttribAsString)

NResult N_API SCardSetAttribAsByte(SCARDHANDLE hCard, DWORD dwAttrId, BYTE attr);
NResult N_API SCardSetAttribAsDWord(SCARDHANDLE hCard, DWORD dwAttrId, DWORD attr);

N_DECLARE_STATIC_OBJECT_TYPE(NSmartCardsCommands)

#ifdef N_CPP
}
#endif

#endif // !N_SMART_CARDS_COMMANDS_H_INCLUDED
