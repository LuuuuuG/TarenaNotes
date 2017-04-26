/*
用数组改写斐波那契数列。
用三种不同的方法
	思路：延长数组生命周期，加快程序运行。
*/
#include <stdio.h>
/*方法一  将数组放在主函数内
int fei(int arr[],int num){
 	int i = 0;
	for(i = 0;i <= num;i++){
		if(i <= 1){
			arr[i] = 1;
		}
		else{
	  		arr[i] = arr[i - 1] + arr[i - 2]; 
		}
	}
		return arr[num];
}

int main(){
	int num = 0;
	printf("plz input the code:");
	scanf("%d",&num);
	int arr[num];
	printf("the number is %d\n",fei(arr,num));
	return 0;
}*/


//Mr.Yang

int arr[50];	//法2 将数组改为全局变量
				//全局数组不需要初始化
int fei(int num){
//   static int arr[50] = {0}; //法3 延长数组生命周期
	if(num <= 1){ 
        return 1;
    }   
    if(!arr[num - 2]){
		arr[num - 2] = fei(num - 2);
	}
    if(!arr[num - 1]){
		arr[num - 1] = fei(num - 1);
	}
	 return fei(num - 1) + fei(num - 2); 
}

int main(){
    int num = 0;
    printf("plz input the code:");
    scanf("%d",&num);
    printf("the number is %d\n",fei(num));
    return 0;
}
















