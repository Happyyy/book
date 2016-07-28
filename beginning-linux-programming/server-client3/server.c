#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAXDATASIZE 100
int main()
{
	int server_sockfd,server_client_sockfd;
	int server_len,client_len;
	int recvbytes;
	struct sockaddr_in server_address;
	struct sockaddr_in client_address;
//creat an unnamed socket
	server_sockfd = socket(AF_INET,SOCK_STREAM,0);
//name the socket 
	server_address.sin_family = AF_INET;
//server_address.sin_addr.s_addr = inet_addr("127.0.0.1");
	server_address.sin_addr.s_addr = htonl(INADDR_ANY);
	server_address.sin_port = htons(9734);
	server_len = sizeof(server_address);
	bind(server_sockfd,(struct sockaddr *)&server_address,server_len);
//creat listen 
	listen(server_sockfd,5);
	while(1) {
		//char ch;

		char buf[MAXDATASIZE][MAXDATASIZE];
		printf("server waiting...\n");
//accept a connection
		client_len = sizeof(client_address);
		server_client_sockfd = accept(server_sockfd,(struct sockaddr *)&client_address,&client_len);
//read and write
		if ((recvbytes=recv(server_client_sockfd, buf, MAXDATASIZE, 0)) ==-1) 
	{	perror("recv error！");
		exit(1);
	}
		buf[recvbytes] = '\0';
		printf("Received: %s",buf);
		/*system(buf);
		while ((c=getopt_long(argc, buf, GETOPT_FLAGS, long_opts, NULL)) != -1) {
		switch (c) {
			case 'v':
				printf("vv\n");
				break;
			case 'b':
				printf("bbb\n");
				break;
			case 'm':
				printf("mmmmm\n");
				break;
			case 't':
				printf("ttttttt\n");
				break;
			case 'h':
				printf("hhhhhhhhh\n");
				break;
			default:
				printf("default\n");;

		}*/
}
		close(server_client_sockfd);
	}
	close(server_sockfd);
	return 0;
}
