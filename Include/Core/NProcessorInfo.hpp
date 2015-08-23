#ifndef N_PROCESSOR_INFO_HPP_INCLUDED
#define N_PROCESSOR_INFO_HPP_INCLUDED

#include <Core/NObject.hpp>
namespace Neurotec
{
#include <Core/NProcessorInfo.h>
}

N_DEFINE_ENUM_TYPE_TRAITS(Neurotec, NProcessorVendor)

namespace Neurotec
{

class NProcessorInfo
{
	N_DECLARE_STATIC_OBJECT_CLASS(NProcessorInfo)

public:
	static NType NProcessorVendorNativeTypeOf()
	{
		return NObject::GetObject<NType>(N_TYPE_OF(NProcessorVendor), true);
	}

	static NInt GetCount()
	{
		NInt value;
		NCheck(NProcessorInfoGetCount(&value));
		return value;
	}

	static void GetModelInfo(NInt * pFamily, NInt * pModel, NInt * pStepping)
	{
		NCheck(NProcessorInfoGetModelInfo(pFamily, pModel, pStepping));
	}

	static NString GetVendorName()
	{
		return NObject::GetString(NProcessorInfoGetVendorNameN);
	}

	static NProcessorVendor GetVendor()
	{
		NProcessorVendor value;
		NCheck(NProcessorInfoGetVendor(&value));
		return value;
	}

	static NString GetModelName()
	{
		return NObject::GetString(NProcessorInfoGetModelNameN);
	}

	static bool IsMmxSupported()
	{
		NBool value;
		NCheck(NProcessorInfoIsMmxSupportedEx(&value));
		return value != 0;
	}

	static bool Is3DNowSupported()
	{
		NBool value;
		NCheck(NProcessorInfoIs3DNowSupportedEx(&value));
		return value != 0;
	}

	static bool IsSseSupported()
	{
		NBool value;
		NCheck(NProcessorInfoIsSseSupportedEx(&value));
		return value != 0;
	}

	static bool IsSse2Supported()
	{
		NBool value;
		NCheck(NProcessorInfoIsSse2SupportedEx(&value));
		return value != 0;
	}

	static bool IsSse3Supported()
	{
		NBool value;
		NCheck(NProcessorInfoIsSse3SupportedEx(&value));
		return value != 0;
	}

	static bool IsSsse3Supported()
	{
		NBool value;
		NCheck(NProcessorInfoIsSsse3SupportedEx(&value));
		return value != 0;
	}

	static bool IsLZCntSupported()
	{
		NBool value;
		NCheck(NProcessorInfoIsLZCntSupportedEx(&value));
		return value != 0;
	}

	static bool IsPopCntSupported()
	{
		NBool value;
		NCheck(NProcessorInfoIsPopCntSupportedEx(&value));
		return value != 0;
	}

	static bool IsSse41Supported()
	{
		NBool value;
		NCheck(NProcessorInfoIsSse41SupportedEx(&value));
		return value != 0;
	}

	static bool IsSse4aSupported()
	{
		NBool value;
		NCheck(NProcessorInfoIsSse4aSupportedEx(&value));
		return value != 0;
	}

	static bool IsSse5Supported()
	{
		NBool value;
		NCheck(NProcessorInfoIsSse5SupportedEx(&value));
		return value != 0;
	}

	static bool IsNeonSupported()
	{
		NBool value;
		NCheck(NProcessorInfoIsNeonSupported(&value));
		return value != 0;
	}
};

}

#endif // !N_PROCESSOR_INFO_HPP_INCLUDED
