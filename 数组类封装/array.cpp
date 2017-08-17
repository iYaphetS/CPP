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

//β������
void Array::pushBack(const int &val)
{
	if (this->size == this->capicity)
	{
		return;
	}
	this->paddress[this->size] = val;
	this->size++;
}
//ͷ������
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
//���ָ��λ��Ԫ��
int& Array::at(int index)
{
	//���ڴ������Ϸ����±꣬�������޷��������������������Խ��������û�����
	return this->paddress[index];
}
//ɾ��ָ��λ��Ԫ��
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

//��ֵ=����--------���������������Ͽ������캯��
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

//�������룬<<���� ----------arr << 1 << 2
Array& Array::operator<<(int val)
{
	pushBack(val);
	return *this;
}
//�±�[]����
int& Array::operator[](int index)
{
	return this->paddress[index];
}

//���������<<���� ----------cout << arr;
ostream& operator<<(ostream &os, Array &arr)
{
	for (int i = 0; i < arr.size; i++)
	{
		os << arr.paddress[i] << " ";
	}
	return os;
}