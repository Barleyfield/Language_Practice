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
	struct sockaddr_in server, client;
	int server_len = sizeof(server);
	char buf[256];
	int buf_len = 0;

	server.sin_family = AF_INET;
	server.sin_addr.s_addr = inet_addr(TIME_SERVER);
	server.sin_port = htons(TIME_PORT);

	if((sock = socket(AF_INET, SOCK_DGRAM, 0)) == -1) {
		printf("Socket error!\n");
		exit(1);
	}
	client.sin_family = AF_INET;
	client.sin_addr.s_addr = inet_addr(TIME_SERVER);
	client.sin_port = htons(0);

	if(bind(sock, (struct sockaddr *)&client, sizeof(client)) < 0) {
		printf("Bind Error!\n");
		exit(1);
	}

	buf[0] = '?'; buf[1] = '\0';
	buf_len = sendto(sock, buf, strlen(buf)+1, 0, (struct sockaddr *)&server, server_len);
	if(buf_len < 0) {
		printf("Buffer length Error!\n");
		exit(1);
	}

	buf_len = recvfrom(sock, buf, 256, 0, (struct sockaddr *)0, (int *)0);
	if(buf_len < 0) {
		printf("Buffer length Error!\n");
		exit(1);
	}

	printf("Time information from server is %s\n", buf);
	close(sock);

	return 0;
}