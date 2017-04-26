#ifndef _BANK_H
#define _BANK_H

//消息的类型
#define M_OPEN 1 //开户
#define M_DESTROY 2  //销户
#define M_SAVE 3 //存钱
#define M_TAKE 4 //取钱
#define M_QUERY 5 //查询
#define M_TRANSF 6 //转帐
#define M_SUCESS 7 //处理成功
#define M_FAILED 8 //处理失败

typedef struct{
	int id;
	char usrname[10];
	char pw[10];
	double money;
}Account;

typedef struct{
	long mtype;//消息的类型
	Account act;//账户信息
}Msg;

void init();//初始化

void client();//客户端

void add();//开户

void server();//服务器







#endif //_BANK_H
