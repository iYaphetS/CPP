#pragma once
#include <iostream>
using namespace std;

class MyString
{
	//�ַ������ cout << str
	friend ostream& operator<<(ostream &os, const MyString &str);
	//�ַ������� cout >> str
	friend istream& operator>>(istream &in, MyString &str);

public:
	//�޲ι��캯��
	MyString();
	//�вι��캯�� MyString str = "hello"
	MyString(const char *str);
	//�вι��캯�� MyString str(2, 'c')
	MyString(int n, char c);
	//�������캯�� MyString str1 = str2
	MyString(const MyString &str);
	//��ֵ=����  str1 = str3
	MyString& operator=(const MyString &str);
	//��������
	~MyString();

	//�ַ���ƴ�� ret = str1 + str2
	MyString operator+(const MyString &str);
	//ret = str1 + "hello"
	MyString operator+(const char *str);
	//�ַ���׷�� str1 += str2
	MyString& operator+=(const MyString &str);
	//str1 += "hello"
	MyString& operator+=(const char *str);

	//�ַ�����Ч����
	int mysize();
private:
	char *pString;
	int size;
};