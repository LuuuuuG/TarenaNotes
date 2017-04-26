//变成实现各种排序算法
#include<stdio.h>

//1.0 冒泡排序算法
// 平均时间复杂度 O(N^2) 稳定 (加了flag)对样本的有序性非常敏感
void bubble(int arr[],int len){
	int i = 0,j = 0;
	//1 使用循环来控制比较的轮数
	for(i = 1;i < len;i++){
		//定义标志位,用来判断内层循环是否进行了交换
		int flag = 1;
		//2 使用循环来控制比较的元素下标范围
		for(j = 0;j < len - i;j++){
			//3 如果左边元素大于右边元素，则交换
			if(arr[j] > arr[j+1]){
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
				flag = 0;
			}
		}
		//如果没有发生任何交换,说明已经是从小到大排序,结束冒泡排序
		if(1 == flag){
			break;//跳出循环
		}
	}
}

//2.0 插入排序
// 平均时间复杂度  O(N^2) 稳定，对样本的有序性非常敏感
void insert(int arr[],int len){
	int i = 0,j = 0;
	//1 使用循环将后续的元素依次取出
	for(i = 1;i < len;i++){
		//2	将取出的元素单独保存起来，避免被覆盖
		int temp = arr[i];
		/*
		  3 使用取出的元素与左边元素一次进行比较，
			如果左边元素大于取出的元素，则左边元素右移			*/
		for(j = i;arr[j - 1] > temp && j >= 1;j--){
			arr[j] = arr[j - 1];
		}
		//4 知道左边元素不再大于取出元素，则插入取出元素到左边元素的右边
		if(j != i){	//为了避免元素自己给自己赋值
			arr[j] = temp;
		}
	}
}

//3.0 选择排序
// 平均时间复杂度  O(N^2) 不稳定,对样本有序性不敏感
void choose(int arr[],int len){
	int i= 0,j = 0;
	//1 使用循环将第一个元素起依次取出
	for(i = 0;i < len - 1;i++){
		//2 使用临时变量记录取出元素的下标
		int min = i;
		//3 使用min记录的最小值与后续元素一次比较
		for(j = i + 1;j < len;j++){
			//4 如果后续元素中有小于min记录最小值的元素，则重新记录后续的这个元素
			if(arr[j] < arr[min]){
				min = j;
			}
		}
		//5 直到使用min记录的元素与后续所有元素比较完毕为止,交换记录元素与最开始假定的元素
		if(min != i){	//min变化了才交换
			int temp = arr[i];
			arr[i] = arr[min];
			arr[min] = temp;
		}
	}
}

//4.0 快速排序
// 平均时间复杂度 O(log N),不稳定,有样本有序性不敏感。
void quick(int arr[],int left,int right){
	//1 计算中间元素的下标,单独保存起来
	int p = (left + right) / 2;
	int pivot = arr[p];	
	//2 分别使用左右变量的元素依次和基准之进行比较，小放左，大放右
	int i = 0,j = 0;
	for(i = left,j = right;i < j;){
		//左有元素且小于基准元素,比较下一个元素
		while(i < p && arr[i] < pivot){
			i++;	
		}
		//左有元素,但不再小于基准值,则将左边元素移动到p指向的位置,p指向该元素原来的位置
		if(i < p/*左有元素*/){
			arr[p] = arr[i];
			p = i;
		}
		//右有元素且大于基准值,比较上一个元素
		while(j > p && arr[j] >= pivot){
			j--;
		}
		//右有元素,但不大于基准值,将右边元素移动到p指向的位置,p指向该元素原来的位置
		if(j > p/*右有元素*/){
			arr[p] = arr[j];
			p = j;
		}
	}
	//3 直到左右两边元素下标重合时，放入基准值元素
	arr[p] = pivot;
	//4 对左右两边的分组递归再分组
	if(p - left > 1){
		quick(arr,left,p-1);
	}
	if(right - p > 1){
		quick(arr,p+1,right);
	}
}



int main(){
	int arr[9] = {35,10,30,5,15,30,12,20,3};
	//调用排序算法进行排序
//	bubble(arr,9);	//1.0 冒泡
//	insert(arr,9);	//2.0 插入
//	choose(arr,9);	//3.0 选择
	quick(arr,0,8); //4.0 快排
	//打印
	int i = 0;
	for(i = 0;i < 9;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
	return 0;
}




