#include <iostream>
using namespace std;
#include <string>
class Student
{

};
class Person
{
public:
	Person(string name, int age)
	{
		this->name = name;
		this->age = age;
	}
	operator bool()
	{
		return true;
	}
	operator string()
	{
		return name;
	}
	operator int()
	{
		return age;
	}
	operator Student()
	{
		return Student();
	}
private:
	string name;
	int age;
};

//�Զ���Ķ�����Ҫת���������ͣ���Ҫ�ṩ��Ӧ����ʽ����ת������
//operator ��������() {return �������Ͷ�Ӧ��ֵ}
void test()
{
	Person p1("mike", 10);

	bool b = p1;
	cout << b << endl;

	string str = p1;
	cout << str << endl;

	int num = p1;
	cout << num << endl;

	Student st = p1;


}
int main()
{
	test();
	return 0;
}