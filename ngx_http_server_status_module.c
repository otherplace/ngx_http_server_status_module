/*
 * ngx_http_server_status_module
 * <otherplace@gmail.com>
 */
#include <ngx_config.h>
#include <ngx_core.h>
#include <ngx_http.h>

struct ngx_http_server_status_ctx_s {
	ngx_uint_t rx;
	ngx_uint_t tx;
	ngx_uint_t conn;

};


/* ngx commands */
static ngx_command_t ngx_http_server_status_module_commands[] = {
	{
		ngx_string("server_status_zone"),
		NGX_HTTP_MAIN_CONF|NGX_CONF_TAKE1MORE,
		ngx_http_server_status_zone,
		0,
		0,
		NULL
	},
	{
		ngx_string("server_status"),
		NGX_HTTP_SRV_CONF|NGX_HTTP_LOC_CONF|NGX_HTTP_LIF_CONF|NGX_CONF_TAKE1MORE,
		ngx_http_server_status,
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

static ngx_int_t ngx_http_server_status_body_filter(ngx_http_request_t *r, ngx_chain_t *in)
{
	/*
	 * TODO:
	 * 	lookup shm
	 * 	r->connection->sent add to shm
	 */
	return NGX_DECLINED;
}
