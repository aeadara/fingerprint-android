#ifndef N_IMAGE_FORMAT_HPP_INCLUDED
#define N_IMAGE_FORMAT_HPP_INCLUDED

#include <Core/NExpandableObject.hpp>
namespace Neurotec { namespace Images
{
using ::Neurotec::IO::NFileAccess;
#include <Images/NImageFormat.h>
}}

namespace Neurotec { namespace Images
{

class NImage;
class NImageInfo;
class NImageReader;
class NImageWriter;
class NImageFile;

#include <Core/NNoDeprecate.h>
class NImageFormat : public NObject
{
	N_DECLARE_OBJECT_CLASS(NImageFormat, NObject)

public:
	class ImageFormatCollection;

public:
	static NImageFormat GetTiff()
	{
		return GetObject<NImageFormat>(NImageFormatGetTiffEx, true);
	}

	static NImageFormat GetJpeg()
	{
		return GetObject<NImageFormat>(NImageFormatGetJpegEx, true);
	}

	static NImageFormat GetPng()
	{
		return GetObject<NImageFormat>(NImageFormatGetPngEx, true);
	}

	static NImageFormat GetWsq()
	{
		return GetObject<NImageFormat>(NImageFormatGetWsqEx, true);
	}

	static NImageFormat GetJpeg2K()
	{
		return GetObject<NImageFormat>(NImageFormatGetJpeg2KEx, true);
	}

	static NImageFormat GetBmp()
	{
		return GetObject<NImageFormat>(NImageFormatGetBmpEx, true);
	}

	static NImageFormat GetIHead()
	{
		return GetObject<NImageFormat>(NImageFormatGetIHeadEx, true);
	}

	static const ImageFormatCollection GetFormats();

	static NImageFormat Select(const NStringWrapper & fileName, NFileAccess fileAccess)
	{
		HNImageFormat handle;
		NCheck(NImageFormatSelectExN(fileName.GetHandle(), fileAccess, &handle));
		return FromHandle<NImageFormat>(handle, true);
	}

	static NImageFormat SelectByInternetMediaType(const NStringWrapper & internetMediaType, NFileAccess fileAccess)
	{
		HNImageFormat handle;
		NCheck(NImageFormatSelectByInternetMediaTypeN(internetMediaType.GetHandle(), fileAccess, &handle));
		return FromHandle<NImageFormat>(handle, true);
	}

	static NImageReader SelectReader(const NStringWrapper & fileName, NUInt flags = 0);
	static NImageReader SelectReader(const ::Neurotec::IO::NBuffer & buffer, NUInt flags = 0);
	static NImageReader SelectReader(const void * pBuffer, NSizeType bufferSize, NUInt flags = 0);
	static NImageReader SelectReader(const ::Neurotec::IO::NStream & stream, NUInt flags = 0);
	NImageReader OpenReader(const NStringWrapper & fileName, NUInt flags = 0) const;
	NImageReader OpenReader(const ::Neurotec::IO::NBuffer & buffer, NUInt flags = 0) const;
	NImageReader OpenReader(const void * pBuffer, NSizeType bufferSize, NUInt flags = 0) const;
	NImageReader OpenReader(const ::Neurotec::IO::NStream & stream, NUInt flags = 0) const;
	NImageInfo CreateInfo(const NImage & image, NUInt flags = 0) const;
	NImageWriter OpenWriter(const NStringWrapper & fileName, NUInt flags = 0) const;
	NImageWriter OpenWriter(NUInt flags = 0) const;
	NImageWriter OpenWriter(const ::Neurotec::IO::NStream & stream, NUInt flags = 0) const;

	NString GetName() const
	{
		return GetString(NImageFormatGetNameN);
	}

	NString GetDefaultFileExtension() const
	{
		return GetString(NImageFormatGetDefaultFileExtensionN);
	}

	NString GetDefaultInternetMediaType() const
	{
		return GetString(NImageFormatGetDefaultInternetMediaTypeN);
	}

	NString GetFileFilter() const
	{
		return GetString(NImageFormatGetFileFilterN);
	}

	NString GetInternetMediaType() const
	{
		return GetString(NImageFormatGetInternetMediaTypeN);
	}

	bool CanRead() const
	{
		NBool value;
		NCheck(NImageFormatCanRead(GetHandle(), &value));
		return value != 0;
	}

	bool CanWrite() const
	{
		NBool value;
		NCheck(NImageFormatCanWrite(GetHandle(), &value));
		return value != 0;
	}

