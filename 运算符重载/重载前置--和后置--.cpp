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
	//ǰ��--
	MyInter& operator--()
	{
		--num;
		return *this;
	}
	//����--
	MyInter operator--(int)
	{
		MyInter temp(*this);
		--num;
		return temp;//����ʱ������ı�֮ǰ��ʱ����������������󣬲��Ƕ���������Ҫ���ض��󣬲�������
	}
private:
	int num;
};
ostream& operator<<(ostream &os, const MyInter& m)//�ó�����
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

	//����m2���ص�����������������<< �ڶ��������Ƕ������ã�
	//��vs���ǿ���������������ģ�������g++���ǲ��ܣ������������const���ã����������������󣬻�������������
	//����һ�ַ���--��������<<
	//1.ostream& operator<<(ostream &os, MyInter& m);�����������󣨱�����
	//2.ostream& operator<<(ostream &os, MyInter&& m);ֻ�������������󣨱���ֵ��
	cout << m2-- << endl;
	cout << m2 << endl;
}
int main()
{
	test();
	return 0;
}