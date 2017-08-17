#include <iostream>
using namespace std;
#include <vector>
#include <functional>
#include <algorithm>
#include <numeric>

//set_intersection(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest)
//set_union(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest)
//set_difference(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest)
void test01()
{
	vector<int> v1 = {1, 2, 3, 4, 5, 6};
	vector<int> v2 = {4, 5, 6, 7, 8, 9, 10};
	vector<int> dst;
	//set_intersection(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest)
	//交集
	dst.resize(min(v1.size(), v2.size()));
	vector<int>::iterator myend = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), dst.begin());
	/*
	_OutIt set_intersection(_InIt1 _First1, _InIt1 _Last1,
		_InIt2 _First2, _InIt2 _Last2, _OutIt _Dest)
	*/
	for_each(dst.begin(), myend, [](int val)
	{
		cout << val << " ";
	});
	cout << endl;
}

void test02()
{
	vector<int> v1 = { 1, 2, 3, 4, 5, 6 };
	vector<int> v2 = { 4, 5, 6, 7, 8, 9, 10 };
	vector<int> dst;
	dst.resize(v1.size() + v2.size());
	//求合集
	//set_union(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest)
	vector<int>::iterator myend = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), dst.begin());

	for_each(dst.begin(), myend, [](int val)
	{
		cout << val << " ";
	});
	cout << endl;
}

void test03()
{
	vector<int> v1 = { 1, 2, 3, 4, 5, 6 };
	vector<int> v2 = { 4, 5, 6, 7, 8, 9, 10 };
	vector<int> dst;
	dst.resize(v1.size());
	//set_difference(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest)
	//求v1的差集
	vector<int>::iterator myend = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), dst.begin());
	for_each(dst.begin(), myend, [](int val)
	{
		cout << val << " ";
	});
	cout << endl;

	//求v1的差集
	myend = set_difference(v2.begin(), v2.end(), v1.begin(), v1.end(), dst.begin());
	for_each(dst.begin(), myend, [](int val)
	{
		cout << val << " ";
	});
	cout << endl;

}
int main()
{
	test01();
	test02();
	test03();
	return 0;
}