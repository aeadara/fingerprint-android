#ifndef N_DATA_FILE_BUILDER_HPP_INCLUDED
#define N_DATA_FILE_BUILDER_HPP_INCLUDED

#include <Plugins/NDataRecord.hpp>

namespace Neurotec { namespace Plugins
{
#include <Plugins/NDataFileBuilder.h>
}}

namespace Neurotec { namespace Plugins
{
class NDataFileBuilder : public NObject
{
	N_DECLARE_OBJECT_CLASS(NDataFileBuilder, NObject)

private:
	static HNDataFileBuilder Create()
	{
		HNDataFileBuilder handle;
		NCheck(NDataFileBuilderCreate(&handle));
		return handle;
	}

public:
	NDataFileBuilder()
		: NObject(Create(), true)
	{
	}

	void AppendRecord(const NDataRecord & record)
	{
		NCheck(NDataFileBuilderAppendRecord(GetHandle(), record.GetHandle()));
	}

	void WriteToFile(const NStringWrapper & fileName)
	{
		NCheck(NDataFileBuilderWriteToFileN(GetHandle(), fileName.GetHandle()));
	}
};
}}

#endif // !N_DATA_FILE_BUILDER_HPP_INCLUDED
