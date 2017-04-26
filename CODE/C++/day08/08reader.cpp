/*************************************************************************
    > File Name: 08reader.cpp
    > Author: Mr.Gang
    > mail: 776881718@qq.com
    > Created Time: 2016年05月20日 星期五 16时44分28秒
 ************************************************************************/

#include<iostream>
using namespace std;
class PDFReader {
public:
	void read (string const& fileName){
		cout << "打开" << fileName << endl;
		cout << "读取到一行文本..." << fileName << endl;
		drawText ();
		cout << "读取到一个图形..." << fileName << endl;
		drawShape ();
		cout << "读取到一个图片..." << fileName << endl;
		drawImage ();
		cout << "关闭" << fileName << endl;
	}
private:
	virtual void drawText (void) const = 0;
	virtual void drawShape(void) const = 0;
	virtual void drawImage(void) const = 0;
};
class PDFRender: public PDFReader{
	virtual void drawText (void) const{
		cout << "绘制文字" << endl;
	}
	virtual void drawShape(void) const {
		cout << "绘制图形" << endl;
	}
	virtual void drawImage(void) const{
		cout << "绘制图片" << endl;
	}
};
int main(){
	
	return 0;
}
