#ifndef N_CORE_LIBRARY_CPP_INCLUDED
#define N_CORE_LIBRARY_CPP_INCLUDED

#include <NCore.hpp>

using namespace ::Neurotec::Collections;
using namespace ::Neurotec::Plugins;
using namespace ::Neurotec::Plugins::ComponentModel;
using namespace ::Neurotec::IO;

namespace Neurotec
{
}

#if defined(N_CLANG) && defined(N_CPP11)

void * operator new(size_t size, const std::nothrow_t &) noexcept
{
	void * pObject;
	Neurotec::NAlloc(size, &pObject);
	return pObject;
}

void operator delete(void * pObject, const std::nothrow_t &) noexcept
{
	Neurotec::NFree(pObject);
}

void * operator new[](size_t size, const std::nothrow_t &) noexcept
{
	void * pObject;
	Neurotec::NAlloc(size, &pObject);
	return pObject;
}

void operator delete[](void * pObject, const std::nothrow_t &) noexcept
{
	Neurotec::NFree(pObject);
}

void * operator new(size_t size, const Neurotec::Clear &)
{
	return Neurotec::NCAlloc(size);
}

void operator delete(void * pObject, const Neurotec::Clear &)
{
	Neurotec::NFree(pObject);
}

void * operator new[](size_t size, const Neurotec::Clear &)
{
	return Neurotec::NCAlloc(size);
}

void operator delete[](void * pObject, const Neurotec::Clear &)
{
	Neurotec::NFree(pObject);
}

void * operator new(size_t size, Neurotec::NSizeType alignment, Neurotec::NSizeType offset)
{
	return Neurotec::NAlignedAlloc(size, alignment, offset);
}

void operator delete(void * pObject, Neurotec::NSizeType alignment, Neurotec::NSizeType offset)
{
	Neurotec::NAlignedFree(pObject);
	N_UNREFERENCED_PARAMETER(alignment);
	N_UNREFERENCED_PARAMETER(offset);
}

void * operator new[](size_t size, Neurotec::NSizeType alignment, Neurotec::NSizeType offset)
{
	return Neurotec::NAlignedAlloc(size, alignment, offset);
}

void operator delete[](void * pObject, Neurotec::NSizeType alignment, Neurotec::NSizeType offset)
{
	Neurotec::NAlignedFree(pObject);
	N_UNREFERENCED_PARAMETER(alignment);
	N_UNREFERENCED_PARAMETER(offset);
}

void * operator new(size_t size, Neurotec::NSizeType alignment, Neurotec::NSizeType offset, const Neurotec::Clear &)
{
	return Neurotec::NAlignedCAlloc(size, alignment, offset);
}

void operator delete(void * pObject, Neurotec::NSizeType alignment, Neurotec::NSizeType offset, const Neurotec::Clear &)
{
	Neurotec::NAlignedFree(pObject);
	N_UNREFERENCED_PARAMETER(alignment);
	N_UNREFERENCED_PARAMETER(offset);
}

void * operator new[](size_t size, Neurotec::NSizeType alignment, Neurotec::NSizeType offset, const Neurotec::Clear &)
{
	return Neurotec::NAlignedCAlloc(size, alignment, offset);
}

void operator delete[](void * pObject, Neurotec::NSizeType alignment, Neurotec::NSizeType offset, const Neurotec::Clear &)
{
	Neurotec::NAlignedFree(pObject);
	N_UNREFERENCED_PARAMETER(alignment);
	N_UNREFERENCED_PARAMETER(offset);
}

#endif

#endif // !N_CORE_LIBRARY_CPP_INCLUDED
