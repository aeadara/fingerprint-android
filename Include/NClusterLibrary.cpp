#ifndef N_CLUSTER_LIBRARY_CPP_INCLUDED
#define N_CLUSTER_LIBRARY_CPP_INCLUDED

#include <NCoreLibrary.cpp>

#include <NCluster.hpp>

namespace Neurotec { namespace Cluster
{

void ThrowException(int errorCode)
{
	NThrowException(NString::Format(N_T("Cluster error: {I}"), errorCode));
}

void Communication::Connect(const NStringWrapper & server, int port)
{
	cluster_status_code_e result;
	_my_socket = cluster_sock_connect(&result, server.GetString().GetBufferA(), NString::Format(N_T("{I}"), port).GetBufferA());
	Check(result);
}

}}

#endif // !N_CLUSTER_LIBRARY_CPP_INCLUDED
