#ifndef _BANK_H
#define _BANK_H

#include <sys/types.h>

#define KEY_REQUEST 0x12345678
#define KEY_RESPOND 0x87654321

#define TYPE_OPEN     8001
#define TYPE_CLOSE    8002 
#define TYPE_SAVE     8003
#define TYPE_WITHDRAW 8004
#define TYPE_QUERY    8005
#define TYPE_TRANSFER 8006

typedef struct tag_Account {
	int    id;
	char   name[256];
	char   passwd[9];
	double balance;
}	ACCOUNT;

typedef struct tag_OpenRequest {//开户请求
	long   type;
	pid_t  pid;
	char   name[256];
	char   passwd[9];
	double balance;
}	OPEN_REQUEST;

typedef struct tag_OpenRespond {//开户响应
	long type;
	char error[512];
	int  id;
}	OPEN_RESPOND;

typedef struct tag_CloseRequest {//清户请求
	long   type;
	pid_t  pid;
	int    id;
	char   name[256];
	char   passwd[9];
}	CLOSE_REQUEST;

typedef struct tag_CloseRespond {//清户响应
	long   type;
	char   error[512];
	double balance;
}	CLOSE_RESPOND;

typedef struct tag_SaveRequest {//存款请求
	long   type;
	pid_t  pid;
	int    id;
	char   name[256];
	double money;
}	SAVE_REQUEST;

typedef struct tag_SaveRespond {//存款响应
	long   type;
	char   error[512];
	double balance;
}	SAVE_RESPOND;

typedef struct tag_WithdrawRequest {//取款请求
	long   type;
	pid_t  pid;
	int    id;
	char   name[256];
	char   passwd[9];
	double money;
}	WITHDRAW_REQUEST;

typedef struct tag_WithdrawRespond {//取款响应
	long   type;
	char   error[512];
	double balance;
}	WITHDRAW_RESPOND;

typedef struct tag_QueryRequest {//查询请求
	long   type;
	pid_t  pid;
	int    id;
	char   name[256];
	char   passwd[9];
}	QUERY_REQUEST;

typedef struct tag_QueryRespond {//查询响应
	long   type;
	char   error[512];
	double balance;
}	QUERY_RESPOND;

typedef struct tag_TransferRequest {//转帐请求
	long   type;
	pid_t  pid;
	int    id[2];
	char   name[2][256];
	char   passwd[9];
	double money;
}	TRANSFER_REQUEST;

typedef struct tag_TransferRespond {//转帐响应
	long   type;
	char   error[512];
	double balance;
}	TRANSFER_RESPOND;

#endif // _BANK_H
