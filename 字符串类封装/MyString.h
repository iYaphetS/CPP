#pragma once
#include <iostream>
using namespace std;

class MyString
{
	//字符串输出 cout << str
	friend ostream& operator<<(ostream &os, const MyString &str);
	//字符串输入 cout >> str
	friend istream& operator>>(istream &in, MyString &str);

public:
	//无参构造函数
	MyString();
	//有参构造函数 MyString str = "hello"
	MyString(const char *str);
	//有参构造函数 MyString str(2, 'c')
	MyString(int n, char c);
	//拷贝构造函数 MyString str1 = str2
	MyString(const MyString &str);
	//赋值=重载  str1 = str3
	MyString& operator=(const MyString &str);
	//析构函数
	~MyString();

	//字符串拼接 ret = str1 + str2
	MyString operator+(const MyString &str);
	//ret = str1 + "hello"
	MyString operator+(const char *str);
	//字符串追加 str1 += str2
	MyString& operator+=(const MyString &str);
	//str1 += "hello"
	MyString& operator+=(const char *str);

	//字符串有效长度
	int mysize();
private:
	char *pString;
	int size;
};