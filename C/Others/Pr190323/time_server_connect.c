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
	int sock = 0, sock2 = 0;
	struct sockaddr_in server, client;
	int len;
	char buf[256];
	memset(buf, 0, 256);
	time_t today;

	if((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
		printf("Socket Error!\n");
		exit(1);
	}

	server.sin_family = AF_INET;
	server.sin_addr.s_addr = inet_addr(TIME_SERVER);
	server.sin_port = htons(TIME_PORT);
	bzero(&(server.sin_addr), 8);


	if(bind(sock, (struct sockaddr *)&server, sizeof(server)) == -1) {
		printf("Bind Error!\n");
		exit(1);
	}

	if(listen(sock, 5) == -1) {
		printf("Listen Error!\n");
		exit(1);
	}

	while(1) {
		if((sock2 = accept(sock, (struct sockaddr *)&client, &len)) == -1) {
			printf("Accept Error!\n");
			exit(1);
		}
		time(&today);
		strcpy(buf, ctime(&today));
		send(sock2, buf, strlen(buf)+1, 0);
		close(sock2);
	}


	return 0;
}