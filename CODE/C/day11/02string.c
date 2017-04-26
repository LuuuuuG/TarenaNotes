#include<stdio.h>

int main(){
	char str[20] = {0};
	printf("%d %g %c\n",34,5.4f,'u');
	
	sprintf(str,"%d %g %c\n",34,5.4f,'u');	//将三个数字形成字符串打印到数组里
	printf("%s\n",str);		//两行效果同上面一行

	int num = 0;
	float fnum = 0.0f;
	char ch = 0;
	sscanf("5.4 p 67","%g %c %d",&fnum,&ch,&num);
	printf("%c %d %g\n",ch,num,fnum);

	return 0;
}
