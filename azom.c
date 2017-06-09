#include<sys/stat.h>
#include<sys/types.h>
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
//#include<sys/wait.h>

int main()
{
	int pid;

	pid = fork();

	if(pid == 0)
	{
		printf("chile process pid %d\n",getpid());

		pid =fork();

		if(pid>0)
		{
			exit(1);
		}

		printf(" second child my id %d\n",getpid());
		printf("parent id id %d\n",getppid());
	}

	waitpid(pid,0);

	return 0;
}