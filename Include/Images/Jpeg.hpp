#ifndef JPEG_HPP_INCLUDED
#define JPEG_HPP_INCLUDED

#include <Images/NImage.hpp>
namespace Neurotec { namespace Images
{
#include <Images/Jpeg.h>
}}

namespace Neurotec { namespace Images
{

#undef JPEG_DEFAULT_QUALITY

const NInt JPEG_DEFAULT_QUALITY = 75;

class JpegInfo : public NImageInfo
{
	N_DECLARE_OBJECT_CLASS(JpegInfo, NImageInfo)

public:
	NInt GetQuality() const
	{
		NInt value;
		NCheck(JpegInfoGetQuality(GetHandle(), &value));
		return value;
	}

	void SetQuality(NInt value)
	{
		NCheck(JpegInfoSetQuality(GetHandle(), value));
	}

	bool IsLossless() const
	{
		NBool value;
		NCheck(JpegInfoIsLossless(GetHandle(), &value));
		return value != 0;
	}

	void SetLossless(bool value)
	{
		NCheck(JpegInfoSetLossless(GetHandle(), value ? NTrue : NFalse));
	}
};

}}

#endif // !JPEG_HPP_INCLUDED
