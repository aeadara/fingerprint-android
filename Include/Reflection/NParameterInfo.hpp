#include <Core/NValue.hpp>

#ifndef N_PARAMETER_INFO_HPP_INCLUDED
#define N_PARAMETER_INFO_HPP_INCLUDED

#include <Collections/NCollections.hpp>
namespace Neurotec { namespace Reflection
{
#include <Reflection/NParameterInfo.h>
}}

namespace Neurotec { namespace Reflection
{

class NParameterInfo : public NObject
{
	N_DECLARE_OBJECT_CLASS(NParameterInfo, NObject)

public:
	class StdValueCollection : public ::Neurotec::Collections::NCollectionWithAllOutBase<NNameValuePair, NParameterInfo,
		NParameterInfoGetStdValueCount, NParameterInfoGetStdValue, NParameterInfoGetStdValues>
	{
		StdValueCollection(const NParameterInfo & owner)
		{
			SetOwner(owner);
		}

	protected:
		friend class NParameterInfo;
	};

public:
	NString GetName() const
	{
		return GetString(NParameterInfoGetName);
	}

	NType GetParameterType() const
	{
		return GetObject<HandleType, NType>(NParameterInfoGetParameterType, true);
	}

	NAttributes GetAttributes() const
	{
		NAttributes value;
		NCheck(NParameterInfoGetAttributes(GetHandle(), &value));
		return value;
	}

	NString GetFormat() const
	{
		return GetString<HandleType>(NParameterInfoGetFormat);
	}

	NValue GetDefaultValue() const
	{
		return GetObject<HandleType, NValue>(NParameterInfoGetDefaultValue);
	}

	NValue GetMinValue() const
	{
		return GetObject<HandleType, NValue>(NParameterInfoGetMinValue);
	}

	NValue GetMaxValue() const
	{
		return GetObject<HandleType, NValue>(NParameterInfoGetMaxValue);
	}

	const StdValueCollection GetStdValues() const
	{
		return StdValueCollection(*this);
	}
};

}}

#endif // !N_PARAMETER_INFO_HPP_INCLUDED
