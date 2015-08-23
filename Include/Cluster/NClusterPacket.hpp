#ifndef N_CLUSTER_PACKET_HPP_INCLUDED
#define N_CLUSTER_PACKET_HPP_INCLUDED

#include <Core/NTypes.hpp>
#include <Cluster/NCluster.hpp>
#include <Cluster/NClusterParameters.hpp>

namespace Neurotec { namespace Cluster
{
	typedef struct _NodeInfo
	{
		// Cluster node id.
		int id;
		// One of the ClusterNodeState values.
		cluster_node_state_e state;
	} NodeInfo;


	typedef struct _WorkingNodeInfo
	{
		// Cluster node id.
		int nodeId;
		// Nodes progress of matching task.
		int progress;
	} WorkingNodeInfo;


	class TaskInfo
	{
	public:
		// Id of matching task.
		int taskId;
		// Number of nodes that have finished matching task execution.
		int nodesCompleted;
		// Total number of nodes executing matching task.
		int workingNodes;
		// Matching task execution progress.
		int taskProgress;
		// Information about nodes executing matching task.
		WorkingNodeInfo * workingNodeInfo;
		int workingNodeInfoCount;
		TaskInfo()
		{
			workingNodeInfo = NULL;
			workingNodeInfoCount = 0;
			taskProgress = 0;
			workingNodes = 0;
			nodesCompleted = 0;
			taskId = 0;
		}

		~TaskInfo()
		{
			if (workingNodeInfo) delete workingNodeInfo;
		}
	};


	typedef struct _TaskShortInfo
	{
		// Id of matching task.
		int taskId;
		// Number of nodes that have finished matching task execution.
		int nodesCompleted;
		// Total number of nodes executing matching task.
		int workingNodes;
		// Matching task execution progress.
		int taskProgress;
	} TaskShortInfo;

	class ClusterResults
	{
		public:
		// Result identification string.
		char * id;
		// Serialized match details. See
		// Neurotec.Biometrics.NMMatchDetails.
		char * md;
		NSizeType mdSize;
		// Result similarity.
		int similarity;

		ClusterResults()
		{
			id = NULL;
			md = NULL;
			mdSize = 0;
			similarity = 0;
		}

		~ClusterResults()
		{
			if (id) delete id;
			if (md) delete md;
		}
	} ;



	class ClientPacket
	{
	public:
		client_handle_t * my_data;

	private:

		ClientPacket()
		{
			my_data = initialize_client_handle();

			if (my_data == NULL)
			{
				ThrowException(N_T("Failed to initialize handle"));
			}
		}

	public:
		static ClientPacket * CreateTask(cluster_task_mode_e mode, const void * templateBuffer, int templateSize, const char * query, int queryLength, MatchingParameters * parameters, int resultsLimit)
		{
			std::auto_ptr<ClientPacket> packet(new ClientPacket());
			void * parametersBuffer = NULL;
			NSizeType parametersBufferSize = 0;
			if (parameters != NULL)
			{
				parameters->GetBuffer(&parametersBuffer, &parametersBufferSize);
			}
			Check(cluster_packet_create_task(packet.get()->my_data, mode, templateSize, templateBuffer, queryLength, query, (int)parametersBufferSize, parametersBuffer, resultsLimit));
			return packet.release();
		}

		static ClientPacket * CreateTaskStandardTemplate(cluster_task_mode_e mode, void * templateBuffer, int templateSize, cluster_standard_template_type_e templateType, const char * query, int queryLength, MatchingParameters * parameters, int resultsLimit)
		{
			std::auto_ptr<ClientPacket> packet(new ClientPacket());
			void * parametersBuffer = NULL;
			NSizeType parametersBufferSize = 0;
			if (parameters != NULL)
			{
				parameters->GetBuffer(&parametersBuffer, &parametersBufferSize);
			}
			Check(cluster_packet_create_standard_template_task(packet->my_data, mode, templateSize, templateBuffer, templateType, queryLength, query, (int)parametersBufferSize, parametersBuffer, resultsLimit));
			return packet.release();
		}

		static ClientPacket * CreateProgressRequest(int taskID)
		{
			std::auto_ptr<ClientPacket> packet(new ClientPacket());
			Check(cluster_packet_create_progress_request(packet->my_data, taskID));
			return packet.release();
		}

		static ClientPacket * CreateResultRequest(int taskID, int lowRange, int highRange)
		{
			std::auto_ptr<ClientPacket> packet(new ClientPacket());
			Check(cluster_packet_create_result_request(packet->my_data, taskID, lowRange, highRange));
			return packet.release();
		}

		static ClientPacket * CreateResultDelete(int taskID)
		{
			std::auto_ptr<ClientPacket> packet(new ClientPacket());
			Check(cluster_packet_create_result_delete(packet->my_data, taskID));
			return packet.release();
		}

