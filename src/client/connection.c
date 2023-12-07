#include "connection.h"

int try_connect()
{
  int s = socket(AF_INET, SOCK_STREAM, 0);
  struct sockaddr_in addr = {.sin_family=AF_INET, .sin_port=htons(8080)};
  inet_pton(AF_INET, "127.0.0.1", &addr.sin_addr);

  int con_state = connect(s, &addr, sizeof(addr));
  if (con_state < 0)
    return 10001;
  else
    return s;
}