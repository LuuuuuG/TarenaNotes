//结构体练习
#include<stdio.h>
typedef struct{
	int row,col;
}pt;


/*ONE结构体做形参 not good!
void print(pt pt1){
	printf("(%d, %d)\n",pt1.row,pt1.col);
}
int main(){
	pt pt1 = {4,7};
	print(pt1);
	return 0;
}
*/

//TWO结构体指针做形参
void print(pt *p_pt){ //结构体指针做形参时，尽量加const关键字。
	printf("(%d, %d)\n",p_pt->row,p_pt->col);
}


/*ONE结构体变量作返回值
pt read(void){
	pt pt1 = {0};
	printf("plz input adress of the point:");
	scanf("%d%d",&(pt1.row),&(pt1.col));
	return pt1;
}*/

//TWO
pt *read(pt *p_pt){
	printf("plz input adress of the point:");
	scanf("%d%d",&(p_pt->row),&(p_pt->col));
	return p_pt;

}
int main(){
	pt pt1 = {0},*p_pt = NULL;
	p_pt = read(&pt1);
	print(p_pt);
	return 0;
}
