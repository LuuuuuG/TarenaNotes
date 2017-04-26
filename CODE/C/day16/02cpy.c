#include <stdio.h>
/*
int main(int argc,char **argv[]){
	int num = 1;
	char arr[0] = {0};
	FILE *p_file = fopen("*(argv + num)","r");
	while(1) {
		if(!fread(&ch,sizeof(ch),1,p_file)){
			break;
		}
	printf("%s",arr);
	FILE *p_file1 = fopen("*(argv + num)","w");
	fwrite(&ch,sizeof(ch),1,p_file1);
	
	return 0;
}
*/



int main(int argc,char **argv){
	char buf[100] = {0};
	int size = 0;
	FILE *p_src = NULL,*p_dest = NULL;
	//打开原始文件
	p_src = fopen(*(argv + 1),"rb");
	if(!p_src){
		printf("原始文件打开失败\n");
		return 0;
	}
	//打开新文件
	p_dest = fopen(*(argv + 2),"wb");
	if(!p_dest){
		printf("原始文件打开失败\n");
		//关闭原始文件
		fclose(p_src);
		p_src = NULL;
		return 0;
	}
	while(1){
		size = fread(buf,sizeof(char),100,p_src);
		if (!size){
		//不能从原始文件里获得任何数字时，结束循环。
			break;
		}
		fwrite(buf,sizeof(char),size,p_dest);

	}
	//关闭新文件
	fclose(p_dest);
	p_dest = NULL;
	//关闭原始文件
	fclose(p_src);
	p_src = NULL;
	return 0;
}













