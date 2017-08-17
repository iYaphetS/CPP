#include <iostream>
using namespace std;
#include <vector>
#include <functional>
#include <algorithm>

struct myPrint
{
	
	void operator()(int val, int param)
	{
		cout << "val = " << val << " param = " << param << endl;
	}
};

class Target
{
public:
	Target(myPrint myprint, int par)
	{
		print = myprint;
		param = par;
	}

	void operator()(int val)
	{
		print(val, param);
	}
private:
	myPrint print;
	int param;
};

Target mybind2nd(myPrint print, int val)
{
	return Target(print, val);
}
void test01()
{
	vector<int> v = {1, 5, 3, 8, 10};
	for_each(v.begin(), v.end(), mybind2nd(myPrint(), 100));
	/*bind2nd
	mybind2nd���� 
	1.�����м�����������вι��캯��
	2.�����������󷵻�
	3.mybind2nd()������һ�������

	for_each����
	1.�����ڲ�����һ����������
	void _For_each_unchecked(_InIt _First, _InIt _Last, _Fn1& _Func)
	{	// perform function for each element
	for (; _First != _Last; ++_First)
	_Func(*_First);
	2. _func()�����˶���_func��()�����غ���
	3.���_func���Լ�д��һԪ�������󣬾͵���������()�����غ���
	4.���_func��bind2d���ص�һ���������󣬾͵���������������()�����غ���

	*/
}
int main()
{
	test01();
	return 0;
}