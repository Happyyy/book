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
//定义一些变量
	int client_sockfd;
	int server_addr_len;
	struct sockaddr_in client_addr;
	char mesg[MAXDATASIZE]="-v 9 -b 7 -m 7 -t 3";
//为客户端创建一个socket
	client_sockfd = socket(AF_INET,SOCK_STREAM, 0);
//根据服务器的情况命名socket
	client_addr.sin_family = AF_INET;
	client_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	client_addr.sin_port = htons(9734);
	server_addr_len = sizeof(client_addr);
//连接到服务器socket
	connect(client_sockfd,(struct sockaddr *)&client_addr, server_addr_len);
//读写
	send(client_sockfd, mesg, MAXDATASIZE, 0);
	
	close(client_sockfd);
	exit(0);
}








