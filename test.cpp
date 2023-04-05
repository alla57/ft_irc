#include <sys/types.h>
#include <sys/socket.h>
#include <iostream>
// #include <stdint.h>

typedef struct sockaddr t_sockaddr;

int main()
{
	uint16_t a = 25;
	uint8_t *p;
	p = (uint8_t *)&a;
	std::cout << p[0] << std::endl;
	std::cout << p[1] << std::endl;
}