#include <Core/NObjectPartBase.hpp>

#ifndef N_COLLECTIONS_HPP_INCLUDED
#define N_COLLECTIONS_HPP_INCLUDED

#include <Core/NType.hpp>
#include <Core/NObject.hpp>
#include <Core/NError.hpp>

namespace Neurotec
{
#include <Core/NObjectPart.h>
#include <Core/NArray.h>
namespace Collections
{
#include <Collections/NCollection.h>
}
}
#include <memory.h>

#include <Core/NNoDeprecate.h>

namespace Neurotec { namespace Collections
{
template<typename T, typename TOwner,
	NResult (N_CALLBACK pGetCount)(typename TOwner::HandleType, NInt * pValue),
	NResult (N_CALLBACK pGet)(typename TOwner::HandleType, NInt index, typename NTypeTraits<T>::NativeType * pValue)
 > class NCollectionBase : public NObjectPartBase<TOwner>
{
public:
	typedef T value_type;
	typedef T * pointer;
	typedef T const * const_pointer;
	typedef T & reference;
	typedef T const & const_reference;
	typedef typename NTypeTraits<T>::NativeType native_type;
	typedef typename TOwner::HandleType OwnerHandleType;
	typedef NCollectionIterator<NCollectionBase, value_type> iterator;
	typedef NConstCollectionIterator<NCollectionBase, value_type> const_iterator;
	typedef NCollectionIterator<NCollectionBase, value_type> reverse_iterator;
	typedef NConstCollectionIterator<NCollectionBase, value_type> reverse_const_iterator;

protected:
	NCollectionBase()
	{
	}

public:
	NInt GetCount() const
	{
		NInt value;
		NCheck(pGetCount(this->GetOwnerHandle(), &value));
		return value;
	}

	T Get(NInt index) const
	{
		native_type nativeValue;
		NCheck(pGet(this->GetOwnerHandle(), index, &nativeValue));
		return NTypeTraits<T>::FromNative(nativeValue, true);
	}

	T operator[](NInt index) const
	{
		return Get(index);
	}

	NInt IndexOf(const_reference value) const
	{
		NInt count = GetCount();
		for (NInt i = 0; i < count; i++)
		{
			if (value == Get(i))
				return i;
		}
		return -1;
	}

	bool Contains(const_reference value) const
	{
		return IndexOf(value) != -1;
	}

	iterator begin()
	{
		return iterator(*this, 0);
	}

	const_iterator begin() const
	{
		return const_iterator(*this, 0);
	}

	iterator end()
	{
		return iterator(*this, GetCount());
	}

	const_iterator end() const
	{
		return const_iterator(*this, GetCount());
	}

	reverse_iterator rbegin()
	{
		return reverse_iterator(*this, GetCount() - 1, true);
	}

	reverse_const_iterator rbegin() const
	{
		return reverse_const_iterator(*this, GetCount() - 1, true);
	}

	reverse_iterator rend()
	{
		return reverse_iterator(*this, 0, true);
	}

	reverse_const_iterator rend() const
	{
		return reverse_const_iterator(*this, 0, true);
	}
};

template<typename T, typename TOwner,
	NResult (N_CALLBACK pGetCount)(typename TOwner::HandleType, NInt * pValue),
	NResult (N_CALLBACK pGet)(typename TOwner::HandleType, NInt index, typename NTypeTraits<T>::NativeType * pValue),
	NResult (N_CALLBACK pGetAllOut)(typename TOwner::HandleType, typename NTypeTraits<T>::NativeType * * arValue, NInt * pValueCount) = (NResult (*)(typename TOwner::HandleType, typename NTypeTraits<T>::NativeType * *, NInt *))NULL
 > class NCollectionWithAllOutBase : public NCollectionBase<T, TOwner, pGetCount, pGet>
{
protected:
	NCollectionWithAllOutBase()
	{
	}

public:
	NArrayWrapper<T> GetAll() const
	{
		typename NTypeTraits<T>::NativeType * arNative = NULL;
		NInt nativeCount = 0;
		NCheck(pGetAllOut(this->GetOwnerHandle(), &arNative, &nativeCount));
		return NArrayWrapper<T>(arNative, nativeCount);
	}
};

template<typename T,
	NResult (N_CALLBACK pGetCount)(NInt * pValue),
	NResult (N_CALLBACK pGet)(NInt index, typename NTypeTraits<T>::NativeType * pValue)
 > class NStaticCollectionBase
{
public:
	typedef T value_type;
	typedef T * pointer;
	typedef T const * const_pointer;
	typedef T & reference;
	typedef T const & const_reference;
	typedef typename NTypeTraits<T>::NativeType native_type;
	typedef NCollectionIterator<NStaticCollectionBase, value_type> iterator;
	typedef NConstCollectionIterator<NStaticCollectionBase, value_type> const_iterator;
	typedef NCollectionIterator<NStaticCollectionBase, value_type> reverse_iterator;
	typedef NConstCollectionIterator<NStaticCollectionBase, value_type> reverse_const_iterator;

protected:
	NStaticCollectionBase()
	{
	}

public:
	NInt GetCount() const
	{
		NInt value;
		NCheck(pGetCount(&value));
		return value;
	}

	T Get(NInt index) const
	{
		native_type nativeValue;
		NCheck(pGet(index, &nativeValue));
		return NTypeTraits<T>::FromNative(nativeValue, true);
	}

	T operator[](NInt index) const
	{
		return Get(index);
	}

	NInt IndexOf(const_reference value) const
	{
		NInt count = GetCount();
		for (NInt i = 0; i < count; i++)
		{
			if (value == Get(i))
				return i;
		}
		return -1;
	}

	bool Contains(const_reference value) const
	{
		return IndexOf(value) != -1;
	}

	iterator begin()
	{
		return iterator(*this, 0);
	}

	const_iterator begin() const
	{
		return const_iterator(*this, 0);
	}

	iterator end()
	{
		return iterator(*this, GetCount());
	}

	const_iterator end() const
	{
		return const_iterator(*this, GetCount());
	}

	reverse_iterator rbegin()
	{
		return reverse_iterator(*this, GetCount() - 1, true);
	}

	reverse_const_iterator rbegin() const
	{
		return reverse_const_iterator(*this, GetCount() - 1, true);
	}

	reverse_iterator rend()
	{
		return reverse_iterator(*this, 0, true);
	}

	reverse_const_iterator rend() const
	{
		return reverse_const_iterator(*this, 0, true);
	}
};

template<typename T>
class CollectionChangedEventArgs : public EventArgs
{
private:
	NCollectionChangedAction action;
	NInt newIndex;
	const void * arNewItems;
	NInt newItemCount;
	NInt oldIndex;
	const void * arOldItems;
	NInt oldItemCount;
public:
	CollectionChangedEventArgs(HNObject hObject, NCollectionChangedAction action, NInt newIndex, const void * arNewItems, NInt newItemCount,
		NInt oldIndex, const void * arOldItems, NInt oldItemCount, void * pParam)
		: EventArgs(hObject, pParam)
	{
		this->action = action;
		this->newIndex = newIndex;
		this->arNewItems = arNewItems;
		this->newItemCount = newItemCount;
		this->oldIndex = oldIndex;
		this->arOldItems = arOldItems;
		this->oldItemCount = oldItemCount;
	}

public:
	NCollectionChangedAction GetAction() const
	{
		return action;
	}

