#include<iostream>
using namespace std;

struct Student{
	char name[1024];
	int age;
	char info[4096];
};
//引用不会发生内存复制，效率更高
void print (Student const& s){ //常引用
	cout << "姓名：" << s.name << endl;
//	cout << "年龄：" << s.age++ << endl;
	cout << "年龄：" << s.age << endl;
	cout << "简历：" << s.info << endl;
}
void show(int const& cr){
	cout << cr << endl;
}
void disp(int& r){
	cout << r << endl;
}
int fuck(){
	int x = 4;
	return x;
}

int main(){
	Student s = {"徐少远",18,"全国花样撸管冠军！"};
	print (s);
//	print (s);

	show(10);
//	disp(10);//error  10是临时变量 将亡右值a
	int a = 1,b = 2;
	show(a+b);
//	disp(a+b);//error
	double c = 3.45;	//隐士转换会将值方式临时变量中,不可修改
	show(c);
//	disp(c);
	show(fuck());	//返回值也是常量
//	disp(fuck());//error

	return 0;
}
