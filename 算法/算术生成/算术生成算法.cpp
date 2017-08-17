#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>
#include <string>

class person
{
	friend class myplus;
public:

	person()
	{
		this->name = "";
		this->age = 0;
	}
	person(string name, int age)
	{
		this->name = name;
		this->age = age;
	}

	void print()
	{
		cout << "name:" << name << " age:" << age << endl;
	}
private:
	string name;
	int age;
};

class myplus
{
public:
	int operator()(int val, person &p)
	{
		return val + p.age;
	}
};
//accumulate(iterator beg, iterator end, value) 
//将容器的元素进行累加操作，返回累加结果
void test01()
{
	vector<person> p = {person("aa", 10), person("bb", 20), person("cc", 30)};

	/*
	accumulate(_InIt _First, _InIt _Last, _Ty _Val, _Fn2 _Func)
	_Func(_Val, *_First)
	*/
	int ret = accumulate(p.begin(), p.end(), 0, myplus());

	cout << ret << endl;

	p.resize(10);
	person temp("ss", 33);
	fill(p.begin(), p.end(), temp);

	for (auto it : p)
	{
		it.print();
	}
}
int main()
{

	test01();
	return 0;
}