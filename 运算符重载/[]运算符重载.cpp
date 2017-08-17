#include <iostream>
using namespace std;

class Array
{
	friend void test();
	int& operator[](int index)
	{
		return this->arr[index];
	}

private:
	int arr[10];
};

void test()
{
	Array arr1;

	for (int i = 0; i < 10; i++)
	{
		arr1[i] = i + 100;
	}

	for (int i = 0; i < 10; i++)
	{
		cout << arr1[i] << " ";
	}
	cout << endl;
}
int main()
{

	test();
	return 0;
}
