#include <iostream>
using namespace std;
#include <string>

class Person
{
	friend ostream& operator<<(ostream &os, const Person &p);

public:
	Person(string name, int age)
	{
		this->name = name;
		this->age = age;
	}
	Person(const Person &p)
	{
		this->name = p.name;
		this->age = p.age;
	}
private:
	string name;
	int age;
};

ostream& operator<<(ostream &os, const Person &p)
{
	os << "name:" << p.name << " age:" << p.age;
	os << "	";
	return os;
}
void test()
{
	Person p1("mike", 10);
	Person p2("lili", 20);
	Person p3(p1);
	cout << p1 << p2 << p3 << endl;
}
int main()
{
	test();
	return 0;
}