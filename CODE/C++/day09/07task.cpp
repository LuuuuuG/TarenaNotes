/*************************************************************************
    > File Name: 04return.cpp
    > Author: Mr.Gang
    > mail: 776881718@qq.com
    > Created Time: 2016年05月23日 星期一 15时05分24秒
 ************************************************************************/
#include<cstdio>   //fopen
#include<errno.h>  //errno
#include<ctime>	
#include<cstring>  //strerror
#include<iostream>
using namespace std;
class FileError {
public:
	FileError(time_t time,string const& file,int line,
			string const& func,string const& desc):
		m_time(time),m_file(file),m_line(line),
		m_func(func),m_desc(desc){}
	friend ostream& operator << (ostream& os,
			FileError const& err){
		tm* local = localtime(&err.m_time);
				cout << '[' << local->tm_year + 1900
					<< "年" << local->tm_mon +1
					<< "月" << local->tm_mday 
					<< "日" << ' '
					<< local->tm_hour << ':'
					<< local->tm_min << ':'
					<< local->tm_sec << ' '
					<< err.m_file << ' ' << err.m_line << ' '
					<< err.m_func << "]" << err.m_desc;
	}
private:
	time_t m_time;//出错时间
	string m_file;//出错文件
	int	   m_line;//出错行号
	string m_func;//出错函数
	string m_desc;//错误描述
};


class A {
public:
	A (void) {
		cout << "A构造" << endl;
	}
	~A (void){
		cout << "A析构" << endl;
	}
};
void fuck(void){
	A a;
	cout << "调用fopen前" << endl;
	FILE* fp = fopen("none","r");
	if(!fp){
//		perror ("fopen");
//		throw 100;
		throw FileError (time(NULL),
				__FILE__,__LINE__,__func__,
				strerror(errno));
	}
	cout << "fopen 成功" << endl;
	fclose(fp);
}
void shit(void){
	A a;
	cout << "调用fuck前" << endl;
	fuck();
	cout << "调用fuck后" << endl;
}
void bitch(void){
	A a;
	cout << "调用shit前" << endl;
	shit();
	cout << "调用shit后" << endl;
}
int main(){
	try{
		A a;
		cout << "调用bitch前" << endl;
		bitch();
		cout << "调用bitch后" << endl;
	}
	catch (FileError& ex){
		
		//	cout << "失败!" << endl;
			cout << ex << endl;
			return -1;
	}
	cout << "成功！" << endl;
	return 0;
}
