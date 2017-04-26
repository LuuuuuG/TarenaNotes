#include "student.h"
int main(){
	Student s1("张飞",30);
	s1.who();
	s1.eat("包子");
	s1.learn("C++");
	Student* s2 = new Student("赵云",22);
	s2->who();
	s2->eat("Shit");
	s2->learn("日语");
	delete s2;
	return 0;

}
