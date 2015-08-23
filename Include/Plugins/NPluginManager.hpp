#include <Plugins/NPlugin.hpp>

#ifndef N_PLUGIN_MANAGER_HPP_INCLUDED
#define N_PLUGIN_MANAGER_HPP_INCLUDED

#include <Collections/NCollection.hpp>
namespace Neurotec { namespace Plugins
{
using ::Neurotec::Collections::NCollectionChangedAction;
#include <Plugins/NPluginManager.h>
}}

namespace Neurotec { namespace Plugins
{

class NPluginManager : public NObject
{
	N_DECLARE_OBJECT_CLASS(NPluginManager, NObject)

public:
	class PluginCollection : public ::Neurotec::Collections::NCollectionWithChangeNotifications<NPlugin, NPluginManager,
		NPluginManagerGetPluginCount, NPluginManagerGetPlugin, NPluginManagerGetPlugins,
		NPluginManagerAddPluginsCollectionChanged, NPluginManagerRemovePluginsCollectionChanged>
	{
		PluginCollection(const NPluginManager & owner)
		{
			SetOwner(owner);
		}

		friend class NPluginManager;
	public:
		NPlugin Add(const NPluginModule & module, const NStringWrapper & directory)
		{
			HNPlugin hPlugin;
			NCheck(NPluginManagerAddPluginN(this->GetOwnerHandle(), module.GetHandle(), directory.GetHandle(), &hPlugin));
			return FromHandle<NPlugin>(hPlugin, true);
		}

		NPlugin Add(const NStringWrapper & fileName)
		{
			HNPlugin hPlugin;
			NCheck(NPluginManagerAddPluginFromFileN(this->GetOwnerHandle(), fileName.GetHandle(), &hPlugin));
			return FromHandle<NPlugin>(hPlugin, true);
		}

		NInt IndexOf(const NStringWrapper & name) const
		{
			HNPlugin hPlugin;
			NCheck(NPluginManagerGetPluginByNameN(this->GetOwnerHandle(), name.GetHandle(), &hPlugin));
			return ::Neurotec::Collections::NCollectionWithAllOutBase<NPlugin, NPluginManager,
				NPluginManagerGetPluginCount, NPluginManagerGetPlugin, NPluginManagerGetPlugins>::IndexOf(FromHandle<NPlugin>(hPlugin, true));
		}

		bool Contains(const NStringWrapper & name) const
		{
			return IndexOf(name) != -1;
		}

		using ::Neurotec::Collections::NCollectionBase<NPlugin, NPluginManager, NPluginManagerGetPluginCount, NPluginManagerGetPlugin>::Get;

		NPlugin Get(const NStringWrapper & name) const
		{
			HNPlugin hPlugin;
			NCheck(NPluginManagerGetPluginByNameN(this->GetOwnerHandle(), name.GetHandle(), &hPlugin));
			return FromHandle<NPlugin>(hPlugin, true);
		}

		NPlugin operator[](const NStringWrapper & name) const
		{
			return Get(name);
		}
	};

	class DisabledPluginCollection : public ::Neurotec::Collections::NCollectionWithChangeNotifications<NString, NPluginManager,
		NPluginManagerGetDisabledPluginCount, NPluginManagerGetDisabledPluginN, NPluginManagerGetDisabledPlugins,
		NPluginManagerAddDisabledPluginsCollectionChanged, NPluginManagerRemoveDisabledPluginsCollectionChanged>
	{
		DisabledPluginCollection(const NPluginManager & owner)
		{
			SetOwner(owner);
		}

		friend class NPluginManager;

	public:
		NInt Add(const NStringWrapper & value)
		{
			NInt index;
			NCheck(NPluginManagerAddDisabledPluginN(this->GetOwnerHandle(), value.GetHandle(), &index));
			return index;
		}

		NInt Remove(const NStringWrapper & value)
		{
			NInt index;
			NCheck(NPluginManagerRemoveDisabledPluginN(this->GetOwnerHandle(), value.GetHandle(), &index));
			return index;
		}

		void RemoveAt(NInt index)
		{
			NCheck(NPluginManagerRemoveDisabledPluginAt(this->GetOwnerHandle(), index));
		}

		void Clear()
		{
			NCheck(NPluginManagerClearDisabledPlugins(this->GetOwnerHandle()));
		}
	};

public:
	static NType NPluginManagerPluginCallbackNativeTypeOf()
	{
		return NObject::GetObject<NType>(N_TYPE_OF(NPluginManagerPluginCallback), true);
	}

	static NArrayWrapper<NPluginManager> GetInstances()
	{
		return GetObjects<NPluginManager>(NPluginManagerGetInstances, true);
	}

	void EnsurePluginSearchPerformed()
	{
		NCheck(NPluginManagerEnsurePluginSearchPerformed(GetHandle()));
	}

	void Refresh()
	{
		NCheck(NPluginManagerRefresh(GetHandle()));
	}

	void PlugAll()
	{
		NCheck(NPluginManagerPlugAll(GetHandle()));
	}

	void UnplugAll()
	{
		NCheck(NPluginManagerUnplugAll(GetHandle()));
	}

	NString GetPluginSearchPath() const
	{
		return GetString(NPluginManagerGetPluginSearchPathN);
	}

	void SetPluginSearchPath(const NStringWrapper & value)
	{
		SetString(NPluginManagerSetPluginSearchPathN, value);
	}

	NString GetInterfaceType() const
	{
		return GetString(NPluginManagerGetInterfaceTypeN);
	}

	NInt GetInterfaceVersions(NVersionRange * arValues, NInt valuesLength) const
	{
		return NCheck(NPluginManagerGetInterfaceVersions(GetHandle(), reinterpret_cast<NVersionRange_ *>(arValues), valuesLength));
	}

	NArrayWrapper<NVersionRange> GetInterfaceVersions() const
	{
		NInt count = NCheck(GetInterfaceVersions(NULL, 0));
		NArrayWrapper<NVersionRange> values(count);
		count = NCheck(GetInterfaceVersions(values.GetPtr(), count));
		values.SetCount(count);
		return values;
	}

	NBool AllowsUnplug() const
	{
		NBool value;
		NCheck(NPluginManagerAllowsUnplug(GetHandle(), &value));
		return value;
	}

	const PluginCollection GetPlugins() const
	{
		return PluginCollection(*this);
	}

	PluginCollection GetPlugins()
	{
		return PluginCollection(*this);
	}

	const DisabledPluginCollection GetDisabledPlugins() const
	{
		return DisabledPluginCollection(*this);
	}

	DisabledPluginCollection GetDisabledPlugins()
	{
		return DisabledPluginCollection(*this);
	}
};

}}

#endif // !N_PLUGIN_MANAGER_HPP_INCLUDED
