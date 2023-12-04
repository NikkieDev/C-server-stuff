#include <stdio.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <string.h>
#include <stdio.h>

typedef struct user {
	int user_id;
	int socket_fd;
} user;

int main() {	
	int s = socket(AF_INET, SOCK_STREAM, 0);
	struct sockaddr_in addr = {
		AF_INET,
		0x901f,
		0
	};

	char greet[64];

	bind(s, &addr, sizeof(addr));
	listen(s, 1);

	int client_fd = accept(s, 0, 0);

	user new_user = { .user_id = 1, .socket_fd = client_fd };

	char buffer[256];

	recv(client_fd, buffer, 256, 0);
	printf("From client: %s\n", buffer);

	sprintf(greet, "Welcome user %d\n", new_user.user_id);
	memset(buffer, 0, sizeof(buffer));

	strcpy(buffer, greet);
	send(client_fd, buffer, sizeof(buffer), 0);

	close(client_fd);
	close(s);

	return 1;
}
