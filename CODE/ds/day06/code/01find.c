//使用查找算法查找指定的目标元素
#include<stdio.h>


//1.0 实现线性查找
//平均时间复杂度O(N),对样本的有序性不敏感
int find(int arr[],int len,int data){
	int i = 0;
	for(i = 0;i < len;i++){
		if(data == arr[i]){
			return i;  //返回元素对应的下标
		}
	}
	return -1;	//表示查找失败;
}

//2.0 实现二分查找算法
//平均时间复杂度O(log N),要求样本元素必须有序;
int find_binary(int arr[],int left,int right,int data){
	
	if(left <= right){
		//1.计算中间元素的下标
		int p = (left + right) / 2;
		//2.使用目标元素与中间元素比较大小，相等返回
		if (data == arr[p]){
			return p;
		}
		//3.如果目标元素小于中间元素，则在左边查找 --递归
		else if(data < arr[p]){
			return find_binary(arr,left,p - 1,data);
		}
		//4.如果目标元素大于中间元素，则在右边查找 --递归
		else{
			return find_binary(arr,p + 1,right,data);
		}
	}
	return -1;  //表示查找失败
}


int main(){
	int arr[9] = {10,20,30,40,50,60,70,80,90};
	//int pos = find(arr,9,40);
	int pos = find_binary(arr,0,8,400);
	if(-1 != pos){
		printf("查找目标元素成功，所在下标是:%d\n",pos);//3		
	}
	else{
		printf("目标元素不存在\n");
	}
	return 0;
}
