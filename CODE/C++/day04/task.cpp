#include<iostream>
using namespace std;
class Array{
public:
	//���캯��
	Array (int size):m_data(new int[size]),m_size(size),m_top(0){}
	//��������
	Array(Array const& that):m_data(new int[that.m_size]),m_size(that.m_size),m_top(that.m_top){
		for(int i = 0;i < that.m_top;++i)
			m_data[i] = that.m_data[i];
	}
	//������ֵ
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
	//��������
	~Array(){
		if(m_data){
			delete[] m_data;
			m_data = NULL;
		}
	}
	//������β������һ��Ԫ��
	bool push(int item){
		if (m_top >= m_size)
			return false;
		m_data[m_top++] = item;
		return true;
	}
	//������β������һ��Ԫ��
	bool pop(int& item){
		if(m_top <= 0)
			return false;
		m_data[--m_top];
		return true;
	}
	//�����±��ȡһ��Ԫ��
	bool get(int index,int& item) const{
		if(index < 0 || m_top <= index)
			return false;
		item = m_data[index];
		return true;
	}
	//�����±��޸�Ԫ��
	bool set (int index,int item){
		if(index < 0 || m_top <= index)
			return false;
		m_data[index] = item;
		return true;
	}
	//�������
	void clear(void){
		if(m_top > 0)
			m_top = 0;
	}
	//�ж������Ƿ�Ϊ��
	bool empty(void) const {
		return m_top <= 0;
	}
	//���ң�����ָ��Ԫ�ص�һ�γ��ֵ��±�
	int find (int item) const{
		for(int i = 0; i < m_top;++i)
			if(m_data[i] == item)
				return i;
		return -1;
	}
	//�滻�������������еĸ���Ԫ��ȫ���滻Ϊ��һ��ֵ
	void replace (int search,int replaced){
		for(int i = 0;i < m_top;++i)
			if(m_data[i] == search)
				m_data[i] = replaced;
	}
	//��ת
	void reverse(void){
		int mid = m_top / 2;
		for(int i = 0;i < mid;++i){
			int temp = m_data[i];
			m_data[i] = m_data[m_top - 1 - i];
			m_data[m_top-1-i] = temp;
		}
	}
	//���� (ð������)
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
	//��ӡ
	void print (void) const{
		for(int i = 0;i<m_top;++i)
			cout << m_data[i] << ' ';
		cout << endl;
	}	
		
private:
	int* m_data;//����ָ��
	int m_size;//�����С
	int m_top;//��������
};


int main(){
	Array a (10);
	//����Ԫ��
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
	//�滻
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