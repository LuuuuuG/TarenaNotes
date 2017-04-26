#include<iostream>
#include<cstdlib>
using namespace std;

int main(){
	//C方式动态内存分配和释放
	int* p=(int*)malloc(sizeof(int));
	*p = 1234;
	cout << *p << endl;
	free(p);
	//C++方式动态内存分配和释放
	//C++方式动态对象创建和销毁
	p = new int (5678);
	cout << *p << endl;
	delete p;
	p = NULL;
	delete p;

	p = new int[5];//C++98
	p = new int[5] {100,200,300,400,500}; //-std=c++0x
	//int x;  //后缀法，前类型后变量
	// int x[5];  //中缀法，两边类型中间变量
/*
	p[0] = 100;
	p[1] = 200;
	p[2] = p[0] + p[1];
	p[3] = 400;
	p[4] = 500;
*/
	for (size_t i=0;i<5;++i)
		cout << p[i] << ' ';
		cout << endl;
	delete[] p;  //!!!
//	int (*pa)[4] = new int[3][4];//指针数组
	int (*pa)[4] = new int[3][4] {
	{11,12,13,14},
	{21,22,23,24},
	{31,32,33,34}};
	
/*
	for(int i=0;i < 3; ++i)
		for (int j = 0;j < 4; ++j)
			pa[i][j] = (i+1)*10+j+1;
*/
	for(int i=0;i<3;++i){
		for(int j=0;j<4;++j)
			cout << pa[i][j] << ' ';
		cout << endl;
	}
	delete[] pa;
/*	if(){
	
	
	}
	else{
		free(p);
	}
*/	try{
		p= new int[0xFFFFFFFF];
		delete[] p;
	}
	catch (exception& ex){
		perror("new");//打印错误信息
		//清理
		exit(EXIT_FAILURE);//体面地自杀
	}

	return 0;
}
