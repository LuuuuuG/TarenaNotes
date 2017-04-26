#include <pthread.h>
#include <cstdio>
#include <iostream>
using namespace std;
class Thread {
public:
	// 启动线程
	void start (void) {
		pthread_create (&m_tid, NULL, run, this);
	}
private:
	// 线程过程
	static void* run (void* arg) {
		return static_cast<Thread*> (arg)->run ();
	}
	// 线程任务
	virtual void* run (void) = 0;
	pthread_t m_tid; // 线程标识
};
class AddThread : public Thread {
private:
	// 线程任务
	void* run (void) {
		for (;;) {
			cout << '+' << flush;
			usleep (200000);
		}
		return NULL;
	}
};
class SubThread : public Thread {
private:
	// 线程任务
	void* run (void) {
		for (;;) {
			cout << '-' << flush;
			usleep (50000);
		}
		return NULL;
	}
};
class ChrThread : public Thread {
public:
	ChrThread (char chr, useconds_t usec) :
		m_chr (chr), m_usec (usec) {}
private:
	// 线程任务
	void* run (void) {
		for (;;) {
			cout << m_chr << flush;
			usleep (m_usec);
		}
		return NULL;
	}
	char m_chr;
	useconds_t m_usec;
};
int main (void) {
	AddThread at;
	SubThread st;
	at.start ();
	st.start ();
	ChrThread star ('*', 100000);
	ChrThread dot ('.', 400000);
	star.start ();
	dot.start ();
	getchar ();
	return 0;
}
