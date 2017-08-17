#include <iostream>
using namespace std;
class Person
{
	friend Person operator+(const int &val, const Person & p);
	friend void test();
public:
	Person(int age)
	{
		this->age = age;
	}
	Person operator+(const Person &p)
	{
		Person ret(this->age + p.age);
		return ret;
	}
	Person operator+(const int &val)
	{
		Person ret(this->age + val);
		return ret;
	}
	Person(const Person &p)
	{
		this->age = p.age;
	}
private:
	int age;
};
Person operator+(const int &val, const Person & p)
{
	Person ret(val + p.age);
	return ret;
}
void test()
{
	Person p1(10);
	Person p2(20);

	Person ret1 = p1 + p2;
	cout << "age:" << ret1.age << endl;

	Person ret2 = p1 + 100;
	cout << "age:" << ret2.age << endl;

	Person ret3 = 200 + p1;
	cout << "age:" << ret3.age << endl;

}
int main()
{
	test();
	return 0;
}