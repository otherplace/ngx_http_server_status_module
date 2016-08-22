/*
 * ngx_http_server_status_module
 * <otherplace@gmail.com>
 */
#include <ngx_config.h>
#include <ngx_core.h>
#include <ngx_http.h>



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
