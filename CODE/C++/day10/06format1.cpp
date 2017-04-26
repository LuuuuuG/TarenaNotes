/*************************************************************************
    > File Name: 06forma.cpp
    > Author: Mr.Gang
    > mail: 776881718@qq.com
    > Created Time: 2016年05月24日 星期二 16时03分40秒
 ************************************************************************/

#include<iostream>
#include<cmath>
using namespace std;
int main(){
	cout << cout.precision () << endl;
	cout << sqrt(200) << endl;
	cout.precision(10);//精度
	cout << sqrt(200) << endl;

	cout << '[' ;
	cout.width (10);//域宽 只有域宽是一次性的 其他设置后就不会变了
	cout << 123 << ']' << endl;

	cout << '[' ;
	cout.width (10);
	cout.fill ('*');//填充*
	cout << 123 << ']' << endl;

	cout << '[' ;
	cout.width (10);
	cout.fill (' ');
	cout.setf(ios::left,ios::adjustfield);//左对齐
	cout << 123 << ']' << endl;

	cout << '[' ;
	cout.width (10);
	cout.setf(ios::internal,ios::adjustfield);//两端对齐
	cout << 123 << ']' << endl;
	
	cout << '[' ;
	cout.width (10);
	cout.setf (ios::showpos);//显示正号
	cout << 123 << ']' << endl;
	

	
	return 0;
}
