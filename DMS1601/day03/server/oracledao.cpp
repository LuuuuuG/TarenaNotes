// 实现Oracle数据访问对象类
#include <iostream>
using namespace std;
#include "oracledao.h"
// 构造器
OracleDao::OracleDao (string const& username,
	string const& password)
	throw (DBException) {
	cout << "建立数据库连接开始..." << endl;

	cout << "建立数据库连接完成。" << endl;
}
// 析构器
OracleDao::~OracleDao (void) {
	cout << "关闭数据库连接开始..." << endl;

	cout << "关闭数据库连接完成。" << endl;
}
// 插入
void OracleDao::insert (MLogRec const& log)
	throw (DBException) {
	cout << "插入数据库开始..." << endl;
	cout << log << endl;
	cout << "插入数据库完成。" << endl;
}
