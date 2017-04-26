#include<iostream>
using namespace std;
//short->char ,有损转换
void fuck(char c){
	cout << 1 << endl;
}
//short->int,升级转换
void fuck(int i){
	cout << 2 << endl;
}
//short->long long,过分升级
void fuck(long long i){
	cout << 3 << endl;
}

int main(){
	short s;//2 升级转换 》有损转换
	fuck(s);
}
