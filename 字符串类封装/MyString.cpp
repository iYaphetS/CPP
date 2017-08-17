#include "MyString.h"
#pragma warning(disable:4996)

ostream& operator<<(ostream &os, const MyString &str)
{
	os << str.pString;
	return os;
}
istream& operator>>(istream &in, MyString &str)
{
	//�����뷨�ַ������ڻ�����
	char buf[1024];
	memset(buf, 0, sizeof(buf));
	in.getline(buf, 1024);

	if (str.pString != NULL)
	{
		delete[]str.pString;
		str.pString = NULL;
	}
	//�������������ݿ����������Ա����ָ��Ķѿռ���ȥ
	str.size = strlen(buf);
	char *newspace = new char[str.size + 1];
	memset(newspace, 0, str.size + 1);
	strcpy(newspace, buf);
	str.pString = newspace;
	
	return in;
}


//�޲ι��캯��
MyString::MyString()
{
	size = 0;
	pString = new char[size + 1];
	memset(pString, 0, size + 1);
	pString[0] = '\0';//**
	
}
//�вι��캯�� MyString str = "hello"
MyString::MyString(const char *str)
{
	size = strlen(str);
	pString = new char[size + 1];
	memset(pString, 0, size + 1);
	strcpy(pString, str);
	
}
//�вι��캯�� MyString str(2, 'c')
MyString::MyString(int n, char c)
{
	size = n;
	pString = new char[size + 1];
	memset(pString, 0, size + 1);
	for (int i = 0; i < n; ++i)
	{
		pString[i] = c;
	}
}

//�������캯�� MyString str1 = str2
MyString::MyString(const MyString &str)
{
	size = str.size;
	pString = new char[size + 1];
	memset(pString, 0, size + 1);
	strcpy(pString, str.pString);
}
//��ֵ=����  str1 = str3
MyString& MyString::operator=(const MyString &str)
{
	if (pString != NULL)
	{
		delete[]pString;
		pString = NULL;
	}
	size = str.size;
	pString = new char[size + 1];
	memset(pString, 0, size + 1);
	strcpy(pString, str.pString);

	return *this;
}

//��������
MyString::~MyString()
{
	if (pString != NULL)
	{
		delete[]pString;
		pString = NULL;
	}
}

//�ַ���ƴ�� ret = str1 + str2
MyString MyString::operator+(const MyString &str)
{
	int newsize = strlen(pString) + strlen(str.pString);
	char *newspace = new char[newsize + 1];
	memset(newspace, 0, newsize + 1);
	strcat(newspace, pString);
	strcat(newspace, str.pString);

	MyString temp(newspace);//������ʱ����
	return temp;//������ʱ����ʵ�ʿ���һ�������������󷵻أ����������û���ö�������
	//�����������,�������󽫱����٣�����ʱ��������
}
//ret = str1 + "hello"
MyString MyString::operator+(const char *str)
{
	int newsize = strlen(pString) + strlen(str);
	char *newspace = new char[newsize + 1];
	memset(newspace, 0, newsize + 1);
	strcat(newspace, pString);
	strcat(newspace, str);

	MyString temp(newspace);
	return temp;
}
//�ַ���׷�� str1 += str2
MyString& MyString::operator+=(const MyString &str)
{
	int newsize = strlen(pString) + strlen(str.pString);
	char *newspace = new char[newsize + 1];
	memset(newspace, 0, newsize + 1);
	strcat(newspace, pString);
	strcat(newspace, str.pString);

	if (pString != NULL)
	{
		delete[]pString;
		pString = NULL;
	}
	pString = newspace;
	size = newsize;

	return *this;
}
//str1 += "hello"
MyString& MyString::operator+=(const char *str)
{
	int newsize = strlen(pString) + strlen(str);
	char *newspace = new char[newsize + 1];
	memset(newspace, 0, newsize + 1);
	strcat(newspace, pString);
	strcat(newspace, str);

	if (pString != NULL)
	{
		delete[]pString;
		pString = NULL;
	}
	pString = newspace;
	size = newsize;

	return *this;
}

//�ַ�����Ч����
int MyString::mysize()
{
	return size;
}