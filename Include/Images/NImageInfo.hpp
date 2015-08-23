#ifndef N_IMAGE_INFO_HPP_INCLUDED
#define N_IMAGE_INFO_HPP_INCLUDED

#include <Core/NExpandableObject.hpp>
namespace Neurotec { namespace Images
{
using ::Neurotec::IO::HNStream;
using ::Neurotec::IO::NFileAccess;
using ::Neurotec::IO::HNBuffer;
#include <Images/NImageInfo.h>
}}

N_DEFINE_ENUM_TYPE_TRAITS(Neurotec::Images, NImageRotateFlipType)

namespace Neurotec { namespace Images
{

class NImageFormat;

class NImageInfo : public NExpandableObject
{
	N_DECLARE_OBJECT_CLASS(NImageInfo, NExpandableObject)

private:
	static HNImageInfo Create()
	{
		HNImageInfo handle;
		NCheck(NImageInfoCreate(&handle));
		return handle;
	}

public:
	static NType NImageRotateFlipTypeNativeTypeOf()
	{
		return NObject::GetObject<NType>(N_TYPE_OF(NImageRotateFlipType), true);
	}

	static bool IsImageRotateFlipTypeValid(NImageRotateFlipType value)
	{
		return NImageRotateFlipTypeIsValid(value) != 0;
	}

	static bool IsImageRotateFlipTypeRotateTypeValid(NImageRotateFlipType value)
	{
		return NImageRotateFlipTypeRotateTypeIsValid(value) != 0;
	}

	static bool IsImageRotateFlipTypeFlipTypeValid(NImageRotateFlipType value)
	{
		return NImageRotateFlipTypeFlipTypeIsValid(value) != 0;
	}

	static NImageRotateFlipType GetImageRotateFlipTypeRotateType(NImageRotateFlipType value)
	{
		return NImageRotateFlipTypeGetRotateType(value);
	}

	static NImageRotateFlipType GetImageRotateFlipTypeFlipType(NImageRotateFlipType value)
	{
		return NImageRotateFlipTypeGetFlipType(value);
	}

	static NImageRotateFlipType MinimizeImageRotateFlipTypeRotation(NImageRotateFlipType value)
	{
		return NImageRotateFlipTypeMinimizeRotation(value);
	}

	static NImageRotateFlipType MinimizeImageRotateFlipTypeFlip(NImageRotateFlipType value)
	{
		return NImageRotateFlipTypeMinimizeFlip(value);
	}

	static NImageRotateFlipType CreateImageRotateFlipType(NImageRotateFlipType rotate, NImageRotateFlipType flip)
	{
		NImageRotateFlipType value;
		NCheck(NImageRotateFlipTypeCreate(rotate, flip, &value));
		return value;
	}

	NImageInfo()
		: NExpandableObject(Create(), true)
	{
	}

	NImageFormat GetFormat() const;

	NUInt GetWidth() const
	{
		NUInt value;
		NCheck(NImageInfoGetWidth(GetHandle(), &value));
		return value;
	}

	NUInt GetHeight() const
	{
		NUInt value;
		NCheck(NImageInfoGetHeight(GetHandle(), &value));
		return value;
	}

	NImageRotateFlipType GetTransform() const
	{
		NImageRotateFlipType value;
		NCheck(NImageInfoGetTransform(GetHandle(), &value));
		return value;
	}

	void SetTransform(NImageRotateFlipType value)
	{
		NCheck(NImageInfoSetTransform(GetHandle(), value));
	}
};

}}

#include <Images/NImageFormat.hpp>

namespace Neurotec { namespace Images
{

inline NImageFormat NImageInfo::GetFormat() const
{
	return GetObject<HandleType, NImageFormat>(NImageInfoGetFormatEx, true);
}

}}

#endif // !N_IMAGE_INFO_HPP_INCLUDED