		~ClientPacket()
		{
			if (my_data != NULL)
			{
				finalize_client_handle(my_data);
				my_data = NULL;
			}
		}


	};

	class AdminPacket
	{

	public:
		admin_handle_t * my_data;

	private:

		AdminPacket()
		{
			my_data = initialize_admin_handle();
			if (my_data == NULL)
			{
				ThrowException(N_T("Failed to initialize handle"));
			}
		}


	public:
		static AdminPacket * CreatePacket_DatabaseFlush()
		{
			std::auto_ptr<AdminPacket> packet(new AdminPacket());
			Check(cluster_admin_database_flush(packet->my_data));
			return packet.release();
		}

		static AdminPacket * CreatePacket_DatabaseUpdate()
		{
			std::auto_ptr<AdminPacket> packet(new AdminPacket());
			Check(cluster_admin_database_update(packet->my_data));
			return packet.release();
		}

		static AdminPacket * CreatePacket_NodesInfoRequest()
		{
			std::auto_ptr<AdminPacket> packet(new AdminPacket());
			Check(cluster_admin_nodes_info_req(packet->my_data));
			return packet.release();
		}

		static AdminPacket * CreatePacket_ServerInfoRequest()
		{
			std::auto_ptr<AdminPacket> packet(new AdminPacket());
			Check(cluster_admin_server_info_req(packet->my_data));
			return packet.release();
		}

		static AdminPacket * CreatePacket_ResultsInfoRequest()
		{
			std::auto_ptr<AdminPacket> packet(new AdminPacket());
			Check(cluster_admin_results_info_req(packet->my_data));
			return packet.release();
		}

		static AdminPacket * CreatePacket_ServerKill()
		{
			std::auto_ptr<AdminPacket> packet(new AdminPacket());
			Check(cluster_admin_server_kill(packet->my_data));
			return packet.release();
		}

		static AdminPacket * CreatePacket_ServerStart()
		{
			std::auto_ptr<AdminPacket> packet(new AdminPacket());
			Check(cluster_admin_cluster_start(packet->my_data));
			return packet.release();
		}

		static AdminPacket * CreatePacket_TasksInfoRequest()
		{
			std::auto_ptr<AdminPacket> packet(new AdminPacket());
			Check(cluster_admin_tasks_complete_info_req(packet->my_data));
			return packet.release();
		}

		static AdminPacket * CreatePacket_TasksShortInfoRequest()
		{
			std::auto_ptr<AdminPacket> packet(new AdminPacket());
			Check(cluster_admin_tasks_short_info_req(packet->my_data));
			return packet.release();
		}


		static AdminPacket * CreatePacket_NodeStop(int nodeID)
		{
			std::auto_ptr<AdminPacket> packet(new AdminPacket());
			Check(cluster_admin_node_stop(packet->my_data, nodeID));
			return packet.release();
		}

		static AdminPacket * CreatePacket_NodeKill(int nodeID)
		{
			std::auto_ptr<AdminPacket> packet(new AdminPacket());
			Check(cluster_admin_node_kill(packet->my_data, nodeID));
			return packet.release();
		}

		static AdminPacket * CreatePacket_InsertRequest(int taskID)
		{
			std::auto_ptr<AdminPacket> packet(new AdminPacket());
			Check(cluster_admin_db_insert_result_request(packet->my_data, taskID));
			return packet.release();
		}


		static AdminPacket * CreatePacket_DeleteRequest(int taskID)
		{
			std::auto_ptr<AdminPacket> packet(new AdminPacket());
			Check(cluster_admin_db_delete_result_request(packet->my_data, taskID));
			return packet.release();
		}


		static AdminPacket * CreatePacket_InsertTemplates(NInt count, const int * idsLengths, const char* const* ids, const int * templatesLengths, const void* const* templates)
		{
			std::auto_ptr<AdminPacket> packet(new AdminPacket());
			Check(cluster_admin_insert_db_records(packet->my_data, count, idsLengths, ids, templatesLengths , templates));
			return packet.release();
		}

		static AdminPacket * CreatePacket_InsertTemplates(NInt count, NInt keyIndex, NInt valuesCount, const int ** valueTypes, const size_t ** valuesSizes, const void ** const * values)
		{
			std::auto_ptr<AdminPacket> packet(new AdminPacket());
			Check(cluster_admin_db_insert2(packet->my_data, (unsigned int)count, keyIndex, (size_t)valuesCount, valueTypes, valuesSizes, values));
			return packet.release();
		}

