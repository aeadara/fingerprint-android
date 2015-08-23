#ifndef N_COM_ERROR_H_INCLUDED
#define N_COM_ERROR_H_INCLUDED

#include <Core/NError.h>
#include <Interop/NWindows.h>
#ifndef N_WINDOWS
typedef NInt HRESULT;
#endif

#ifdef N_CPP
extern "C"
{
#endif

#define COM_TRY \
	HRESULT COM_THE_ERROR = S_OK;\
	NBool COM_FINALLY_entered = NFalse;

#define COM_RESULT(value) \
	{\
		COM_THE_ERROR = value;\
		goto COM_TRY_End;\
	}

#define COM_RETURN COM_RESULT(S_OK)

HRESULT N_API ComErrorSetLastN(HRESULT code, HNString hMessage);

HRESULT N_API ComErrorSetLastA(HRESULT code, const NAChar * szMessage);
#ifndef N_NO_UNICODE
HRESULT N_API ComErrorSetLastW(HRESULT code, const NWChar * szMessage);
#endif
#ifdef N_DOCUMENTATION
HRESULT N_API ComErrorSetLast(HRESULT code, const NChar * szMessage);
#endif
#define ComErrorSetLast N_FUNC_AW(ComErrorSetLast)

HRESULT N_API ComErrorSetN(NResult code);

#define COM_ERROR_MN_(code, hMessage) \
	{\
		COM_THE_ERROR = ComErrorSetLastN(code, hMessage);\
		goto COM_TRY_End;\
	}
#define COM_ERROR_MN(code, hMessage) COM_ERROR_MN_(code, hMessage)
#define COM_ERROR(code) COM_ERROR_MN_(code, NULL)

#define COM_ERROR_M_A(code, szMessage) \
	{\
		COM_THE_ERROR = ComErrorSetLastA(code, szMessage);\
		goto COM_TRY_End;\
	}
#define COM_ERROR_MA(code, szMessage) COM_ERROR_M_A(code, szMessage)

#ifndef N_NO_UNICODE
#define COM_ERROR_M_W(code, szMessage) \
	{\
		COM_THE_ERROR = ComErrorSetLastW(code, szMessage);\
		goto COM_TRY_End;\
	}
#define COM_ERROR_MW(code, szMessage) COM_ERROR_M_W(code, szMessage)
#endif

#define COM_ERROR_M N_MACRO_AW(COM_ERROR_M)

#define COM_RAISE(result) \
	{\
		COM_RESULT(result);\
	}\

#define COM_CHECK(result) \
	{\
		HRESULT COM_CHECK_result = (result);\
		if (N_UNLIKELY(FAILED(COM_CHECK_result))) COM_RAISE(COM_CHECK_result);\
	}

#define COM_CHECK_N(result) \
	{\
		NResult COM_CHECK_N_result = (result);\
		if (N_UNLIKELY(NFailed(COM_CHECK_N_result)))\
		{\
			COM_RAISE(ComErrorSetN(COM_CHECK_N_result));\
		}\
	}

#define COM_TRY_END_RAW } }

#define COM_FINALLY \
	N_UNREFERENCED_PARAMETER(COM_THE_ERROR);\
	COM_TRY_End: if (!COM_FINALLY_entered) { COM_FINALLY_entered = NTrue; {

#define COM_THE_ERROR COM_TRY_result
#define COM_WAS_ERROR FAILED(COM_THE_ERROR)

#define COM_TRY_END \
	COM_TRY_END_RAW\
	return COM_THE_ERROR;

#define COM_TRY_E \
	COM_FINALLY\
	COM_TRY_END

#ifdef N_CPP
}
#endif

#endif // N_COM_ERROR_H_INCLUDED
