#ifndef N_PLUGIN_MODULE_HPP_INCLUDED
#define N_PLUGIN_MODULE_HPP_INCLUDED

#include <Core/NModule.hpp>
namespace Neurotec { namespace Plugins
{
#include <Plugins/NPluginModule.h>
}}
#include <Core/NMemory.hpp>

namespace Neurotec { namespace Plugins
{

class NPluginModule : public NModule
{
	N_DECLARE_OBJECT_CLASS(NPluginModule, NModule)

private:
	static HNPluginModule Create()
	{
		HNPluginModule handle;
		NCheck(NPluginModuleCreate(&handle));
		return handle;
	}

public:
	NPluginModule()
		: NModule(Create(), true)
	{
	}

	NString GetPluginName() const
	{
		return GetString(NPluginModuleGetPluginNameN);
	}

	void SetPluginName(const NStringWrapper & value)
	{
		SetString(NPluginModuleSetPluginNameN, value);
	}

	NString GetInterfaceType() const
	{
		return GetString(NPluginModuleGetInterfaceTypeN);
	}

	void SetInterfaceType(const NStringWrapper & value)
	{
		SetString(NPluginModuleSetInterfaceTypeN, value);
	}

	NInt GetInterfaceVersions(NVersionRange * arValues, NInt valuesLength) const
	{
		return NCheck(NPluginModuleGetInterfaceVersions(GetHandle(), reinterpret_cast<NVersionRange_ *>(arValues), valuesLength));
	}

	NArrayWrapper<NVersionRange> GetInterfaceVersions() const
	{
		NInt count = NCheck(GetInterfaceVersions(NULL, 0));
		NArrayWrapper<NVersionRange> values(count);
		count = NCheck(GetInterfaceVersions(values.GetPtr(), count));
		values.SetCount(count);
		return values;
	}

	NInt GetPriority() const
	{
		NInt value;
		NCheck(NPluginModuleGetPriority(GetHandle(), &value));
		return value;
	}

	void SetPriority(NInt value)
	{
		NCheck(NPluginModuleSetPriority(GetHandle(), value));
	}

	NString GetIncompatiblePlugins() const
	{
		return GetString(NPluginModuleGetIncompatiblePluginsN);
	}

	void SetIncompatiblePlugins(const NStringWrapper & value)
	{
		SetString(NPluginModuleSetIncompatiblePluginsN, value);
	}
};

}}

#endif // !N_PLUGIN_MODULE_HPP_INCLUDED
