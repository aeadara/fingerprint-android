#ifndef IHEAD_HPP_INCLUDED
#define IHEAD_HPP_INCLUDED

#include <Images/NImage.hpp>
namespace Neurotec { namespace Images
{
#include <Images/IHead.h>
}}

namespace Neurotec { namespace Images
{

class IHeadInfo : public NImageInfo
{
	N_DECLARE_OBJECT_CLASS(IHeadInfo, NImageInfo)
};

}}

#endif // !IHEAD_HPP_INCLUDED
