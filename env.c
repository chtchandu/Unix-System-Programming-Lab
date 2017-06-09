#include<sys/stat.h>
#include<sys/types.h>
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/wait.h>

int main(int argc, char const *argv[],char *env[])
{
	int i;
	while(env[i]!=0)
	{
		printf("%s\n",env[i]);
		i++;
	}
	return 0;
}