//练习
#include<stdio.h>
typedef struct{
	int row;
	int col;
}point;

typedef struct{
	point pt1,pt2;	
}mian;
/*方法一：用结构体变量。
int main(){
	point pt1 = {0,0},pt2 = {0,0},pt_mid = {0,0};
	printf("plz input the adress of pt1:");
	scanf("%d%d",&(pt1.row),&(pt1.col));
	printf("plz input the adress of pt2:");
	scanf("%d%d",&(pt2.row),&(pt2.col));
	pt_mid.row = (pt1.row + pt2.row) / 2;
	pt_mid.col = (pt1.col + pt2.col) / 2;
	printf("middle of two point is %d %d\n",pt_mid.row,pt_mid.col);
	return 0;
}
*/
//方法二：结构体指针。
int main(){
	point pt1 = {0,0},pt2 = {0,0},mid = {0,0};
	point *p_pt1 = &pt1;
	point *p_pt2 = &pt2;
	point *p_mid = &mid;
	printf("plz input the adress of pt1:");
	scanf("%d%d",&(pt1.row),&(pt1.col));
	printf("plz input the adress of pt2:");
	scanf("%d%d",&(pt2.row),&(pt2.col));
	p_mid->row = (p_pt1->row + p_pt2->row) / 2;
	p_mid->col = (p_pt1->col + p_pt2->col) / 2;
	printf("middle of two point is %d %d\n",p_mid->row,p_mid->col);
	return 0;
}

