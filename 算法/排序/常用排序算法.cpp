#include <iostream>
using namespace std;
#include <vector>
#include <functional>
#include <algorithm>
#include <numeric>
#include <string>
#include <ctime>

//1. merge(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest)
void test01()
{
	//要求将两个已经有序（且两个都是升序或者降序）的序列，按照原来的顺序放到新容器中
	vector<int> v1 = {1, 2, 4, 6, 8, 10};
	vector<int> v2 = {3, 5, 8, 11, 12};
	vector<int> v;
	v.resize(v1.size() + v2.size());
	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v.begin());

	for_each(v.begin(), v.end(), [](int val)
	{
		cout << val << " ";
	});
	cout << endl;
}
//merge默认的是升序，如果是降序，要手动添加降序规则
void test02()
{
	vector<int> v1;
	v1.push_back(2);
	v1.push_back(1); 
	v1.push_back(6);
	v1.push_back(4);
	vector<int> v2 = {1, 4, 2, 9, 6};
	vector<int> v;
	v.resize(v1.size() + v2.size());

	sort(v1.begin(), v1.end(), greater<int>());
	sort(v2.begin(), v2.end(), greater<int>());

	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v.begin(), greater<int>());
	for_each(v.begin(), v.end(), [](int val)
	{
		cout << val << " ";
	});
	cout << endl;
}

//2. sort(iterator beg, iterator end, _callback)
//要求迭代器必须是随机迭代器----vector deque两种
void test03()
{
	vector<int> v = {1,3, 4, 6, -1};

	sort(v.begin(), v.end());

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

//打乱顺序
//3. random_shuffle(iterator beg, iterator end) 
void test04()
{
	srand((unsigned int)time(NULL));
	vector<int> v = {1, 3, 4, 7, -1, 10};

	sort(v.begin(), v.end(), greater<int>());

	random_shuffle(v.begin(), v.end());
	for (auto it : v)
	{
		cout << it << " ";
	}
	cout << endl;
}

//4. reverse(iterator beg, iterator end)
void test05()
{
	vector<int> v = {1, 3, 5, 6, 10};

	reverse(v.begin(), v.end());

	for_each(v.begin(), v.end(), [](int val)
	{
		cout << val << " ";
	});
	cout << endl;
}
int main()
{
	//test01();
	//test02();
	//test03();
	//test04();
	test05();
	return 0;
}