#include <iostream>
using namespace std;

class person
{
public:
	int age;
public:
	person()
	{
		this->age = 0;
		cout << "�޲ι���" << endl;
	}
	person(int age)
	{
		this->age = age;
		cout << "�вι���" << endl;
	}
	person(person &p)
	{
		this->age = p.age;
		cout << "��������" << endl;
	}
	~person()
	{
		cout << "��������" << endl;
	}
};

void test()
{
	person p[2]{person(10), person(20)};
	person p1(person(30));
	person p2(p1);
}
int main()
{
	//person p = person(10);
	test();

	return 0;
}
