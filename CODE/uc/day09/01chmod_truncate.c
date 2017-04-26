#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>


int main(){
	struct stat st = {};
	int res = stat("a.txt",&st);
	if(-1 == res){
		perror("stat");
		exit(-1);
	}
	printf("st.st_mode = %o,st.st_size = %ld\n",st.st_mode&0777,st.st_size);
	
	res = chmod("a.txt",0600);
	if(-1 == res){
		perror("chmod");
		exit(-1);
	}
	printf("修改权限成功\n");

	res = truncate("a.txt",100);
	if(-1 == res){
		perror("truncate");
		exit(-1);
	}
	printf("修改长度成功\n");
	
	res = stat("a.txt",&st);
	if(-1 == res){
		perror("stat");
		exit(-1);
	}
	printf("st.st_mode = %o,st.st_size = %ld\n",st.st_mode&0777,st.st_size);

	
	return 0;

}
