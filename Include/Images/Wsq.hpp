#ifndef WSQ_HPP_INCLUDED
#define WSQ_HPP_INCLUDED

#include <Images/NImage.hpp>
#include <Images/NistCom.hpp>
namespace Neurotec { namespace Images
{
#include <Images/Wsq.h>
}}

namespace Neurotec { namespace Images
{

#undef WSQ_DEFAULT_BIT_RATE
#undef WSQ_IMPLEMENTATION_NEUROTECHNOLOGY_WIN32_X86
#undef WSQ_IMPLEMENTATION_NEUROTECHNOLOGY_WIN64_X64
#undef WSQ_IMPLEMENTATION_NEUROTECHNOLOGY_DEBIAN_I386
#undef WSQ_IMPLEMENTATION_NEUROTECHNOLOGY_DEBIAN_AMD64
#undef WSQ_IMPLEMENTATION_NEUROTECHNOLOGY_MACOSX_INTEL
#undef WSQ_IMPLEMENTATION_NEUROTECHNOLOGY_MACOSX_INTEL64
#undef WSQ_IMPLEMENTATION_NEUROTECHNOLOGY_MACOSX_POWERPC

const NFloat WSQ_DEFAULT_BIT_RATE = 0.75f;
const NUShort WSQ_IMPLEMENTATION_NEUROTECHNOLOGY_WIN32_X86 = 10150;
const NUShort WSQ_IMPLEMENTATION_NEUROTECHNOLOGY_WIN64_X64 = 10151;
const NUShort WSQ_IMPLEMENTATION_NEUROTECHNOLOGY_DEBIAN_I386 = 10152;
const NUShort WSQ_IMPLEMENTATION_NEUROTECHNOLOGY_DEBIAN_AMD64 = 10153;
const NUShort WSQ_IMPLEMENTATION_NEUROTECHNOLOGY_MACOSX_INTEL = 10154;
const NUShort WSQ_IMPLEMENTATION_NEUROTECHNOLOGY_MACOSX_INTEL64 = 10155;
const NUShort WSQ_IMPLEMENTATION_NEUROTECHNOLOGY_MACOSX_POWERPC = 10156;

class WsqInfo : public NImageInfo
{
	N_DECLARE_OBJECT_CLASS(WsqInfo, NImageInfo)

public:
	NFloat GetBitRate() const
	{
		NFloat value;
		NCheck(WsqInfoGetBitRate(GetHandle(), &value));
		return value;
	}

	void SetBitRate(NFloat value)
	{
		NCheck(WsqInfoSetBitRate(GetHandle(), value));
	}

	NUShort GetImplementationNumber() const
	{
		NUShort value;
		NCheck(WsqInfoGetImplementationNumber(GetHandle(), &value));
		return value;
	}

	bool HasNistCom() const
	{
		NBool value;
		NCheck(WsqInfoHasNistCom(GetHandle(), &value));
		return value != 0;
	}

	void SetHasNistCom(bool value)
	{
		NCheck(WsqInfoSetHasNistCom(GetHandle(), value ? NTrue : NFalse));
	}

	NistCom GetNistCom() const
	{
		HNistCom hValue;
		NCheck(WsqInfoGetNistCom(GetHandle(), &hValue));
		return FromHandle<NistCom>(hValue, true);
	}
};

}}

#endif // !WSQ_HPP_INCLUDED
