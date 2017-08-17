#include <iostream>
using namespace std;
#include <vector>
#include <functional>
#include <string>
#include <algorithm>


class person
{
	friend struct myprint;
public:
	person()
	{
		this->name = "";
		this->age = 0;
	}
	person(string name, int age)
	{
		this->name = name;
		this->age = age;
	}
	
private:
	string name;
	int age;
};

template <class arg1, class arg2, class arg3, class ret>
struct mythird_fution
{
	typedef arg1 first_argment_type;
	typedef arg2 second_argment_type;
	typedef arg3 third_argment_type;
	typedef ret result_type;

};
template <class func>
class mybinder3nd
{

	typedef typename func::first_argment_type first_arg_type;
	typedef typename func::second_argment_type second_arg_type;
	typedef typename func::third_argment_type third_arg_type;
	typedef typename func::result_type ret_type;

public:
	mybinder3nd(func myfunc, second_arg_type par2, third_arg_type par3)
	{
		myfunction = myfunc;
		parma2 = par2;
		param3 = par3;
	}
	ret_type operator()(first_arg_type param1)
	{
		myfunction(param1, parma2, param3);
	}
	
private:
	func myfunction;
	second_arg_type parma2;
	third_arg_type param3;
};
template <class func, class second_type, class third_type>
mybinder3nd<func> mybind3nd(func function, second_type param2, third_type param3)
{
	return mybinder3nd<func>(function, param2, param3);
}
struct myprint : public mythird_fution<person, person, person, void>
{
	void operator()(person p, person param1, person param2)
	{
		cout << "age = " << p.age + param1.age + param2.age << endl;
	}
};
void test01()
{
	vector<person> v = {person("aa", 10), person("bb", 20)};

	person p1("cc", 30);
	person p2("dd", 40);
	for_each(v.begin(), v.end(), mybind3nd(myprint(), p1, p2));
}
int main()
{
	test01();
	return 0;
}