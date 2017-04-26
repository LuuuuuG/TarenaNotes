//文件作业

#include <stdio.h>
typedef struct{
	int id;
	float salary;
	char name[10];
}person;

int main(){
	int id = 0;
	FILE *p_file = fopen("person.bin","rb");
	if(p_file){
		while(1){
			
			if(!fread(&id,sizeof(int),1,p_file)){
				break;//不能获得下一个id的时候结束循环。
			}
			printf("%d\n",id);
			fseek(p_file,sizeof(person) - sizeof(int),SEEK_CUR);
			//结构体大小 - int类型大小 = id 之间的距离
		}
	}
	return 0;
}
