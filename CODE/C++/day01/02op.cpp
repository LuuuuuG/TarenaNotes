#include<iostream>
#include<stdio.h>

int main(){
//	printf("请输入一个表达式：");
	std::cout<<"请输入一个表达式：";
	int x,y;
	char op;
//	scanf("%d%c%d",&x,&op,&y);
	std::cin>>x>>op>>y;
	int z;
	switch(op){
		case'+':
			z=x+y;
			break;
		case'-':
			z=x-y;
			break;
		case'x':
			z=x*y;
			break;
		case'/':
			z=x/y;
			break;
		default:
//			fprintf(stderr,"无效表达式！\n");
			std::cerr<<"无效表达式！"<<std::endl;
	}
//	printf("%d%c%d=%d\n",x,op,y,z);
	std::cout<<x<<op<<y<<"="<<z<<std::endl;
	return 0;
}
