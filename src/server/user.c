#include "./user.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <string.h>

void listen_user(void *__client)
{
  client *__pClient = (client *)__client; // point to client pointer
  int reading = 1;
  char temp_buffer[32];
  
  ssize_t temp_size = sizeof(temp_buffer);
  ssize_t client_buffer = sizeof(__pClient->buffer);

  strncpy(__pClient->buffer, "Welcome\0", 12);
  printf("\nsending welcome packet\n");

  send(__pClient->socket_descriptor, __pClient->buffer, client_buffer, 0);
  // memset(__pClient->buffer, 0, sizeof(__pClient->buffer)); // only necessary when not overwriting shortly after. Use when variable is only needed later and can be cleared

  recv(__pClient->socket_descriptor, __pClient->buffer, client_buffer, 0);

  while (strncmp(__pClient->buffer, "options", client_buffer) != 0)
  {
    recv(__pClient->socket_descriptor, __pClient->buffer, client_buffer, 0);

    strncpy(temp_buffer, "Failed\0", temp_size);
    send(__pClient->socket_descriptor, temp_buffer, temp_size, 0);
  }
  printf("\33[0;32m\nRECEIVED: %s\n", __pClient->buffer);

  strncpy(temp_buffer, "Success!\0", temp_size);
  printf("\33[0;32mSending '%s'\n", temp_buffer);
  send(__pClient->socket_descriptor, temp_buffer, temp_size, 0);

  printf("\033[0;31m\n[%s]\n\t-socket_descript: %d\n\t-text-received: %s\n\033[0m", \
  __pClient->thread_name, __pClient->socket_descriptor, __pClient->buffer);

  close(__pClient->socket_descriptor);
  pthread_exit(NULL);
}

void initialize_user(client *__client, int users)
{
  pthread_t thid;
  char *thread_name = malloc(9 + sizeof(users));

  snprintf(thread_name, 9 + sizeof(users), "thread-%d", users);
  strncpy(__client->thread_name, thread_name, 9 + sizeof(users));

  printf("\nCreating %s", thread_name);

  pthread_create(&thid, NULL, listen_user, __client);
  pthread_join(thid, NULL);

  free(thread_name);
}

client add_user(int client_fd, int users)
{
  client user = {
    .socket_descriptor = client_fd
  };

  return user;
}