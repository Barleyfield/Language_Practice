#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define TIME_SERVER "127.0.0.1"
#define TIME_PORT 5010

int main() {
	int sock = 0;
	struct sockaddr_in server;
	char buf[256];
	memset(buf, 0, 256);
	if((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
		printf("Socket Error!\n");
		exit(1);
	}

	server.sin_family = AF_INET;
	server.sin_addr.s_addr = inet_addr(TIME_SERVER);
	server.sin_port = htons(TIME_PORT);
	bzero(&(server.sin_addr), 8);

	if(connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
		printf("Connect Error!\n");
		exit(1);
	}

	if(recv(sock, buf, sizeof(buf), 0) < 0) {
		printf("Receive Error!\n");
		exit(1);
	}

	printf("Time Information from server is %s\n", buf);
	close(sock);


	return 0;
}