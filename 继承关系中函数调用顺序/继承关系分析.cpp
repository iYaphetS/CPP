#include <iostream>
using namespace std;
class base
{
public:
	base()
	{

	}
	base(base *p)
	{
		ptr = p;
	}
private:
	base *ptr;
};
class M
{

};
class A : public base
{
public:
	A()
	{

	}
	A(base *p): base(p)
	{

	}
	
private:
	int num;
};
class B : public base
{
public:
	B()
	{

	}
	B(base *p) : base(p)
	{

	}
private:
	M m1;
	M *m2;
	A a;
};
int main()
{
	return 0;
}