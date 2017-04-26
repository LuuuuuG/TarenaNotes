//共享库的动态加载
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

int main(){
	//1.打开/加载共享库文件libadd.so
	void* handle = dlopen("./add_shared/libadd.so",RTLD_NOW/*立即加载*/);
	//2.判断是否打开失败,并打印错误信息
	if (NULL == handle) {
		printf("dlopen:%s\n",dlerror());
		return -1;//表示出错结束
		// exit(-1);
	}
	//3.获取共享库中函数add_int的地址
	//3.1 定义函数指针来接收函数的地址
	int (*p_add_int)(int,int);
	p_add_int = (int (*)(int,int))dlsym(handle,"add_int");
//	p_add_int = dlsym(handdle,,"add_int"); C语言中会自动隐士转换
	//4.判断获取是否失败,并打印错误信息
	if(NULL == p_add_int){
		printf("dlsym:%s\n",dlerror());
		return -1;
	}
	//5.调用add_int函数进行计算
	int res = p_add_int(100,200);
	printf("result = %d\n",res); //300
	//6.关闭/卸载共享库文件libadd.so
	res = dlclose(handle);
	//7.判断关闭是否失败,并打印错误信息
	if(0 != res){
		printf("dlclose: %s\n",dlerror());
		return -1;
	}
	return 0;
}
