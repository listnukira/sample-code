#include <stdio.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main() {
	char hostname[128];
	char ip[16];
	struct hostent* host;
	struct sockaddr_in sock_addr;
	int i;

	gethostname(hostname, sizeof(hostname));
	printf("hostname: %s\n", hostname);

	host = gethostbyname(hostname);

	printf("\nhost name alias list:\n");
	for (i = 0; host->h_aliases[i]; ++i) {
		printf("%s\n", host->h_aliases[i]);
	}

	// h_addr_list point to (struct in_addr)
	printf("\nip address list:\n");
	for (i = 0; host->h_addr_list[i]; ++i) {
		sock_addr.sin_addr = *((struct in_addr*) host->h_addr_list[i]);
		inet_ntop(AF_INET, &sock_addr.sin_addr, ip, sizeof(ip));
		printf("%s\n", ip);
	}

	return 0;
}
