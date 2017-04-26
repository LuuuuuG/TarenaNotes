// 定义数据对象类
#ifndef _DATA_H
#define _DATA_H
#include <unistd.h>
#include <iostream>
using namespace std;
// 匹配日志记录
struct MLogRec {
	char  logname[32]; // 登录名
	char  logip[32];   // 登录IP
	pid_t pid;         // 登录进程PID
	long  logintime;   // 登入时间
	long  logouttime;  // 登出时间
	long  durations;   // 登录时段
	friend ostream& operator<< (ostream& os,
		MLogRec const& log) {
		return os << log.logname << ','
			<< log.logip << ','
			<< log.pid << ','
			<< log.logintime << ','
			<< log.logouttime << ','
			<< log.durations;
	}
};
#endif // _DATA_H
