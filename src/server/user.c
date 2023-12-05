#include "./user.h"
#include <pthread.h>
#include <stdio.h>

user *make_user(int user_id, int socket_fd)
{
    user *pNew_user = malloc(sizeof(user));

    pNew_user->user_id = user_id;
    pNew_user->socket_fd = socket_fd;

    return pNew_user;
}

void listen_user(void *arg)
{
    printf("I'm %s", arg);
    pthread_exit(arg);
}

void add_user(int client_fd, int users)
{
    pthread_t thid;
    char thread_name[6 + sizeof(users)];
    sprintf(thread_name, "thread-%d", users);

    pthread_create(&thid, NULL, listen_user, thread_name);
    pthread_join(thid, thread_name);
}