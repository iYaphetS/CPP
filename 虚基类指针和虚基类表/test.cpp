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

//��̳л������������
/*
1.��C��A��B��ͬʱ�̳�����ͬ������basedata,
������C�л�������basedata���˷��ڴ�
----����ķ���
----�Ի�����ظ����ݵ��࣬������̳����̳���
2.ͨ����C���ʹ���basedata�ǻ����������
----����ķ���
----����ͨ�����������������
*/
/*
=======================δ��̳�֮ǰ����A����
+---
| +--- (base class base)
0      | | basedata
| +---
4      | a
+---
=======================δ��̳�֮ǰ����B����
+---
| +--- (base class base)
0      | | basedata
| +---
4      | b
+---
=======================δ��̳�֮ǰ����C����
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

=======================��̳�֮�����A����
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
== == == == == == == == == == == = ��̳�֮�����B����
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
== == == == == == == == == == == = ��̳�֮�����C����
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
	//���ַ�ʽ����basedata
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
	//1.ͨ������c1ֱ�ӷ���
	c1.basedata = 100;
	//2.ͨ������c1����A�м̳й�����vbptr(�����ָ��)ָ�����������������ָ���ƫ�����ҵ�basedata
	cout << c1.A::basedata << endl;
	//&c1-----�̳й�������A�е�vbptr���׵�ַ
	cout << ((base *)( (char *)&c1  +   *((int *)(*(int *)&c1)+1)  ))->basedata << endl;

	cout << c1.B::basedata << endl;

	//2.ͨ������c1����B�м̳й�����vbptr(�����ָ��)ָ�����������������ָ���ƫ�����ҵ�basedata
	//((char *)&c1 + sizeof(A) - sizeof(base))----�̳й�������B�е�vbptr���׵�ַ
	printf("%d\n", ((base *)(((char*)&c1 + sizeof(A)-sizeof(base)) + (*((int *)(*(int *)((char*)&c1 + sizeof(A)-sizeof(base))) + 1))))->basedata);

	int p = (int)((char *)&c1 + sizeof(A)-sizeof(base));
	printf("%d\n",     ((base *)(p +  *((int *)(*(int *)p) + 1)))->basedata         );
	cout << ((base *)(p + *((int *)(*(int *)p) + 1)))->basedata << endl;

	//cout << sizeof(A) << endl;
	//cout << sizeof(base) << endl;

	//cout << (void *)(char *)&c1<< endl;//c++�в������char *��ַ
	//printf("%d\n", &c1);
	//printf("%d\n", (char *)&c1);
}

int main()
{
	test();
	test1();
	return 0;
}
