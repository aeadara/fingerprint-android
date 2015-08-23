#ifndef N_IMAGE_WRITER_HPP_INCLUDED
#define N_IMAGE_WRITER_HPP_INCLUDED

#include <Core/NExpandableObject.hpp>
namespace Neurotec { namespace Images
{
using ::Neurotec::IO::HNStream;
using ::Neurotec::IO::NFileAccess;
using ::Neurotec::IO::HNBuffer;
#include <Images/NImageWriter.h>
}}

namespace Neurotec { namespace Images
{

class NImage;
class NImageInfo;
class NImageFormat;

class NImageWriter : public NObject
{
	N_DECLARE_OBJECT_CLASS(NImageWriter, NObject)

public:
	void Write(const NImage & image, const NImageInfo & info = NULL, NUInt flags = 0);

	::Neurotec::IO::NBuffer GetBuffer()
	{
		HNBuffer hValue;
		NCheck(NImageWriterGetBuffer(GetHandle(), &hValue));
		return FromHandle< ::Neurotec::IO::NBuffer>(hValue);
	}

	NImageFormat GetFormat() const;
};

}}

#include <Images/NImage.hpp>
#include <Images/NImageInfo.hpp>
#include <Images/NImageFormat.hpp>

namespace Neurotec { namespace Images
{

inline NImageFormat NImageWriter::GetFormat() const
{
	return GetObject<HandleType, NImageFormat>(NImageWriterGetFormatEx, true);
}

inline void NImageWriter::Write(const NImage & image, const NImageInfo & info, NUInt flags)
{
	NCheck(NImageWriterWrite(GetHandle(), image.GetHandle(), info.GetHandle(), flags));
}

}}

#endif // !N_IMAGE_WRITER_HPP_INCLUDED
