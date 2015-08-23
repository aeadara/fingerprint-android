#ifndef N_IMAGE_WRITER_H_INCLUDED
#define N_IMAGE_WRITER_H_INCLUDED

#include <Core/NObject.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(NImageWriter, NObject)

#ifdef N_CPP
}
#endif

#include <IO/NBuffer.h>
#include <Images/NImage.h>
#include <Images/NImageInfo.h>
#include <Images/NImageFormat.h>

#ifdef N_CPP
extern "C"
{
#endif

NResult N_API NImageWriterWrite(HNImageWriter hWriter, HNImage hImage, HNImageInfo hInfo, NUInt flags);
NResult N_API NImageWriterGetBuffer(HNImageWriter hWriter, HNBuffer * phValue);

N_DEPRECATED("function is deprecated, use NImageWriterGetFormatEx instead")
NResult N_API NImageWriterGetFormat(HNImageWriter hWriter, HNImageFormat * phValue);
NResult N_API NImageWriterGetFormatEx(HNImageWriter hWriter, HNImageFormat * phValue);

#ifdef N_CPP
}
#endif

#endif // !N_IMAGE_WRITER_H_INCLUDED
