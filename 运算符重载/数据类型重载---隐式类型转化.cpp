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

//自定义的对象需要转换其他类型，需要提供相应的隐式类型转换规则
//operator 数据类型() {return 数据类型对应的值}
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