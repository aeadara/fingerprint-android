#ifndef N_PLUGIN_HPP_INCLUDED
#define N_PLUGIN_HPP_INCLUDED

#include <Core/NObject.hpp>
#include <Core/NTimeSpan.hpp>
#include <Plugins/NPluginModule.hpp>
namespace Neurotec { namespace Plugins
{
#include <Plugins/NPlugin.h>
}}

N_DEFINE_ENUM_TYPE_TRAITS(Neurotec::Plugins, NPluginState)

namespace Neurotec { namespace Plugins
{
class NPluginManager;

class NPlugin : public NObject
{
	N_DECLARE_OBJECT_CLASS(NPlugin, NObject)

public:
	static NType NPluginStateNativeTypeOf()
	{
		return NObject::GetObject<NType>(N_TYPE_OF(NPluginState), true);
	}

	void Plug()
	{
		NCheck(NPluginPlug(GetHandle()));
	}

	void Unplug()
	{
		NCheck(NPluginUnplug(GetHandle()));
	}

	void Enable()
	{
		NCheck(NPluginEnable(GetHandle()));
	}

	void Disable()
	{
		NCheck(NPluginDisable(GetHandle()));
	}

	NPluginManager GetOwner() const;

	NString GetFileName() const
	{
		return GetString(NPluginGetFileNameN);
	}

	NPluginState GetState() const
	{
		NPluginState state;
		NCheck(NPluginGetState(GetHandle(), &state));
		return state;
	}

	NError GetError() const
	{
		return GetObject<HNPlugin, NError>(NPluginGetError);
	}

	NTimeSpan GetLoadTime() const
	{
		NTimeSpan_ loadTime;
		NCheck(NPluginGetLoadTime(GetHandle(), &loadTime));
		return NTimeSpan(loadTime);
	}

	NPluginModule GetModule() const
	{
		return GetObject<HandleType, NPluginModule>(NPluginGetModule, true);
	}

	NVersion GetSelectedInterfaceVersion() const
	{
		NVersion_ version;
		NCheck(NPluginGetSelectedInterfaceVersion(GetHandle(), &version));
		return NVersion(version);
	}

	NTimeSpan GetPlugTime() const
	{
		NTimeSpan_ plugTime;
		NCheck(NPluginGetPlugTime(GetHandle(), &plugTime));
		return NTimeSpan(plugTime);
	}
};

}}

#include <Plugins/NPluginManager.hpp>

namespace Neurotec { namespace Plugins
{
inline NPluginManager NPlugin::GetOwner() const
{
	return NObject::GetOwner<NPluginManager>();
}
}}

#endif // !N_PLUGIN_HPP_INCLUDED
