#include <iostream>
using namespace std;

class Func
{
public:
	int operator()(int a, int b)
	{
		return a + b;
	}

private:
	int a;
	int b;
};
void dologic(Func &fun)
{
	int a = 10;
	int b = 20;
	cout << fun(a, b) << endl;
}

int main()
{
	Func fun;

	int a = 10;
	int b = 12;
	int ret = fun(a, b);//·Âº¯Êý
	cout << ret << endl;

	dologic(fun);
	return 0;
}