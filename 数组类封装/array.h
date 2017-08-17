#pragma once
#include <iostream>
using namespace std;

//关于函数的返回值是返回值还是返回引用，要看要不要做左值
class Array
{
	//数组输出，<<重载 ----------cout << arr;
	//这是全局函数重载运算符，局部函数重载要在库代码中添加，不安全
	friend ostream& operator<<(ostream &os, Array &arr);
public:
	Array();
	explicit Array(int capicity);//explicit(禁止隐式类型转换) 是防止这样初始化 Array arr = 10;
	Array(Array &arr);
	~Array();

	/*数组操作函数*/
	//尾部插入
	void pushBack(const int &val);
	//头部插入
	void pushFront(const int &val);
	//获得指定位置元素
	int& at(int index);
	//删除指定位置元素
	void deleteArr(int index);
	//获得数组的容量
	int getcapicity();

	/*运算符重载*/
	//赋值=重载
	Array& operator=(Array &arr);
	//数据输入，<<重载 ----------arr << 1 << 2
	Array& operator<<(int val);
	//下标[]重载
	int& operator[](int index);
	
private:
	int capicity;
	int size;
	int *paddress;
};