#include<iostream>
using namespace std;
//void*->... 省略号匹配
void fuck(double shit,...){
	cout << 1 << endl;
}
//double->int,有损转换
void fuck(int i,void* p){
	cout << 2 << endl;
}

int main(){
	double d;
	void* p;
	fuck(d,p);//2 有损转换 》省略号匹配
	return 0;
}
