#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

int main()
{
    int s = socket(AF_INET, SOCK_STREAM, 0);
    int received = 0;
    char str[INET_ADDRSTRLEN];
    char client_buffer[128];
    ssize_t bytes_send;

    strcpy(client_buffer, "test123\0");

    struct sockaddr_in addr = {
        AF_INET,
        0x901f
    };
    
    inet_pton(AF_INET, "127.0.0.1", &addr.sin_addr);
    connect(s, &addr, sizeof(addr));
    
    printf("Sending '%s'\n\0", client_buffer);

    bytes_send = send(s, client_buffer, sizeof(client_buffer), 0);
    printf("bytes send: %ld", bytes_send);

    memset(client_buffer, 0, sizeof(client_buffer));

    return 1;
}