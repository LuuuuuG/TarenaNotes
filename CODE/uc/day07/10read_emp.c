#include"person.h"

int main(){
	//打开文件
	int fd = open("emp.dat",O_RDONLY);
	if(-1 == fd){
		perror("open");
		exit(-1);
	}
	printf("打开文件成功\n");
	//读取数据
	person p1;
	int res = read(fd,&p1,sizeof(person));
	if(-1 == res){
		perror("read");
		exit(-1);
	}
	printf("员工信息:%d %s %lg\n",p1.id,p1.name,p1.salary);
	//关闭文件
	close(fd);
	printf("关闭成功\n");
	return 0;
}
