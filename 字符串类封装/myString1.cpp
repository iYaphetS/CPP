#include "myString.h"
#include <string>
#pragma warning(disable:4996)
MyString::MyString()
{
	this->mSize = 0;
	this ->pAddress = new char[mSize + 1];
	memset(pAddress, 0, mSize + 1);
	pAddress[0] = '\0';//上面清空这里可以不写
}
MyString::MyString(int n, char c)
{
	this->mSize = n;
	this->pAddress = new char[mSize + 1];
	memset(pAddress, 0, mSize + 1);
	for (int i = 0; i < n; i++)
	{
		pAddress[i] = c;
	}

}
MyString::MyString(const MyString& str)
{
	this->mSize = str.mSize;
	this->pAddress = new char[mSize + 1];
	memset(pAddress, 0, mSize + 1);
	strcpy(pAddress, str.pAddress);
}
MyString& MyString::operator=(const MyString& str)
{
	if (this->pAddress != NULL)
	{
		delete[]pAddress;
		pAddress = NULL;
	}
	this->mSize = str.mSize;
	this->pAddress = new char[mSize + 1];
	memset(pAddress, 0, mSize + 1);
	strcpy(pAddress, str.pAddress);

	return *this;

}
MyString& MyString::operator=(const char* str)
{
	if (this->pAddress != NULL)
	{
		delete[]pAddress;
		pAddress = NULL;
	}
	this->mSize = strlen(str);
	this->pAddress = new char[mSize + 1];
	memset(pAddress, 0, mSize + 1);
	strcpy(pAddress, str);
	return *this;
}
MyString::~MyString()
{
	this->mSize = 0;//注意这要置0
	if (this->pAddress != NULL)
	{
		delete[]pAddress;
		pAddress = NULL;
	}
}

//str1 + str2
MyString MyString::operator+(const MyString& str)
{
	MyString temp;//这个临时对象也可以在数据确定后创建（调用有参构造函数）
	if (temp.pAddress != NULL)
	{
		delete[]temp.pAddress;
		temp.pAddress = NULL;
	}
	temp.mSize = this->mSize + str.mSize;
	temp.pAddress = new char[temp.mSize + 1];
	memset(temp.pAddress, 0, temp.mSize + 1);
	strcat(temp.pAddress, this->pAddress);
	strcat(temp.pAddress, str.pAddress);
	return temp;
}

//str + "hello"
MyString MyString::operator+(const char *s)
{
	MyString temp;
	if (temp.pAddress != NULL)
	{
		delete[]temp.pAddress;
		temp.pAddress = NULL;
	}
	temp.mSize = this->mSize + strlen(s);
	temp.pAddress = new char[temp.mSize + 1];
	memset(temp.pAddress, 0, temp.mSize + 1);
	strcat(temp.pAddress, this->pAddress);
	strcat(temp.pAddress, s);
	return temp;
}

//str1 += str2;
MyString& MyString::operator+=(const MyString& str)
{
	MyString temp;
	if (temp.pAddress != NULL)
	{
		delete[]temp.pAddress;
		temp.pAddress = NULL;
	}
	temp.mSize = this->mSize + str.mSize;
	temp.pAddress = new char[temp.mSize + 1];
	memset(temp.pAddress, 0, temp.mSize + 1);
	strcat(temp.pAddress, this->pAddress);//上面清空，这里才能用strcat，不然使用strcpy
	strcat(temp.pAddress, str.pAddress);
	
	*this = temp;//调用赋值函数
	return *this;
	/*可以直接调用上面的重载函数
	*this = *this + str;
	*/
}
//str1 += "hello"
MyString& MyString::operator+=(const char *s)
{
	MyString temp;
	if (temp.pAddress != NULL)
	{
		delete[]temp.pAddress;
		temp.pAddress = NULL;
	}
	temp.mSize = this->mSize + strlen(s);
	temp.pAddress = new char[temp.mSize + 1];
	memset(temp.pAddress, 0, temp.mSize + 1);
	strcat(temp.pAddress, this->pAddress);
	strcat(temp.pAddress, s);

	*this = temp;
	return *this;
	/*可以直接调用上面的重载函数
	*this = *this + s;
	*/
}

char& MyString::operator[](int index)
{
	return this->pAddress[index];
}
int MyString::Size()
{
	return this->mSize;
}
std::ostream& operator<<(std::ostream &out, MyString &str)
{
	out << str.pAddress;
	return out;
}
std::istream& operator >> (std::istream &in, MyString &str)
{
	char buf[1024] = {0};
	in.getline(buf, 1024);

	if (str.pAddress != NULL)
	{
		delete[]str.pAddress;
		str.pAddress = NULL;
	}

	int size = strlen(buf);
	char *newspace = new char[size + 1];
	memset(newspace, 0, size + 1);
	strcpy(newspace, buf);

	str.mSize = size;
	str.pAddress = newspace;

	return in;
}
