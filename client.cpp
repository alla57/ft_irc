#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>
#include <string.h>
#include <netdb.h>
#include <unistd.h>

int main()
{
	int fd_socket;
	struct sockaddr socket_struct;
	struct addrinfo hints, *res;

	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;

	getaddrinfo("127.0.0.1", "3490", &hints, &res);

	if ((fd_socket = socket(res->ai_family, res->ai_socktype, res->ai_protocol)) == -1)
		std::cerr << "socket creation error" << std::endl;
	if (connect(fd_socket, res->ai_addr, res->ai_addrlen) == -1)
		std::cerr << "connection error" << std::endl;
	write(fd_socket, "client: hello", 13);
}