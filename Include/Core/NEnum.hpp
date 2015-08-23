#ifndef N_ENUM_HPP_INCLUDED
#define N_ENUM_HPP_INCLUDED

#include <Core/NType.hpp>
namespace Neurotec
{
#include <Core/NEnum.h>
}

namespace Neurotec
{

class NEnum
{
private:
	NEnum();
	NEnum(const NEnum &);

public:
	static NString ToString(const NType & type, NInt32 value, const NStringWrapper & format = NString())
	{
		HNString hValue;
		NCheck(NEnumToStringN(type.GetHandle(), value, format.GetHandle(), &hValue));
		return NString(hValue, true);
	}

	static bool TryParse(const NType & type, const NStringWrapper & value, const NStringWrapper & format, NInt32 * pValue)
	{
		NBool result;
		NCheck(NEnumTryParseN(type.GetHandle(), value.GetHandle(), format.GetHandle(), pValue, &result));
		return result != 0;
	}
	static bool TryParse(const NType & type, const NStringWrapper & value, NInt32 * pValue) { return TryParse(type, value, NString(), pValue); }

	static NInt32 Parse(const NType & type, const NStringWrapper & value, const NStringWrapper & format = NString())
	{
		NInt32 result;
		NCheck(NEnumParseN(type.GetHandle(), value.GetHandle(), format.GetHandle(), &result));
		return result;
	}

	static NArrayWrapper<NInt> GetValues(const NType & type)
	{
		NInt count;
		NCheck(NEnumGetValues(type.GetHandle(), NULL, &count));
		NArrayWrapper<NInt> values(count);
		NCheck(NEnumGetValues(type.GetHandle(), values.GetPtr(), &count));
		return values;
	}

};

}

#endif // !N_ENUM_HPP_INCLUDED
