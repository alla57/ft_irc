#include <sys/types.h>
#include <sys/socket.h>
#include <iostream>
#include <netinet/in.h>
#include <unistd.h>
#include <sys/wait.h>
// #include <iomanip>
// #include <stdio.h>
// #include <stdint.h>

typedef struct sockaddr t_sockaddr;

int main()
{
	int fd_socket, new_fd;
	int status;
	t_sockaddr socket_struct, their_addr;
	socklen_t addr_size;

	if ((fd_socket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) == -1)
		std::cerr << "socket creation error" << std::endl;
	if (bind(fd_socket, &socket_struct, sizeof(socket_struct)) == -1)
		std::cerr << "socket binding failed" << std::endl;
	if (listen(fd_socket, 2) == -1)
		std::cerr << "socket listening failed" << std::endl;
	addr_size = sizeof(their_addr);
	if ((new_fd = accept(fd_socket, &their_addr, &addr_size)))
		std::cerr << "accept() failed" << std::endl;
	if (fork() == 0)
	{
		std::cout << "i am the child" << std::endl;
		
	}
	else
		wait(&status);
	return (0);
}