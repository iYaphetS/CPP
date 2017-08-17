#include <iostream>
using namespace std;
//#include <string>
#pragma warning(disable:4996)

class Person
{
	friend istream& operator>>(istream &in, Person &p);
	friend ostream& operator<<(ostream &os, const Person &p);

private:
	//string name;
	int age;
};
istream& operator>>(istream &in, Person &p)
{
	in >> p.age;
	//in >> p.name;
	return in;
}

ostream& operator<<(ostream &os, const Person &p)
{
	os << p.age;
	return os;
}

void test()
{
	Person p1;
	cin >> p1;
	cout << p1;
}
int main()
{
	test();
	return 0;
}