#include<iostream>
using namespace std;
void fuck(void){
	cout << 1 << endl;
}

void fuck(int a){
	cout << 2 << endl;
}

//void fuck(int b){}

void fuck (int a,double b){
	cout << 3 << endl;
}

void fuck (double a,int b){
	cout << 4 << endl;
}
//上面4个函数都会构成重载关系

/*
int fuck (double a,int b){
	return 0;
}
*/  // 歧义
int main(){

	fuck();//匹配第一个函数
	fuck(1);//第二个
	fuck(1,1.);//第三个
	fuck(1.,1);//第四个
	return 0;
}
