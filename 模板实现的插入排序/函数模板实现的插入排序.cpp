#include <iostream>
using namespace std;
#include <string>
/*
使用模板实现插入排序
*/
class person
{
	friend ostream& operator<<(ostream &os, person &p);
	friend bool operator<(person &p1, person &p2);
public:
	person(string name, int age)
	{
		this->name = name;
		this->age = age;
	}
public:
	string name;
	int age;
};
ostream& operator<<(ostream &os, person &p)
{
	os << "name:" << p.name << " age:" << p.age;
	return os;
}
bool operator<(person &p1, person &p2)
{
	return p1.age < p2.age ? true : false;
}


template <class T>
void insertSort(T arr[], int size)
{
	//在有序的序列上插入元素
	for (int i = 1; i < size; i++)
	{
		T temp= arr[i];
		int j = i - 1;
		for (; j >= 0 && temp < arr[j]; j--)
		{
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = temp;
	}
}
template <class T>
void print(T arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << endl;
	}
}
//测试普通类型
void test1()
{
	int arr[6] = {1, 2, 8, 3, 4, 10};
	int len = sizeof(arr) / sizeof(int);
	cout << "排序前：" << endl;
	print<int>(arr, len);

	insertSort<int>(arr, len);
	cout << "排序后：" << endl;
	print<int>(arr, len);
	
}
//测试复杂类型
void test2()
{
	person parr[4] = { person("A", 10), person("B", 80), person("C", 40), person("D", 20) };
	int len = sizeof(parr) / sizeof(person);
	cout << "排序前(年龄排序)：" << endl;
	print<person>(parr, len);

	insertSort<person>(parr, len);
	cout << "排序后(年龄排序)：" << endl;
	print<person>(parr, len);
}
int main()
{
	test1();
	test2();
	return 0;
}