	NInt GetNewIndex() const
	{
		return newIndex;
	}

	NArrayWrapper<T> GetNewItems() const
	{
		return NArrayWrapper<T>((typename NTypeTraits<T>::NativeType *)arNewItems, newItemCount, false, false);
	}

	NInt GetOldIndex() const
	{
		return oldIndex;
	}

	NArrayWrapper<T> GetOldItems() const
	{
		return NArrayWrapper<T>((typename NTypeTraits<T>::NativeType *)arOldItems, oldItemCount, false, false);
	}
};

template<typename T, typename F>
class CollectionChangedEventHandler : public EventHandlerBase<F>
{
public:
	CollectionChangedEventHandler(const F & callback)
		: EventHandlerBase<F>(callback)
	{
	}

	static NResult N_API NativeCallback(HNObject hObject, NCollectionChangedAction action, NInt newIndex, const void * arNewItems, NInt newItemCount,
		NInt oldIndex, const void * arOldItems, NInt oldItemCount, void * pParam)
	{
		NResult result = N_OK;
		try
		{
			CollectionChangedEventHandler * pHandler = static_cast<CollectionChangedEventHandler *>(pParam);
			CollectionChangedEventArgs<T> e(hObject, action, newIndex, arNewItems, newItemCount,
				oldIndex, arOldItems, oldItemCount, pHandler->pParam);
			pHandler->callback(e);
		}
		N_EXCEPTION_CATCH_AND_SET_LAST(result);
		return result;
	};
};

template<typename T>
class ItemCollectionChangedEventArgs : public EventArgs
{
private:
	NCollectionChangedAction action;
	NInt newIndex;
	HNArray hNewItems;
	NInt oldIndex;
	HNArray hOldItems;
public:
	ItemCollectionChangedEventArgs(HNObject hObject, NCollectionChangedAction action, NInt newIndex, HNArray hNewItems,
		NInt oldIndex, HNArray hOldItems, void * pParam)
		: EventArgs(hObject, pParam)
	{
		this->action = action;
		this->newIndex = newIndex;
		this->hNewItems = hNewItems;
		this->oldIndex = oldIndex;
		this->hOldItems = hOldItems;
	}

public:
	NCollectionChangedAction GetAction() const
	{
		return action;
	}

