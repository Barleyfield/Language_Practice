#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <time.h>

#define TIME_SERVER "127.0.0.1"
#define TIME_PORT 5010

int main()
{
	int sock = 0;
	struct sockaddr_in server, client;
	int server_len = 0;
	int client_len = sizeof(client_len);
	char buf[256];
	int buf_len = 0;
	time_t today;

	if((sock = socket(AF_INET, SOCK_DGRAM, 0)) == -1) {
		printf("Socket Error!\n");
		exit(1);
	}

	server.sin_family = AF_INET;
	server.sin_addr.s_addr = inet_addr(TIME_SERVER);
	server.sin_port = htons(TIME_PORT);

	if(bind(sock, (struct sockaddr *)&server, sizeof(server)) == -1) {
		printf("Bind Error!\n");
		exit(1);
	}

	while(1) {
		memset(buf, 0, 256);
		buf_len = recvfrom(sock, buf, 256, 0, (struct sockaddr *)&client, &client_len);
		if(buf_len < 0) {
			printf("Buffer Length Error!\n");
			exit(1);
		}
		printf("Server : Got %s\n", buf);

		time(&today);
		strcpy(buf, ctime(&today));
		sendto(sock, buf, strlen(buf)+1, 0, (struct sockaddr *)&client, client_len);
	}

	return 0;
}