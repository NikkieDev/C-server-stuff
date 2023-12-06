#include <stdio.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <string.h>
#include <stdio.h>
#include "./user.h"

int main() {
	int s = socket(AF_INET, SOCK_STREAM, 0);
	int users = 0;
	
	struct sockaddr_in addr = {
		AF_INET,
		0x901f,
		0
	};

	char greet[32];

	bind(s, &addr, sizeof(addr));
	listen(s, 2);

	int client_fd = accept(s, 0, 0);
	++users;
	add_user(client_fd, users);

	char buffer[32];

	// recv(client_fd, buffer, sizeof(buffer), 0);
	// printf("From client: %s\n", buffer);

	// make thread for new user
	// while connected -> listen for options from user.
	// on option receive, execute action.
	// on action resolve, send resolved.

	// sprintf(greet, "Welcome user %d\n\0", new_user->user_id);
	// memset(buffer, 0, sizeof(buffer));

	// strcpy(buffer, greet);
	// send(client_fd, buffer, sizeof(buffer), 0);

	// close(client_fd);
	// close(s);

	return 1;
}
