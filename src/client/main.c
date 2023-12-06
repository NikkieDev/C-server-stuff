#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdio.h>

int main()
{
  int s = socket(AF_INET, SOCK_STREAM, 0);
  char write_buffer[128], read_buffer[128];
  ssize_t bytes_send;

  strncpy(write_buffer, "options\0", sizeof(write_buffer));

  struct sockaddr_in addr = {
      AF_INET,
      0x901f
  };
  
  inet_pton(AF_INET, "127.0.0.1", &addr.sin_addr);
  connect(s, &addr, sizeof(addr));
  
  // printf("Sending '%s'\n", write_buffer);

  // bytes_send = send(s, write_buffer, sizeof(write_buffer), 0);
  // printf("bytes send: %ld", bytes_send);

  // memset(write_buffer, 0, sizeof(write_buffer));
  printf("receiving first\n");
  recv(s, read_buffer, sizeof(read_buffer), 0);
  printf("RECEIVED: %s\n", read_buffer);
  send(s, write_buffer, sizeof(write_buffer), 0);

  memset(read_buffer, 0, sizeof(read_buffer));
  recv(s, read_buffer, sizeof(read_buffer), 0);
  printf("RECEIVED 2: %s\n", read_buffer);

  return 1;
}