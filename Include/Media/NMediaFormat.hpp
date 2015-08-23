#ifndef N_MEDIA_FORMAT_HPP_INCLUDED
#define N_MEDIA_FORMAT_HPP_INCLUDED

#include <Media/NMediaTypes.hpp>
#include <Core/NExpandableObject.hpp>
namespace Neurotec { namespace Media
{
#include <Media/NMediaFormat.h>
}}

namespace Neurotec { namespace Media
{

class NMediaFormat : public NExpandableObject
{
	N_DECLARE_OBJECT_CLASS(NMediaFormat, NExpandableObject)

public:
	NMediaType GetMediaType() const
	{
		NMediaType value;
		NCheck(NMediaFormatGetMediaType(GetHandle(), &value));
		return value;
	}

	NUInt GetMediaSubtype() const
	{
		NUInt value;
		NCheck(NMediaFormatGetMediaSubtype(GetHandle(), &value));
		return value;
	}

	void SetMediaSubtype(NUInt value)
	{
		NCheck(NMediaFormatSetMediaSubtype(GetHandle(), value));
	}

	bool IsCompatibleWith(const NMediaFormat & otherFormat) const
	{
		NBool result;
		NCheck(NMediaFormatIsCompatibleWith(GetHandle(), otherFormat.GetHandle(), &result));
		return result != 0;
	}
};

}}

#endif // !N_MEDIA_FORMAT_HPP_INCLUDED
