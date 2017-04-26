//09write_emp.c
#include"person.h"
int main(){
	person p1 = {233,"xushaoyuan",233.666};
	//创建文件
	int fd = open("emp.dat",O_RDWR|O_CREAT,0664);
	if(-1 == fd){
		perror("open");
		exit(-1);
	}
	printf("打开/创建文件成功\n");
	//写入数据
	int res = write(fd,&p1,sizeof(person));
	if(-1 == res){
		perror("write");
		exit(-1);
	}
	printf("写入数据成功,写入数据大小是:%d\n",res);
	//关闭文件
	res = close(fd);
	if(-1 == res){
		perror("close");
		exit(-1);
	}
	printf("成功关闭文件\n");

	return 0;
}
