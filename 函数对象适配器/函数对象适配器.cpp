#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <string>
using namespace std;

//1.重载()的函数对象适配器
/*_Fn1 for_each(_InIt _First, _InIt _Last, _Fn1 _Func)
_First---输入迭代器（只读）开始位置
_Last----输入迭代器尾端
_Func----输出函数对象
for (; _First != _Last; ++_First)
_Func(*_First);--------一个对象参数
}

*/
//本身是个二元函数就继承于binary_function
//本身是个一元函数就继承于unary_function
//binary_function<int, int, void>
//第一个参数是重载括号函数的第一个参数类型
//第二个参数是重载括号函数的第二个参数类型
//第三个参数是重载括号函数的返回值类型
struct myprint : public binary_function<int, int, void>
{
	void operator()(int val, int parama)const
	{
		cout << val + parama << endl;
	}
};
void test01()
{
	vector<int> v = {1, 2, 3, 4, 5};
	//函数适配器将参数不匹配的函数匹配成符合要求的函数对象
	//bind1nd----将参数绑定到第一个参数上 
	//bind2nd----将参数绑定到第二个参数上
	for_each(v.begin(), v.end(), bind2nd(myprint(), 10));
}

//2.取反适配器
//注意只对谓词有效，什么是谓词（普通函数或者是重载operator()的返回值为bool的函数对象或仿函数）
//一元谓词（参数只有一个），not1就是它的取反适配器
//二元谓词（参数有两个），not2就是它的取反适配器
void test02()
{
	vector<int> v = {2, 1, 8, 6, 3, 4};

	sort(v.begin(), v.end(), not2(less<int>()));//比较两个参数
	//sort(v.begin(), v.end(), greater<int>());
	for_each(v.begin(), v.end(), [](int val)
	{
		cout << val << " ";
	});
	cout << endl;
}

//3.普通函数的适配器
void myfun(int val, int param)
{
	cout << val + param << endl;
}


void test03()
{
	vector<int> v = {1, 2, 3, 4, 7};

	//for_each(v.begin(), v.end());
	//ptr_fun将自己定义的普通函数转成函数对象
	for_each(v.begin(), v.end(), bind2nd(ptr_fun(myfun), 10));

}

//4.成员普通函数适配器  mem_fun_ref(容器存储对象) mem_fun(容器存储对象指针)
class person
{
public:
	person(string name, int age)
	{
		this->name = name;
		this->age = age;
	}

	void print()
	{
		cout << "name:" << this->name << " age:" << this->age << endl;
	}
private:
	string name;
	int age;
};
#if 1
void test04()
{
	vector<person> v;
	v.push_back(person("aa", 10));
	v.push_back(person("bb", 20));
	v.push_back(person("cc", 30));

	for_each(v.begin(), v.end(), mem_fun_ref(&person::print));
}
#endif

void test05()
{
	vector<person*> v;
	v.push_back(new person("aa", 10));
	v.push_back(new person("bb", 20));
	v.push_back(new person("cc", 30));

	for_each(v.begin(), v.end(), mem_fun(&person::print));

	for_each(v.begin(), v.end(), [](person *p)
	{
		delete p;
	});

}
int main()
{
	//test01();
	//test02();
	//test03();
	test04();
	test05();
	return 0;
}