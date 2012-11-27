#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define SERVER_ADDR "140.113.216.151"
#define SERVER_PORT 12346
#define PRIME 43

void decrypt(char* data, char* skey, int len, int prime);
void encrypt(char* data, char* skey, int len, int prime);

int main()
{
	char host_addr[16];
	char hostname[128];
	char send_data[1024];
	char recv_data[1024];
	char skey[33];
	struct sockaddr_in server_addr, cli_addr;
	int sockfd, rc, len;

	// Connect to server
	if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		perror("Can't open stream socket.");
		exit(-1);
	}

	// Set server_addr
	bzero(&server_addr, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = inet_addr(SERVER_ADDR);
	server_addr.sin_port = htons(SERVER_PORT);

	// Connect to server
	if((connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr))) < 0) {
		perror("Connect server error.");
		close(sockfd);
		exit(-1);
	}
	printf("Connect OK\n");
	printf("[initialAuthentication] Start Initial\n");

	// Get host ip address
	bzero(&cli_addr, sizeof(cli_addr));
	len = sizeof(cli_addr);
	getsockname(sockfd, (struct sockaddr *)&cli_addr, &len);
	inet_ntop(AF_INET, &cli_addr.sin_addr, host_addr, sizeof(host_addr));

	// Step 0
	printf("[Authentication] Authentication Step 0\n");
	len = sprintf(&send_data[4], "%s", "/hello");
	len = htonl(len); // for memcpy use, convert to big endian
	memcpy(send_data, &len, sizeof(len));
	if ((rc = write(sockfd, send_data, strlen(&send_data[4]) + 4)) < 0) {
		close(sockfd);
		exit(-1);
	}

	// Step 1
	if ((rc = read(sockfd, &recv_data, 1024)) < 0) {
		close(sockfd);
		exit(-1);
	}
	printf("[Authentication] Authentication Step 1\n");

	// Step 2
	printf("[Authentication] Authentication Step 2\n");
	len = sprintf(&send_data[4], "/sendIP %s", host_addr);
	len = htonl(len);
	memcpy(send_data, &len, sizeof(len));
	if ((rc = write(sockfd, send_data, strlen(&send_data[4]) + 4)) < 0) {
		close(sockfd);
		exit(-1);
	}

	// Step 3
	if ((rc = read(sockfd, &recv_data, 1024)) < 0) {
		close(sockfd);
		exit(-1);
	}
	memcpy(&skey, &recv_data[9], sizeof(skey));
	printf("[Authentication] Authentication Step 3\n");
	printf("[Authentication] Authentication OK\n");

	printf("Authentication OK!\n");
	printf("Enter Control State\n");

	while ((rc = read(sockfd, &recv_data, 1024)) > 0) {
		printf("[Control] Receive command\n");
		recv_data[rc] = '\0';

		decrypt(&recv_data[4], skey, rc - 4, PRIME);
		 printf("%s\n", &recv_data[4]);

		len = sprintf(&send_data[4], "%s", &recv_data[16]);
		printf("%s\n", &send_data[4]);
		encrypt(&send_data[4], skey, len, PRIME);

		len = htonl(len);
		memcpy(send_data, &len, sizeof(len));
		if ((rc = write(sockfd, send_data, strlen(&send_data[4]) + 4)) < 0) {
			close(sockfd);
			exit(-1);
		}
		//printf("%s\n", &recv_data[4]);
		//decrypt(&send_data[4], skey, strlen(&recv_data[16]), PRIME);
		//printf("%s\n", &send_data[4]);
	}

	close(sockfd);
	return 0;
}

void decrypt(char* data, char* skey, int len, int prime)
{
	int i;
	for (i = 0; i < len; ++i) {
		data[i] = data[i] ^ skey[i % prime];
	}
}

void encrypt(char* data, char* skey, int len, int prime)
{
	decrypt(data, skey, len, prime);
}
