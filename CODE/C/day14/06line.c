#include <stdio.h>

typedef struct{
	int row,col;
}pt;
typedef struct{
	pt pt1,pt2;
}line;
/* Mr.Yang
//计算线段长度平方的函数
int len2(const line *p_l) {
	return (p_l->pt1.row - p_l->pt2.row) * (p_l->pt1.row - p_l->pt2.row) + (p_l->pt1.col - p_l->pt2.col) * (p_l->pt1.col - p_l->pt2.col);
}
//挑出比较长线段的函数
void longer(const line *p_l1, const line *p_l2, line **pp_l) {
	*pp_l = (line *)(len2(p_l1) > len2(p_l2) ? p_l1 : p_l2);
}*/

void longer(const line *p_l1,const line *p_l2,line **pp_l){
    int m = (((p_l1->pt1.row - p_l1->pt2.row) * (p_l1->pt1.row - p_l1->pt2.row)) + ((p_l1->pt1.col - p_l1->pt2.col) * (p_l1->pt1.col - p_l1->pt2.col)));
    int n = (((p_l2->pt1.row - p_l2->pt2.row) *(p_l2->pt1.row - p_l2->pt2.row)) + ((p_l2->pt1.col - p_l2->pt2.col) * (p_l2->pt1.col - p_l2->pt2.col)));
     *pp_l =(line *)(m > n ? p_l1 : p_l2);
}





int main(){
	line l1 = {0},l2 = {0};
	line *p_l = NULL;
	printf("plz input 1st line:");
	scanf("%d%d%d%d",&(l1.pt1.row),&(l1.pt1.col),&(l1.pt2.row),&(l1.pt2.col));
	printf("plz input 2ed line:");
	scanf("%d%d%d%d",&(l2.pt1.row),&(l2.pt1.col),&(l2.pt2.row),&(l2.pt2.col));
	longer(&l1,&l2,&p_l);
	printf("The longer is (%d, %d),(%d, %d)\n",p_l->pt1.row,p_l->pt1.col,p_l->pt2.row,p_l->pt2.col);
	return 0;
}
