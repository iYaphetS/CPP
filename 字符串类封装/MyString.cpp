#include "MyString.h"
#pragma warning(disable:4996)

ostream& operator<<(ostream &os, const MyString &str)
{
	os << str.pString;
	return os;
}
istream& operator>>(istream &in, MyString &str)
{
	//将输入法字符串放在缓冲区
	char buf[1024];
	memset(buf, 0, sizeof(buf));
	in.getline(buf, 1024);

	if (str.pString != NULL)
	{
		delete[]str.pString;
		str.pString = NULL;
	}
	//将缓存区的内容拷贝到对象成员变量指向的堆空间中去
	str.size = strlen(buf);
	char *newspace = new char[str.size + 1];
	memset(newspace, 0, str.size + 1);
	strcpy(newspace, buf);
	str.pString = newspace;
	
	return in;
}


//无参构造函数
MyString::MyString()
{
	size = 0;
	pString = new char[size + 1];
	memset(pString, 0, size + 1);
	pString[0] = '\0';//**
	
}
//有参构造函数 MyString str = "hello"
MyString::MyString(const char *str)
{
	size = strlen(str);
	pString = new char[size + 1];
	memset(pString, 0, size + 1);
	strcpy(pString, str);
	
}
//有参构造函数 MyString str(2, 'c')
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

//拷贝构造函数 MyString str1 = str2
MyString::MyString(const MyString &str)
{
	size = str.size;
	pString = new char[size + 1];
	memset(pString, 0, size + 1);
	strcpy(pString, str.pString);
}
//赋值=重载  str1 = str3
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

//析构函数
MyString::~MyString()
{
	if (pString != NULL)
	{
		delete[]pString;
		pString = NULL;
	}
}

//字符串拼接 ret = str1 + str2
MyString MyString::operator+(const MyString &str)
{
	int newsize = strlen(pString) + strlen(str.pString);
	char *newspace = new char[newsize + 1];
	memset(newspace, 0, newsize + 1);
	strcat(newspace, pString);
	strcat(newspace, str.pString);

	MyString temp(newspace);//产生零时对象
	return temp;//返回零时对象，实际拷贝一份匿名匿名对象返回（调用者如果没有用对象来接
	//这个匿名对象,匿名对象将被销毁），零时对象被销毁
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
//字符串追加 str1 += str2
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

//字符串有效长度
int MyString::mysize()
{
	return size;
}