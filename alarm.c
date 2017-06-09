#include<sys/stat.h>
#include<sys/types.h>
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/wait.h>
#include<signal.h>

void handler(int s)
{
	printf("the signal is %d\n",s);
	alarm(3);
}

int main()
{
	int a=0;

	printf("process sstart\n");
	signal(SIGALRM,handler);
	alarm(5);
	for(;;)
	{
		printf("%d\n",a++);
		sleep(1);
	}

	return 0;

}