#pragma once
#include <iostream>
using namespace std;

//���ں����ķ���ֵ�Ƿ���ֵ���Ƿ������ã�Ҫ��Ҫ��Ҫ����ֵ
class Array
{
	//���������<<���� ----------cout << arr;
	//����ȫ�ֺ���������������ֲ���������Ҫ�ڿ��������ӣ�����ȫ
	friend ostream& operator<<(ostream &os, Array &arr);
public:
	Array();
	explicit Array(int capicity);//explicit(��ֹ��ʽ����ת��) �Ƿ�ֹ������ʼ�� Array arr = 10;
	Array(Array &arr);
	~Array();

	/*�����������*/
	//β������
	void pushBack(const int &val);
	//ͷ������
	void pushFront(const int &val);
	//���ָ��λ��Ԫ��
	int& at(int index);
	//ɾ��ָ��λ��Ԫ��
	void deleteArr(int index);
	//������������
	int getcapicity();

	/*���������*/
	//��ֵ=����
	Array& operator=(Array &arr);
	//�������룬<<���� ----------arr << 1 << 2
	Array& operator<<(int val);
	//�±�[]����
	int& operator[](int index);
	
private:
	int capicity;
	int size;
	int *paddress;
};