#include<sys/stat.h>
#include<sys/types.h>
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/wait.h>

int mysystem(char *cmd)
{
	int pid,status;

	if(cmd==NULL)
		return 1;

	pid=fork();

	if(pid==-1)
		return -1;

	if(pid==0)
	{
		execl("/bin/sh","sh","-c",cmd,0);
		exit(127);
	}

	if(pid>0)
	{
		waitpid(pid,&status,0);
		printf("system completed\n");
	}

	return status;
}

int main(int argc , char ** argv)
{
	int n;

	n = mysystem(argv[1]);

	switch(n)
	{
		case 1: printf("enter valid command\n");
				break;

		case -1: printf("forking error\n");
				 break;

		case 127: printf("exec error\n");
				 break;
	}

	return 0;
}

