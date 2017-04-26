#include<iostream>
using namespace std;

/*void fuck(char const* path){
}*//*
void fuck(void){
}
*/
void fuck(char const* /*哑元*/){ //传参数也不用
}

//利用哑元 构成人为重载
void bar(void){
	cout << 1 << endl;
}
void bar(int){
	cout << 2 << endl;
}

int main(){
	fuck("./etc/fuck.cfg");
	bar();
	bar(1);
	return 0;
}
