#ifndef TIFF_HPP_INCLUDED
#define TIFF_HPP_INCLUDED

#include <Images/NImage.hpp>
namespace Neurotec { namespace Images
{
#include <Images/Tiff.h>
}}

namespace Neurotec { namespace Images
{

class TiffInfo : public NImageInfo
{
	N_DECLARE_OBJECT_CLASS(TiffInfo, NImageInfo)
};

}}

#endif // !TIFF_HPP_INCLUDED
