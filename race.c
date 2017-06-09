#include<sys/stat.h>
#include<sys/types.h>
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/wait.h>

void disp(char *s)
{
	char *p;
	char c;

	p=s;

	while(c=*p++)
	{
		putc(c,stdout);
		fflush(stdout);
		sleep(1);
	}
}

int main()
{
	int pid;

	pid =fork();

	if(pid==0)
	{
		disp("child");
	}

	else
	{
		disp("parent");
	}
	return 0;
}
