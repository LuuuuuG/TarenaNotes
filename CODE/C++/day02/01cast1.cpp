#include<iostream>
using namespace std;
//char->int,升级转换
void fuck(char* p,int i){
	cout << 1 << endl;
}
//char*->char const*,加常转换(加const)
void fuck(char const* cp,char c){
	cout << 2 << endl;
}
int main(){
	char* p,c;
	fuck(p,c);//2 加常转换 > 升级转换
	return 0;
}
