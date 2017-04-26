//errno.c
//使用errno来获取具体的错误原因
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>

int main(){
	printf("出错之前:%d\n",errno);
	printf("strerror:%s\n",strerror(errno));
	perror("perror");
	printf("%m");
	printf("\n------------------\n");
	//1.打开文件/etc/passwd,使用fopen函数	
	FILE* fp = fopen("/etc/passwdd","rb");
	if(NULL == fp){
		printf("打开文件失败\n");
		printf("出错之后:%d\n",errno);
		printf("strerror:%s\n",strerror(errno));
		perror("fopen");
		perror("fp");
		printf("%m");
		printf("\n------------------\n");
//		exit(-1);
	}
	//2.关闭文件etc/passwd文件
//	fclose(fp);
	
	printf("\n------------------\n");
	//联系 使用"wb"方式打开文件/etc/passwd，判断打开是否失败，并用两中方法打印错误信息
	fp = fopen("/etc/passwd","wb");
	if(NULL == fp){
		printf("打开文件失败\n");
		perror("fopen");
		printf("errno = %d\n",errno);
		printf("strerror:%s\n",strerror(errno));
		exit(-1);
	}
	fclose(fp);
	return 0;
}
