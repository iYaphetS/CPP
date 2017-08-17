#include <iostream>
using namespace std;

class Student
{
public:
	Student(int a)
	{
		sa = a;
	}
private:
	int sa;
};

class Person
{
	friend Person operator-(int val, Person &p);
	friend void test();
public:
	Person(int a, int b)
	{
		ma = a;
		mb = b;
	}
#if 0
	Person operator-(Person &p)
	{
		Person ret(100 - p.ma, 100 - p.mb);
		return ret;
	}
#endif
private:
	int ma;
	int mb;
};

Person operator-(int val, Person &p)
{
	Person ret(val - p.ma, val - p.mb);
	return ret;//���Է��ؾֲ����󣨲�������������ÿ������캯���������ܷ��ؾֲ���������
}
void test()
{
	Person p(10, 20);

	Person ret = 100 - p;
	cout << "ret: " << "ma: " << ret.ma << " mb: " << ret.mb << endl;
 
}
int main()
{
	test();
	return 0;
}