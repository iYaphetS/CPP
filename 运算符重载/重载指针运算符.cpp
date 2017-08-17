#include <iostream>
using namespace std;
#include <string>

class Person
{
public:
	Person(string name, int age)
	{
		this->name = name;
		this->age = age;
	}
	void showperson()
	{
		cout << "name:" << this->name << " age:" << this->age << endl;
	}
private:
	string name;
	int age;
};

class SmartPoint
{
public:
	SmartPoint(Person *p)
	{
		this->Pperson = p;
	}
	Person* operator->()
	{
		return Pperson;
	}
	Person operator*()
	{
		return *Pperson;
	}
	~SmartPoint()
	{
		if (this->Pperson != NULL)
		{
			delete Pperson;
		}
	}
private:
	Person *Pperson;
};
void test()
{
	Person *p = new Person("mike", 10);
	SmartPoint sp(p);

	sp->showperson();
	(*sp).showperson();
}

int main()
{
	test();
	return 0;
}