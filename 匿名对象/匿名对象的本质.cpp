#include <iostream>

using namespace std;
class myint
{
	friend ostream & operator <<(ostream & os, myint &m);
public:
	myint(int val)
	{
		num = val;
	}
	//����+
	myint operator +(int num)
	{
		myint temp(*this);

		temp.num += num;
		return temp;
	}
	//����+=
	myint& operator +=(int num)
	{
		this->num += num;
		return *this;
	}

private:
	int num;
};
ostream & operator <<(ostream & os, myint &m)
{
	os << m.num;
	return os;
}


int main()
{
	myint m1(10);

	myint m2(20);

	myint m3 = m1 + 10;

	m2 = m1 + 100;//��ϵͳ�ṩ��Ĭ�ϸ�ֵ����

	m1 + 10 = 12;//������������ֵ
	cout << m1 + 10 + 20 << endl;//��������qt�²���ֱ��������������
	cout << (m1 + 10 = 13) << endl;//�����������
	cout << "m3:" << m3 << endl;
	cout << "m2:" << m2 << endl;

	m1 += 1000;
	cout << "m1:" << m1 << endl;

	return 0;
}

