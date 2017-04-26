/*************************************************************************
    > File Name: 11task.cpp
    > Author: Mr.Gang
    > mail: 776881718@qq.com
    > Created Time: 2016年05月24日 星期二 17时37分25秒
 ************************************************************************/
//练习：实现一个基于异或算法的加密解密程序
//C = P ^ K   K 密钥
//P = C ^ K
#include<iostream>
#include<cstdlib>
#include<fstream>
using namespace std;
//src ^ key -> dst
//密钥函数
int xorFile (char const* src,
	char const* dst,unsigned char key){
	//打开源文件
	ifstream ifs (src,ios::binary);
	if (!ifs){
		cout << "无法打开源文件" << src << endl;
		return -1;
	}
	//打开目标文件
	ofstream ofs (dst,ios::binary);
	if (!ifs){
		cout << "无法打开目标文件" << src << endl;
		ifs.close();
		return -1;
	}
	char buf[10240];
	while(ifs.read (buf,sizeof(buf))){
		for (int i = 0;i < sizeof (buf);++i)
			buf[i] ^= key;
		ofs.write (buf,sizeof(buf));
	}
	if (!ifs.eof()){
		cout << "无法读取源文件:" << src << endl;
		ofs.close();
		ifs.close();
	}
	int last = ifs.gcount ();
	for (int i = 0;i < last; ++i)
		buf[i] ^= key;
	ofs.write (buf,last);
	ofs.close();
	ifs.close();
	return 0;
}

//加密  明文->密文
int encrypt(char const* plain,char const* cipher){
	srand (time(NULL));
	unsigned char key = rand () % 256;
	if (xorFile (plain,cipher,key) == -1)
		return -1;
	cout << "密钥:" << (unsigned int)key << endl;
}

//解密  密文->明文
int decrypt (char const* cipher,char const* plain,unsigned char key){
	return xorFile(cipher,plain,key);
}

int main(int argc,char* argv[]){
	if(argc < 3){//检查命令行参数
		cout << "加密:" << argv[0]
			<< " <明文文件><密文文件>" << endl;
		cout << "解密:" << argv[0]
			<< " <密文文件><明文文件><密钥>" << endl;
		return -1;
	}
	if (argc < 4)//不提供密钥
		//加密
		return encrypt(argv[1],argv[2]);
	else//提供密钥
		//解密
		return decrypt(argv[1],argv[2],atoi(argv[3]));
	return 0;
}










