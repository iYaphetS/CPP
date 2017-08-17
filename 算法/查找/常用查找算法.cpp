#include <iostream>
using namespace std;
#include <functional>
#include <algorithm>
#include <vector>
#include <numeric>
#include <string>

/*
find(iterator beg, iterator end, value)
*/
void test01()
{
	vector<int> v = {1, 2, 4, 5, 9, 3};

	vector<int>::iterator ret = find(v.begin(), v.end(), 4);
	if (ret == v.end())
	{
		cout << "û���ҵ�" << endl;
	}
	else
	{
		cout << *ret << endl;
	}
}

/*��������Ԫ����ͬ
adjacent_find(iterator beg, iterator end, _callback);
_callback��������Ĭ���Ǽ�ֵ==�����ڶ���
//1. ����==�������
//2. �ֶ������������ıȽϹ���(��������)
*/
void test02()
{
	vector<int> v = { 1, 2, 4, 5, 2, 9, 3 };
	vector<int>::iterator ret = adjacent_find(v.begin(), v.end());
	if (ret == v.end())
	{
		cout << "û���ҵ�" << endl;
	}
	else
	{
		cout << *ret << endl;
	}
}

/*----���ֲ���
bool binary_search(iterator beg, iterator end, value);
*/
void test03()
{
	/*���ֲ��ҵ�����
	1.����������������(Ĭ������)
	2.����˳��Ĭ��less<int>��Ҫ��������˳�����һ��	
	*/
	//vector<int> v = { 1, 2,  5, 2, 9,4, 3 };err
	vector<int> v = { 1, 2,  3, 4, 5,6, 7 ,8,9};
	sort(v.begin(), v.end(), greater<int>());
	//bool ret = binary_search(v.begin(), v.end(), 4);
	/*
	binary_search(_FwdIt _First, _FwdIt _Last,
		const _Ty& _Val, _Pr _Pred)
	*/
	bool ret = binary_search(v.begin(), v.end(), 1, greater<int>());
	if (ret)
	{
		cout << "�ҵ���" << endl;
	}
	else
	{
		cout << "û���ҵ�" << endl;
	}
}

class person 
{
	friend class Myfun;
	friend class personcompare;
public:
	person(string name, int age)
	{
		this->name = name;
		this->age = age;
	}
	bool operator==(const person &p)//Ҫ��const
	{
		return this->name == p.name && this->age == p.age;
	}
	void print()
	{
		cout << "name:" << name << " age:" << age << endl;
	}
private:
	string name;
	int age;
};
class Myfun : public binary_function<person, person, bool>
{
public:
	//����Ҫ��const
	bool operator()(const person &p, const person &param) const
	{
		return param.name == p.name && param.age == p.age;
	}
};
/*
find_if(iterator beg, iterator end, _callback);
*/
bool myfun(int val, int param)
{
	return val == param;
}
void test04()
{
	vector<int> v = { 1, 2,  3, 4, 5,6, 7 };
	vector<int>::iterator ret = find_if(v.begin(), v.end(), bind2nd(ptr_fun(myfun), 2));
	cout << *ret << endl;

	vector<person> v1 = {person("aa", 10), person("bb", 20), person("cc", 30)};

	person temp("aa", 10);
	vector<person>::iterator ret1 = find_if(v1.begin(), v1.end(), bind2nd(Myfun(), temp));
	ret1->print();
}
/*
count(iterator beg, iterator end, value);
*/
void test05()
{
	vector<int> v = {1, 2, 4, 2, 2, 5, 6, 2, 6};

	int ret = count(v.begin(), v.end(), 2);

	cout << ret << endl;

}

class personcompare : public binary_function<person*, person *, bool>
{
public:
	bool operator()(person *p, person *param) const
	{
		return p->name == param->name && p->age == param->age;
	}
};

/*
count_if(iterator beg, iterator end, _callback);
*/
void test06()
{
	vector<person> v = { person("aa", 10), person("aa", 10), person("bb", 20), person("cc", 30) };

	//�洢��������==
	person temp("aa", 10);;
	int ret = count(v.begin(), v.end(), temp);
	cout << ret << endl;

	vector<person *> v1;
	v1.push_back(new person("aa", 10));
	v1.push_back(new person("aa", 10));
	v1.push_back(new person("aa", 10));
	v1.push_back(new person("bb", 20));
	v1.push_back(new person("cc", 30));
	
	//��count_if
	ret = count_if(v1.begin(), v1.end(), bind2nd(personcompare(), &temp));

	cout << ret << endl;

	for_each(v1.begin(), v1.end(), [](person *p)
	{
		delete p;
	});
}
int main()
{
	//test01();
	//test02();
	test03();
	//test04();
	//test05();
	//test06();
	return 0;
}