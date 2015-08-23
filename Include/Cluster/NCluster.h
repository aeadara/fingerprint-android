#ifndef N_CLUSTER_H_INCLUDED
#define N_CLUSTER_H_INCLUDED

#include <Core/NCore.h>

#ifdef __cplusplus
extern "C"
{
#endif

N_DECLARE_MODULE(NCluster)

typedef struct _client_handle_t client_handle_t;
typedef struct _admin_handle_t admin_handle_t;

//typedef struct _cluster_packet_t cluster_packet_t;
typedef struct _cluster_socket_t cluster_socket_t;

typedef struct cluster_task_params_s cluster_task_params_t;

/*
 * Receiving packet types
 */
typedef enum _cluster_packet_type_e
{
	CLUSTER_PACKET_TASK_ID = 2,
	CLUSTER_PACKET_RESULT = 5,
	CLUSTER_PACKET_ADMIN_COMPLETE_INFO = 23,
	CLUSTER_PACKET_ADMIN_SHORT_INFO = 24,
	CLUSTER_PACKET_ADMIN_NODES_INFO = 25,
	CLUSTER_PACKET_ADMIN_RESULTS_INFO = 26,
	CLUSTER_PACKET_ADMIN_SERVER_INFO = 36,
	CLUSTER_PACKET_TASK_PROGRESS = 28
} cluster_packet_type_e;

/*
 * Error codes returned by client library
 */
typedef enum _cluster_status_code_e
{
	CLUSTER_OK = 0,
	CLUSTER_INTERNAL_ERROR = 1,
	CLUSTER_ARGUMENT_ERROR = 2,
	CLUSTER_EXTRACTION_ERROR = 3,
	CLUSTER_PACKET_ERROR = 4,
	CLUSTER_ALGORITHM_ERROR = 5,
	CLUSTER_HANDLE_ERROR = 6,
	CLUSTER_NOT_REGISTERED_ERROR = N_E_NOT_ACTIVATED
} cluster_status_code_e;

/*
 * Task match modes
 */
typedef enum _cluster_task_mode_e
{
	CLUSTER_NORMAL  = 0,		/* < return all results from database */
	CLUSTER_FIRST   = (1<<0),	/* < return first which match search criteria */
	CLUSTER_DETAILS = (1<<1)	/* < return match details */
} cluster_task_mode_e;

/*
 * Template type
 */
typedef enum _cluster_standard_template_type_e
{
	CLUSTER_TEMPLATE_ISO = 0,		/* ISO standard template */
	CLUSTER_TEMPLATE_ANSI = 1,		/* ANSI standard template */
} cluster_standard_template_type_e;

/*
 * Cluster node state
 */
typedef enum _cluster_node_state_e
{
	CLUSTER_NODE_STARTING = 1,
	CLUSTER_NODE_READY = 2,
	CLUSTER_NODE_REMOVING = 3,
	CLUSTER_NODE_SPARE = 4
} cluster_node_state_e;

typedef enum _cluster_server_status_e
{
	CLUSTER_SERVER_STATUS_PREPARING,
	CLUSTER_SERVER_STATUS_READY,
	CLUSTER_SERVER_STATUS_ERROR,
} cluster_server_status_e;

typedef enum _cluster_insert_delete_result_e
{
	CLUSTER_INSERT_DELETE_SERVER_NOT_READY = -2,
	CLUSTER_INSERT_DELETE_FAILED = -1,
	CLUSTER_INSERT_DELETE_WAITING = 0,
	CLUSTER_INSERT_DELETE_SUCCEEDED = 1,
	CLUSTER_INSERT_DELETE_PARTIALLY_SUCCEEDED = 2,
} cluster_insert_delete_result_e;

typedef enum _cluster_insert_delete_status_e
{
	CLUSTER_INSERT_DELETE_STATUS_NONE = 0,
	CLUSTER_INSERT_DELETE_STATUS_OK = 1,
	CLUSTER_INSERT_DELETE_STATUS_INTERNAL_ERROR = 2,
	CLUSTER_INSERT_DELETE_STATUS_INVALID_FORMAT = 3,
	CLUSTER_INSERT_DELETE_STATUS_DATABASE_ERROR = 4,
	CLUSTER_INSERT_DELETE_STATUS_DUPLICATE_ID = 5,
} cluster_insert_delete_status_e;

/*
 * Generic Cluster functions
 */


/*
 * Initializes cluster library. Call before any other cluster function.
 * @return CLUSTER_OK on success and other cluster_status_code_e on error
 */
cluster_status_code_e N_API cluster_initialize(void);

/*
 * De-initializes cluster library. Call after all other cluster functions are finished.
 * @return CLUSTER_OK on success and other cluster_status_code_e on error
 */
cluster_status_code_e N_API cluster_finalize(void);

/*
 * Connects to cluster server
 * param[out] code Cluster status code
 * param[in] server Server address
 * param[in] port Server port
 * @return pointer to cluster_sock_t and NULL on error and set code to
 * cluster_status_code_e
 */
cluster_socket_t * N_API_PTR_RET cluster_sock_connect(cluster_status_code_e *code, const char *server, const char *port);

/*
 * Connection mode
 */
typedef enum _cluster_connect_mode_e
{
	/* Connects to servers in random order */
	CLUSTER_CONNECT_RANDOM = 1,
	/* Connects to servers in consequent order */
	CLUSTER_CONNECT_CONSEQUENTLY = 2,
} cluster_connect_mode_e;

/*
 * Connects to one of cluster servers.
 *
 * @warning This function is experimental and can be changed in the near
 * future.
 *
 * It lets to use one of the few servers. If connection is failed then
 * tries connect to another server if tries counter lets. Also this
 * function can be used for balanced loading,
 * param[out] code Cluster status code
 * param[in] servers array of server addresses
 * param[in] ports array of server ports
 * param[in] servers_count count of records in servers, ports array
 * param[in] mode describes procedure of connection
 * param[in] tries maximum reconnection try count
 * param[out] connected_server_index returns of connected server's number
 * @return pointer to cluster_lib_sock_t and NULL on error and set code to
 * cluster_statues_code_e
 */
cluster_socket_t * N_API_PTR_RET _experimental_cluster_sock_connect_multi(cluster_status_code_e *code, char **servers, char **ports, int servers_count, cluster_connect_mode_e mode, int tries, int *connected_server_index);

/*
 * Closes cluster socket
 * param[in] socket Cluster socket
 * @return CLUSTER_OK on success and other cluster_status_code_e on error
 */
cluster_status_code_e N_API cluster_sock_close(cluster_socket_t *sock);

/*
 * Sends a packet to server from Client handle
 * param[in] hnd Client handle
 * param[in] socket Cluster socket
 * @return CLUSTER_OK on success and other cluster_status_code_e on error
 */
cluster_status_code_e N_API cluster_packet_send(void *hnd, cluster_socket_t *sock);

/*
 * Gets packet type from Client handle
 * param[in] hnd Cluster handle
 * param[out] type packet type
 * @return CLUSTER_OK on success and other cluster_status_code_e on error
 */
cluster_status_code_e N_API cluster_get_packet_type(void *hnd, cluster_packet_type_e *type);

/*
 * Receives a packet from server
 * param[in] hnd Client handle, created with initialize_client_handle() or initialize_admin_handle() functions
 * param[in] socket Cluster socket
 * @return CLUSTER_OK on success and other cluster_status_code_e on error
 */
cluster_status_code_e N_API cluster_packet_recv(void *hnd, cluster_socket_t *sock);


/*
 * Cluster client functions
 */

/*
 * Initializes client handle.
 * @return pointer to client_handle_t on success and NULL on error
 */
client_handle_t * N_API_PTR_RET initialize_client_handle(void);

/*
 * De-initializes client handle
 * @param[in] hnd Client handle
 * @return CLUSTER_OK on success and other cluster_status_code_e on error
 */
cluster_status_code_e N_API finalize_client_handle(client_handle_t *hnd);

/*
 * Returns result status from client handle
 * @param[in] hnd Client handle initialized with cluster_packet_recv() function
 * @param[out] status Results status.
 * @return CLUSTER_OK on success and other cluster_status_code_e on error
 */
cluster_status_code_e N_API cluster_get_results_status(client_handle_t *hnd, int *status);

/*
 * Returns result progress from client handle
 * @param[in] hnd Client handle initialized with cluster_packet_recv() function
 * @param[out] progress Progress of the matching task
 * @return CLUSTER_OK on success and other cluster_status_code_e on error
 */
cluster_status_code_e N_API cluster_get_results_progress(client_handle_t *hnd, int *progress);

/*
 * Returns results error string length from client handle
 * @param[in] hnd Client handle initialized with cluster_packet_recv() function
 * @param[out] e_len Length of the error string
 * @return CLUSTER_OK on success and other cluster_status_code_e on error
 */
cluster_status_code_e N_API cluster_get_results_error_len(client_handle_t *hnd, int *e_len);

/*
 * Returns results error information from client handle
 * @param[in] hnd Client handle initialized with cluster_packet_recv() function
 * @param[in] e_len Size of error buffer
 * @param[out] e_str Error buffer
 * @return CLUSTER_OK on success and other cluster_status_code_e on error
 */
cluster_status_code_e N_API cluster_get_results_error_string(client_handle_t *hnd, int e_len, void *e_str);

/*
 * Returns results count from client handle
 * @param[in] hnd Client handle initialized with cluster_packet_recv() function
 * @param[out] rcount Results count
 * @return CLUSTER_OK on success and other cluster_status_code_e on error
 */
cluster_status_code_e N_API cluster_get_results_count(client_handle_t *hnd, int *rcount);

/*
 * Returns id string and matching details sizes of one result from Client handle
 * @param[in] hnd Client handle initialized with cluster_packet_recv() function
 * @param[out] id_length Size of result id
 * @param[out] md_length Size of matching details
 * @param[in] offset Offset of cluster_results_t array
 * @return CLUSTER_OK  on on success and other cluster_status_code on error
 */
cluster_status_code_e N_API cluster_get_results_info(client_handle_t *hnd, int offset, int *id_length, int *md_length);

/*
 * Returns id string and matching details of one result from Client handle
 * @param[in] hnd Client handle initialized with cluster_packet_recv() function
 * @param[int] id_length Size of id buffer
 * @param[out] id Id buffer
 * @param[in] md_length Size of md buffer
 * @param[out] md Matching details buffer
 * @param[in] offset Offset of cluster_results_t array
 * @return CLUSTER_OK  on on success and other cluster_status_code on error
 */
cluster_status_code_e N_API cluster_get_results_data(client_handle_t *hnd, int offset, int id_length,  char* id, int md_length, void *md);

/*
 * Returns id string and matching details of one result from Client handle
 * @param[in] hnd Client handle initialized with cluster_packet_recv() function
 * @param[in] offset Offset of cluster_lib_results_t array
 * @param[int] id_length Size of id buffer
 * @param[out] id Id buffer. Can be NULL if id is not needed.
 * @param[out] similarity Pointer to an int variable which receives similarity value. Can be NULL if similarity is not needed.
 * @return CLUSTER_OK on success and other cluster_status_code on error
 */
cluster_status_code_e N_API cluster_get_results_similarity(client_handle_t *hnd, int offset, int id_length, char *id, int *similarity);

/*
 * Initializes handle with cluster task packet
 * @param[in] hnd Client handle initialized with initialize_client_handle() function
 * @param[in] mode Cluster matching task mode
 * @param[in] template_size Size of template
 * @param[in] cluster_template Cluster template
 * @param[in] query_size Size of matching query
 * @param[in] query Matching query
 * @param[in] params_size Size of Matcher parameters. Can be obtained using #cluster_task_params_get_param_buffer_size.
 * @param[in] params Matcher parameters. Can be obtained using #cluster_task_params_get_param_buffer.
 * @param[in] results_limit Maximum number of results to get, use 0 for no limit
 * @return CLUSTER_OK  on on success and other cluster_status_code on error
 */
cluster_status_code_e N_API cluster_packet_create_task(client_handle_t *hnd, cluster_task_mode_e mode, int template_size, const void *cluster_template, int query_size, const char *query, int params_size, const void *params, int results_limit);

/*
 * Initializes handle with cluster task packet
 * @param[in] hnd Client handle initialized with initialize_client_handle() function
 * @param[in] mode Cluster matching task mode
 * @param[in] template_size Size of template
 * @param[in] cluster_template Cluster template
 * @param[in] template_type Cluster template standard type
 * @param[in] query_size Size of matching query
 * @param[in] query Matching query
 * @param[in] params_size Size of Matcher parameters. Can be obtained using #cluster_task_params_get_param_buffer_size.
 * @param[in] params Matcher parameters. Can be obtained using #cluster_task_params_get_param_buffer.
 * @param[in] results_limit Maximum number of results to get, use 0 for no limit
 * @return CLUSTER_OK  on on success and other cluster_status_code on error
 */
cluster_status_code_e N_API cluster_packet_create_standard_template_task(client_handle_t *hnd, cluster_task_mode_e mode, int template_size, const void *cluster_template, cluster_standard_template_type_e template_type, int query_size, const char *query, int params_size, const void *params, int results_limit);


/*
 * Initializes Client handle with progress request packet
 * @param[in] hnd Client handle initialized with initialize_client_handle() function
 * @params[in] task_id  id of task for which get progress
 * @return CLUSTER_OK  on on success and other cluster_status_code on error
 */
cluster_status_code_e N_API cluster_packet_create_progress_request(client_handle_t *hnd, int task_id);
/*
 * Initializes Client handle with result request packet
 * @param[in] hnd Client handle initialized with initialize_client_handle() function
 * @params[in] task_id Task id
 * @params[in] low_range One-based index of first wanted result (use -1 for all)
 * @params[in] high_range One-based index of last wanted result (use -1 for all)
 * @return CLUSTER_OK  on on success and other cluster_status_code on error
 */
cluster_status_code_e N_API cluster_packet_create_result_request(client_handle_t *hnd, int task_id, int low_range, int high_range);

/*
 * Initializes Client handle with result delete request packet
 * @param[in] hnd Client handle initialized with initialize_client_handle() function
 * @params[in] task_id Task id
 * @return CLUSTER_OK  on on success and other cluster_status_code on error
 */
cluster_status_code_e N_API cluster_packet_create_result_delete(client_handle_t *hnd, int task_id);

/*
 * Returns task progress and results count(if they are available) from Client
 * handle
 * @param[in] hnd Client handle initalized with cluster_packet_recv() function
 * @param[out] progress Task progress
 * @param[out] rcount Results count(if available)
 * @return CLUSTER_OK  on on success and other cluster_status_code on error
 */
cluster_status_code_e N_API cluster_get_task_progress(client_handle_t *hnd, int *progress, int *rcount);

/*
 * Returns task id from Client handle
 * @param[in] hnd Client handle initalized with cluster_packet_recv() function
 * @param[out] task_id Id of the task
 * @return CLUSTER_OK  on on success and other cluster_status_code on error
 */
cluster_status_code_e N_API cluster_get_task_id(client_handle_t *hnd, int *task_id);

/*
 * Admin functions
 */


/*
 * Initializes admin handle.
 * @return pointer to admin_handle_t on success and NULL on error
 */
admin_handle_t * N_API_PTR_RET initialize_admin_handle(void);

/*
 * De-initializes admin handle
 * @param[in] hnd Admin handle
 * @return CLUSTER_OK on success and other cluster_status_code_e on error
 */
cluster_status_code_e N_API finalize_admin_handle(admin_handle_t *hnd);

/*
 * Initializes admin handle with admin cluster start packet
 * @param[in] hnd Admin handle initialized with initialize_admin_handle() function
 * @return CLUSTER_OK on success and other cluster_status_code on error
 */
cluster_status_code_e N_API cluster_admin_cluster_start(admin_handle_t *hnd);

/*
 * Initializes admin handle with admin cluster node stop packet
 * @param[in] hnd Admin handle initialized with initialize_admin_handle() function
 * @param[in] node_id Id of node to stop
 * @return CLUSTER_OK on success and other cluster_status_code on error
 */
cluster_status_code_e N_API cluster_admin_node_stop(admin_handle_t *hnd, int node_id);

/*
 * Initializes admin handle with admin cluster server kill packet
 * @param[in] hnd Admin handle initialized with initialize_admin_handle() function
 * @return CLUSTER_OK on success and other cluster_status_code on error
 */
cluster_status_code_e N_API cluster_admin_server_kill(admin_handle_t *hnd);

/*
 * Initializes admin handle with admin cluster node kill packet
 * @param[in] hnd Admin handle initialized with initialize_admin_handle() function
 * @param[in] node_id Id of node to kill
 * @return CLUSTER_OK on success and other cluster_status_code on error
 */
cluster_status_code_e N_API cluster_admin_node_kill(admin_handle_t *hnd, int node_id);

/*
 * Initializes admin handle with admin cluster database update packet
 * @param[in] hnd Admin handle initialized with initialize_admin_handle() function
 * @return CLUSTER_OK on success and other cluster_status_code on error
 */
cluster_status_code_e N_API cluster_admin_database_update(admin_handle_t *hnd);

/*
 * Initializes admin handle with admin cluster database flush packet
 * @param[in] hnd Admin handle initialized with initialize_admin_handle() function
 * @return CLUSTER_OK on success and other cluster_status_code on error
 */
cluster_status_code_e N_API cluster_admin_database_flush(admin_handle_t *hnd);

/*
 * Initializes admin handle with admin node info request packet
 * @param[in] hnd Admin handle initialized with initialize_admin_handle() function
 * @return CLUSTER_OK on success and other cluster_status_code on error
 */
cluster_status_code_e N_API cluster_admin_nodes_info_req(admin_handle_t *hnd);

/*
 * Initializes admin handle with admin results info request packet
 * @param[in] hnd Admin handle initialized with initialize_admin_handle() function
 * @return CLUSTER_OK on success and other cluster_status_code on error
 */
cluster_status_code_e N_API cluster_admin_results_info_req(admin_handle_t *hnd);

/*
 * Initializes admin handle with admin complete tasks info request packet
 * @param[in] hnd Admin handle initialized with initialize_admin_handle() function
 * @return CLUSTER_OK on success and other cluster_status_code on error
 */
cluster_status_code_e N_API cluster_admin_tasks_complete_info_req(admin_handle_t *hnd);

/*
 * Initializes admin handle with admin short tasks info request packet
 * @param[in] hnd Admin handle initialized with initialize_admin_handle() function
 * @return CLUSTER_OK on success and other cluster_status_code on error
 */
cluster_status_code_e N_API cluster_admin_tasks_short_info_req(admin_handle_t *hnd);

/*
 * Builds cluster database record insert packet
 * @param[in] hnd Admin handle initialized with initialize_admin_handle() function
 * @param[in] count Count of records in ids_len, ids, templates_len, templates array
 * @param[in] ids_len array of pointers to ids lengths of record ids to be inserted into database
 * @param[in] ids array of pointers to ids of records to be inserted into database
 * @param[in] templates_len array of pointers to templates lengths of records to be inserted into database
 * @param[in] templates array of pointers to templates of records to be inserted into database
 * @return CLUSTER_OK on success and other cluster_status_code on error
 */
cluster_status_code_e N_API cluster_admin_insert_db_records(admin_handle_t *hnd, int count, const int * ids_len, const char * const *ids, const int * templates_len, const void * const * templates);

/**
 * Builds cluster database insert packet 2
 * @param[in] hnd Admin handle initialized with initialize_admin_handle() function
 * @param[in] count queries count
 * @param[in] key_index index of primary key
 * @param[in] values_count count of values to insert
 * @param[in] values_type array of values type (1 - string, 2 - binary)
 * @param[in] values_size array of values sizes excluding termination value
 * @param[in] values array of values to insert, string termination is not required
 * @return CLUSTER_OK on success and other cluster_status_code on error
 */
cluster_status_code_e N_API cluster_admin_db_insert2(admin_handle_t *hnd,
	unsigned int count, int key_index, size_t values_count,
	const int **values_type, const size_t **values_size,
	const void ** const *values);

/**
 * Builds cluster database insert packet 3.
 * @param[in] hnd Admin handle initialized wiht initialize_admin_handle() function
 * @param[in] count queries count
 * @param[in] key_index index of primary key
 * @param[in] values_count count of values to insert
 * @param[in] values_type array of values type (1 - string, 2 - binary)
 * @param[in] values_size array of values sizes excluding termination value
 * @param[in] values array of values to insert, string termination is not required
 * @param[in] column_names array of SQLDBInsertQueryPattern2 sql template parameters (f.e. for "@name@" parameter should be passed "name")
 * @param[in] column_name_sizes size of string in column_names array
 * @return CLUSTER_OK on success and other cluster_status_code on error
 */
cluster_status_code_e N_API cluster_admin_db_insert3(admin_handle_t *hnd,
	unsigned int count, int key_index, size_t values_count,
	const int **values_type, const size_t **values_size,
	const void ** const *values, const size_t **value_names_size,
	const char ** const *value_names);

/*
 * Builds cluster database record insert packet
 * @param[in] hnd Admin handle initialized with initialize_admin_handle() function
 * @param[in] count Count of records in ids_len, ids, templates_len, templates array
 * @param[in] ids_len array of pointers to ids lengths of record ids to be inserted into database
 * @param[in] ids array of pointers to ids of records to be inserted into database
 * @param[in] templates_len array of pointers to templates lengths of records to be inserted into database
 * @param[in] templates array of pointers to templates of records to be inserted into database
 * @param[in] templates_type array of types of templates/records to be inserted into database
 * @return CLUSTER_OK on success and other cluster_status_code on error
 */
cluster_status_code_e N_API cluster_admin_insert_standard_template_db_records(admin_handle_t *hnd, int count, const int * ids_len, const char * const *ids, const int * templates_len, const void * const * templates, const cluster_standard_template_type_e * templates_type);

cluster_status_code_e N_API cluster_admin_get_insert_task_id(admin_handle_t *hnd, int *task_id);

cluster_status_code_e N_API cluster_admin_db_insert_result_request(admin_handle_t *hnd, int task_id);
cluster_status_code_e N_API cluster_admin_get_insert_task_result(admin_handle_t *hnd, int *result);
cluster_status_code_e N_API cluster_admin_get_insert_task_batch_size(admin_handle_t *hnd, int *batch_size);
cluster_status_code_e N_API cluster_admin_get_insert_task_status(admin_handle_t *hnd, int template_index, int *status);
cluster_status_code_e N_API cluster_admin_get_insert_task_error(admin_handle_t *hnd, int template_index, int *error_len, char **error_str);

/*
 * Builds cluster database record delete packet
 * @param[in] hnd Admin handle initialized with initialize_admin_handle() function
 * @param[in] count Count of records in ids_len, ids array
 * @param[in] ids_len array of pointers to ids lengths of record ids to be deleted from database
 * @param[in] ids array of pointers to ids of records to be deleted from database
 * @return CLUSTER_OK on success and other cluster_status_code on error
 */
cluster_status_code_e N_API cluster_admin_delete_db_records(admin_handle_t *hnd, int count, const int * ids_len, const char * const *ids);
cluster_status_code_e N_API cluster_admin_get_delete_task_id(admin_handle_t *hnd, int *task_id);

cluster_status_code_e N_API cluster_admin_db_delete_result_request(admin_handle_t *hnd, int task_id);
cluster_status_code_e N_API cluster_admin_get_delete_task_result(admin_handle_t *hnd, int *result);
cluster_status_code_e N_API cluster_admin_get_delete_task_batch_size(admin_handle_t *hnd, int *batch_size);
cluster_status_code_e N_API cluster_admin_get_delete_task_status(admin_handle_t *hnd, int template_index, int *status);
cluster_status_code_e N_API cluster_admin_get_delete_task_error(admin_handle_t *hnd, int template_index, int *error_len, char **error_str);

/*
 * Builds cluster database record update packet
 * @param[in] hnd Admin handle initialized with initialize_admin_handle() function
 * @param[in] count Count of strings in id_strings array
 * @param[in] id_strings array of pointers to ids of updated fields in database
 * @return CLUSTER_OK on success and other cluster_status_code on error
 */
cluster_status_code_e N_API cluster_admin_change_db_records(admin_handle_t *hnd, int count, const char **id_strings);

/*
 * Gets admin results count from admin handle
 * @param[in] hnd Admin handle initialized with cluster_packet_recv() function
 * @param[out] r_count Results count
 * @return CLUSTER_OK on success and other cluster_status_code_e on error
 */
cluster_status_code_e N_API cluster_get_admin_results_count(admin_handle_t *hnd, int *rcount);

/*
 * Gets admin results id from admin handle
 * @param[in] hnd Admin handle initialized with cluster_packet_recv() function
 * @param[in] offset Offset of resulsts_id array
 * @param[out] results_id Id of task which results are available for retrieval
 * @return CLUSTER_OK on success and other cluster_status_code_e on error
 */
cluster_status_code_e N_API cluster_get_admin_results_id(admin_handle_t *hnd, int offset, int *results_id);

/*
 * Admin nodes info packet information querying functions
 */

/*
 * Gets node count from admin handle
 * @param[in] hnd Admin handle initialized with function cluster_packet_recv()
 * function
 * @param[out] nodes_count Count of nodes in cluster
 * @return CLUSTER_OK on success and other cluster_status_code_e on error
 */
cluster_status_code_e N_API cluster_get_admin_nodes_info_count(admin_handle_t *hnd, int *nodes_count);

/*
 * Gets node id from admin handle
 * @param[in] hnd Admin handle initialized with function cluster_packet_recv()
 * function
 * @param[in] offset Offset of cluster_node_state structures array
 * @param[out] nodes_id Id of the node in cluster form cluster_node_state array
 * @param[out] nodes_state State of the node in cluster form cluster_node_state array.
 * @return CLUSTER_OK on success and other cluster_status_code_e on error
 */
cluster_status_code_e N_API cluster_get_admin_nodes_info(admin_handle_t *hnd, int offset, int *nodes_id, cluster_node_state_e *node_state);


/*
 * Admin complete info packet information querying functions
 */

/*
 * Gets count of task, for which complete information could be queried
 * @param[in] hnd Admin handle initialized with function cluster_packet_recv()
 * function
 * @param[out] count Count of task for which complete information could be
 * queried
 * @return CLUSTER_OK on success and other cluster_status_code_e on error
 */
cluster_status_code_e N_API cluster_get_admin_tasks_complete_info_count(admin_handle_t *hnd, int *count);

/*
 * Gets task id from specific cluster_info_t structures located in array
 * @param[in] hnd Admin handle initialized with function cluster_packet_recv()
 * function
 * @param[in] offset Offset of cluster_info_t structures array
 * @param[out] task_id Task id from structure
 * @param[out] nodes_completed Count of the nodes that have completed task
 * @param[out] working_nodes Count of the nodes that are working on task
 * @param[out] task_progress Progress of task
 * @return CLUSTER_OK on success and other cluster_status_code_e on error
 */
cluster_status_code_e N_API cluster_get_admin_tasks_complete_info(admin_handle_t *hnd, int offset, int *task_id, int *nodes_completed, int * working_nodes, int *task_progress);


/*
 * Gets specific node information working on specific task from specific cluster_info_t structures located in array
 * @param[in] hnd Admin handle initialized with function cluster_packet_recv()
 * function
 * @param[in] offset Offset of cluster_info_t structures array
 * @param[in] working_nodes_offset Offset of cluster_node_info structures array
 * @param[out] node_id Id of the node
 * @param[out] node_progress Progress of specific task in node
 * @return CLUSTER_OK on success and other cluster_status_code_e on error
 */
cluster_status_code_e N_API cluster_get_admin_tasks_complete_info_node_info(admin_handle_t *hnd, int offset, int working_nodes_offset, int *node_id, int *node_progress);

/*
 * Admin short task info packet information querying functions
 */

/*
 * Gets count of tasks, for which short information is returned
 * @param[in] hnd Admin handle initialized with function cluster_packet_recv()
 * function
 * @param[out] count Count of task for which short information is returned
 * @return CLUSTER_OK on success and other cluster_status_code_e on error
 */
cluster_status_code_e N_API cluster_get_admin_task_short_info_count(admin_handle_t *hnd, int *count);


/*
 * Gets Id of the task, count of working nodes on the task, completed nodes of the task for which information could be queried
 * @param[in] hnd Admin handle initialized with function cluster_packet_recv()
 * function
 * @param[in] offset Offset of cluster_node_info_t structures array
 * @param[out] task_id Id of the task, for which information could be queried
 * @param[out] nodes_completed Count of the nodes that completed working with
 * task
 * @param[out] working_nodes Count of the nodes working on the task
 * @return CLUSTER_OK on success and other cluster_status_code_e on error
 */
cluster_status_code_e N_API cluster_get_admin_tasks_short_info(admin_handle_t *hnd, int offset, int *task_id, int *nodes_completed, int *working_nodes_count);

/*
 * Initializes admin handle with admin server info request packet
 * @param[in] hnd Admin handle initialized with initialize_admin_handle() function
 * @return CLUSTER_OK on success and other cluster_status_code on error
 */
cluster_status_code_e N_API cluster_admin_server_info_req(admin_handle_t *hnd);

/*
 * Gets server info: current status of the server.
 * @param[in] hnd Admin handle initialized with function cluster_packet_recv()
 * function
 * @param[in] server_status Indicates current server status.
 * @return CLUSTER_OK on success and other cluster_status_code_e on error
 */
cluster_status_code_e N_API cluster_admin_get_server_info(admin_handle_t *hnd, int *server_status);

/*
 * Creates handle of cluster task parameters.
 * @return new handle of cluster task parameters on success and NULL on error.
 */
cluster_task_params_t* N_API_PTR_RET cluster_task_params_create();

/*
 * Free previously allocated handle of cluster task parameters.
 */
void N_API cluster_task_params_free(cluster_task_params_t *cluster_task_params);

/*
 * Adds a parameter to cluster task parameters.
 * @param[in] cluster_task_params handle of cluster task params created with #cluster_task_params_create
 * @param[in] part part of NMatcher param (see NMatcher documentation).
 * @param[in] id  id of NMatcher param (see NMatcher documentation).
 * @param[in] value value of NMatcher param (see NMatcher documentation).
 * @return CLUSTER_OK on success and other cluster_status_code_e on error
 */
cluster_status_code_e N_API cluster_task_params_add_param(cluster_task_params_t *cluster_task_params, NUInt part, NUInt id, NULong value);

/*
 * Get cluster task param buffer.
 * @param[in] cluster_task_params handle of cluster task params created with #cluster_task_params_create
 * @return pointer to a params buffer which can be given to #cluster_packet_create_task.
 */
void* N_API_PTR_RET cluster_task_params_get_param_buffer(cluster_task_params_t *cluster_task_params);

/*
 * Get cluster task param buffer size.
 * @param[in] cluster_task_params handle of cluster task params created with #cluster_task_params_create
 * @return size of params buffer which can be given to #cluster_packet_create_task.
 */
int N_API cluster_task_params_get_param_buffer_size(cluster_task_params_t *cluster_task_params);

#ifdef __cplusplus
}
#endif


#endif /* !N_CLUSTER_H_INCLUDED */
