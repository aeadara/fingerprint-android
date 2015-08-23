#ifndef PNG_HPP_INCLUDED
#define PNG_HPP_INCLUDED

#include <Images/NImage.hpp>
namespace Neurotec { namespace Images
{
#include <Images/Png.h>
}}

namespace Neurotec { namespace Images
{

#undef PNG_DEFAULT_COMPRESSION_LEVEL

const NInt PNG_DEFAULT_COMPRESSION_LEVEL = 6;

class PngInfo : public NImageInfo
{
	N_DECLARE_OBJECT_CLASS(PngInfo, NImageInfo)

public:
	NInt GetCompressionLevel() const
	{
		NInt value;
		NCheck(PngInfoGetCompressionLevel(GetHandle(), &value));
		return value;
	}

	void SetCompressionLevel(NInt value)
	{
		NCheck(PngInfoSetCompressionLevel(GetHandle(), value));
	}
};

}}

#endif // !PNG_HPP_INCLUDED
