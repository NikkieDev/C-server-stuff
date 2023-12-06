#include "./user.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <string.h>

user *make_user(int user_id, int socket_fd)
{
  user *pNew_user = malloc(sizeof(user));

  pNew_user->user_id = user_id;
  pNew_user->socket_fd = socket_fd;

  return pNew_user;
}

void listen_user(void *__client)
{
  client *__pClient = (client *)__client;
  ssize_t bytes_received;

  bytes_received = recv(__pClient->socket_descriptor, __pClient->buffer, sizeof(__pClient->buffer), 0);

  while (strncmp(__pClient->buffer, "options", sizeof(__pClient->buffer)) != 0) {
    bytes_received = recv(__pClient->socket_descriptor, __pClient->buffer, sizeof(__pClient->buffer), 0);

    strncpy(__pClient->buffer, "Options returning!\0", sizeof(__pClient->buffer));
    memset(__pClient->buffer, 0, sizeof(__pClient->buffer));

    if (strncmp(__pClient->buffer, "options", sizeof(__pClient->buffer)))
      send(__pClient->socket_descriptor, __pClient->buffer, sizeof(__pClient->buffer), 0);
  }
  
  printf("\033[0;31m\n[%s]\n\t-socket_descript: %d\n\t-text-received: %s\n\t-bytes received: %ld\n", \
  __pClient->thread_name, __pClient->socket_descriptor, __pClient->buffer, bytes_received);

  printf("\033[0m");
  pthread_exit(NULL);
}

void add_user(int client_fd, int users)
{
  pthread_t thid;
  client *p_client = malloc(sizeof(client));

  char *thread_name = malloc(9 + sizeof(users));
  snprintf(thread_name, 9 + sizeof(users), "thread-%d", users);

  strncpy(p_client->thread_name, thread_name, 9 + sizeof(users));
  p_client->socket_descriptor = client_fd;

  printf("\nCreating %s", thread_name);

  pthread_create(&thid, NULL, listen_user, p_client);
  pthread_join(thid, NULL);

  free(thread_name);
  free(p_client);
}