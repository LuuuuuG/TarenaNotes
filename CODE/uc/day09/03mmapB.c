//通过i映射的方式将文件emp.dat中的3个员工信息打印出来
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#include<sys/mman.h>

typedef struct{
	int id;
	char name[20];
	double salary;
}Emp;
int main(){
	system("clear");
	//1 打开文件emp.dat 使用open函数
	int fd = open("emp.dat",O_RDONLY);
	if(-1 == fd){
		perror("open"),exit(-1);
	}
	printf("成功打开文件\n");
/*	//2 修改文件的大小为三个员工的大小
	int res = ftruncate(fd,3*sizeof(Emp));
	if(-1 == res){
		perror("ftruncate");
		exit(-1);
	}
	printf("成功修改文件大小\n");*/
	//3 建立文件到虚拟地址的映射
	void* pv = mmap(NULL,3*sizeof(Emp),PROT_READ,MAP_SHARED,fd,0);
	if(MAP_FAILED == pv){
		perror("mmap"),exit(-1);
	}
	printf("成功建立映射\n");
	//4 使用虚拟地址读取员工信息
	Emp* pe = pv;
	printf("id\t name\t\t salary\t\n");
	printf("%d\t %s\t %lg\n",pe[0].id,pe[0].name,pe[0].salary);
	printf("%d\t %s  \t %lg\n",pe[1].id,pe[1].name,pe[1].salary);
	printf("%d\t %s  \t %lg\n",pe[2].id,pe[2].name,pe[2].salary);
	//5 解除映射
	int res = munmap(pv,3*sizeof(Emp));
	if(-1 == res){
		perror("munmap"),exit(-1);
	}
	printf("成功解除映射\n");
	//6 关闭文件
	res = close(fd);
	if(-1 == res){
		perror("close"),exit(-1);
	}
	printf("成功关闭文件\n");
	return 0;

}

