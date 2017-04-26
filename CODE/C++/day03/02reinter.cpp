#include<cstdio>
#include<iostream>
using namespace std;
int main(){
	float f = 1.2;
	printf("%g %#x\n",f,f); //1.2 1???

	unsigned char* p = reinterpret_cast<unsigned char*>(&f);
	printf("%#x %#x %#x %#x\n",p[0],p[1],p[2],p[3]);
	return 0;
}
