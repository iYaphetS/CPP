#include <iostream>
using namespace std;
#include <string>
/*
使用单例模式实现一个打印机类
打印传入的字符串
累计打印次数
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
		cout << "字符串内容：" << str << endl;
		count++;
		cout << "打印次数：" << count << endl;
	}
private:
	//单例模式类的构造，拷贝构造，析构函数要私有化，防止外部创建多个对象
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
