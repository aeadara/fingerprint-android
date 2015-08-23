#ifndef N_DATA_FILE_HPP_INCLUDED
#define N_DATA_FILE_HPP_INCLUDED

#include <Core/NObject.hpp>
#include <Plugins/NDataRecord.hpp>

namespace Neurotec { namespace Plugins
{
#include <Plugins/NDataFile.h>
}}

namespace Neurotec { namespace Plugins
{
class NDataFile : public NObject
{
	N_DECLARE_OBJECT_CLASS(NDataFile, NObject)

public:
	class RecordCollection : public ::Neurotec::Collections::NCollectionWithAllOutBase<NDataRecord, NDataFile,
		NDataFileGetRecordCount, NDataFileGetRecord, NDataFileGetRecords>
	{
		RecordCollection(const NDataFile & owner)
		{
			SetOwner(owner);
		}

		friend class NDataFile;
	};

public:
	NString GetFileName() const
	{
		HNString handle;
		NCheck(NDataFileGetFileName(GetHandle(), &handle));
		return NString(handle, true);
	}

	const RecordCollection GetRecords() const
	{
		return RecordCollection(*this);
	}
};
}}

#endif // !N_DATA_FILE_HPP_INCLUDED