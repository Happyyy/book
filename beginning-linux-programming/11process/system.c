#include <stdio.h>
#include <stdlib.h>
int main()
{
	printf("Running ps with system function\n");
	system("ps auxf");
	printf("Done!\n");
	exit(0);
}

