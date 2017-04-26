#include <stdio.h>
#include <stdlib.h>
typedef struct{
	int row,col;
}pt;

pt *midpt(const pt *p_pt1,const pt *p_pt2){
	pt *p_mid = (pt *)malloc(sizeof(pt));
	if(p_mid){
		p_mid->row = (p_pt1->row + p_pt2->row) / 2;
		p_mid->col = (p_pt1->col + p_pt2->col) / 2;
	}
	return p_mid;
}

int main(){
	pt pt1 = {0},pt2 = {0};
	pt *p_mid = NULL;
	printf("plz input 1st point:");
	scanf("%d%d",&(pt1.row),&(pt1.col));
	printf("plz input 2ed point:");
	scanf("%d%d",&(pt2.row),&(pt2.col));
	p_mid = midpt(&pt1,&pt2);
	if(p_mid){
		printf("the middle point is (%d, %d)\n",p_mid->row,p_mid->col);
		free(p_mid);
		p_mid = NULL;
	}
	return 0;
}
