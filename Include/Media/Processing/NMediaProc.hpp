#ifndef N_MEDIA_PROC_HPP_INCLUDED
#define N_MEDIA_PROC_HPP_INCLUDED

#include <Media/NMedia.hpp>
namespace Neurotec { namespace Media { namespace Processing
{
#include <Media/Processing/NMediaProc.h>
}}}

namespace Neurotec { namespace Media { namespace Processing
{

class NMediaProc
{
private:
	NMediaProc()
	{
	}

	N_DECLARE_MODULE_CLASS(NMediaProc)
};

}}}

#endif // !N_MEDIA_PROC_HPP_INCLUDED
