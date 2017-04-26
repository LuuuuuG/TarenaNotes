#include <stdio.h>
int main(){
	int arr[5] = {0},num = 0,size = 0;
	FILE *p_file = fopen("a.bin","rb");
	if(p_file){
		size = fread(arr,sizeof(int),5,p_file);
		printf("size is %d\n",size);
		for(num = 0;num <= 4;num++){
			printf("%d ",arr[num]);
		}
		printf("\n");
		fclose(p_file);
		p_file = NULL;
	}
	return 0;
}


