#ifndef N_STRING_WRITER_H_INCLUDED
#define N_STRING_WRITER_H_INCLUDED

#include <IO/NTextWriter.h>
#include <Text/NStringBuilder.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(NStringWriter, NTextWriter)

NResult N_API NStringWriterCreate(HNStringWriter * phWriter);
NResult N_API NStringWriterCreateWithCapacity(NInt capacity, HNStringWriter * phWriter);
NResult N_API NStringWriterCreateEx(NInt capacity, NInt maxCapacity, NInt growthDelta, HNStringWriter * phWriter);

NResult N_API NStringWriterDetachString(HNStringWriter hWriter, HNString * phValue);

#ifdef N_CPP
}
#endif

#endif // !N_STRING_WRITER_H_INCLUDED
