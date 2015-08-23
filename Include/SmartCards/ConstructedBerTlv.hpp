#ifndef CONSTRUCTED_BER_TLV_HPP_INCLUDED
#define CONSTRUCTED_BER_TLV_HPP_INCLUDED

#include <SmartCards/BerTlv.hpp>
namespace Neurotec { namespace SmartCards
{
#include <SmartCards/ConstructedBerTlv.h>
}}

namespace Neurotec { namespace SmartCards
{

class ConstructedBerTlv : public BerTlv
{
	N_DECLARE_OBJECT_CLASS(ConstructedBerTlv, BerTlv)

public:
	class DataObjectCollection : public ::Neurotec::Collections::NCollectionBase<BerTlv, ConstructedBerTlv,
		ConstructedBerTlvGetDataObjectCount, ConstructedBerTlvGetDataObjectEx>
	{
		DataObjectCollection(const ConstructedBerTlv & owner)
		{
			SetOwner(owner);
		}

		friend class ConstructedBerTlv;

	public:
		NInt GetCapacity() const
		{
			NInt value;
			NCheck(ConstructedBerTlvGetDataObjectCapacity(this->GetOwnerHandle(), &value));
			return value;
		}

		void SetCapacity(NInt value)
		{
			NCheck(ConstructedBerTlvSetDataObjectCapacity(this->GetOwnerHandle(), value));
		}

		void Set(NInt index, const BerTlv & value)
		{
			NCheck(ConstructedBerTlvSetDataObject(this->GetOwnerHandle(), index, value.GetHandle()));
		}

		NInt Add(const BerTlv & value)
		{
			NInt index;
			NCheck(ConstructedBerTlvAddDataObjectEx2(this->GetOwnerHandle(), value.GetHandle(), &index));
			return index;
		}

		void Insert(NInt index, const BerTlv & value)
		{
			NCheck(ConstructedBerTlvInsertDataObject(this->GetOwnerHandle(), index, value.GetHandle()));
		}

		void RemoveAt(NInt index)
		{
			NCheck(ConstructedBerTlvRemoveDataObjectAt(this->GetOwnerHandle(), index));
		}

		void Clear()
		{
			NCheck(ConstructedBerTlvClearDataObjects(this->GetOwnerHandle()));
		}

	public:
		NInt IndexOf(const BerTag & tag) const
		{
			NInt index;
			NCheck(ConstructedBerTlvFindDataObjectIndex(this->GetOwnerHandle(), tag.GetValue(), &index));
			return index;
		}

		bool Contains(const BerTag & tag) const
		{
			return IndexOf(tag) != -1;
		}

		BerTlv Get(const BerTag & tag) const
		{
			HBerTlv hDataObject;
			NCheck(ConstructedBerTlvFindDataObjectEx(this->GetOwnerHandle(), tag.GetValue(), &hDataObject));
			return FromHandle<BerTlv>(hDataObject, true);
		}

		BerTlv operator[](const BerTag & tag) const
		{
			return Get(tag);
		}
	};

public:
	DataObjectCollection GetDataObjects()
	{
		return DataObjectCollection(*this);
	}

	const DataObjectCollection GetDataObjects() const
	{
		return DataObjectCollection(*this);
	}
};

}}

#endif // !CONSTRUCTED_BER_TLV_HPP_INCLUDED
