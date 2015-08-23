#ifndef N_GEOMETRY_HPP_INCLUDED
#define N_GEOMETRY_HPP_INCLUDED

#include <Core/NTypes.hpp>
namespace Neurotec { namespace Geometry
{
#include <Geometry/NGeometry.h>
}}

N_DEFINE_ENUM_TYPE_TRAITS(Neurotec::Geometry, NInterpolationMode)

namespace Neurotec { namespace Geometry
{

class NPoint : public NPoint_
{
	N_DECLARE_STRUCT_CLASS(NPoint)

public:
	NPoint(NInt x, NInt y)
	{
		X = x;
		Y = y;
	}
};

class NPointF : public NPointF_
{
	N_DECLARE_STRUCT_CLASS(NPointF)

public:
	NPointF(NFloat x, NFloat y)
	{
		X = x;
		Y = y;
	}
};

class NPointD : public NPointD_
{
	N_DECLARE_STRUCT_CLASS(NPointD)

public:
	NPointD(NDouble x, NDouble y)
	{
		X = x;
		Y = y;
	}
};

class NSize : public NSize_
{
	N_DECLARE_STRUCT_CLASS(NSize)

public:
	NSize(NInt width, NInt height)
	{
		Width = width;
		Height = height;
	}
};

class NSizeF : public NSizeF_
{
	N_DECLARE_STRUCT_CLASS(NSizeF)

public:
	NSizeF(NFloat width, NFloat height)
	{
		Width = width;
		Height = height;
	}
};

class NSizeD : public NSizeD_
{
	N_DECLARE_STRUCT_CLASS(NSizeD)

public:
	NSizeD(NDouble width, NDouble height)
	{
		Width = width;
		Height = height;
	}
};

class NRect : public NRect_
{
	N_DECLARE_STRUCT_CLASS(NRect)

public:
	NRect(NInt x, NInt y, NInt width, NInt height)
	{
		X = x;
		Y = y;
		Width = width;
		Height = height;
	}
};

class NRectF : public NRectF_
{
	N_DECLARE_STRUCT_CLASS(NRectF)

public:
	NRectF(NFloat x, NFloat y, NFloat width, NFloat height)
	{
		X = x;
		Y = y;
		Width = width;
		Height = height;
	}
};

class NRectD : public NRectD_
{
	N_DECLARE_STRUCT_CLASS(NRectD)

public:
	NRectD(NDouble x, NDouble y, NDouble width, NDouble height)
	{
		X = x;
		Y = y;
		Width = width;
		Height = height;
	}
};

class NGeometry
{
	N_DECLARE_STATIC_OBJECT_CLASS(NGeometry)

public:
	static NType NInterpolationModeNativeTypeOf()
	{
		return NObject::GetObject<NType>(N_TYPE_OF(NInterpolationMode), true);
	}
};

}}

N_DEFINE_STRUCT_TYPE_TRAITS(Neurotec::Geometry, NPoint)
N_DEFINE_STRUCT_TYPE_TRAITS(Neurotec::Geometry, NPointF)
N_DEFINE_STRUCT_TYPE_TRAITS(Neurotec::Geometry, NPointD)
N_DEFINE_STRUCT_TYPE_TRAITS(Neurotec::Geometry, NSize)
N_DEFINE_STRUCT_TYPE_TRAITS(Neurotec::Geometry, NSizeF)
N_DEFINE_STRUCT_TYPE_TRAITS(Neurotec::Geometry, NSizeD)
N_DEFINE_STRUCT_TYPE_TRAITS(Neurotec::Geometry, NRect)
N_DEFINE_STRUCT_TYPE_TRAITS(Neurotec::Geometry, NRectF)
N_DEFINE_STRUCT_TYPE_TRAITS(Neurotec::Geometry, NRectD)

#endif // !N_GEOMETRY_HPP_INCLUDED
