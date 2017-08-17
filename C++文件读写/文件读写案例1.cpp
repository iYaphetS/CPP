#include <iostream>
using namespace std;
#include <fstream>
#include <string>
#include <cstring>
#pragma warning(disable:4996)

//����ͨ�ļ��ļ�
void test01()
{
	//�򿪷�ʽһ
	ifstream ifs("test.txt", ios::in);//ͨ����ifstream����Ĺ��캯�����ļ�
	//�򿪷�ʽ��
#if 0
	ifstream ifs;
	ifs.open("test.txt", ios::in);
#endif
	if (!ifs)//����ļ���ʧ�ܣ�������ifs��ֵΪ0
	{
		cout << "�ļ���ʧ��" << endl;
	}
	char buf[1024] = {0};
#if 0
	while (ifs >> buf)
	{
		cout << buf << endl;
		memset(buf, 0, 1024);
	}
#endif
	while (ifs.getline(buf, 1024))//cin.getline(buf, 1024)//���Ǵӱ�׼�豸�����ݣ�������Ǵ��ļ��ж�����
	{
		cout << buf << endl;
		memset(buf, 0, 1024);
	}

	

	ifs.close();

}
//�ļ��������ڲ���һ��״̬��ֻ��good��true������¶��ļ��Ķ�д������ȷִ��
//�����ļ������л�������״̬bad eof fail��good��������������Ҳ����˵�������ļ�ֻҪʹ������ĳһ��״̬����
//ʹ����һ��״̬�ó���true����ôgood��״̬��Ϊfalse����ô��ʱ���ļ��������ǲ���ȷ��
//bad-----Ӳ������ϵͳ����---�޷��޸��Ĵ���
//fail----�������ô������Ž���intת��int�ȴ��󣬿��޸�----����clear��������
//eof-----�ļ�ָ��ָ���ļ�ĩβ�����޸����ȵ���clear�������� �����ƶ��ļ�ָ��
void test05()
{
	ifstream ifs("test.txt", ios::in);//ͨ����ifstream����Ĺ��캯�����ļ�
	//�򿪷�ʽ��

	if (!ifs)//����ļ���ʧ�ܣ�������ifs��ֵΪ0
	{
		cout << "�ļ���ʧ��" << endl;
	}
	char buf[1024] = { 0 };
	while (ifs.getline(buf, 1))//cin.getline(buf, 1024)//���Ǵӱ�׼�豸�����ݣ�������Ǵ��ļ��ж�����
	{
		cout << buf << endl;
		memset(buf, 0, 1024);
	}
	if (ifs.fail())//ifs.getline(buf, 1)�������ô���
	{
		cout << "fail״̬����Ϊtrue" << endl;
	}

	ifs.clear();
	while (ifs.getline(buf, 1024))//cin.getline(buf, 1024)//���Ǵӱ�׼�豸�����ݣ�������Ǵ��ļ��ж�����
	{
		cout << buf << endl;
		memset(buf, 0, 1024);
	}
}
void test06()
{
	ifstream ifs("test.txt", ios::in);//ͨ����ifstream����Ĺ��캯�����ļ�
	//�򿪷�ʽ��

	if (!ifs)//����ļ���ʧ�ܣ�������ifs��ֵΪ0
	{
		cout << "�ļ���ʧ��" << endl;
	}
	char buf[1024] = { 0 };
	while (ifs.getline(buf, 1024))//cin.getline(buf, 1024)//���Ǵӱ�׼�豸�����ݣ�������Ǵ��ļ��ж�����
	{
		cout << buf << endl;
		memset(buf, 0, 1024);
	}
	if (ifs.eof())//�ļ�ָ��ָ���ļ�ĩβ
	{
		cout << "eof״̬����Ϊtrue" << endl;
	}

	ifs.clear();
	ifs.seekg(0, ios::beg);
	while (ifs.getline(buf, 1024))//cin.getline(buf, 1024)//���Ǵӱ�׼�豸�����ݣ�������Ǵ��ļ��ж�����
	{
		cout << buf << endl;
		memset(buf, 0, 1024);
	}
}


//д��ͨ�ļ�
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
	���ڶ��ļ�����ʱ������ڴ�������-----_block_type_is_valid(phead->nblockuse)
	string���ַ���ֻ��15����Ч�ַ���ʱ����ڶ����ڲ�char����
	���ǳ�����15���ַ�������ָ��ָ��Ķѿռ�
	���ļ������������ļ�����Ϊ�����浽�ļ���ֻ��һ���ַ��ĵ�ַ��������رտռ��ͷź�
	�ļ������ݾͶ����������ڴ�Ƿ����ʣ�
	*/
	char name[64];
	int age;
};
//д�������ļ�
void test03()
{
	//�Զ����Ʒ�ʽд�ļ�
	ofstream ofs("binary.dat", ios::out | ios::binary);
	if (!ofs)
	{
		cout << "�ļ���ʧ��" << endl;
	}

	Person pArr[3]{Person("A", 10), Person("B", 20), Person("C", 30)};

	ofs.write((char *)pArr, sizeof(pArr));

	ofs.close();
}

//���������ļ�
void test04()
{
	ifstream ifs("binary.dat", ios::in | ios::binary);
	if (!ifs)
	{
		cout << "���ļ�ʧ��" << endl;
	}

	Person person;
	while ( ifs.read((char *)&person, sizeof(Person)) )
	{
		person.print();
	}
	ifs.clear();//�ظ����ļ��Ļ�һ���������״̬��ֻҪ����good״̬Ϊfalse�����ļ���Ч
	//�ļ�ָ���ƶ�--ָ��λ�ö�
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