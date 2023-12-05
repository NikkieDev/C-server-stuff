#ifndef USER_H
#define USER_H

typedef struct {
    int user_id;
    int socket_fd;
} user;

user *make_user(int user_id, int socket_fd);
void add_user(int client_fd, int users);

#endif // USER_H