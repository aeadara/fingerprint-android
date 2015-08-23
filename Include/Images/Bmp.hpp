#ifndef BMP_HPP_INCLUDED
#define BMP_HPP_INCLUDED

#include <Images/NImage.hpp>
namespace Neurotec { namespace Images
{
#include <Images/Bmp.h>
}}
#if defined(N_FRAMEWORK_MFC)
	#include <afxstr.h>
	#include <atlimage.h>
#elif defined(N_FRAMEWORK_WX)
	#include <wx/image.h>
#endif

namespace Neurotec { namespace Images
{

class BmpInfo : public NImageInfo
{
	N_DECLARE_OBJECT_CLASS(BmpInfo, NImageInfo)
};

}}

#endif // !BMP_HPP_INCLUDED
