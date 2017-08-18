#include <iostream>
using namespace std;

class base
{
public:
	base()
	{
		cout << "base:构造函数" << endl;
	}
	void test01()
	{
		cout << "base:test01" << endl;

	}
	virtual void test02()
	{
		cout << "derived:test02" << endl;
	}
	virtual ~base()
	{
		cout << "base:析构函数" << endl;
	}
};


class derived :public base
{
public:
	derived()
	{
		cout << "derived:构造函数" << endl;
	}
	void test01()
	{
		cout << "derived:test01" << endl;

	}
	virtual void test02()
	{
		cout << "derived:test02" << endl;
	}
	virtual void test03()
	{
		cout << "derived:test03" << endl;

	}
	virtual ~derived()
	{
		cout << "derived:析构函数" << endl;
	}
	
};
#if 0
class ss : public derived
{
public:

	virtual void test02()
	{
		cout << "derived:test02" << endl;
	}
};
#endif
int main()
{
	base * p = new derived;
	//ss s;
	p->test01();
	delete p;
	/*在编译delete p的时候，类base中析构函数没有virtual关键字
	静态联编的时候p的确指向了一块内存空间，但是这块内存空间
	的内容，编译器是不知道的，（就比如int a = 10;编译只会根据a的类型
	为它分配4个字节的空间但是a为多少是不知道的）所以在编译的时候就
	默认与base绑定（早绑定）了
	并不会根据它指向的内容来绑定（静态会根据对象的类型来调用函数的）
	所以在delete p；只会调用base类的析构函数
	但是编译器发现类中某个函数有virtual，就不会在编译函数调用的时候将函数与对象
	进行绑定，就是所谓的动态联编
	在子类对象初始化（调用构造函数会对继承过来的虚指针从新赋值）
	后继承过来的虚函数指针指向发生变化就会指向子类的虚函数表
	在运行阶段调p调用的函数与具体对象绑定，p就会调用子类的虚函数指针指向的析构函数
	
	在编译某个函数的时候，看到调用这个函数的对象实现这个函数没有virtual
	关键字，就会在编译的时候与这个对象进行绑定
	如果这个对象实现这个函数有virtual关键字，那么这个函数就不会绑定这个对象，
	会在运行的时候根据实际的对象与之绑定
	*/

	return 0;
}