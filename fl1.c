#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
	int fd;
	struct flock p,c;

	fd = open("f1",O_RDWR);

	p.l_type=F_WRLCK;
	p.l_whence=SEEK_SET;
	p.l_start=-100;
	p.l_len=100;

	fcntl(fd,F_SETLK,&p);

	printf("process acquired lock , pid is %d\n",getpid());
	sleep(30);

	p.l_type=F_UNLCK;

	fcntl(fd,F_SETLK,&p);

	printf("process releases lock\n");

	return 0;
}