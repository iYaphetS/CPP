#include <iostream>
using namespace std;
//#include <cstring>
//#include <string>


class base
{
public:
	int basedata;
};

class A : virtual public base
{
public:
	int a;
};

class B : virtual public base
{
public:
	int b;
};

//多继承会产生两个问题
/*
1.类C从A和B中同时继承了相同的数据basedata,
所以类C中会有两份basedata，浪费内存
----解决的方法
----对会产生重复数据的类，采用虚继承来继承它
2.通过类C访问公共basedata是会产生二义性
----解决的方法
----可以通过类作用域符来访问
*/
/*
=======================未虚继承之前的类A布局
+---
| +--- (base class base)
0      | | basedata
| +---
4      | a
+---
=======================未虚继承之前的类B布局
+---
| +--- (base class base)
0      | | basedata
| +---
4      | b
+---
=======================未虚继承之前的类C布局
+---
| +-- - (base class A)
| | +-- - (base class base)
0 | | | basedata
| | +-- -
4 | | a
| +-- -
| +-- - (base class B)
| | +-- - (base class base)
8 | | | basedata
| | +-- -
12 | | b
| +-- -
16 | c
+ -- -

=======================虚继承之后的类A布局
+---
0 | {vbptr}
4 | a
+ -- -
+-- - (virtual base base)
8 | basedata
+ -- -

A::$vbtable@:
0 | 0
1 | 8 (Ad(A + 0)base)
== == == == == == == == == == == = 虚继承之后的类B布局
+ -- -
0 | {vbptr}
4 | b
+ -- -
+-- - (virtual base base)
8 | basedata
+ -- -

B::$vbtable@:
0 | 0
1 | 8 (Bd(B + 0)base)
== == == == == == == == == == == = 虚继承之后的类C布局
+ -- -
| +-- - (base class A)
0 | | {vbptr}
4 | | a
| +-- -
| +-- - (base class B)
8 | | {vbptr}
12 | | b
| +-- -
16 | c
+ -- -
+-- - (virtual base base)
20 | basedata
+ -- -

C::$vbtable@A@:
0 | 0
1 | 20 (Cd(A + 0)base)

C::$vbtable@B@:
0 | 0
1 | 12 (Cd(B + 0)base)
==========================================
*/
class C : public A, public B
{
public:
	int c;
};

void test()
{
	//两种方式访问basedata
	A a1;
	a1.basedata = 200;
	cout << a1.A::basedata << endl;

	B b1;
	b1.B::basedata = 300;
	cout << b1.basedata << endl;
}
void test1()
{
	C c1;
	//1.通过对象c1直接访问
	c1.basedata = 100;
	//2.通过对象c1从类A中继承过来的vbptr(虚基类指针)指向的虚基类表相对虚基类指针的偏移量找到basedata
	cout << c1.A::basedata << endl;
	//&c1-----继承过来的类A中的vbptr的首地址
	cout << ((base *)( (char *)&c1  +   *((int *)(*(int *)&c1)+1)  ))->basedata << endl;

	cout << c1.B::basedata << endl;

	//2.通过对象c1从类B中继承过来的vbptr(虚基类指针)指向的虚基类表相对虚基类指针的偏移量找到basedata
	//((char *)&c1 + sizeof(A) - sizeof(base))----继承过来的类B中的vbptr的首地址
	printf("%d\n", ((base *)(((char*)&c1 + sizeof(A)-sizeof(base)) + (*((int *)(*(int *)((char*)&c1 + sizeof(A)-sizeof(base))) + 1))))->basedata);

	int p = (int)((char *)&c1 + sizeof(A)-sizeof(base));
	printf("%d\n",     ((base *)(p +  *((int *)(*(int *)p) + 1)))->basedata         );
	cout << ((base *)(p + *((int *)(*(int *)p) + 1)))->basedata << endl;

	//cout << sizeof(A) << endl;
	//cout << sizeof(base) << endl;

	//cout << (void *)(char *)&c1<< endl;//c++中不能输出char *地址
	//printf("%d\n", &c1);
	//printf("%d\n", (char *)&c1);
}

int main()
{
	test();
	test1();
	return 0;
}
