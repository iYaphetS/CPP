#include <iostream>
using namespace std;
#include<iomanip>


class base
{
public:
	virtual void test()
	{

	}
};
class derived : public base
{
public:
	void test()
	{

	}
};
void test1()
{
	base *b = NULL;
	derived *d = NULL;

	b = static_cast<base *>(d);
	d = static_cast<derived *>(b);

}
void test2()
{
	base *b = NULL;
	derived *d = NULL;

	b = dynamic_cast<base *>(d);
	d = dynamic_cast<derived *>(b);//ÒªÓÐÐéº¯Êý

}
int main()
{
	test1();
	test2();
	cout << "1. " << setfill(' ') << "Hello! " << endl;
	return 0;
}