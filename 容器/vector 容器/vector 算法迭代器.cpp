#include <iostream>
using namespace std;
#include <string>
#include <vector>

//vector�����Ƕ�̬������ģ�壬���еĵ�����(�����������������ݵķ���)֧���������

//��Ż�����������
void test01()
{
	vector<int> v;
	//β������
	v.push_back(2);
	v.push_back(4);
	v.push_back(8);
	v.push_back(1);

	//����   typedef T* iterator
	//�������ṩ�����ķ���v.begin()ָ�������е�һ��Ԫ�أ�v.end()ָ�����������һ��Ԫ�ص���һ��λ��
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

//��Ÿ�����������
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

	for (auto it : v)//����д���Ƕ���
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

	for (auto it : v)//����д����ָ������ָ��
	{
		cout << *it << endl;
	}
}

//����Ƕ������
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