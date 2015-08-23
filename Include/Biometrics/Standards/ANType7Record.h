#ifndef AN_TYPE_7_RECORD_H_INCLUDED
#define AN_TYPE_7_RECORD_H_INCLUDED

#include <Biometrics/Standards/ANBinaryRecord.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(ANType7Record, ANBinaryRecord)

#define AN_TYPE_7_RECORD_FIELD_LEN AN_RECORD_FIELD_LEN
#define AN_TYPE_7_RECORD_FIELD_IDC AN_RECORD_FIELD_IDC
#define AN_TYPE_7_RECORD_FIELD_UDF AN_RECORD_FIELD_DATA

#ifdef N_CPP
}
#endif

#endif // !AN_TYPE_7_RECORD_H_INCLUDED
