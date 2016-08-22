# ngx_http_server_status_module
===============================

The ngx_http_server_status module provides various information of every nginx's virtual host. Such as TX, RX, number of connection, TX/RX of upstream(s).

Configuration directives
========================
server_status_zone
------------------
* **syntax**: server_status_zone zone*:size*
* **default**: -
* **context**: http

server_status
--------------------
* **syntax**: server_status zone=all*|zone,zone,..* *format=json|csv|xml*
* **default**: server_status zone=all format=json
* **context**: server, location, if


Supported nginx version
=======================

* nginx-1.10.1

How to compile
==============

	$ cd nginx-1.10.x/
	$ ./configure --add-module=<path of this module>


