#include <iostream>

using namespace std;

void init_arr(int (&p)[10])
{
	//cout << sizeof(p) << endl;
	int len = sizeof(p) / sizeof(int);
	for (int i = 0; i < len; i++)
	{
		p[i] = i + 1;
	}
}

void init_arr1(int* p)
{
	//cout << sizeof(p) << endl;
	int len = sizeof(p) / sizeof(int);
	for (int i = 0; i < len; i++)
	{
		p[i] = i + 1;
	}
}

int main()
{
	int arr[10];
	init_arr(arr);
	init_arr1(arr);

	return 0;
}