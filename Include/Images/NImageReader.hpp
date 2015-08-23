#ifndef N_IMAGE_READER_HPP_INCLUDED
#define N_IMAGE_READER_HPP_INCLUDED

#include <Core/NExpandableObject.hpp>
namespace Neurotec { namespace Images
{
using ::Neurotec::IO::HNStream;
using ::Neurotec::IO::NFileAccess;
using ::Neurotec::IO::HNBuffer;
#include <Images/NImageReader.h>
}}

namespace Neurotec { namespace Images
{

class NImage;
class NImageInfo;
class NImageFormat;

class NImageReader : public NObject
{
	N_DECLARE_OBJECT_CLASS(NImageReader, NObject)

public:
	NImage Read(NUInt flags = 0, NImageInfo * pInfo = NULL);
	NImageInfo ReadInfo(NUInt flags = 0);

	NImageFormat GetFormat() const;
};

}}

#include <Images/NImage.hpp>
#include <Images/NImageInfo.hpp>
#include <Images/NImageFormat.hpp>

namespace Neurotec { namespace Images
{

inline NImageFormat NImageReader::GetFormat() const
{
	return GetObject<HandleType, NImageFormat>(NImageReaderGetFormatEx, true);
}

inline NImage NImageReader::Read(NUInt flags, NImageInfo * pInfo)
{
	HNImage hImage;
	HNImageInfo hInfo = NULL;
	NCheck(NImageReaderRead(GetHandle(), flags, pInfo ? &hInfo : NULL, &hImage));
	if (pInfo) *pInfo = FromHandle<NImageInfo>(hInfo);
	return FromHandle<NImage>(hImage);
}

inline NImageInfo NImageReader::ReadInfo(NUInt flags)
{
	HNImageInfo hInfo;
	NCheck(NImageReaderReadInfo(GetHandle(), flags, &hInfo));
	return FromHandle<NImageInfo>(hInfo);
}

}}

#endif // !N_IMAGE_READER_HPP_INCLUDED
