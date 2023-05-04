#include <sys/types.h>
#include <sys/socket.h>
#include <iostream>
#include <netinet/in.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <netdb.h>
// #include <iomanip>
// #include <stdio.h>
// #include <stdint.h>

typedef struct sockaddr t_sockaddr;

int main()
{
	int fd_socket, client_fd;
	struct 	addrinfo hints;
	struct 	addrinfo *res;
	int status;
	t_sockaddr socket_struct, their_addr;
	socklen_t addr_size;

	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = AI_PASSIVE;
	getaddrinfo(NULL, "3490", &hints, &res);

	if ((fd_socket = socket(res->ai_family, res->ai_socktype, res->ai_protocol)) == -1)
		std::cerr << "socket creation error" << std::endl;
	if (bind(fd_socket, res->ai_addr, res->ai_addrlen) == -1)
		std::cerr << "socket binding failed" << std::endl;
	if (listen(fd_socket, 5) == -1)
		std::cerr << "socket listening failed" << std::endl;
	size_t buf_size = 512, msg_len;
	while (1)
	{
		addr_size = sizeof(their_addr);
		if ((client_fd = accept(fd_socket, &their_addr, &addr_size)) == -1)
			std::cerr << "accept() failed" << std::endl;
		char buf[buf_size + 1];
		memset(buf, 0, sizeof(buf));
		msg_len = read(client_fd, buf, buf_size);
		std::cout << "msg_len = " << msg_len << std::endl;
		std::cout << "server: " << buf << std::endl;
	}
	// if (fork() == 0)
	// {
	// 	std::cout << "i am the child" << std::endl;
		
	// }
	// else
	// 	wait(&status);
	return (0);
}