#include "array.h"

Array::Array()
{
	this->capicity = 10;
	this->size = 0;
	this->paddress = new int[this->capicity];
}
Array::Array(int capicity)
{
	this->capicity = capicity;
	this->size = 0;
	this->paddress = new int[this->capicity];
}
Array::Array(Array &arr)
{
	this->capicity = arr.capicity;
	this->size = arr.size;
	this->paddress = new int[arr.capicity];

	for (int i = 0; i < this->size; i++)
	{
		this->paddress[i] = arr.paddress[i];
	}
}
Array::~Array()
{
	if (this->paddress != NULL)
	{
		delete[]this->paddress;
		this->paddress = NULL;
	}
}

//尾部插入
void Array::pushBack(const int &val)
{
	if (this->size == this->capicity)
	{
		return;
	}
	this->paddress[this->size] = val;
	this->size++;
}
//头部插入
void Array::pushFront(const int &val)
{
	if (this->size == this->capicity)
	{
		return;
	}
	for (int i = this->size  - 1; i >= 0; i--)
	{
		this->paddress[i + 1] = this->paddress[i];
	}
	this->paddress[0] = val;
	this->size++;
}
//获得指定位置元素
int& Array::at(int index)
{
	//用于传来不合法的下标，我们是无法做出处理，这种情况出现越界出错，有用户控制
	return this->paddress[index];
}
//删除指定位置元素
void Array::deleteArr(int index)
{
	if (index < 0 || index > this->size - 1)
	{
		return;
	}
	for (int i = index; i < this->size - 1; i++)
	{
		this->paddress[i] = this->paddress[i + 1];
	}
	this->size--;
}
int Array::getcapicity()
{
	return this->capicity;
}

//赋值=重载--------就是析构函数加上拷贝构造函数
Array& Array::operator=(Array &arr)
{
	if (this->paddress != NULL)
	{
		delete[]this->paddress;
		this->paddress = NULL;
	}
	this->capicity = arr.capicity;
	this->size = arr.size;
	this->paddress = new int[arr.capicity];

	for (int i = 0; i < this->size; i++)
	{
		this->paddress[i] = arr.paddress[i];
	}
	return *this;
}

//数据输入，<<重载 ----------arr << 1 << 2
Array& Array::operator<<(int val)
{
	pushBack(val);
	return *this;
}
//下标[]重载
int& Array::operator[](int index)
{
	return this->paddress[index];
}

//数组输出，<<重载 ----------cout << arr;
ostream& operator<<(ostream &os, Array &arr)
{
	for (int i = 0; i < arr.size; i++)
	{
		os << arr.paddress[i] << " ";
	}
	return os;
}