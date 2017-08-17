#include <iostream>
using namespace std;
#include "myString.h"


void test()
{
	MyString str1;
	cout << "ÇëÊäÈë×Ö·û´®£º";
	cin >> str1;
	MyString str2(5, 'G');
	MyString str3(str1);
	cout << str3 << endl;
	str3 = str2;
	cout << str3 << endl;

	MyString str4 = str1 + str2;
	cout << str4 << endl;

	str4 = str3 + "haha";
	cout << str4 << endl;

	str4 += str3;
	cout << str4 << endl;

	str4 += "heihei";
	cout << str4 << endl;


}
int main()
{
	test();
	return 0;
}