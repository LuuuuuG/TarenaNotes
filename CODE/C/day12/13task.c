#include<stdio.h>
#define		SWAP1(ch)	ch >= 'a' && ch <= 'z' ? ch + 'A' - 'a' : 0	
#define		SWAP2(ch)	ch >= 'A' && ch <= 'Z' ? ch + 'a' - 'A' : 0
int main(){
	char ch = 0;
	printf("plz input a char:");
	scanf("%c",&ch);
	if (ch >= 'a' && ch <= 'z'){
		printf("%c\n",SWAP1(ch));
	}
	else if (ch >= 'A' && ch <= 'Z'){
		printf("%c\n",SWAP2(ch));
	}
	else{
		printf("ERROR\n");
	}
	return 0;
}
