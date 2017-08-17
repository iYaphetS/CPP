#include <iostream>
using namespace std;
#include <vector>
#include <functional>
#include <algorithm>

struct myPrint
{
	
	void operator()(int val, int param)
	{
		cout << "val = " << val << " param = " << param << endl;
	}
};

class Target
{
public:
	Target(myPrint myprint, int par)
	{
		print = myprint;
		param = par;
	}

	void operator()(int val)
	{
		print(val, param);
	}
private:
	myPrint print;
	int param;
};

Target mybind2nd(myPrint print, int val)
{
	return Target(print, val);
}
void test01()
{
	vector<int> v = {1, 5, 3, 8, 10};
	for_each(v.begin(), v.end(), mybind2nd(myPrint(), 100));
	/*bind2nd
	mybind2nd函数 
	1.调用中间适配器类的有参构造函数
	2.并将匿名对象返回
	3.mybind2nd()整体是一个类对象

	for_each函数
	1.函数内部调用一个遍历函数
	void _For_each_unchecked(_InIt _First, _InIt _Last, _Fn1& _Func)
	{	// perform function for each element
	for (; _First != _Last; ++_First)
	_Func(*_First);
	2. _func()调用了对象_func的()的重载函数
	3.如果_func是自己写的一元函数对象，就调用这个类的()的重载函数
	4.如果_func是bind2d返回的一个匿名对象，就调用这个适配器类的()的重载函数

	*/
}
int main()
{
	test01();
	return 0;
}