#ifndef N_IO_TYPES_HPP_INCLUDED
#define N_IO_TYPES_HPP_INCLUDED

#include <Core/NTypes.hpp>
namespace Neurotec { namespace IO
{
#include <IO/NIOTypes.h>
}}

N_DEFINE_ENUM_TYPE_TRAITS(Neurotec::IO, NByteOrder)
N_DEFINE_ENUM_TYPE_TRAITS(Neurotec::IO, NSeekOrigin)
N_DEFINE_ENUM_TYPE_TRAITS(Neurotec::IO, NFileMode)
N_DEFINE_ENUM_TYPE_TRAITS(Neurotec::IO, NFileAccess)
N_DEFINE_ENUM_TYPE_TRAITS(Neurotec::IO, NFileShare)

namespace Neurotec { namespace IO
{

class NIOTypes
{
	N_DECLARE_STATIC_OBJECT_CLASS(NIOTypes)

public:
	static NType NByteOrderNativeTypeOf()
	{
		return NObject::GetObject<NType>(N_TYPE_OF(NByteOrder), true);
	}

	static NType NSeekOriginNativeTypeOf()
	{
		return NObject::GetObject<NType>(N_TYPE_OF(NSeekOrigin), true);
	}

	static NType NFileModeNativeTypeOf()
	{
		return NObject::GetObject<NType>(N_TYPE_OF(NFileMode), true);
	}

	static NType NFileAccessNativeTypeOf()
	{
		return NObject::GetObject<NType>(N_TYPE_OF(NFileAccess), true);
	}

	static NType NFileShareNativeTypeOf()
	{
		return NObject::GetObject<NType>(N_TYPE_OF(NFileShare), true);
	}

	static bool IsByteOrderValid(NByteOrder value)
	{
		return NByteOrderIsValid(value) != 0;
	}

	static NByteOrder GetByteOrderSystem()
	{
		return NByteOrderGetSystem();
	}

	static bool IsByteOrderReverse(NByteOrder value)
	{
		return NByteOrderIsReverse(value) != 0;
	}

	static bool IsSeekOriginValid(NSeekOrigin value)
	{
		return NSeekOriginIsValid(value) != 0;
	}

	static bool IsFileModeValid(NFileMode value)
	{
		return NFileModeIsValid(value) != 0;
	}

	static bool IsFileAccessValid(NFileAccess value)
	{
		return NFileAccessIsValid(value) != 0;
	}

	static bool IsFileShareValid(NFileShare value)
	{
		return NFileShareIsValid(value) != 0;
	}
};

}}

#endif // !N_IO_TYPES_HPP_INCLUDED
