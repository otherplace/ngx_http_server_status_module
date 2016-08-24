# ngx_http_server_status_module(not yet compileable)
===============================

The ngx_http_server_status module provides various information of every nginx's virtual host. Such as TX, RX, number of connection, TX/RX of upstream(s).

Configuration directives
========================
server_status_zone
------------------
* **syntax**: server_status_zone zone=name:size
* **default**: -
* **context**: http

server_status
--------------------
* **syntax**: server_status *format=json|csv|xml*
* **default**: server_status format=json
* **context**: server, location, if, if in location

server_status_use
--------------------
* **syntax**: server_status_use *zone=all|name,name,..* *off*
* **default**: server_status_use off
* **context**: server, location, if, if in location

Configuration example
=====================
	http {
		server_status_zone zone=global_status_zone:1g;
		server_status_zone zone=php_zone:100m;
		server {
			server_name blah.blah.com;
			server_status_use global_status_zone;

			location / {
				...
				proxy_pass ..;
			}
			location ~* *\.php$ {
				server_status_use php_zone;
				proxy_pass localhost:7070;
			}
		}
		server {
			server_name another.blah.com;
			server_status_use global_status_zone;
			root /var/www/another;
			...
		}

		server {
			server_name other.blah.com;
			root /var/www/other;

			location / {
				return 403;
			}
			location /media {
				server_status_use global_zone;
			}
		}
		server {
			server_name localhost;
			listen 8888 default_server;
			location /monitor {
			 	allow 192.168.0.0/24;
				deny all;
				server_status zone=global_zone;
			}
			location /monitor/all {
			 	allow 192.168.0.0/24;
				deny all;
				server_status zone=all;
			}
			location /monitor/php {
			 	allow 192.168.0.0/24;
				deny all;
				server_status zone=php_zone;
			}
	}

Supported nginx version
=======================

* nginx-1.10.1

How to compile
==============

	$ cd nginx-1.10.x/
	$ ./configure --add-module=<path of this module>


