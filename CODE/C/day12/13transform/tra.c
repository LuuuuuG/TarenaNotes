//tra.c
#include <stdio.h>
#include "tra.h"
char ch;
void print(void){
	printf("plz input a letter:");
	scanf("%c",&ch);
	if (ch >= 'A' && ch <= 'Z'){	//大写 => 小写
		ch = ch + 'a' - 'A';
	}
	else if(ch >= 'a' && ch <= 'z'){ // 小写 => 大写	
		ch = ch + 'A' - 'a';
	}
	
}
