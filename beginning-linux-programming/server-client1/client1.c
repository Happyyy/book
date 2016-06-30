#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/un.h>
#include <sys/types.h>
#include <sys/socket.h>

int main()
{//一些变量定义
	int sockfd;
	int len;
	struct sockaddr_un address;
	int result;
	char ch = 'A';
//为客户端创建一个socket
	sockfd = socket(AF_UNIX, SOCK_STREAM, 0);
//根据服务器的情况给socket命名
	address.sun_family = AF_UNIX;
	strcpy(address.sun_path, "server_socket");
	len = sizeof(address);
//将我们的socket连接到服务器的socket
	result = connect(sockfd, (struct sockaddr *)&address, len);
	if(result == -1)
	{
		perror("opps:client1");
		exit(1);
	}
//现在就可以通过socket进行读写操作了
	write(sockfd, &ch, 1);
	read(sockfd, &ch ,1);
	printf("char from server = %c\n", ch);
	close(sockfd);
	exit(0);
} 
