#include <stdio.h>
#define		CHR(ch)		((ch) >= 'a' && (ch) <= 'z' ? (ch) +'A' -'a' : (ch) - 'A' +'a')
int main(){
	char ch = 0;
	printf("plz input a char:");
	scanf("%c",&ch);
	printf("Change after is: %c\n",CHR(ch));
	return 0;
}






