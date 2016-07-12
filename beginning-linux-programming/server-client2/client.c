#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
int main()
{
//定义一些变量
	int sockfd;
	int len;
	int result;
	struct sockaddr_in address;
	char ch = '1';
//为客户端创建一个socket
	sockfd = socket(AF_INET,SOCK_STREAM, 0);
//根据服务器的情况命名socket
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = inet_addr("127.0.0.1");
	address.sin_port = 9734;
	len = sizeof(address);
//连接到服务器socket
	result = connect(sockfd,(struct sockaddr *)&address, len);
	if (result == -1)
	{
		perror("Oops: client1");
		exit(1);
	}
//读写
	write(sockfd, &ch, 1);
	read(sockfd, &ch, 1);
	printf("char from server = %c\n",ch);
	close(sockfd);
	exit(0);
}







