#include <Core/NType.hpp>

#ifndef N_MEMBER_INFO_HPP_INCLUDED
#define N_MEMBER_INFO_HPP_INCLUDED

namespace Neurotec { namespace Reflection
{
#include <Reflection/NMemberInfo.h>
}}

namespace Neurotec { namespace Reflection
{

class NMemberInfo : public NObject
{
	N_DECLARE_OBJECT_CLASS(NMemberInfo, NObject)

public:
	NType GetDeclaringType() const
	{
		return GetObject<HandleType, NType>(NMemberInfoGetDeclaringType, true);
	}

	NInt GetId() const
	{
		NInt value;
		NCheck(NMemberInfoGetId(GetHandle(), &value));
		return value;
	}

	NString GetName() const
	{
		return GetString(NMemberInfoGetName);
	}

	NAttributes GetAttributes() const
	{
		NAttributes value;
		NCheck(NMemberInfoGetAttributes(GetHandle(), &value));
		return value;
	}
};

}}

#endif // !N_MEMBER_INFO_HPP_INCLUDED
