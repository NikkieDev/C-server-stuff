#include "./user.h"

user *make_user(int user_id, int socket_fd)
{
    user *pNew_user = malloc(sizeof(user));

    pNew_user->user_id = user_id;
    pNew_user->socket_fd = socket_fd;

    return pNew_user;
}