#include <iostream>
using namespace std;
#include <string>
#include <fstream>
#pragma warning(disable:4996)


class Person
{
public:
#if 1
	Person()
	{
		this->name = "";
		this->age = 0;
	}
	Person(string name, int age)
	{
		this->name = name;
		this->age = age;
	}
#endif
#if 0
	Person()
	{
		memset(name, 0, sizeof(name));
		strcpy(name, "");
		this->age = 0;
	}
	Person(char * name, int age)
	{
		memset(this->name, 0, sizeof(this->name));
		strcpy(this->name, name);
		this->age = age;
	}
#endif
	void print()
	{
		cout << "name:" << name << " age:" << age << endl;
	}
public:
	string name;
	/*
	���ڶ��ļ�����ʱ������ڴ�������-----_block_type_is_valid(phead->nblockuse)
	string���ַ���ֻ��15����Ч�ַ���ʱ����ڶ����ڲ�char����
	���ǳ�����15���ַ�������ָ��ָ��Ķѿռ�
	���ļ������������ļ�����Ϊ�����浽�ļ���ֻ��һ���ַ��ĵ�ַ��������رտռ��ͷź�
	�ļ������ݾͶ����������ڴ�Ƿ����ʣ�
	*/
	//char name[64];
	int age;
};

//д�ļ�
void test01()
{
	ofstream ofs("person.dat", ios::out | ios::binary);

	if (!ofs)
	{
		cout << "�����ļ�ʧ��" << endl;
		return;
	}

	Person p[3] = {Person("zhangsan", 10), Person("wangwu", 20), Person("zhaoliu", 30)};

	int size = sizeof(p) / sizeof(p[0]);
	char buf[1024] = { 0 };

	for (int i = 0; i < size; ++i)
	{ 
		int lenth = p[i].name.length();
		strcpy(buf, p[i].name.c_str());
		ofs.write(buf, lenth);//����д��ȥ
		ofs << " ";//�ո�
		ofs << lenth;//���ֵĳ���
		ofs << " ";//�ո�
		ofs << p[i].age;//������д��ȥ
		ofs << '\n';
		//zhangsan 8 10
		memset(buf, 0, 1024);
	}
	ofs.close();
}

//���ļ�
void test02()
{
	ifstream ifs("person.dat", ios::in | ios::binary);

	if (!ifs)
	{
		cout << "�ļ���ʧ��" << endl;
		return;
	}
	//�����ж�
	char buf[1024] = { 0 };
	char name[64] = { 0 };
	int len = 0;
	int age = 0;
	while (ifs.getline(buf, 1024))
	{
		sscanf(buf, "%s %d %d", name, &len, &age);
		Person p(name, age);
		p.print();
	}

	ifs.close();

}

void test()
{
	ofstream ofs("a.txt", ios::out);

	ofs << "abc";
	ofs << " ";
	ofs << 10;

	ofs.close();
}
int main()
{
	//test();
	test01();
	test02();
	return 0;
}