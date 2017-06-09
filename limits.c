#include<sys/stat.h>
#include<sys/types.h>
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/wait.h>
#include<limits.h>

#define _POSIX_SOURCE

int main()
{
	int a;

	a=sysconf(_SC_CLK_TCK);
	printf("%d\n",a);

	a=pathconf("/",_PC_PATH_MAX);
	printf("%d\n",a);

	a=sysconf(_SC_OPEN_MAX);
	printf("%d\n",a);

	a=pathconf("/",_PC_NAME_MAX);
	printf("%d\n",a);

	a=sysconf(_SC_CHILD_MAX);
	printf("%d\n",a);

	return 0;

}