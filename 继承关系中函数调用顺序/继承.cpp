#include <iostream>
using namespace std;

class Girl
{
public:
	Girl(int m)
	{
		this->m = m;
		cout << "Girl构造函数" << endl;
	}
	~Girl()
	{
		cout << "Girl析构函数" << endl;
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
		cout << "Parent构造函数" << endl;
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
		cout << "Parent析构函数" << endl;
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
		cout << "Son构造函数" << endl;
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
		cout << "Son析构函数" << endl;
	}
private:
	int g;
	Girl p1;
	Girl p2;
};
void test()
{
	Son s1(10, 1, 2, 3, 4);
	//子类函数与父类的函数同名（参数完全一样或者重载函数）的原则是同名隐藏，就近访问
	//发生重名，子类要调用父类的函数就必须要显示的写出父类的作用域
	s1.fun1(20);
	s1.Parent::fun1();
	s1.Parent::fun1(10);
}
int main()
{
	//一个son类中继承parent，类中成员变量有girl类对象p1, p2
	//调用构造函数的顺序：
	//1.先调用父类parent构造函数，
	//2.再调用成员类对象的构造函数
	//3.再调用类本身的构造函数
	//析构函数的调用顺序与构造函数相反
	test();
	/*
	Parent构造函数
	Girl构造函数
	Girl构造函数
	Son构造函数
	Son析构函数
	Girl析构函数
	Girl析构函数
	Parent析构函数
	*/
	return 0;
}