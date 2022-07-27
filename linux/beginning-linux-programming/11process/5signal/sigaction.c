#include <stdio.h>
#include <unistd.h>
#include <signal.h>
void ouch(int sig)
{
        printf("Ouch! I got a signal %d\n",sig);
}

int main()
{
	struct sigaction act;
	act.sa_handler = ouch;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;
	sigaction(SIGINT,&act,0);
	
	while(1)
	{
		printf("Hello world\n");
		sleep(1);
	}
}

