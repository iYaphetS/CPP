#include <iostream>
using namespace std;
#include <string>

template <class T>
void BubbleSort(T arr[], int len)
{
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = 0; j < len - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				T temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

template <class T>
void print(T arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << endl;
	}

}
//测试基础数据类型
void test01()
{
	int arr[] = {2, 8, 4, 3, 2, 9};
	int len = sizeof(arr) / sizeof(arr[0]);
	BubbleSort(arr, len);
	print(arr, len);
}

class person
{
	friend ostream& operator<<(ostream &os, const person &p)
	{
		os << "name:" << p.name << " age:" << p.age;
		return os;
	}
public:
	person(string name, int age)
	{
		this->name = name;
		this->age = age;
	}
	bool operator>(const person &p)
	{
		return this->age > p.age;
	}

private:
	string name;
	int age;
};
//测试复杂数据类型
void test02()
{
	person p[3] = {person("aa", 10), person("bb", 30), person("cc", 20)};
	int len = sizeof(p) / sizeof(person);
	BubbleSort(p, len);
	print(p, len);
}
int main()
{
	test01();
	test02();
	return 0;
}