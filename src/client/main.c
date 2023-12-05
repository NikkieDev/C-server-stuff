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

    strcpy(client_buffer, "test123\0");

    struct sockaddr_in addr = {
        AF_INET,
        0x901f
    };
    
    inet_pton(AF_INET, "127.0.0.1", &addr.sin_addr);
    connect(s, &addr, sizeof(addr));
    
    send(s, client_buffer, sizeof(client_buffer), 0);
    while (received == 0)
    {
        ssize_t bytes = recv(s, client_buffer, sizeof(client_buffer), 0);

        if (bytes != 0)
        {
            printf("%s", client_buffer);
            break;
        }
    }

    return 1;
}