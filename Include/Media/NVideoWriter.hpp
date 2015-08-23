#ifndef N_VIDEO_WRITER_HPP_INCLUDED
#define N_VIDEO_WRITER_HPP_INCLUDED

#include <Images/NImages.hpp>
#include <Media/NVideoWriterOptions.hpp>
namespace Neurotec { namespace Video
{
using ::Neurotec::Images::HNImage;
#include <Media/NVideoWriter.h>
}}

namespace Neurotec { namespace Video
{

class NVideoWriter : public NObject
{
	N_DECLARE_OBJECT_CLASS(NVideoWriter, NObject)

private:
	static HNVideoWriter Create(const NStringWrapper & fileName, NInt width, NInt height, NDouble frameRate, const NVideoWriterOptions & options)
	{
		HNVideoWriter handle;
		NCheck(NVideoWriterCreateFileN(fileName.GetHandle(), width, height, frameRate, options.GetHandle(), &handle));
		return handle;
	}

public:
	NVideoWriter(const NStringWrapper & fileName, NInt width, NInt height, NDouble frameRate, const NVideoWriterOptions & options)
		: NObject(Create(fileName, width, height, frameRate, options), true)
	{
	}

	void WriteFrame(const ::Neurotec::Images::NImage & frame)
	{
		NCheck(NVideoWriterWriteFrame(GetHandle(), frame.GetHandle()));
	}
};

}}

#endif // !N_VIDEO_WRITER_HPP_INCLUDED
