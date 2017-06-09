#include<sys/stat.h>
#include<sys/types.h>
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/wait.h>

#define _POSIX_SOURCE

int main()
{
	#ifdef _POSIX_JOB_CONTROL
		printf("%d",_POSIX_JOB_CONTROL);
	#else
		printf("error\n");
	#endif

	#ifdef _POSIX_SAVED_IDS
		printf("%d",_POSIX_SAVED_IDS);
	#else
		printf("error\n");
	#endif

	#ifdef _POSIX_CHOWN_RESTRICTED
		printf("%d",_POSIX_CHOWN_RESTRICTED);
	#else
		printf("error\n");
	#endif

	#ifdef _POSIX_VDISABLE
		printf("%d",_POSIX_VDISABLE);
	#else
		printf("error\n");
	#endif

	#ifdef _POSIX_NO_TRUNC
		printf("%d",_POSIX_NO_TRUNC);
	#else
		printf("error\n");
	#endif

	return 0;
}