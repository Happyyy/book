#include <signal.h>
#include <stdio.h>
#include <unistd.h>
void ouch (int a)
{
	printf("OUCH, I GOT A SIGNAL %d\n",a);
	signal(SIGINT,SIG_DFL);
}
int main()
{
	signal(SIGINT,ouch);
	while(1) {
		printf("Hello,World!\n");
		sleep(1);
	}
}
