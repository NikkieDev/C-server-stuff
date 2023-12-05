#ifndef USER_H
#define USER_H

typedef struct {
    int user_id;
    int socket_fd;
} user;

user *make_user(int user_id, int socket_fd);

#endif // USER_H