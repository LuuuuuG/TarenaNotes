/*************************************************************************
    > File Name: 05open.cpp
    > Author: Mr.Gang
    > mail: 776881718@qq.com
    > Created Time: 2016年05月24日 星期二 14时55分48秒
 ************************************************************************/

#include<iostream>
#include<fstream>
using namespace std;

int main(){
	ofstream ofs("open.txt");//写文件
	if(!ofs){
		cout << "无法打开文件!" << endl;
		return -1;
	}
	ofs << 123 << ' ' << 4.56 << ' ' << "apple" << endl;
	ofs.close();
	ofs.open("open.txt",ios::app);//追加
	if(!ofs){
		cout << "无法打开文件!" << endl;
		return -1;
	}
	ofs << "append_line" << endl;
	ofs.close();
	ifstream ifs("open.txt");//读文件
	if(!ifs){
		cout << "无法打开文件!" << endl;
		return -1;
	}
	int i;
	double d;
	string s1,s2;
	ifs >> i >> d >> s1 >> s2;
	cout << i << endl;
	cout << d << endl;
	cout << s1 << endl;
	cout << s2 << endl;
	return 0;
}
