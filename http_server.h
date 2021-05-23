#ifndef KHTTPD_HTTP_SERVER_H
#define KHTTPD_HTTP_SERVER_H

#include <linux/list.h>
#include <net/sock.h>

struct http_server_param {
    struct socket *listen_socket;
};

struct http_server_wq {
    struct workqueue_struct *client_wq;
    struct list_head head;
    bool should_stop;
};

struct http_server {
    struct socket *socket;
    struct work_struct work;
    struct list_head list;
};

extern int http_server_daemon(void *arg);

#endif
