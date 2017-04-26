#include<stdio.h>
typedef struct{
	int row,col;
}pt;

typedef struct{
	pt center;	//结构体嵌套~
	int radius;
}circle;

const circle *larger(const circle *p_cl1,const circle *p_cl2){
	return p_cl1->radius >= p_cl2->radius ? p_cl1 : p_cl2;
}

int main(){
	circle cl1 = {0},cl2 = {0};
	const circle *p_cl = NULL;
	printf("piz input address of one circle:");
	scanf("%d%d%d",&(cl1.center.row),&(cl1.center.col),&(cl1.radius));
	printf("piz input address of another circle:");
	scanf("%d%d%d",&(cl2.center.row),&(cl2.center.col),&(cl2.radius));
	p_cl = larger(&cl1,&cl2);
	printf("result is ((%d, %d), %d)\n",p_cl->center.row,p_cl->center.col,p_cl->radius);
	return 0;
}
