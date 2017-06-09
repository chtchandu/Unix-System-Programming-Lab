#include<sys/stat.h>
#include<sys/types.h>
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
	int pid ;

	pid = fork();

	if(pid >0)
	{
		sleep(10);
		system("ps -el");
	}

	if(pid == 0)
	{
		printf("child process\n");
		exit(0);
	}

	return 0;
}