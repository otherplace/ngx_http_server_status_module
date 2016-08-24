/*
 * ngx_http_server_status_module
 * <otherplace@gmail.com>
 */
#include <ngx_config.h>
#include <ngx_core.h>
#include <ngx_http.h>

struct ngx_http_server_status_queue_s {
	ngx_queue_t sstatq;
	ngx_uint_t server_id;
	ngx_array_t server_names; /* ngx_str_t */
	ngx_uint_t rx;
	ngx_uint_t tx;
	ngx_uint_t conn;
};
struct ngx_http_server_status_node_s {
	ngx_queue_t sstatq_top;
};
struct ngx_http_server_status_loc_conf_s {
	ngx_flag_t is_use;
	ngx_flag_t is_use_all_zone;
	ngx_array_t zone_array; /* ngx_shm_zone_t * */
};
static char *ngx_http_server_status_zone_parse(ngx_conf_t *cf, ngx_command_t *cmd, void *conf);
static char *ngx_http_server_status_use_parse(ngx_conf_t *cf, ngx_command_t *cmd, void *conf);
static char *ngx_http_server_status_parse(ngx_conf_t *cf, ngx_command_t *cmd, void *conf);

/* ngx commands */
static ngx_command_t ngx_http_server_status_module_commands[] = {
	{
		ngx_string("server_status_zone"),
		NGX_HTTP_MAIN_CONF|NGX_CONF_TAKE1,
		ngx_http_server_status_zone_parse,
		0,
		0,
		NULL
	},
	{
		ngx_string("server_status_use"),
		NGX_HTTP_SRV_CONF|NGX_HTTP_LOC_CONF|NGX_HTTP_LIF_CONF|NGX_CONF_TAKE1MORE,
		ngx_http_server_status_use_parse,
		NGX_HTTP_LOC_CONF_OFFSET,
		0,
		NULL
	},
	{
		ngx_string("server_status"),
		NGX_HTTP_SRV_CONF|NGX_HTTP_LOC_CONF|NGX_HTTP_LIF_CONF|NGX_CONF_TAKE1MORE,
		ngx_http_server_status_parse,
		NGX_HTTP_LOC_CONF_OFFSET,
		0,
		NULL
	},
	ngx_null_command
};
static ngx_http_module_t ngx_http_server_status_module_ctx = {
	NULL, /* preconfiguration */
	ngx_http_server_status_init, /* postconfiguration */
	NULL, /* create main configuration */
	NULL, /* init main configuration */
	NULL, /* create server configuration */
	NULL, /* merge server configuration */
	ngx_http_server_status_create_loc_conf, /* create location configuration */
	ngx_http_server_status_merge_loc_conf /* merge location configuration */
};

ngx_module_t ngx_http_server_status_module = {
	NGX_MODULE_V1,
	&ngx_http_server_status_module_ctx, /* module context */
	ngx_http_server_status_module_commands, /* module directives */
	NGX_HTTP_MODULE, /* module type */
	NULL, /* init master */
	NULL, /* init module */
	NULL, /* init process */
	NULL, /* init thread */
	NULL, /* exit thread */
	NULL, /* exit process */
	NULL, /* exit master */
	NGX_MODULE_V1_PADDING
};

static ngx_http_output_body_filter_pt ngx_http_next_body_filter;

static char *ngx_http_server_status_zone_parse(ngx_conf_t *cf, ngx_command_t *cmd, void *conf)
{
	/*
	 * TODO:
	 * 	parse below
	 * 	ex)
	 * 		server_status_zone zone=blah_blah:100m;
	 */
	return NGX_CONF_OK;
}
static char *ngx_http_server_status_use_parse(ngx_conf_t *cf, ngx_command_t *cmd, void *conf)
{
	/*
	 * TODO:
	 * 	parse below
	 * 	ex)
	 * 		server_status_use blah_blah;
	 * 			or
	 * 		server_status_use off;
	 * 			or
	 * 		server_status_use;
	 */
	return NGX_CONF_OK;
}
static char *ngx_http_server_status_parse(ngx_conf_t *cf, ngx_command_t *cmd, void *conf)
{
	/*
	 * TODO:
	 * 	parse below example config
	 * 	ex)
	 * 		server_status;
	 * 			or
	 * 		server_status zone=blah_blah;
	 * 			or
	 *		server_status format=xml;
	 *			or
	 *		server_status zone=blah_blah format=xml;
	 *			or
	 *		server_status zone=blah_blah,blah format=xml;
	 */
	return NGX_CONF_OK;
}
static ngx_int_t ngx_http_server_status_use_body_filter(ngx_http_request_t *r, ngx_chain_t *in)
{
	/*
	 * TODO:
	 * 	lookup shm
	 * 	r->connection->sent add to shm
	 */
	return NGX_DECLINED;
}
static ngx_int_t ngx_http_server_stauts_body_fileter(ngx_http_request_t *r, ngx_chain_t *in)
{
	/*
	 * TODO:
	 * 	lookup shm
	 * 	generate response body flow configured format
	 * 	response body
	 */

	return NGX_DECLINED;
}
