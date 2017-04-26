//03seek.c
//使用lseek函数调整文件的读写位置
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
//a.txt : abcdefjhijklmn
int main(){
	//1.打开文件a.txt 使用open函数
	//默认读写位置是文件的开头位置
	int fd = open("a.txt",O_RDWR);
	if(-1 == fd){
		perror("open");
		exit(-1);
	}
	printf("打开文件成功\n");
	//2.调整文件的读写位置 使用lseek函数
	printf("\n-*-*-*-*-*-*--*-*-*-\n");
	/*读写操作执行完毕之后自动指向下一位*/
	char cv;
	read(fd,&cv,1);
	printf("cv = %c\n",cv); //'a'
	
	read(fd,&cv,1);
	printf("cv = %c\n",cv); //'a'
	
	write(fd,"C",1);  //覆盖‘c’
	
	read(fd,&cv,1);
	printf("cv = %c\n",cv); //'d'
	
	printf("\n-*-*-*-*开头-*-*--*-*-*-\n");
	//实现从文件开头位置想后偏移5个字节
	int len = lseek(fd,5,SEEK_SET);
	if(-1 == len){
		perror("lseek"),exit(-1);
	}
	printf("len = %d\n",len); //5
	read(fd,&cv,1);
	printf("cv = %c\n",cv);  //f

	//实现从文件开头位置向前偏移3个字节
/*	len = lseek(fd,-3,SEEK_SET);   //error
	if(-1 == len){
		perror("lseek"),exit(-1);
	}
	printf("len = %d\n",len);	//执行不到
	
*/	
	printf("\n-*-*-*-*当前-*-*--*-*-*-\n");
	//从当前位置向后偏移3字节
	len = lseek(fd,3,SEEK_CUR);
	if(-1 == len){
		perror("lseek"),exit(-1);
	}
	read(fd,&cv,1); 
	printf("cv = %c\n",cv);//j, 指向k

	//从当前位置向前偏移2字节
	len = lseek(fd,-2,SEEK_CUR);
	if(-1 == len){
		perror("lseek");
		exit(-1);
	}
	write(fd,"I",1);// 覆盖‘i’ 指向j
	read(fd,&cv,1);
	printf("cv = %c\n",cv); //j,指向k
	
	printf("\n-*-*-*-*末尾-*-*--*-*-*-\n");
	//调整读写位置到文件末尾,打印函数返回值
	len = lseek(fd,0,SEEK_END);
	if(-1 == len){
		perror("lseek");
		exit(-1);
	}
	printf("len = %d\n",len); //len = 15
	
	//末尾位置向前偏移1个字节
	len = lseek(fd,-1,SEEK_END);
	if(-1 == len){
		perror("lseek");
		exit(-1);
	}
	read(fd,&cv,1);
	// 'a' = 97  'A' = 65  '0' = 48  '\n' = 10
	printf("cv = %c[%d]\n",cv,cv); // \n   10
	
	//从文件末尾向后偏移3个字节
	len = lseek(fd,3,SEEK_END);
	if(-1 == len){
		perror("lseek");
		exit(-1);
	}
	len = write(fd,"hello",5);
	if(-1 == len){
		perror("write");
		exit(-1);
	}

	//3。关闭文件a.txt 使用close函数
	printf("\n-*-*-*-*-*-*--*-*-*-\n");
	int res = close(fd);
	if(-1 == res){
		perror("close"),exit(-1);
	}
	printf("成功关闭文件\n");
	return 0;
}
