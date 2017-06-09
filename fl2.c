#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
	int fd;
	char buf[50];
	struct flock s;

	fd = open("f1",O_RDWR);

	s.l_type=F_WRLCK;
	s.l_whence=SEEK_SET;
	s.l_start=-100;
	s.l_len=100;

	while(fcntl(fd,F_SETLK,&s)==-1)
	{
		fcntl(fd,F_GETLK,&s);
		printf("process is already locked by %d\n",s.l_pid);
		sleep(1);
	}

	printf("process got the lock\n");

	lseek(fd,-50,SEEK_END);

	read(fd,buf,50);
	printf("%s",buf);

	s.l_type=F_UNLCK;

	fcntl(fd,F_SETLK,&s);

	printf("process releases lock\n");

	return 0;
}