#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	pid_t pid;
	char *message;
	int n,exit_code;
	pid = fork();
	switch(pid) 
	{
	case -1:
		message = "fork failed\n";
		exit(1);
	case 0:
		message = "This is child\n";
		n = 5;
		exit_code = 36;
		break;
	default:
		message = "This is parent\n";
		n = 3;
		exit_code = 0;
		break;
	}


	for(;n>0;n--)
        {
	        puts(message);
        	sleep(1);
        }


	if(pid != 0)
        {
                int stat_val;
                pid_t child_pid;
                child_pid = wait(&stat_val);
		printf("Child process finished successfully.The child pid is %d\n",child_pid);
                if(WIFEXITED(stat_val))
                {
                        printf("exit with the code:%d\n",WEXITSTATUS(stat_val));
                }
                else
                {
                        printf("Child process terminated abnormally\n");
                }
	}	  
	exit(exit_code);
}	
