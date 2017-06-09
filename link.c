#include<sys/stat.h>
#include<sys/types.h>
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/wait.h>

int main(int argc, char const *argv[])
{
	link(argv[1],argv[2]);
	return 0;
}