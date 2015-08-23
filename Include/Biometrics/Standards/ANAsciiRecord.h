#ifndef AN_ASCII_RECORD_H_INCLUDED
#define AN_ASCII_RECORD_H_INCLUDED

#include <Biometrics/Standards/ANRecord.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(ANAsciiRecord, ANRecord)

#define AN_ASCII_RECORD_MAX_FIELD_NUMBER 999999999

#ifdef N_CPP
}
#endif

#endif // !AN_ASCII_RECORD_H_INCLUDED
