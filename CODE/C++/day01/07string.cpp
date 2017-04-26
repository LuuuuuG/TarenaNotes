#include<cstdio>
#include<cstring>//c字符串处理
#include<iostream>
//#include<string>//c++字符串处理
using namespace std;

int main(){
/*
	char text[12];
	scanf("%s",text);
	printf("%s\n",text);
*/
/*	string text;
	cin >> text;
	cout << text << endl;
*/
/*	char s1[ ]="123456789";
	char s2[9];
	strcpy(s2,s1); //strcpy 会复制 '\0'
*/
	string s1="123456789";
	string s2;
	s2=s1;
	cout << s2 << endl;
	string s3 = "ABCDEFG";
	s2=s1+s3;
	cout << s2 << endl;
	string s4="tarena";
	string s5="microsoft";
	cout << (s4 < s5) << endl;//t > m  假 0
	s5[0]='M';
	cout << s5 <<endl;
	cout << s5.size() << endl;
	cout << s5.length() << endl;

	char const* p = s5.c_str();//
	cout << p << endl;
	cout << strlen (p) << endl;

	cout << sizeof(s4) << ' ' <<sizeof(s5) << endl;
	return 0;
}
