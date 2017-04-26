#include<iostream>
using namespace std;
class Array{
public:
	//构造函数
	Array (int size):m_data(new int[size]),m_size(size),m_top(0){}
	//拷贝构造
	Array(Array const& that):m_data(new int[that.m_size]),m_size(that.m_size),m_top(that.m_top){
		for(int i = 0;i < that.m_top;++i)
			m_data[i] = that.m_data[i];
	}
	//拷贝赋值
	Array& operator= (Array const& that){
		if(&that!= this){
			if(m_data){
				delete[] m_data;
				m_data = NULL;
			}
			m_data = new int[that.m_size];
			for(int i = 0;i < that.m_top;++i){
				m_data[i] = that.m_data[i];
			}
			m_size = that.m_size;
			m_top = that.m_top;
		}
		return *this;
	}
	//析构函数
	~Array(){
		if(m_data){
			delete[] m_data;
			m_data = NULL;
		}
	}
	//在数组尾部存入一个元素
	bool push(int item){
		if (m_top >= m_size)
			return false;
		m_data[m_top++] = item;
		return true;
	}
	//从数组尾部弹出一个元素
	bool pop(int& item){
		if(m_top <= 0)
			return false;
		m_data[--m_top];
		return true;
	}
	//根据下标获取一个元素
	bool get(int index,int& item) const{
		if(index < 0 || m_top <= index)
			return false;
		item = m_data[index];
		return true;
	}
	//根据下标修改元素
	bool set (int index,int item){
		if(index < 0 || m_top <= index)
			return false;
		m_data[index] = item;
		return true;
	}
	//清空数组
	void clear(void){
		if(m_top > 0)
			m_top = 0;
	}
	//判断数组是否为空
	bool empty(void) const {
		return m_top <= 0;
	}
	//查找：返回指定元素第一次出现的下标
	int find (int item) const{
		for(int i = 0; i < m_top;++i)
			if(m_data[i] == item)
				return i;
		return -1;
	}
	//替换：将数组中所有的给定元素全部替换为另一个值
	void replace (int search,int replaced){
		for(int i = 0;i < m_top;++i)
			if(m_data[i] == search)
				m_data[i] = replaced;
	}
	//逆转
	void reverse(void){
		int mid = m_top / 2;
		for(int i = 0;i < mid;++i){
			int temp = m_data[i];
			m_data[i] = m_data[m_top - 1 - i];
			m_data[m_top-1-i] = temp;
		}
	}
	//排序 (冒泡排序)
	void sort(void){
		for(int i = 0;i < m_top - 1; ++i){
			bool ok = true;
			for(int j = 0;j < m_top - 1 - i; ++j)
				if(m_data[j] > m_data[j+1]){
					int temp = m_data[j];
					m_data[j] = m_data[j+1];
					m_data[j+1] = temp;
					ok = false;
				}
			if(ok)
				break;
		}
	}
	//打印
	void print (void) const{
		for(int i = 0;i<m_top;++i)
			cout << m_data[i] << ' ';
		cout << endl;
	}	
		
private:
	int* m_data;//数组指针
	int m_size;//数组大小
	int m_top;//数组上限
};


int main(){
	Array a (10);
	//插入元素
	for(int i = 200;i >= 100;i -= 10)
		if(! a.push(i))
			cout << "Array::push() fail !" << endl;
		a.print();
		//
/*	for( int j = 0;j <= 10;++j){
		int item;
		if(! a.pop(item))
			cout << "Array::pop() fail !" << endl;
		else
			cout << item << endl;
	}
*/
	//替换
	a.set
		(1,150);
		(3,150);
		(5,150);
		(7,150);
		a.print();
		
		a.replace(150,250);
		a.sort();
		a.print();
		
		a.reverse();
		a.print();

		cout << boolalpha << a.empty() << endl;

		a.clear();
		cout << a.empty() << endl;

		a.push(345);
		a.push(621);
		a.push(178);
		a.push(436);
		a.sort();

		int item;
		a.pop(item);
		a.print();

		Array b = a;
		b.print();
		b.push(872);
		b.push(233);
		b.sort();
		b.print();
		a = b;
		a.print();


	return 0;
}