#include"bank.h"
typedef struct{
	long mtype;
	char buf[20];
}Msg;

void add(){
	Account act = {0,"abc","123456",100};
	//提示用户增加开户信息
	printf("请输入账户名称:");
	fgets(act.name,10,stdin);
	if(strlen(act.name) == 9 && act.name[8] != '\n'){
		scanf("%*[^\n]");
		scanf("%*c");
	}
	printf("请输入密码：");
	fgets(act.pw,10,stdin);
	if(strlen(act.pw) == 9 && act.pw[9] != '\n'){
		scanf("%*[^\n]");
		scanf("%*c");
	}
	printf("请输入余额:");
	scanf("%lg",&act.money);
	//打包用户输入的信息到消息的结构体变量中 发送给服务器
	//1 获取key值
	key_t key = ftok(".",100);
	
	//2 发送消息 msgsnd
	Msg msg1 = {};
	
	
	

}
