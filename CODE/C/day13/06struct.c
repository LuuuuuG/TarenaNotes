#include<stdio.h>
typedef struct{
	int row,col;
}pt;

pt *midpt(const pt *p_pt1,const pt *p_pt2,pt *p_mid){
	p_mid->row = (p_pt1->row + p_pt2->row) / 2;
	p_mid->col = (p_pt1->col + p_pt2->col) / 2;
	return p_mid;
}

int main(){
	pt pt1 = {0},pt2 = {0},mid = {0}, *p_pt = NULL;
	printf("plz input a point :");
	scanf("%d%d",&(pt1.row),&(pt1.col));
	printf("plz input another point :");
	scanf("%d%d",&(pt2.row),&(pt2.col));
	p_pt = midpt(&pt1,&pt2,&mid);
	printf("the middle point is (%d, %d)\n",p_pt->row,p_pt->col);
	return 0;
}

