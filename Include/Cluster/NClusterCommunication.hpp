#ifndef N_CLUSTER_COMMUNICATION_HPP_INCLUDED
#define N_CLUSTER_COMMUNICATION_HPP_INCLUDED

#include <Cluster/NCluster.hpp>
#include <Cluster/NClusterPacket.hpp>

namespace Neurotec { namespace Cluster
{
#include <Cluster/NCluster.h>
}}

namespace Neurotec { namespace Cluster
{
	class Communication
	{
	public:
		N_DEPRECATED("method is deprecated, do not use")
		static void Initialize()
		{
			Check(cluster_initialize());
		}

		N_DEPRECATED("method is deprecated, do not use")
		static void Finalize()
		{
			Check(cluster_finalize());
		}

	private:
		cluster_socket_t * _my_socket;
	public:

		Communication()
		{
		}

		Communication(const NStringWrapper & server, int port)
		{
			Connect(server, port);
		}

		void Connect(const NStringWrapper & server, int port);

		void Close()
		{
			Check(cluster_sock_close(_my_socket));
			_my_socket = NULL;
		}

	private:
		void SendPacket(void * packet)
		{
			Check(cluster_packet_send(packet, _my_socket));
		}

	public:
		void SendPacket(ClientPacket * packet)
		{
			SendPacket(packet->my_data);
		}

		void SendPacket(AdminPacket * packet)
		{
			SendPacket(packet->my_data);
		}

		void SendReceivePacket(ClientPacket * packet_in, ClientPacketReceived ** received_packet)
		{
			*received_packet = NULL;
			SendPacket(packet_in);
			ReceivePacket(received_packet);
		}

		void SendReceivePacket(AdminPacket * packet_in, AdminPacketReceived ** received_packet)
		{
			*received_packet = NULL;
			SendPacket(packet_in);
			ReceivePacket(received_packet);
		}

	private:
		void ReceivePacket(AdminPacketReceived ** received_packet)
		{
			*received_packet = new AdminPacketReceived();
			Check(cluster_packet_recv((*received_packet)->my_data, _my_socket));
		}

		void ReceivePacket(ClientPacketReceived ** received_packet)
		{
			*received_packet = new ClientPacketReceived();
			Check(cluster_packet_recv((*received_packet)->my_data, _my_socket));
		}
	};

}}

#endif // !N_CLUSTER_COMMUNICATION_HPP_INCLUDED