	NInt GetNewIndex() const
	{
		return newIndex;
	}

	T GetNewItems() const
	{
		return NTypeTraits<T>::FromNative(hNewItems, false);
	}

	NInt GetOldIndex() const
	{
		return oldIndex;
	}

	T GetOldItems() const
	{
		return NTypeTraits<T>::FromNative(hOldItems, false);
	}
};

template<typename F>
class ItemCollectionChangedEventHandler : public EventHandlerBase<F>
{
public:
	ItemCollectionChangedEventHandler(const F & callback)
		: EventHandlerBase<F>(callback)
	{
	}

	static NResult N_API NativeCallback(HNObject hObject, NCollectionChangedAction action, NInt newIndex, HNArray hNewItems,
		NInt oldIndex, HNArray hOldItems, void * pParam)
	{
		NResult result = N_OK;
		try
		{
			ItemCollectionChangedEventHandler * pHandler = static_cast<ItemCollectionChangedEventHandler *>(pParam);
			ItemCollectionChangedEventArgs<NArray> e(hObject, action, newIndex, hNewItems,
				oldIndex, hOldItems, pHandler->pParam);
			pHandler->callback(e);
		}
		N_EXCEPTION_CATCH_AND_SET_LAST(result);
		return result;
	};
};

template<typename T, typename TOwner,
	NResult (N_CALLBACK pGetCount)(typename TOwner::HandleType, NInt * pValue),
	NResult (N_CALLBACK pGet)(typename TOwner::HandleType, NInt index, typename NTypeTraits<T>::NativeType * pValue),
	NResult (N_CALLBACK pGetAllOut)(typename TOwner::HandleType, typename NTypeTraits<T>::NativeType * * arValue, NInt * pValueCount),
	NResult (N_CALLBACK pAddChangedCallback)(typename TOwner::HandleType, HNCallback hCallback),
	NResult (N_CALLBACK pRemoveChangedCallback)(typename TOwner::HandleType, HNCallback hCallback)
 > class NCollectionWithChangeNotifications : public NCollectionWithAllOutBase<T, TOwner, pGetCount, pGet, pGetAllOut>
{
protected:
	NCollectionWithChangeNotifications()
	{
	}

public:
	void AddCollectionChangedCallback(const NCallback & callback) const
	{
		NCheck(pAddChangedCallback(this->GetOwnerHandle(), callback.GetHandle()));
	}

	template<typename F>
	NCallback AddCollectionChangedCallback(const F & callback, void * pParam = NULL) const
	{
		NCallback cb = NTypes::CreateCallback<CollectionChangedEventHandler<T, F> >(callback, pParam);
		AddCollectionChangedCallback(cb);
		return cb;
	}

	void RemoveCollectionChangedCallback(const NCallback & callback) const
	{
		NCheck(pRemoveChangedCallback(this->GetOwnerHandle(), callback.GetHandle()));
	}

	template<typename F>
	NCallback RemoveCollectionChangedCallback(const F & callback, void * pParam = NULL) const
	{
		NCallback cb = NTypes::CreateCallback<CollectionChangedEventHandler<T, F> >(callback, pParam);
		RemoveCollectionChangedCallback(cb);
		return cb;
	}
};

}}

#include <Core/NReDeprecate.h>

#endif // !N_COLLECTIONS_HPP_INCLUDED
