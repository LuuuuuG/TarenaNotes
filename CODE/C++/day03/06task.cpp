 //练习:控制台时钟(精度：秒)
#include<time.h>
#include<cstdio>
#include<iostream>
#include<iomanip>  //setfill setw
using namespace std;
//step1:找对象
class Clock{
	
public:
	//构造函数
	Clock(int& tm_hour,int& tm_min,int& tm_sec){
		m_hour = tm_hour;
		m_min = tm_min;
		m_sec = tm_sec;
	}
	//缺省构造函数
	Clock (void){
		time_t t = time(0);
		struct tm* pt = localtime(&t);
		m_hour = pt->tm_hour;
		m_min = pt->tm_min;
		m_sec = pt->tm_sec;
		
	}
	//成员函数
	void run(void){
		for(;;){
			show();
			tick();
		//	cout << m_hour << ':' << m_min << ':' << m_sec << endl;
		}
	}

private:
	void show(void){
/*		printf("\r%02d:%02d:%02d",
			m_hour,m_min,m_sec);
		fflush(stdout);//刷新缓冲区
*/		cout << '\r' << setfill('0') //流
			<< setw (2) << m_hour << ':' 
			<< setw (2) <<m_min << ':'
			<< setw (2) << m_sec << flush;

	}
	void tick(void){
		sleep(1);
		if(++m_sec == 60){
			m_sec = 0;
			if(++m_min == 60){
				m_min = 0;
				if(++m_hour == 24){
					m_hour = 0;
				}
			}
		}
	}
	//成员变量
	int m_hour;
	int m_min;
	int m_sec;
};

int main(){
/*	C语言：
	time_t t = time(0);
	struct tm* p_time = localtime(&t);
	printf("%d:%d:%d\n",p_time->tm_hour,p_time->tm_min,p_time->tm_sec);
*/	
	/*构造函数
	time_t t = time(0);
	struct tm* pt = localtime(&t);
	Clock ck(pt->tm_hour,pt->tm_min,pt->tm_sec);
	*/

	Clock ck;//缺省构造函数
	ck.run();

	return 0;
}
