/*************************************************************************
    > File Name: 05smart.cpp
    > Author: Mr.Gang
    > mail: 776881718@qq.com
    > Created Time: 2016年05月19日 星期四 16时18分11秒
 ************************************************************************/

#include<iostream>
using namespace std;
//电话
class Phone  {
private:
	string m_number;
public:
	Phone(string const& number):
		m_number(number){
			cout << "Phone构造：" << this << endl;
		}
	void call (string const& rcvr){
		cout << m_number << "致电给"
			<< rcvr << endl;
	}
};
//播放器
class Player {
public:
	Player(string const& media):
		m_media(media){
			cout << "Player构造：" << this << endl;
		}
	
	void play(string const& clip) const{
		cout << m_media << "播放器播放"
			<< clip << endl;
	}
private:
	string m_media;
};
//计算机
class Computer{
public:
	Computer (string const& os):
		m_os(os){
			cout << "Computer构造：" << this << endl;
		}
	void run (string const& app) const{
		cout << "在" << m_os << "系统上运行"
			<< app << endl;
	}
private:
	string m_os;
};
//智能电话
class SmartPhone : public Phone,
	public Player,public Computer{
public:
	SmartPhone (string const& number,
			string const& media,
			string const& os):Phone(number),
		Player(media),Computer(os){	
			cout << "SmartPhone构造：" << this << endl;
		}
};

int main(){
	SmartPhone sp ("18603855892","MP4","IOS");
	sp.call("012345678");
	sp.play("小苹果.mp4");
	sp.run("微信");
	SmartPhone* psp = &sp;
	Phone* pp = psp;
	Player* pl = psp;
	Computer* pc = psp;
	cout << pp << ' ' << pl << ' ' << pc << endl;
	cout << static_cast<SmartPhone*> (pp) << endl;
	cout << static_cast<SmartPhone*> (pl) << endl;
	cout << static_cast<SmartPhone*> (pc) << endl;

	cout << reinterpret_cast<SmartPhone*> (pp) << endl;
	cout << reinterpret_cast<SmartPhone*> (pl) << endl;
	cout << reinterpret_cast<SmartPhone*> (pc) << endl;
	return 0;
}




