#include <iostream>
using namespace std;
#include <string>
/*
ʹ�õ���ģʽʵ��һ����ӡ����
��ӡ������ַ���
�ۼƴ�ӡ����
*/
class Print
{
public:
	static Print* getpPrint()
	{
		return pPrint;
	}
	void printInfo(const string str)
	{
		cout << "�ַ������ݣ�" << str << endl;
		count++;
		cout << "��ӡ������" << count << endl;
	}
private:
	//����ģʽ��Ĺ��죬�������죬��������Ҫ˽�л�����ֹ�ⲿ�����������
	Print()
	{
		count = 0;
	}
	Print(const Print &p)
	{

	}
	~Print()
	{

	}	
private:
	static Print *pPrint;
	int count;
};
Print *Print::pPrint = new Print;

void test()
{
	Print *p1 = Print::getpPrint();
	Print *p2 = Print::getpPrint();

	p1->printInfo("hello");
	p2->printInfo("mike");
}
int main()
{
	test();
	return 0;
}
