//使用fwrite将[1~10^6]之间的每一个整数写入到文件num.dat中；
#include<stdio.h>
#include<stdlib.h>

int main(){
	FILE* pf = fopen("num.dat","w");
	if(!pf){
		printf("打开文件失败\n");
		return ;
	}
	printf("打开/创建文件成功\n");
	int i = 0;
	for(i = 0;i < 1000000;i++){
		fwrite(&i,sizeof(int),1,pf);	
	}
	printf("写入数据成功\n");
	int res = fclose(pf);
	if(EOF == res){
		perror("fclose");
		exit(-1);
	}
	printf("成功关闭\n");
	pf = NULL;
	return 0;
}
