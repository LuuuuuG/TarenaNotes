//模拟登陆程序、
#include<stdio.h>
#include<string.h>
int main(){
	char usr[10] = {0},pw[10] = {0};
	int i = 0;
	for(i = 1;i <= 3;i++){
			printf("plz input user name:");
			fgets(usr,10,stdin);
			if(strlen(usr) == 9 && usr[8] != '\n'){//clean 
				scanf("%*[^\n]");
				scanf("%*c");
			}
			if(strcmp(usr,"admin\n")){   
				continue;
			}

			printf("plz input passward:");
			fgets(pw,10,stdin);
			if(strlen(pw) == 9 && pw[8] != '\n'){//clean 
				scanf("%*[^\n]");
				scanf("%*c");
			}
			if(strcmp(pw,"123456\n")){   
				continue;
			}
			break;
	}
	if(i <= 3){ //异常结束 登陆成功
		printf("succed login\n");
	}
	else{	//正常结束 登陆失败
		printf("fail to login\n");
	}

	return 0;
}
