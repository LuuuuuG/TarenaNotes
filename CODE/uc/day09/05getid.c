//
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>

int main(){
	printf("pid = %d\n",getpid());
	printf("ppid = %d\n",getppid());
	printf("uid = %d\n",getuid());
	printf("gid = %d\n",getgid());

	return 0;
}
