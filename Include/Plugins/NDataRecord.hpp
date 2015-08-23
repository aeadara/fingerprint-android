#ifndef N_DATA_RECORD_HPP_INCLUDED
#define N_DATA_RECORD_HPP_INCLUDED

#include <Core/NObject.hpp>

namespace Neurotec { namespace Plugins
{
#include <Plugins/NDataRecord.h>
}}

namespace Neurotec { namespace Plugins
{
class NDataRecord : public NObject
{
	N_DECLARE_OBJECT_CLASS(NDataRecord, NObject)

public:
	NString GetId() const
	{
		HNString handle;
		NCheck(NDataRecordGetId(GetHandle(), &handle));
		return NString(handle, true);
	}

	NVersion GetVersion() const
	{
		NVersion_ value;
		NCheck(NDataRecordGetVersion(GetHandle(), &value));
		return NVersion(value);
	}
};
}}

#endif // !N_DATA_RECORD_HPP_INCLUDED