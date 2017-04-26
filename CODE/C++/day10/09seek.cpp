/*************************************************************************
    > File Name: 09seek.cpp
    > Author: Mr.Gang
    > mail: 776881718@qq.com
    > Created Time: 2016年05月24日 星期二 17时19分27秒
 ************************************************************************/

#include<iostream>
#include<fstream>
using namespace std;

int main(){
	fstream fs ("seek.txt",ios::in|ios::out);
	fs << "0123456789"; 
	fs.seekp (-7,ios::cur); 
	fs << "ABCD";  //写

	fs.seekg (0,ios::beg);//从头读
	int i;
	fs >> i;
	cout << i << endl;//12

	fs.seekg (-3,ios::end);//从距离尾-3的地方读
	fs >> i;
	cout << i << endl;//789

	return 0;
}
