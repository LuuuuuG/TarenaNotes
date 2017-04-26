/*************************************************************************
    > File Name: 10string.cpp
    > Author: Mr.Gang
    > mail: 776881718@qq.com
    > Created Time: 2016年05月24日 星期二 17时28分40秒
 ************************************************************************/

#include<iostream>
#include<sstream>
#include<cstdio>
using namespace std;

int main(){
/*	
	char str[1024];
	sprintf(str,"%d %g %s ",123,4.55,"string");
	cout << str << endl;
*/
	ostringstream oss;
	oss << 123 << ' ' << 4.56 << ' ' << "string";
	string str = oss.str();
	cout << str << endl;

	int i;
	double d;
	char s[256];
	sscanf(str,"%d%lf%s",&i,&d,s);
	istringstream
	return 0;
}
