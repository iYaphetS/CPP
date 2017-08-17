#include <iostream>
using namespace std;
#include "array.h"


void test()
{
	Array arr1;
	Array arr2(20);
	for (int i = 0; i < arr1.getcapicity(); i++)
	{
		arr1.pushBack(i + 10);
	}
	arr1.deleteArr(0);
	arr1.deleteArr(0);
	arr1.deleteArr(0);
	arr1 << 20 << 21 << 22;
	cout << arr1 << endl;
	cout << arr1.at(9) << endl;

	for (int i = 0; i < arr2.getcapicity(); i++)
	{
		arr2.pushBack(i + 10);
	}
	arr2.deleteArr(0);
	arr2.deleteArr(0);
	arr2.deleteArr(0);
	arr2.pushFront(100);
	arr2.pushFront(200);
	cout << arr2 << endl;

	//拷贝构造
	Array arr3(arr1);
	cout << arr3 << endl;

	//赋值函数
	Array arr4;
	arr4 = arr2;
	cout << arr4 << endl;

}
int main()
{
	test();
	return 0;
}