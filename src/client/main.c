#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdio.h>
#include "connection.h"

int main()
{
  int s = try_connect();
  char write_buffer[128], read_buffer[128];

  while (s == 10001) {
    printf("Couldn't connect, retrying...\n");
    fflush(stdout);
    sleep(3);
    s = try_connect();
  }

  strncpy(write_buffer, "options\0", sizeof(write_buffer));

  printf("receiving first\n");
  recv(s, read_buffer, sizeof(read_buffer), 0); // receive "Welcome" as nullterminated string from server
  printf("READ: %s\n", read_buffer);
  send(s, write_buffer, sizeof(write_buffer), 0); // send "options" as nullterminated string to server

  recv(s, read_buffer, sizeof(read_buffer), 0); // Try receiving server responding message
  while (strncmp(read_buffer, "Success!", sizeof(read_buffer)))
  {
    recv(s, read_buffer, sizeof(read_buffer), 0);
  }

  printf("Received back: %s\n", read_buffer);

  return 1;
}