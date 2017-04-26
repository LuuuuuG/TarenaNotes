#include<iostream>
using namespace std;

void fuck(int i,double d = 3.14,string s = "字符串"){
//  前面的参数带缺省值后面也必须带有
	cout << i << ',' << d << ',' << s << endl;
}

//void shit(int i = 100){ //常量 缺省值
//void shit(int i = 20+80){//常量表达式 缺省值
/*
int i=100;
void shit(int g = i){//全局变量 缺省值
*/
//void shit(int i,int j = i){
/*
void shit(int i=s){
	static int s=100;
	cout << i << endl;
}
*/
//声明
//void shit(int i = 100);//缺省值只能放在函数声明中
//void shit (int =100); //函数声明中参数名可以省略...
int add(int x,int y,int z = 0){
	return x + y + z;
}

int add(int x,int y){
	return x + y;
}

void shit();
int main(){
	fuck(233,2.13,"你好");
	fuck(250,2.13);//250,2.13,"字符串"
	fuck(333);//333,3.14,"字符串"
//	shit();
//	add(123,456);//有歧义
	add(123,456,789);
	return 0;
}
//定义
void shit(int i/* = 100*/){//定义中不能带有缺省参数,可以加注释
	cout << i << endl;
}
