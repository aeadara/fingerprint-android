#ifndef N_FILE_ENUMERATOR_HPP_INCLUDED
#define N_FILE_ENUMERATOR_HPP_INCLUDED

#include <IO/NFile.hpp>
namespace Neurotec { namespace IO
{
#include <IO/NFileEnumerator.h>
}}

namespace Neurotec { namespace IO
{

class NFileEnumerator : public NObject
{
	N_DECLARE_OBJECT_CLASS(NFileEnumerator, NObject)

private:
	static HNFileEnumerator Create(const NStringWrapper & path)
	{
		HNFileEnumerator handle;
		NCheck(NFileEnumeratorCreateN(path.GetHandle(), &handle));
		return handle;
	}

public:
	NFileEnumerator(const NStringWrapper & path)
		: NObject(Create(path), true)
	{
	}

	bool MoveNext()
	{
		NBool value;
		NCheck(NFileEnumeratorMoveNext(GetHandle(), &value));
		return value != NFalse;
	}

	NString GetFileName()
	{
		HNString handle;
		NCheck(NFileEnumeratorGetFileName(GetHandle(), &handle));
		return NString(handle, true);
	}

	NFileAttributes GetFileAttributes()
	{
		NFileAttributes value;
		NCheck(NFileEnumeratorGetFileAttributes(GetHandle(), &value));
		return value;
	}
};

}}

#endif // !N_FILE_ENUMERATOR_HPP_INCLUDED
