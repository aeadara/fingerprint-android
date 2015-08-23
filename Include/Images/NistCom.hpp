#ifndef NIST_COM_HPP_INCLUDED
#define NIST_COM_HPP_INCLUDED

#include <Core/NObject.hpp>
namespace Neurotec { namespace Images
{
#include <Images/NistCom.h>
}}

namespace Neurotec { namespace Images
{

class NistCom : public NObject
{
	N_DECLARE_OBJECT_CLASS(NistCom, NObject)

public:
	class ItemCollection : public ::Neurotec::Collections::NCollectionBase<NNameStringPair, NistCom,
		NistComGetItemCount, NistComGetItem>
	{
		ItemCollection(const NistCom & owner)
		{
			SetOwner(owner);
		}

	public:
		void Set(NInt index, const NNameStringPair & value)
		{
			NCheck(NistComSetItem(this->GetOwnerHandle(), index, &value));
		}

		NInt Add(const NNameStringPair & value)
		{
			NInt count = this->GetCount();
			NCheck(NistComAddItem(this->GetOwnerHandle(), &value));
			return count;
		}

		void Insert(NInt index, const NNameStringPair & value)
		{
			NCheck(NistComInsertItem(this->GetOwnerHandle(), index, &value));
		}

		void RemoveAt(NInt index)
		{
			NCheck(NistComRemoveItemAt(this->GetOwnerHandle(), index));
		}

		void Clear()
		{
			NCheck(NistComClearItems(this->GetOwnerHandle()));
		}

	public:
		NString Get(const NStringWrapper & key) const
		{
			HNString hValue;
			NCheck(NistComGetValueN(this->GetOwnerHandle(), key.GetHandle(), &hValue));
			return NString(hValue, true);
		}

		void Set(const NStringWrapper & key, const NStringWrapper & value)
		{
			NCheck(NistComSetValueN(this->GetOwnerHandle(), key.GetHandle(), value.GetHandle()));
		}

		void Add(const NStringWrapper & key, const NStringWrapper & value)
		{
			NCheck(NistComAddValueN(this->GetOwnerHandle(), key.GetHandle(), value.GetHandle()));
		}

		friend class NistCom;
	};

private:
	static HNistCom Create(NUInt flags)
	{
		HNistCom handle;
		NCheck(NistComCreate(flags, &handle));
		return handle;
	}

	static HNistCom Create(const NStringWrapper & fileName, NUInt flags)
	{
		HNistCom handle;
		NCheck(NistComCreateFromFileN(fileName.GetHandle(), flags, &handle));
		return handle;
	}

	static HNistCom Create(const ::Neurotec::IO::NBuffer & buffer, NUInt flags, NSizeType * pSize)
	{
		HNistCom handle;
		NCheck(NistComCreateFromMemoryN(buffer.GetHandle(), flags, pSize, &handle));
		return handle;
	}

	static HNistCom Create(const void * pBuffer, NSizeType bufferSize, NUInt flags, NSizeType * pSize)
	{
		HNistCom handle;
		NCheck(NistComCreateFromMemory(pBuffer, bufferSize, flags, pSize, &handle));
		return handle;
	}

	static HNistCom Create(const ::Neurotec::IO::NStream & stream, NUInt flags)
	{
		HNistCom handle;
		NCheck(NistComCreateFromStream(stream.GetHandle(), flags, &handle));
		return handle;
	}

public:
	explicit NistCom(NUInt flags = 0)
		: NObject(Create(flags), true)
	{
	}

	explicit NistCom(const NStringWrapper & fileName, NUInt flags = 0)
		: NObject(Create(fileName, flags), true)
	{
	}

	explicit NistCom(const ::Neurotec::IO::NBuffer & buffer, NUInt flags = 0, NSizeType * pSize = NULL)
		: NObject(Create(buffer, flags, pSize), true)
	{
	}

	NistCom(const void * pBuffer, NSizeType bufferSize, NUInt flags = 0, NSizeType * pSize = NULL)
		: NObject(Create(pBuffer, bufferSize, flags, pSize), true)
	{
	}

	explicit NistCom(const ::Neurotec::IO::NStream & stream, NUInt flags = 0)
		: NObject(Create(stream, flags), true)
	{
	}

	void Save(const NStringWrapper & fileName, NUInt flags = 0) const
	{
		NCheck(NistComSaveToFileN(GetHandle(), fileName.GetHandle(), flags));
	}

	ItemCollection GetItems()
	{
		return ItemCollection(*this);
	}

	const ItemCollection GetItems() const
	{
		return ItemCollection(*this);
	}
};

}}

#endif // !NIST_COM_HPP_INCLUDED
