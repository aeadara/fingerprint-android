#ifndef N_ENVIRONMENT_HPP_INCLUDED
#define N_ENVIRONMENT_HPP_INCLUDED

#include <Core/NObject.hpp>
namespace Neurotec
{
#include <Core/NEnvironment.h>
}

namespace Neurotec
{

class NEnvironment
{
	N_DECLARE_STATIC_OBJECT_CLASS(NEnvironment)

public:
	static NString GetCallStack(NInt framesToSkip = 0)
	{
		HNString hCallStack;
		NCheck(NEnvironmentGetCallStack(framesToSkip + 1, &hCallStack));
		return NString(hCallStack, true);
	}

	static NString GetCurrentDirectory()
	{
		HNString hPath;
		NCheck(NEnvironmentGetCurrentDirectory(&hPath));
		return NString(hPath, true);
	}

	static NString GetSystemDirectory()
	{
		HNString hPath;
		NCheck(NEnvironmentGetSystemDirectory(&hPath));
		return NString(hPath, true);
	}
};

}
#endif // !N_ENVIRONMENT_HPP_INCLUDED
