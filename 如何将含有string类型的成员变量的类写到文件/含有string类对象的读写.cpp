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
	会在读文件的是时候出现内存访问溢出-----_block_type_is_valid(phead->nblockuse)
	string在字符串只有15个有效字符的时候放在对象内部char数组
	但是超过了15个字符，放在指针指向的堆空间
	在文件不能这样存文件，因为这样存到文件的只是一串字符的地址，当程序关闭空间释放后
	文件的内容就读不出来（内存非法访问）
	*/
	//char name[64];
	int age;
};

//写文件
void test01()
{
	ofstream ofs("person.dat", ios::out | ios::binary);

	if (!ofs)
	{
		cout << "创建文件失败" << endl;
		return;
	}

	Person p[3] = {Person("zhangsan", 10), Person("wangwu", 20), Person("zhaoliu", 30)};

	int size = sizeof(p) / sizeof(p[0]);
	char buf[1024] = { 0 };

	for (int i = 0; i < size; ++i)
	{ 
		int lenth = p[i].name.length();
		strcpy(buf, p[i].name.c_str());
		ofs.write(buf, lenth);//名字写进去
		ofs << " ";//空格
		ofs << lenth;//名字的长度
		ofs << " ";//空格
		ofs << p[i].age;//把年龄写进去
		ofs << '\n';
		//zhangsan 8 10
		memset(buf, 0, 1024);
	}
	ofs.close();
}

//读文件
void test02()
{
	ifstream ifs("person.dat", ios::in | ios::binary);

	if (!ifs)
	{
		cout << "文件打开失败" << endl;
		return;
	}
	//按照行读
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