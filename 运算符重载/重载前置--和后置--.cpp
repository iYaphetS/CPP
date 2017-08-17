#include <iostream>
using namespace std;

class MyInter
{
	friend ostream& operator<<(ostream &os, const MyInter& m);
public:
	MyInter(int val)
	{
		num = val;
	}
	//前置--
	MyInter& operator--()
	{
		--num;
		return *this;
	}
	//后置--
	MyInter operator--(int)
	{
		MyInter temp(*this);
		--num;
		return temp;//返回时对象本身改变之前零时对象产生的匿名对象，不是对象本身，所以要返回对象，不是引用
	}
private:
	int num;
};
ostream& operator<<(ostream &os, const MyInter& m)//用常引用
{
	os << m.num;
	return os;
}

void test()
{
	MyInter m1(10);
	MyInter m2(10);


	cout << --m1 << endl;
	cout << m1 << endl;

	//由于m2返回的匿名对象，这里重载<< 第二个参数是对象引用，
	//在vs下是可以引用匿名对象的，但是在g++下是不能，所以最好是用const引用，可以引用有名对象，还可以匿名对象
	//还有一种方法--重载两种<<
	//1.ostream& operator<<(ostream &os, MyInter& m);引用有名对象（变量）
	//2.ostream& operator<<(ostream &os, MyInter&& m);只能引用匿名对象（变量值）
	cout << m2-- << endl;
	cout << m2 << endl;
}
int main()
{
	test();
	return 0;
}