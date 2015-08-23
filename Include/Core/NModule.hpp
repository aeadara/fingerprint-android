#include <Core/NObject.hpp>
#include <Collections/NCollections.hpp>

#ifndef N_MODULE_HPP_INCLUDED
#define N_MODULE_HPP_INCLUDED

namespace Neurotec
{
#include <Core/NModule.h>
}

N_DEFINE_ENUM_TYPE_TRAITS(Neurotec, NModuleOptions)

namespace Neurotec
{
#define N_NATIVE_MODULE_OF(name) (name::NativeModuleOf())
#define N_DECLARE_MODULE_CLASS(name) \
	public:\
		static ::Neurotec::NModule NativeModuleOf()\
		{\
			return ::Neurotec::NObject::GetObject<NModule>(N_MODULE_OF(name), true);\
		}

class NModule : public NObject
{
	N_DECLARE_OBJECT_CLASS(NModule, NObject)

public:
	class DefinedTypeCollection : public ::Neurotec::Collections::NCollectionWithAllOutBase<NType, NModule,
		NModuleGetDefinedTypeCount, NModuleGetDefinedType, NModuleGetDefinedTypes>
	{
		DefinedTypeCollection(const NModule & owner)
		{
			SetOwner(owner);
		}

		friend class NModule;
	};

private:
	static HNModule Create()
	{
		HNModule handle;
		NCheck(NModuleCreate(&handle));
		return handle;
	}

public:
	static NType NModuleOptionsNativeTypeOf()
	{
		return NObject::GetObject<NType>(N_TYPE_OF(NModuleOptions), true);
	}

	static NArrayWrapper<NModule> GetLoadedModules()
	{
		return GetObjects<NModule>(NModuleGetLoadedModules, true);
	}

	static NModule LoadFromFile(const NStringWrapper & fileName)
	{
		HNModule hModule;
		NCheck(NModuleLoadFromFileN(fileName.GetHandle(), &hModule));
		return FromHandle<NModule>(hModule, true);
	}

	static void CheckInit(NModuleOfProc pTypeOf, bool lazy)
	{
		NCheck(NModuleCheckInitP(pTypeOf, lazy ? NTrue : NFalse));
	}

	NModule()
		: NObject(Create(), true)
	{
		Reset();
	}

	void CheckInit(bool lazy) const
	{
		NCheck(NModuleCheckInit(GetHandle(), lazy ? NTrue : NFalse));
	}

	NModuleOptions GetOptions() const
	{
		NModuleOptions value;
		NCheck(NModuleGetOptions(GetHandle(), &value));
		return value;
	}

	void SetOptions(NModuleOptions value)
	{
		NCheck(NModuleSetOptions(GetHandle(), value));
	}

	NArrayWrapper<NModule> GetDependences() const
	{
		return GetObjects<HNModule, NModule>(NModuleGetDependences, true);
	}

	NString GetName() const
	{
		return GetString(NModuleGetNameN);
	}

	void SetName(const NStringWrapper & value)
	{
		SetString(NModuleSetNameN, value);
	}

	NString GetTitle() const
	{
		return GetString(NModuleGetTitleN);
	}

	void SetTitle(const NStringWrapper & value)
	{
		SetString(NModuleSetTitleN, value);
	}

	NString GetProduct() const
	{
		return GetString(NModuleGetProductN);
	}

	void SetProduct(const NStringWrapper & value)
	{
		SetString(NModuleSetProductN, value);
	}

	NString GetCompany() const
	{
		return GetString(NModuleGetCompanyN);
	}

	void SetCompany(const NStringWrapper & value)
	{
		SetString(NModuleSetCompanyN, value);
	}

	NString GetCopyright() const
	{
		return GetString(NModuleGetCopyrightN);
	}

	void SetCopyright(const NStringWrapper & value)
	{
		SetString(NModuleSetCopyrightN, value);
	}

	NString GetId() const
	{
		return GetString(NModuleGetId);
	}

	void SetId(const NStringWrapper & value)
	{
		SetString(NModuleSetIdN, value);
	}

	NString GetNativeId() const
	{
		return GetString(NModuleGetNativeId);
	}

	void SetNativeId(const NStringWrapper & value)
	{
		SetString(NModuleSetNativeIdN, value);
	}

	NInt GetVersionMajor() const
	{
		NInt value;
		NCheck(NModuleGetVersionMajor(GetHandle(), &value));
		return value;
	}

	void SetVersionMajor(NInt value)
	{
		NCheck(NModuleSetVersionMajor(GetHandle(), value));
	}

	NInt GetVersionMinor() const
	{
		NInt value;
		NCheck(NModuleGetVersionMinor(GetHandle(), &value));
		return value;
	}

	void SetVersionMinor(NInt value)
	{
		NCheck(NModuleSetVersionMinor(GetHandle(), value));
	}

	NInt GetVersionBuild() const
	{
		NInt value;
		NCheck(NModuleGetVersionBuild(GetHandle(), &value));
		return value;
	}

	void SetVersionBuild(NInt value)
	{
		NCheck(NModuleSetVersionBuild(GetHandle(), value));
	}

	NInt GetVersionRevision() const
	{
		NInt value;
		NCheck(NModuleGetVersionRevision(GetHandle(), &value));
		return value;
	}

	void SetVersionRevision(NInt value)
	{
		NCheck(NModuleSetVersionRevision(GetHandle(), value));
	}

	NString GetFileName() const
	{
		return GetString(NModuleGetFileName);
	}

	NString GetActivated() const
	{
		return GetString(NModuleGetActivatedN);
	}

	NType GetType(const NStringWrapper & name, bool mustExist = false) const
	{
		HNType hValue;
		NCheck(NModuleGetTypeWithNameN(GetHandle(), name.GetHandle(), mustExist ? NTrue : NFalse, &hValue));
		return FromHandle<NType>(hValue, true);
	}

	NValue CreateInstance(const NStringWrapper & name, NAttributes attributes = naNone) const
	{
		HNValue hValue;
		NCheck(NModuleCreateInstanceN(GetHandle(), name.GetHandle(), attributes, &hValue));
		return FromHandle<NValue>(hValue);
	}

	const DefinedTypeCollection GetDefinedTypes() const
	{
		return DefinedTypeCollection(*this);
	}
};

}

#endif // !N_MODULE_HPP_INCLUDED
