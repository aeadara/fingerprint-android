#ifndef N_MEDIA_HPP_INCLUDED
#define N_MEDIA_HPP_INCLUDED

#include <Core/NCore.hpp>
namespace Neurotec { namespace Media
{
#include <Media/NMedia.h>
}}

namespace Neurotec { namespace Media
{

class NMedia
{
private:
	NMedia()
	{
	}

	N_DECLARE_MODULE_CLASS(NMedia)
};

}}

#endif // !N_MEDIA_HPP_INCLUDED
