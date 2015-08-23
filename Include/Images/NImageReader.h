#ifndef N_IMAGE_READER_H_INCLUDED
#define N_IMAGE_READER_H_INCLUDED

#include <Core/NObject.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(NImageReader, NObject)

#ifdef N_CPP
}
#endif

#include <Images/NImage.h>
#include <Images/NImageInfo.h>
#include <Images/NImageFormat.h>

#ifdef N_CPP
extern "C"
{
#endif

NResult N_API NImageReaderRead(HNImageReader hReader, NUInt flags, HNImageInfo * phInfo, HNImage * phImage);
NResult N_API NImageReaderReadInfo(HNImageReader hReader, NUInt flags, HNImageInfo * phInfo);
NResult N_API NImageReaderGetReadSize(HNImageReader hReader, NSizeType * pSize);

N_DEPRECATED("function is deprecated, use NImageReaderGetFormatEx instead")
NResult N_API NImageReaderGetFormat(HNImageReader hReader, HNImageFormat * phValue);
NResult N_API NImageReaderGetFormatEx(HNImageReader hReader, HNImageFormat * phValue);

#ifdef N_CPP
}
#endif

#endif // !N_IMAGE_READER_H_INCLUDED
