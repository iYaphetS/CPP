#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <string>
using namespace std;

//1.����()�ĺ�������������
/*_Fn1 for_each(_InIt _First, _InIt _Last, _Fn1 _Func)
_First---�����������ֻ������ʼλ��
_Last----���������β��
_Func----�����������
for (; _First != _Last; ++_First)
_Func(*_First);--------һ���������
}

*/
//�����Ǹ���Ԫ�����ͼ̳���binary_function
//�����Ǹ�һԪ�����ͼ̳���unary_function
//binary_function<int, int, void>
//��һ���������������ź����ĵ�һ����������
//�ڶ����������������ź����ĵڶ�����������
//�������������������ź����ķ���ֵ����
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
	//������������������ƥ��ĺ���ƥ��ɷ���Ҫ��ĺ�������
	//bind1nd----�������󶨵���һ�������� 
	//bind2nd----�������󶨵��ڶ���������
	for_each(v.begin(), v.end(), bind2nd(myprint(), 10));
}

//2.ȡ��������
//ע��ֻ��ν����Ч��ʲô��ν�ʣ���ͨ��������������operator()�ķ���ֵΪbool�ĺ��������º�����
//һԪν�ʣ�����ֻ��һ������not1��������ȡ��������
//��Ԫν�ʣ���������������not2��������ȡ��������
void test02()
{
	vector<int> v = {2, 1, 8, 6, 3, 4};

	sort(v.begin(), v.end(), not2(less<int>()));//�Ƚ���������
	//sort(v.begin(), v.end(), greater<int>());
	for_each(v.begin(), v.end(), [](int val)
	{
		cout << val << " ";
	});
	cout << endl;
}

//3.��ͨ������������
void myfun(int val, int param)
{
	cout << val + param << endl;
}


void test03()
{
	vector<int> v = {1, 2, 3, 4, 7};

	//for_each(v.begin(), v.end());
	//ptr_fun���Լ��������ͨ����ת�ɺ�������
	for_each(v.begin(), v.end(), bind2nd(ptr_fun(myfun), 10));

}

//4.��Ա��ͨ����������  mem_fun_ref(�����洢����) mem_fun(�����洢����ָ��)
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