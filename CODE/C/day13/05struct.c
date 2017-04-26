//
#include<stdio.h>
typedef struct{
	int row,col;
}pt;
typedef struct{
	pt pt1,pt2;
}rect;

int area(const rect *p_rect){  //计算面积
	int ret = (p_rect->pt1.row - p_rect->pt2.row) * (p_rect->pt1.col - p_rect->pt2.col);
	return ret >= 0 ? ret : 0 - ret;
}

int main(){
	rect r = {0};
	printf("请输入长方形的位置：");
	scanf("%d%d%d%d",&(r.pt1.row),&(r.pt1.col),&(r.pt2.row),&(r.pt2.col));
	printf("面积是：%d\n",area(&r));  // ????
	return 0;
}
