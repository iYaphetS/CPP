#include <iostream>
using namespace std;
#pragma warning(disable:4996)

void test1()
{
	char c = cin.get();//从缓冲区拿（读）字符，如果缓冲区没有字符会阻塞等待用户输入，知道输入换行符结束
	cout << c << endl;
	char ch;
	cin.get(ch);
	cout << ch << endl;
	cin.get(ch);
	cout << ch << endl;
	cin.get(ch);
	cout << ch << endl;
}
void test2()
{
	char buf[1024];
	//没有读取换行，换行还在缓冲区
	cin.get(buf, 10);//在指定长度一定预留最后一个位置给\0,不会出现写溢出
	cout << buf << endl;
	char c = cin.get();
	if ( c == '\n')
	{
		cout << "换行还在缓冲区" << endl;
	}
}

void test3()
{
	//忽略当前字符
	cin.ignore(2);//cout 输出c
	char c = cin.get();//abc
	//cin.ignore(2);写在输入的后面，没有效果，cout输出a
	cout << c << endl;

}

void test4()
{
	char ch, c;
	
	ch = cin.get();//输入abc，拿走了a
	ch = cin.peek();
	cout << ch << endl;//输出b
	cout << ch << endl;//输出b

	//偷窥缓冲区当前字符，只看不拿
	c = cin.peek();
	cout << c << endl;//输出a
	c = cin.get();//即看又拿 输入abc，拿走a
	cout << c << endl;//输出a
	
}

void test5()
{
	char ch = cin.get();
	cout << "拿走的字符：" << ch << endl;

	cin.putback(ch);
	char buf[1024] = {0};
	cin.get(buf, 1024);
	cout << buf << endl;

}
int main()
{
	test1();
	//test2();
	//test3();
	//test4();
	//test5();
	//test6();


	//char buf[10];
	//scanf("%s", buf);
	//printf("%s", buf);
	//cin >> buf;
	//cout << buf;
	return 0;
}