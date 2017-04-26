#include<stdio.h>
#include<math.h>
typedef struct{
	int row,col;
}pt;

typedef struct{
	pt pt1,pt2;
}line;


int len2(const line *p_l){
	return (p_l->pt1.row - p_l->pt2.row) * (p_l->pt1.row - p_l->pt2.row) + (p_l->pt1.col - p_l->pt2.col)*(p_l->pt1.col - p_l->pt2.col);
}


const line *longer(const line *p_l1,const line *p_l2){
	return len2(p_l1) > len2(p_l2) ? p_l1 : p_l2;
	
	/*
		int m = (((p_l1->pt1.row - p_l1->pt2.row) * (p_l1->pt1.row - p_l1->pt2.row)) + ((p_l1->pt1.col - p_l1->pt2.col) * (p_l1->pt1.col - p_l1->pt2.col)));
	int n = (((p_l2->pt1.row - p_l2->pt2.row) *(p_l2->pt1.row - p_l2->pt2.row)) + ((p_l2->pt1.col - p_l2->pt2.col) * (p_l2->pt1.col - p_l2->pt2.col)));
*/
/*
	int m = sqrt(((p_l1->pt1.row - p_l1->pt2.row),2) + sqrt((p_l1->pt1.col - p_l1->pt2.col),2));
	int n = sqrt(((p_l2->pt1.row - p_l2->pt2.row),2) + sqrt((p_l2->pt1.col - p_l2->pt2.col),2));
*/
//	return m > n ? p_l1 : p_l2;
}

int main(){
	line l1 = {0},l2 = {0};
	const line *p_l = NULL;
	printf("plz input 1st line :");
	scanf("%d%d%d%d",&(l1.pt1.row),&(l1.pt1.col),&(l1.pt2.row),&(l1.pt2.col));
	printf("plz input 2nd line :");
	scanf("%d%d%d%d",&(l2.pt1.row),&(l2.pt1.col),&(l2.pt2.row),&(l2.pt2.col));
	p_l = longer(&l1,&l2);
	printf("The longer is (%d, %d),(%d, %d)\n",p_l->pt1.row,p_l->pt1.col,p_l->pt2.row,p_l->pt2.col);
	return 0;
}


//Mr.Yang










