#ifndef N_CLUSTER_HPP_INCLUDED
#define N_CLUSTER_HPP_INCLUDED

#include <Core/NCore.hpp>

namespace Neurotec { namespace Cluster
{
#include <Cluster/NCluster.h>
}}

namespace Neurotec { namespace Cluster
{
	void ThrowException(int errorCode);

	inline void ThrowException(const NStringWrapper & error)
	{
		NThrowException(error);
	}

	inline void Check(cluster_status_code_e res)
	{
		if (res != CLUSTER_OK) ThrowException(res);
	}

}}

#endif // !N_CLUSTER_HPP_INCLUDED
