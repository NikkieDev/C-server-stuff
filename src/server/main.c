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

	bind(s, &addr, sizeof(addr));
	listen(s, 2);

	int client_fd = accept(s, 0, 0);
	client user = add_user(client_fd, &users);
	client *p_user = &user;
	initialize_user(p_user, users);

	// make thread for new user
	// while connected -> listen for options from user.
	// on option receive, execute action.
	// on action resolve, send resolved.

	close(s);
	return 1;
}
