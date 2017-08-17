#include <iostream>
using namespace std;
#include "MyString.h"

void test()
{
	MyString str1;
	cout << "str1:" << str1 << endl;
	cin >> str1;
	cout << "str1:" << str1 << endl;
	MyString str2 = "hello world";
	cout << "str2:" << str2 << endl;
	MyString str3(3, 'a');
	cout << "str3:" << str3 << endl;
	MyString str4(str1);
	cout << "str4:" << str4 << endl;

	MyString str5 = str1 + str2;
	cout << "str5:" << str5 << endl;

	str5 = str1 + str3;
	cout << "str5:" << str5 << endl;

	str5 = str1 + "moji";
	cout << "str5:" << str5 << endl;

	str5 += str4;
	cout << "str5:" << str5 << endl;

	str5 += "GGGGG";
	cout << "str5:" << str5 << endl;

}
int main()
{

	test();
	return 0;
}