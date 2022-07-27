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
        char ch = 'A';
//创建一个socket
        sockfd = socket(AF_INET,SOCK_STREAM, 0);
//命名socket
        address.
    }