	bool CanWriteMultiple() const
	{
		NBool value;
		NCheck(NImageFormatCanWriteMultiple(GetHandle(), &value));
		return value != 0;
	}
};
#include <Core/NReDeprecate.h>

class NImageFormat::ImageFormatCollection : public ::Neurotec::Collections::NStaticCollectionBase<NImageFormat,
	NImageFormatGetFormatCount, NImageFormatGetFormatEx>
{
	ImageFormatCollection()
	{
	}

	friend class NImageFormat;
};

}}

#include <Images/NImage.hpp>
#include <Images/NImageInfo.hpp>
#include <Images/NImageReader.hpp>
#include <Images/NImageWriter.hpp>

namespace Neurotec { namespace Images
{

inline const NImageFormat::ImageFormatCollection NImageFormat::GetFormats()
{
	return NImageFormat::ImageFormatCollection();
}

inline NImageReader NImageFormat::SelectReader(const NStringWrapper & fileName, NUInt flags)
{
	HNImageReader hReader;
	NCheck(NImageFormatSelectReaderFromFileN(fileName.GetHandle(), flags, &hReader));
	return FromHandle<NImageReader>(hReader);
}

inline NImageReader NImageFormat::SelectReader(const ::Neurotec::IO::NBuffer & buffer, NUInt flags)
{
	HNImageReader hReader;
	NCheck(NImageFormatSelectReaderFromMemoryN(buffer.GetHandle(), flags, &hReader));
	return FromHandle<NImageReader>(hReader);
}

inline NImageReader NImageFormat::SelectReader(const void * pBuffer, NSizeType bufferSize, NUInt flags)
{
	HNImageReader hReader;
	NCheck(NImageFormatSelectReaderFromMemory(pBuffer, bufferSize, flags, &hReader));
	return FromHandle<NImageReader>(hReader);
}

inline NImageReader NImageFormat::SelectReader(const ::Neurotec::IO::NStream & stream, NUInt flags)
{
	HNImageReader hReader;
	NCheck(NImageFormatSelectReaderFromStream(stream.GetHandle(), flags, &hReader));
	return FromHandle<NImageReader>(hReader);
}

inline NImageReader NImageFormat::OpenReader(const NStringWrapper & fileName, NUInt flags) const
{
	HNImageReader hReader;
	NCheck(NImageFormatOpenReaderFromFileN(GetHandle(), fileName.GetHandle(), flags, &hReader));
	return FromHandle<NImageReader>(hReader);
}

inline NImageReader NImageFormat::OpenReader(const ::Neurotec::IO::NBuffer & buffer, NUInt flags) const
{
	HNImageReader hReader;
	NCheck(NImageFormatOpenReaderFromMemoryN(GetHandle(), buffer.GetHandle(), flags, &hReader));
	return FromHandle<NImageReader>(hReader);
}

inline NImageReader NImageFormat::OpenReader(const void * pBuffer, NSizeType bufferSize, NUInt flags) const
{
	HNImageReader hReader;
	NCheck(NImageFormatOpenReaderFromMemory(GetHandle(), pBuffer, bufferSize, flags, &hReader));
	return FromHandle<NImageReader>(hReader);
}

inline NImageReader NImageFormat::OpenReader(const ::Neurotec::IO::NStream & stream, NUInt flags) const
{
	HNImageReader hReader;
	NCheck(NImageFormatOpenReaderFromStream(GetHandle(), stream.GetHandle(), flags, &hReader));
	return FromHandle<NImageReader>(hReader);
}

inline NImageInfo NImageFormat::CreateInfo(const NImage & image, NUInt flags) const
{
	HNImageInfo hInfo;
	NCheck(NImageFormatCreateInfo(GetHandle(), image.GetHandle(), flags, &hInfo));
	return FromHandle<NImageInfo>(hInfo);
}

inline NImageWriter NImageFormat::OpenWriter(const NStringWrapper & fileName, NUInt flags) const
{
	HNImageWriter hWriter;
	NCheck(NImageFormatOpenWriterToFileN(GetHandle(), fileName.GetHandle(), flags, &hWriter));
	return FromHandle<NImageWriter>(hWriter);
}

inline NImageWriter NImageFormat::OpenWriter(NUInt flags) const
{
	HNImageWriter hWriter;
	NCheck(NImageFormatOpenWriterToMemory(GetHandle(), flags, &hWriter));
	return FromHandle<NImageWriter>(hWriter);
}

inline NImageWriter NImageFormat::OpenWriter(const ::Neurotec::IO::NStream & stream, NUInt flags) const
{
	HNImageWriter hWriter;
	NCheck(NImageFormatOpenWriterToStream(GetHandle(), stream.GetHandle(), flags, &hWriter));
	return FromHandle<NImageWriter>(hWriter);
}

}}

#endif // !N_IMAGE_FORMAT_HPP_INCLUDED
