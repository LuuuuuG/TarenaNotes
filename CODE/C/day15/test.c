#include <stdio.h>
int main(){
    char ch = 0;
    FILE *p_file = fopen("abc.txt","rb");
    if (p_file) {
        fseek(p_file,2,SEEK_SET);  //将位置指针置于文件头后2位
        printf("%ld\n",ftell(p_file));  //打印位置指针当前位置
        fread(&ch,sizeof(char),1,p_file);//读1个字符
        printf("%c\n",ch);
		printf("%ld\n",ftell(p_file));
	}   
    return 0;
}
