#include <iostream>
using namespace std;
#include <vector>
#include <functional>
#include <algorithm>
#include <numeric>

class print
{
public:
	print()
	{
		count = 0;
	}
	void operator()(int val)
	{
		cout << val << endl;
		++count;
	}
public:
	int count;
};
void test01()
{
	vector<int> v = {1, 2, 3, 4, 5, 10};
	print p;
	print ret = for_each(v.begin(), v.end(), p);
	/*
	_Fn1 for_each(_InIt _First, _InIt _Last, _Fn1 _Func)

	return (_Func);//返回的_Func已经改变
	*/
	cout << endl;
	cout << p.count << endl;//0
	cout << ret.count << endl;//6
}

//transform
class mytransform
{
public:
	int operator()(int val)
	{
		return val + 10;
	}
};
void test02()
{
	vector<int> v1 = {1, 2, 3, 4, 5};
	vector<int> dst1;
	vector<int> dst2;
	dst1.resize(v1.size());//对dst1容器一定要开辟内存初始化
	//因为transform内部是赋值操作
	dst2.resize(v1.size());
	transform(v1.begin(), v1.end(), dst1.begin(), mytransform());
	/*
	template<class _InIt, class _OutIt, class _Fn1>
	inline _OutIt _Transform(_InIt _First, _InIt _Last,_OutIt _Dest, _Fn1 _Func)
	{
	for (; _First != _Last; ++_First, ++_Dest)
	*_Dest = _Func(*_First);
	return (_Dest);
	}
	*/
	for_each(dst1.begin(), dst1.end(), [](int val)
	{
		cout << val << endl;
	});
	cout << "===========" << endl;
	transform(v1.begin(), v1.end(), dst1.begin(), dst2.begin(), plus<int>());//_Func(*_First1, *_First2)
	/*
	for (; _First1 != _Last1; ++_First1, (void)++_First2, ++_Dest)
		*_Dest = _Func(*_First1, *_First2);
	return (_Dest);
	}
	*/
	for_each(dst2.begin(), dst2.end(), [](int val)
	{
		cout << val << endl;
	});
}
int main()
{
	//test01();
	test02();
	return 0;
}