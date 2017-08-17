#include <iostream>
using namespace std;
#include <fstream>
#include <vector>
#pragma warning(disable:4996)

/*
使用文件IO读取a.txt文件中的信息，构建Person对象，
使用选择排序按年龄从小到大排序，
将排序后的结果重新写入到文件中（写入方式不限），禁止向文件中写入string类型
*/

//假如 a.txt文件中的内容为
/*
zhangsan 40
lisi 60
wangwu 50
zhaoliu 10
*/

#if 0
void SelctSort(person *p, int len)
{
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = i + 1; j < len; j++)
		{
			if (p[i] > p[j])
			{
				person temp = p[i];
				p[i] = p[j];
				p[j] = temp;
			}
		}
	}
}
void rwfile()
{
	//读文件
	ifstream ifs("a.txt", ios::in);

	if (!ifs)
	{
		cout << "文件打开失败" << endl;
		return;
	}
	//计算行数
	int count = 0;
	char buf[1024] = { 0 };
	while (ifs.getline(buf, 1024))
	{
		count++;
	}
	person *p = new person[count];
	ifs.clear();
	ifs.seekg(0, ios::beg);
	int i = 0;
	while (ifs.getline(buf, 1024))
	{

		char name[64] = { 0 };
		int age = 0;
		cout << buf << endl;
		sscanf(buf, "%s %d", name, &age);
		person temp(name, age);
		p[i] = temp;
		i++;
		memset(buf, 0, 1024);
	}
	ifs.close();

	//排序
	SelctSort(p, count);


	//写文件
	ofstream ofs("a.txt", ios::out);
	if (!ofs)
	{
		cout << "文件打开失败" << endl;
		return;
	}

	for (int i = 0; i < count; i++)
	{
		ofs << p[i].Name;
		ofs << " ";
		ofs << p[i].Age;
		ofs << "\n";
	}
	ofs.close();
	delete[]p;
}
#endif
class person
{
public:
	person()
	{
		memset(Name, 0, sizeof(Name));
		strcpy(Name, "");
		Age = 0;
	}
	person(char* name, int age)
	{
		memset(Name, 0, sizeof(Name));
		strcpy(Name, name);
		Age = age;
	}
	bool operator>(const person &p)
	{
		return this->Age > p.Age;
	}
public:
	char Name[64];
	int Age;
};


void SelctSort(vector<person> &p)
{
	for (unsigned int i = 0; i < p.size() - 1; i++)
	{
		int min = i;	
		for (unsigned int j = i + 1; j < p.size(); j++)
		{
			if (p[i] > p[j])
			{
				min = j;
			}
		}
		if (min != i)
		{
			person temp = p[i];
			p[i] = p[min];
			p[min] = temp;
		}
	}
}

void readfile(vector<person> &p)
{
	ifstream ifs("a.txt", ios::in);
	if (!ifs)
	{
		cout << "file open fail" << endl;
	}

	char buf[1024] = {0};
	//while (ifs >> buf)//读到空格就结束存到buf，继续读下一个字符串
	while (ifs.getline(buf, 1024))
	{
		cout << buf << endl;
		person temp;
		sscanf(buf, "%s %d", temp.Name, &temp.Age);
		p.push_back(temp);
		memset(buf, 0, 1024);
	}

	ifs.close();
}

void writefile(vector<person> &p)
{
	ofstream ofs("a.txt", ios::out);
	for(unsigned int i = 0; i < p.size(); i++)
	{
		ofs << p[i].Name << " " << p[i].Age << endl;
	}
	ofs.close();
}
int main()
{
	//rwfile();
	vector<person> p;
	readfile(p);
	SelctSort(p);
	writefile(p);
	return 0;
}