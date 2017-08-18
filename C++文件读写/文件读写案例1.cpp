#include <iostream>
using namespace std;
#include <fstream>
#include <string>
#include <cstring>
#pragma warning(disable:4996)

//读普通文件文件
void test01()
{
	//打开方式一
	ifstream ifs("test.txt", ios::in);//通过类ifstream对象的构造函数打开文件
	//打开方式二
#if 0
	ifstream ifs;
	ifs.open("test.txt", ios::in);
#endif
	if (!ifs)//如果文件打开失败，流对象ifs的值为0
	{
		cout << "文件打开失败" << endl;
	}
	char buf[1024] = {0};
#if 0
	while (ifs >> buf)
	{
		cout << buf << endl;
		memset(buf, 0, 1024);
	}
#endif
	while (ifs.getline(buf, 1024))//cin.getline(buf, 1024)//这是从标准设备读内容，而这个是从文件中读内容
	{
		cout << buf << endl;
		memset(buf, 0, 1024);
	}

	

	ifs.close();

}
//文件流对象内部有一种状态：只有good是true的情况下对文件的读写才能正确执行
//但是文件操作中会有三个状态bad eof fail与good《《对立》》，也就是说当操作文件只要使这三种某一个状态触发
//使其中一个状态置成了true，那么good的状态就为false，那么这时对文件操作都是不正确的
//bad-----硬件错误，系统错误---无法修复的错误
//fail----函数调用错误，试着将非int转成int等错误，可修复----调用clear（）函数
//eof-----文件指针指向文件末尾，可修复，先调用clear（）函数 ，再移动文件指针
void test05()
{
	ifstream ifs("test.txt", ios::in);//通过类ifstream对象的构造函数打开文件
	//打开方式二

	if (!ifs)//如果文件打开失败，流对象ifs的值为0
	{
		cout << "文件打开失败" << endl;
	}
	char buf[1024] = { 0 };
	while (ifs.getline(buf, 1))//cin.getline(buf, 1024)//这是从标准设备读内容，而这个是从文件中读内容
	{
		cout << buf << endl;
		memset(buf, 0, 1024);
	}
	if (ifs.fail())//ifs.getline(buf, 1)函数调用错误
	{
		cout << "fail状态被置为true" << endl;
	}

	ifs.clear();
	while (ifs.getline(buf, 1024))//cin.getline(buf, 1024)//这是从标准设备读内容，而这个是从文件中读内容
	{
		cout << buf << endl;
		memset(buf, 0, 1024);
	}
}
void test06()
{
	ifstream ifs("test.txt", ios::in);//通过类ifstream对象的构造函数打开文件
	//打开方式二

	if (!ifs)//如果文件打开失败，流对象ifs的值为0
	{
		cout << "文件打开失败" << endl;
	}
	char buf[1024] = { 0 };
	while (ifs.getline(buf, 1024))//cin.getline(buf, 1024)//这是从标准设备读内容，而这个是从文件中读内容
	{
		cout << buf << endl;
		memset(buf, 0, 1024);
	}
	if (ifs.eof())//文件指针指向文件末尾
	{
		cout << "eof状态被置为true" << endl;
	}

	ifs.clear();
	ifs.seekg(0, ios::beg);
	while (ifs.getline(buf, 1024))//cin.getline(buf, 1024)//这是从标准设备读内容，而这个是从文件中读内容
	{
		cout << buf << endl;
		memset(buf, 0, 1024);
	}
}


//写普通文件
void test02()
{
	ofstream ofs;
	ofs.open("haha.txt", ios::out);
	
#if 0
	ofstream ofs("haha.txt", ios::out);	
#endif
	char *buf[] = { "a\n", "ab\n", "abc\n", "abcd\n" };
	int size = sizeof(buf) / sizeof(buf[0]);
	for (int i = 0; i < size; i++)
	{
		ofs << buf[i];
	}

	ofs.close();
}

class Person
{
public:
#if 0
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
#if 1
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
private:
	//string name;
	/*
	会在读文件的是时候出现内存访问溢出-----_block_type_is_valid(phead->nblockuse)
	string在字符串只有15个有效字符的时候放在对象内部char数组
	但是超过了15个字符，放在指针指向的堆空间
	在文件不能这样存文件，因为这样存到文件的只是一串字符的地址，当程序关闭空间释放后
	文件的内容就读不出来（内存非法访问）
	*/
	char name[64];
	int age;
};
//写二进制文件
void test03()
{
	//以二进制方式写文件
	ofstream ofs("binary.dat", ios::out | ios::binary);
	if (!ofs)
	{
		cout << "文件打开失败" << endl;
	}

	Person pArr[3]{Person("A", 10), Person("B", 20), Person("C", 30)};

	ofs.write((char *)pArr, sizeof(pArr));

	ofs.close();
}

//读二进制文件
void test04()
{
	ifstream ifs("binary.dat", ios::in | ios::binary);
	if (!ifs)
	{
		cout << "打开文件失败" << endl;
	}

	Person person;
	while ( ifs.read((char *)&person, sizeof(Person)) )
	{
		person.print();
	}
	ifs.clear();//重复读文件的话一定清空流的状态，只要流的good状态为false，读文件无效
	//文件指针移动--指定位置读
	ifs.seekg(sizeof(Person), ios::beg);
	ifs.read((char *)&person, sizeof(Person));
	person.print();
	ifs.close();
}
int main()
{
	//test01();
	//test02();
	//test03();
	//test04();
	//test05();
	test06();
	return 0;
}