# ngx_http_server_status_module
===============================

The ngx_http_server_status module provides various information of every nginx's virtual host. Such as TX, RX, number of connection, TX/RX of upstream(s).

Configuration directives
========================
server_status_zone
------------------
* **syntanx**: `server_status_zone zone*:size*`
* **default**: `-`
* **contenxt**: `http`

server_status
--------------------
* **syntanx**: `server_status zone=all*|zone,zone,..* *format=json|csv|xml*`
* **default**: `server_status zone=all format=json`
* **contenxt**: `server`, `location`, `if`


Supported nginx version
=======================

* nginx-1.10.1

How to compile
==============

$ cd nginx-1.10.x/
$ ./configure --add-module=<path of this module>


