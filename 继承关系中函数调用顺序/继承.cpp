#include <iostream>
using namespace std;

class Girl
{
public:
	Girl(int m)
	{
		this->m = m;
		cout << "Girl���캯��" << endl;
	}
	~Girl()
	{
		cout << "Girl��������" << endl;
	}
private:
	int m;
};

class Parent
{
public:
	Parent(int a, int b)
	{
		this->a = a;
		this->b = b;
		cout << "Parent���캯��" << endl;
	}
	void fun1()
	{
		cout << "Parent::fun1()" << endl;
	}
	void fun1(int)
	{
		cout << "Parent::fun1(int)" << endl;
	}
	void fun2()
	{
		cout << "Parent::fun2()" << endl;
	}
	~Parent()
	{
		cout << "Parent��������" << endl;
	}
private:
	int a;
	int b;
};

class Son : public Parent
{
public:
	Son(int g, int a, int b, int c, int d) : Parent(a, b), p1(c), p2(d)
	{
		this->g = g;
		cout << "Son���캯��" << endl;
	}
	
	void fun1(int)
	{
		fun2();
		//fun1(10);//erro
		Parent::fun1();
		cout << "Son::fun1()" << endl;
	}
	
	~Son()
	{
		cout << "Son��������" << endl;
	}
private:
	int g;
	Girl p1;
	Girl p2;
};
void test()
{
	Son s1(10, 1, 2, 3, 4);
	//���ຯ���븸��ĺ���ͬ����������ȫһ���������غ�������ԭ����ͬ�����أ��ͽ�����
	//��������������Ҫ���ø���ĺ����ͱ���Ҫ��ʾ��д�������������
	s1.fun1(20);
	s1.Parent::fun1();
	s1.Parent::fun1(10);
}
int main()
{
	//һ��son���м̳�parent�����г�Ա������girl�����p1, p2
	//���ù��캯����˳��
	//1.�ȵ��ø���parent���캯����
	//2.�ٵ��ó�Ա�����Ĺ��캯��
	//3.�ٵ����౾��Ĺ��캯��
	//���������ĵ���˳���빹�캯���෴
	test();
	/*
	Parent���캯��
	Girl���캯��
	Girl���캯��
	Son���캯��
	Son��������
	Girl��������
	Girl��������
	Parent��������
	*/
	return 0;
}