		static AdminPacket * CreatePacket_InsertTemplates(NInt count, const char* const* ids, const int * idsLengths, const int * templatesLengths, const void* const* templates, cluster_standard_template_type_e * templatesTypes)
		{
			std::auto_ptr<AdminPacket> packet(new AdminPacket());
			Check(cluster_admin_insert_standard_template_db_records(packet->my_data, count, idsLengths, ids, templatesLengths, templates, templatesTypes));
			return packet.release();
		}


		static AdminPacket * CreatePacket_DeleteTemplates(NInt count, const char* const* ids, const int * idsLengths)
		{
			std::auto_ptr<AdminPacket> packet(new AdminPacket());
			Check(cluster_admin_delete_db_records(packet->my_data, count, idsLengths, ids));
			return packet.release();
		}

		static AdminPacket * CreatePacket_UpdateDatabaseIDs(NInt count, const char** ids)
		{
			std::auto_ptr<AdminPacket> packet(new AdminPacket());
			Check(cluster_admin_change_db_records(packet->my_data, count, ids));
			return packet.release();
		}



	public:
		~AdminPacket()
		{
			if (my_data != NULL)
			{
				finalize_admin_handle(my_data);
				my_data = NULL;
			}
		}



	};






	class ClientPacketReceived
	{


	public:
		client_handle_t * my_data;

		ClientPacketReceived()
		{
			my_data = initialize_client_handle();
			if (my_data == NULL)
			{
				ThrowException(N_T("Failed to initialize handle"));
			}
		}


		int GetResultsStatus()
		{
			int status;
			Check(cluster_get_results_status(my_data, &status));
			return status;
		}

		int GetResultsProgress()
		{
			int progress;
			Check(cluster_get_results_progress(my_data, &progress));
			return progress;
		}

		NString GetResultsErrorString()
		{
			int length;
			Check(cluster_get_results_error_len(my_data, &length));
			if(length <= 0)
				return "";
			std::auto_ptr<char> errorBytes(new char[length]);
			Check(cluster_get_results_error_string(my_data, length, errorBytes.get()));
			return NString(errorBytes.get(), length);
		}


		void GetResults(int * resultsCount, ClusterResults ** results)
		{
			*resultsCount = 0;
			Check(cluster_get_results_count(my_data, resultsCount));

			if (results)
			{
				std::auto_ptr<ClusterResults> res(new ClusterResults[*resultsCount]);

				for (int i = 0; i < *resultsCount; i++)
				{
					int id_len, md_len;
					Check(cluster_get_results_info(my_data, i, &id_len, &md_len));
					std::auto_ptr<char> id_str(new char[id_len + 1]);
					std::auto_ptr<char> md(new char[md_len]);
					id_str.get()[id_len] = '\0';

					Check(cluster_get_results_data(my_data, i, id_len + 1, id_str.get(), md_len, md.get()));
					Check(cluster_get_results_similarity(my_data, i, 0, NULL, &res.get()[i].similarity));

					res.get()[i].md = md.release();
					res.get()[i].mdSize = md_len;
					res.get()[i].id = id_str.release();
				}

				*results = res.release();
			}
		}


		void GetTaskProgress(int * progress, int * resultCount)
		{
			*progress = 0;
			*resultCount = 0;
			Check(cluster_get_task_progress(my_data, progress, resultCount));
		}


		int GetTaskID()
		{
			int taskID = 0;
			Check(cluster_get_task_id(my_data, &taskID));
			return taskID;
		}


		~ClientPacketReceived()
		{
			if (my_data)
			{
				finalize_client_handle(my_data);
				my_data = NULL;
			}
		}


	};




	class AdminPacketReceived
	{

	public:
		admin_handle_t * my_data;

		AdminPacketReceived()
		{
			my_data = initialize_admin_handle();
			if (my_data == NULL)
			{
				ThrowException(N_T("Failed to initialize handle"));
			}
		}


		void GetResults(int * resultCount, int ** results)
		{
			*resultCount = 0;
			if (results) *results = NULL;
			Check(cluster_get_admin_results_count(my_data, resultCount));

			if (results)
			{
				std::auto_ptr<int> res(new int[*resultCount]);

				for (int i = 0; i < *resultCount; i++)
				{
					int result_id;
					Check(cluster_get_admin_results_id(my_data, i, &result_id));
					res.get()[i] = result_id;

				}
				*results = res.release();
			}
		}


		void GetNodesInfo(int * nodesCount, NodeInfo ** info)
		{
			info = NULL;
			Check(cluster_get_admin_nodes_info_count(my_data, nodesCount));
			std::auto_ptr<NodeInfo> nodeInfo(new NodeInfo[*nodesCount]);
			for (int i = 0; i < *nodesCount; i++)
			{
				int node_id;
				cluster_node_state_e node_state;
				Check(cluster_get_admin_nodes_info(my_data, i, &node_id, &node_state));
				nodeInfo.get()[i].id = node_id;
				nodeInfo.get()[i].state = node_state;
			}
			*info = nodeInfo.release();
		}

