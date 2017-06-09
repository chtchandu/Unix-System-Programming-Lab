#include<sys/stat.h>
#include<sys/types.h>
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/wait.h>

int main(int argc, char const *argv[])
{
	int fd;
	char a;

	fd = open(argv[1],O_RDONLY);

	while(read(fd,&a,1))
	{
		printf("%c",a);
	}
	return 0;
}