//stu.h
#ifndef _STU_H
#define _STU_H
typedef struct Stu{
	int id;//学号	//4 + 20 +8*4 + 4 = 60
	char name[20];	//20
	double English;
	double Chinese;
	double Math;
	double sum;//总成绩
	struct Stu* next;//保存下一个节点   //4
}stu;
//声明功能函数
//1 打开文件
void myopen();
//2 界面
void init(stu *p_head);
//3 增加
void add(stu *p_head);
//4 打印
void show(stu *p_head);
//5 求学员个数
int len(stu *p_head);
//6 删除
void dele(stu *p_head);
//7 查找
void seek(stu *p_head);
//8 修改
void rev(stu *p_head);
//9 排序
void sort(stu *p_head);
//10 保存
void keep(stu *p_head);
//11 退出
void quit(stu *p_head);

#endif	//_STU_H
