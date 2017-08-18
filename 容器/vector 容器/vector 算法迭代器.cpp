#include <iostream>
using namespace std;
#include <string>
#include <vector>

//vector容器是动态数组类模板，类中的迭代器(访问容器中所有数据的方法)支持随机访问

//存放基本数据类型
void test01()
{
	vector<int> v;
	//尾部插入
	v.push_back(2);
	v.push_back(4);
	v.push_back(8);
	v.push_back(1);

	//遍历   typedef T* iterator
	//容器中提供迭代的方法v.begin()指向容器中第一个元素，v.end()指向容器的最后一个元素的下一个位置
	for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;

	//cout << count(v.begin(), v.end(), 5) << endl;
}

class Person
{
	friend ostream& operator<<(ostream &os, const Person&p);
public:
	Person(string name, int age)
	{
		this->name = name;
		this->age = age;
	}
	~Person()
	{
	}
private:
	string name;
	int age;
};
ostream& operator<<(ostream &os, const Person&p)
{
	os << "name:" << p.name << " age:" << p.age;
	return os;
}

//存放复杂数据类型
void test02()
{
	vector<Person> v;
	Person p1("A", 10);
	Person p2("B", 20);
	Person p3("C", 30);
	Person p4("D", 40);

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);

	for (auto it : v)//这种写法是对象
	{
		cout << it << endl;
	}
}

void test03()
{
	vector<Person *> v;
	Person p1("A", 10);
	Person p2("B", 20);
	Person p3("C", 30);
	Person p4("D", 40);

	v.push_back(&p1);
	v.push_back(&p2);
	v.push_back(&p3);
	v.push_back(&p4);

	for (auto it : v)//这种写法是指向对象的指针
	{
		cout << *it << endl;
	}
}

//容器嵌套容器
void test04()
{
	vector<vector<int>> v;
	vector<int> v1, v2, v3, v4;
	v1.push_back(1);
	v2.push_back(2);
	v2.push_back(4);
	v3.push_back(5);
	v3.push_back(6);
	v3.push_back(8);
	v4.push_back(0);

	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);
	v.push_back(v4);

	for (auto it = v.begin(); it != v.end(); ++it)
	{
		for (auto iit = (*it).begin(); iit != (*it).end(); ++iit)
		{
			cout << *iit << " ";
		}
		cout << endl;
	}

}

int main()
{
	//test01();

	//test02();
	//test03();

	test04();
	return 0;
}