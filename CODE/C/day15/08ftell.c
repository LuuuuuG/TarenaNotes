//位置指针演示
#include <stdio.h>
int main(){
    char ch = 0;
    FILE *p_file = fopen("abc.txt","rb");
    if (p_file) {
        fseek(p_file,2,SEEK_SET);  //将位置指针置于文件头后2位
		printf("%ld\n",ftell(p_file));  //打印位置指针当前位置
        fread(&ch,sizeof(char),1,p_file);
        printf("%c\n",ch);
		
        fseek(p_file,4,SEEK_CUR);  //将位置指针置于当前位置后4位
        printf("%ld\n",ftell(p_file));
        fread(&ch,sizeof(char),1,p_file); 
        printf("%c\n",ch);
       
	  	fseek(p_file,-4,SEEK_END);  //将位置指针置于文件尾前4位
        printf("%ld\n",ftell(p_file));
        fread(&ch,sizeof(char),1,p_file);
        printf("%c\n",ch);

		rewind(p_file);			//把位置指针设置成0
        printf("%ld\n",ftell(p_file));
        fclose(p_file);
        p_file = NULL;
    }   
    return 0;
}
