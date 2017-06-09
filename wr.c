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
	char buf[10]="chandresht";
	mkfifo(argv[1],0777);

	fd = open(argv[1],O_WRONLY);

	write(fd,buf,10);
	
	return 0;
}