#include <iostream>
#include <iomanip>//流控制符
using namespace std;
	
class M33{
public:
	M33 (int n = 0) {
		for (int i = 0;i < 3;++i){
			for(int j = 0;j < 3; ++j){
					m_a[i][j] = n;
			}
		}
	}
	M33 (int a[][3]){
		for (int i = 0;i < 3;++i)
			for (int j = 0;j < 3;++j)
				m_a[i][j] = a[i][j];
	}
/*	
	//下标操作符
	int& operator[](int arr[3][3]){
		for (int i = 0;i < 3;++i)
			for (int j = 0;j < 3;++j)
				if(m_a[i][j] == arr[i][j])
					return m_a[i][j];
	}
	int const& operator[] (int i) const{
		return const_cast<M33&>(*this)[i];
	}
*/
	// +
	M33 const operator+ (M33 const& m) const{
		int a[3][3];
		for(int i = 0;i < 3;++i)
			for(int j = 0;j < 3;++j)
				a[i][j] = m_a[i][j] + m.m_a[i][j];
		return a;
	}
	// -
	M33 const operator- (M33 const& m) const{
		int a[3][3];
		for(int i = 0;i < 3;++i)
			for(int j = 0;j < 3;++j)
				a[i][j] = m_a[i][j] - m.m_a[i][j];
		return a;
	}
	// *
	M33 const operator* (M33 const& m) const{
		int a[3][3] = {0};
		for(int i = 0;i < 3;++i)
			for(int j = 0;j < 3;++j)
				for(int k = 0;k < 3;++k)
					a[i][j] += m_a[i][k] * m.m_a[k][j];
		return a;
	}
	// +=
	M33& operator+= (M33 const& m) {
		return *this = *this + m;
	}
	// -=
	M33& operator-= (M33 const& m) {
		return *this = *this - m;
	}
	// *=
	M33& operator*= (M33 const& m) {
		return *this = *this * m;
	}
	// -(负)
	M33 const operator- (){
		return M33() - *this;
	}
	// 前++
	M33& operator++ (){
		return *this += M33(1);
	}
	// 前--
	M33& operator-- (){
		return *this -= M33(1);
	}
	//后++
	M33 const operator++ (int){
		M33 m = *this;
		++*this;
		return m;
	}
	//后--
	M33 const operator-- (int){
		M33 m = *this;
		--*this;
		return m;
	}
	// 输出<<
	friend ostream& operator<< (ostream& os,M33 const& m){
		for(int i = 0;i < 3;++i){
			for(int j = 0;j < 3;++j)
				os << setw(4) << m.m_a[i][j];
			os << endl;
		}
		return os;
	}
	//下标操作符
	int* operator[](int i) {
		return m_a[i];
	}
	int const* operator[] (int i)const {
		return const_cast<M33&>(*this)[i];
	}

private:
	int m_a[3][3];
};

int main(){
	int a1[3][3] = {1,2,3,4,5,6,7,8,9};
	M33 m1(a1);
	int a2[3][3] = {9,8,7,6,5,4,3,2,1};
	M33 m2(a2);

	
	cout << "----------下标访问---------" << endl;
//	cout << a1[2][2] << endl;
//	cout << a2[2][2] << endl;
	
	++m2[1][1];
	//++m2.operator[](1)[1];
	cout << m2 << endl;
	M33 const& cr = m2;
//	--c2[1][1];
	cout << cr[1][1] << endl;
/*
	cout << m1 + m2 << endl << endl;
	cout << m1 - m2 << endl << endl;
	cout << m1 * m2 << endl << endl;

	m1 += m2;
	cout << m1 << endl;
	m1 -= m2;
	cout << m1 << endl;
	m1 *= m2;
	cout << m1 << endl;

	cout << -m1 << endl;
	cout << m1 << endl;

	cout << ++m2 << endl;
	cout << m2 << endl;
*/
	return 0;
}
