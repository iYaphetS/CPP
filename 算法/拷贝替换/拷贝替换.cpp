#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>
#include <string>

/*
copy(iterator beg, iterator end, iterator dest)
replace(iterator beg, iterator end, oldvalue, newvalue)
replace_if(iterator beg, iterator end, _callback, newvalue)
swap(container c1, container c2)
*/

void test01()
{
	vector<int> v1 = {1, 3, 3, 5, 8, 10};
	vector<int> v2;
	v2.resize(v1.size());

	copy(v1.begin(), v1.end(), v2.begin());

	for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	replace(v1.begin(), v1.end(), 3, 666);
	for_each(v1.begin(), v1.end(), [](int val)
	{
		cout << val << " ";
	});
	cout << endl;
}
void test02()
{
	//swap 两个容器的大小是一样的
	vector<int> v1 = { 1, 3, 5, 8, 10 };
	vector<int> v2 = {2, 4, 6, 10, 11};

	swap(v1, v2);
	for_each(v1.begin(), v1.end(), [](int val)
	{
		cout << val << " ";
	});
	cout << endl;

	for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

}

//replace_if(iterator beg, iterator end, _callback, newvalue)
//按照条件来替换容器中的值

class conditionReplace : public binary_function<int, int, bool>
{
public:
	bool operator()(int val, int param) const
	{
		return val > param;
	}
};
void test03()
{
	vector<int> v1 = {1, 4, 5, 6, 3, 11};

	//把大于4的都替换成666
	replace_if(v1.begin(), v1.end(), bind2nd(conditionReplace(), 4), 666);
	for_each(v1.begin(), v1.end(), [](int val)
	{
		cout << val << " ";
	});
	cout << endl;

}

int main()
{
	//test01();
	//test02();
	test03();
	return 0;
}