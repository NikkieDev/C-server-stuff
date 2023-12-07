#ifndef USER_H
#define USER_H

typedef struct {
  char thread_name[16];
  char buffer[256];
  int socket_descriptor;
} client;

client add_user(int client_fd, int users);
void initialize_user(client *__client, int users);

#endif // USER_H