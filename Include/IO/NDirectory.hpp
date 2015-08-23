#ifndef N_DIRECTORY_HPP_INCLUDED
#define N_DIRECTORY_HPP_INCLUDED

#include <Core/NObject.hpp>
namespace Neurotec { namespace IO
{
#include <IO/NDirectory.h>
}}

namespace Neurotec { namespace IO
{

class NDirectory
{
	N_DECLARE_STATIC_OBJECT_CLASS(NDirectory)

public:
	static bool Exists(const NStringWrapper & path)
	{
		NBool value;
		NCheck(NDirectoryExistsN(path.GetHandle(), &value));
		return value != 0;
	}
};

}}

#endif // !N_DIRECTORY_HPP_INCLUDED
