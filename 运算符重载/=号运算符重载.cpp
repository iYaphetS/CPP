#include <iostream>
using namespace std;
#pragma warning(disable:4996)

class Person
{
	friend void test();
public:
	Person(char *name, int age)
	{
		this->pname = new char[strlen(name) + 1];
		strcpy(this->pname, name);
		this->age = age;
	}
	Person(const Person &p)
	{
		this->pname = new char[strlen(p.pname) + 1];
		strcpy(this->pname, p.pname);
		this->age = p.age;
	}
	Person& operator=(const Person &p)
	{
		if (this->pname != NULL)
		{
			delete[]this->pname;
			this->pname = NULL;
		}
		this->pname = new char[strlen(p.pname) + 1];
		strcpy(this->pname, p.pname);
		this->age = p.age;
		return *this;
	}
	~Person()
	{
		if (this->pname != NULL)
		{
			delete[strlen(this->pname) + 1]this->pname;
		}
	}
private:
	char *pname;
	int age;
};

void test()
{
	Person p1("mike", 10);
	Person p2("lili", 20);

	p2 = p1;
	cout << "name:" << p2.pname << " age:" << p2.age << endl;
}
int main()
{
	test();
	return 0;
}