		void GetTasksInfo(int * taskCount, TaskInfo ** info)
		{
			if (info) *info = NULL;
			Check(cluster_get_admin_tasks_complete_info_count(my_data, taskCount));
			std::auto_ptr<TaskInfo> taskInfo(new TaskInfo[*taskCount]);
			for (int i = 0; i < *taskCount; i++)
			{
				int task_id, nodes_completed, working_nodes, task_progress;
				Check(cluster_get_admin_tasks_complete_info(my_data, i, &task_id, &nodes_completed, &working_nodes, &task_progress));
				taskInfo.get()[i].taskId = task_id;
				taskInfo.get()[i].taskProgress = task_progress;
				taskInfo.get()[i].nodesCompleted = nodes_completed;
				taskInfo.get()[i].workingNodes = working_nodes;
				taskInfo.get()[i].workingNodeInfo = new WorkingNodeInfo[working_nodes];
				for (int j = 0; j < working_nodes; j++)
				{
					int node_id, node_progress;
					Check(cluster_get_admin_tasks_complete_info_node_info(my_data, i, j, &node_id, &node_progress));
					info[i]->workingNodeInfo[j].nodeId = node_id;
					info[i]->workingNodeInfo[j].progress = node_progress;
				}
			}
			*info = taskInfo.release();
		}


		void GetTasksShortInfo(int * taskCount, TaskShortInfo ** info)
		{
			if (info) *info = NULL;
			Check(cluster_get_admin_task_short_info_count(my_data, taskCount));
			if (info)
			{
				std::auto_ptr<TaskShortInfo> taskInfo(new TaskShortInfo[*taskCount]);
				for (int i = 0; i < *taskCount; i++)
				{
					int task_id, nodes_completed, working_nodes_count;
					Check(cluster_get_admin_tasks_short_info(my_data, i, &task_id, &nodes_completed, &working_nodes_count));
					taskInfo.get()[i].nodesCompleted = nodes_completed;
					taskInfo.get()[i].taskId = task_id;
					taskInfo.get()[i].workingNodes = working_nodes_count;
				}
				*info = taskInfo.release();
			}
		}


		cluster_server_status_e GetServerInfo()
		{
			cluster_server_status_e res;
			Check(cluster_admin_get_server_info(my_data, (int*)&res));
			return res;
		}


		int GetInsertTaskId()
		{
			int taskId;
			Check(cluster_admin_get_insert_task_id(my_data, &taskId));
			return taskId;
		}


		cluster_insert_delete_result_e GetInsertTaskResult()
		{
			cluster_insert_delete_result_e result;
			NCheck(cluster_admin_get_insert_task_result(my_data, (int*)&result));
			return result;
		}


		int GetInsertTaskBatchSize()
		{
			int batchSize;
			Check(cluster_admin_get_insert_task_batch_size(my_data, &batchSize));
			return batchSize;
		}


		cluster_insert_delete_status_e GetInsertTaskStatus(int templateIndex)
		{
			cluster_insert_delete_status_e status;
			Check(cluster_admin_get_insert_task_status(my_data, templateIndex, (int*)&status));
			return status;
		}


		NString GetInsertTaskError(int templateIndex)
		{
			char * error;
			int errorLen;
			Check(cluster_admin_get_insert_task_error(my_data, templateIndex, &errorLen, &error));
			return NString(error);
		}


		int GetDeleteTaskId()
		{
			int taskId;
			Check(cluster_admin_get_delete_task_id(my_data, &taskId));
			return taskId;
		}


		cluster_insert_delete_result_e GetDeleteTaskResult()
		{
			cluster_insert_delete_result_e result;
			Check(cluster_admin_get_delete_task_result(my_data, (int *)&result));
			return result;
		}


		int GetDeleteTaskBatchSize()
		{
			int batchSize;
			Check(cluster_admin_get_delete_task_batch_size(my_data, &batchSize));
			return batchSize;
		}


		cluster_insert_delete_status_e GetDeleteTaskStatus(int templateIndex)
		{
			cluster_insert_delete_status_e status;
			Check(cluster_admin_get_delete_task_status(my_data, templateIndex, (int*)&status));
			return status;
		}


		NString GetDeleteTaskError(int templateIndex)
		{
			char * error;
			int errorLen;
			Check(cluster_admin_get_delete_task_error(my_data, templateIndex, &errorLen, &error));
			return NString(error);
		}


		~AdminPacketReceived()
		{
			if (my_data != NULL)
			{
				finalize_admin_handle(my_data);
				my_data = NULL;
			}
		}

	};
}}

#endif // !NCLUSTERPACKET_HPP_INCLUDED
