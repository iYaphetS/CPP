#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>

template <class _arg1, class _arg2, class _arg3, class _result>
struct third_function
{
	typedef _arg1 first_argment_type;
	typedef _arg2 second_argment_type;
	typedef _arg3 third_argment_type;
	typedef _result result_type;
};

template <class func>
class mybinder3nd
{
public:
	typedef typename func::first_argment_type first_arg_type;
	typedef typename func::second_argment_type second_arg_type;
	typedef typename func::third_argment_type third_arg_type;
	typedef typename func::result_type ret_type;
	mybinder3nd(func myfunc, second_arg_type param2,
		third_arg_type param3)
	{
		this->myfunc = myfunc;
		this->param2 = param2;
		this->param3 = param3;
	}

	ret_type operator()(first_arg_type param1)
	{
		return myfunc(param1, param2, param3);
	}

private:
	func myfunc;
	second_arg_type param2;
	third_arg_type param3;
};

template <class func,class second_type, class third_type>
mybinder3nd<func> mybind3nd(func print, second_type param2, third_type param3)
{
	return mybinder3nd<func>(print, param2, param3);
}


struct myprint : public third_function<int, int, int, void>
{
	void operator()(int val, int param1, int param2)
	{
		cout << "val = " << val << " param1 = " << param1 << " param2 = " << param2 << endl;
	}
};
void test01()
{
	vector<int> v = {1, 4, 6, 8, 5};
	for_each(v.begin(), v.end(), mybind3nd(myprint(), 100, 200));
	//bind2nd
}
int main()
{
	test01();
	return 0;
}
