#include <iostream>
using namespace std;
#include <string>

/*   字符串初始化
string();//创建一个空的字符串 例如: string str;
string(const string& str);//使用一个string对象初始化另一个string对象
string(const char* s);//使用字符串s初始化
string(int n, char c);//使用n个字符c初始化
*/
void test01()
{
	string str;
	string s1 = "hello world";
	string s2(4, 's');
	string s3(s1);

	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
}

/*                 字符串赋值-------符号操作和函数调用
string& operator=(const char* s);//char*类型字符串 赋值给当前的字符串
string& operator=(const string &s);//把字符串s赋给当前的字符串
string& operator=(char c);//字符赋值给当前的字符串
string& assign(const char *s);//把字符串s赋给当前的字符串
string& assign(const char *s, int n);//把字符串s的前n个字符赋给当前的字符串
string& assign(const string &s);//把字符串s赋给当前字符串
string& assign(int n, char c);//用n个字符c赋给当前字符串
string& assign(const string &s, int start, int n);//将s从start开始n个字符赋值给字符串
*/

void test02()
{
	string str;
	string s1 = "hello world";
	string s2(4, 's');
	string s3(s1);
	cout << s3 << endl;
	s3 = "12345";
	cout << s3 << endl;
	s3 = s2;
	cout << s3 << endl;
	s3.assign("haha");
	cout << s3 << endl;
	s3.assign("everything is ok", 8);
	cout << s3 << endl;
	s3.assign(s1);
	cout << s3 << endl;
	s3.assign(4, 'm');
	cout << s3 << endl;
	s3.assign(s1, 1, 3);
	cout << s3 << endl;
}

/*         访问字符串中的字符-------符号操作和函数调用
char& operator[](int n);//通过[]方式取字符---访问溢出直接崩溃
char& at(int n);//通过at方法获取字符-----访问溢出能捕获异常
*/
void test03()
{
	string s1("hello world");
#if 0
	try
	{
		s1[100] = 'A';
	}
	
	catch (exception &ex)//out_of_range &of
	{
		ex.what();
	}
#endif
	try
	{
		s1.at(100) = 'A';
	}
	catch (exception &ex)
	{
		ex.what();
		cout << "访问溢出" << endl;
	}

}
/*       字符串拼接-----符号操作和函数调用
string& operator+=(const string& str);//重载+=操作符
string& operator+=(const char* str);//重载+=操作符
string& operator+=(const char c);//重载+=操作符
string& append(const char *s);//把字符串s连接到当前字符串结尾
string& append(const char *s, int n);//把字符串s的前n个字符连接到当前字符串结尾
string& append(const string &s);//同operator+=()
string& append(const string &s, int pos, int n);//把字符串s中从pos开始的n个字符连接到当前字符串结尾
string& append(int n, char c);//在当前字符串结尾添加n个字符c
*/
void test04()
{
	string s0 = "123456789";
	string s1("haha");
	string s2(3, 'N');
	s1 += s2;
	cout << s1 << endl;
	s1 += "AAA";
	cout << s1 << endl;
	s1 += 'G';
	cout << s1 << endl;
	s1.append("happy");
	cout << s1 << endl;
	s1.append(s2);
	cout << s1 << endl;
	s1.append("qwerty", 3);
	cout << s1 << endl;
	s1.append(s0, 4, 2);
	cout << s1 << endl;
	s1.append(3, 'p');
	cout << s1 << endl;
}
/*    从头开始（或尾部）找特定字符或字符串
int find(const string& str, int pos = 0) const; //查找str第一次出现位置,从pos开始查找
int find(const char* s, int pos = 0) const;  //查找s第一次出现位置,从pos开始查找
//pos没有默认值
int find(const char* s, int pos, int n) const;  //从pos位置查找s的前n个字符第一次位置
int find(const char c, int pos = 0) const;  //查找字符c第一次出现位置
int rfind(const string& str, int pos = npos) const;//查找str最后一次位置,从pos开始查找
int rfind(const char* s, int pos = npos) const;//查找s最后一次出现位置,从pos开始查找
//pos没有默认值
int rfind(const char* s, int pos, int n) const;//从pos查找s的前n个字符最后一次位置
int rfind(const char c, int pos = npos) const; //查找字符c最后一次出现位置
string& replace(int pos, int n, const string& str); //替换从pos开始n个字符为字符串str
string& replace(int pos, int n, const char* s); //替换从pos开始的n个字符为字符串s
*/
void test05()
{
	//find的返回值是unsigned int 所以直接输出会很大
	int pos;
	string s1 = "1122334455";
	string s2(2, '3');
	cout << (int)s1.find(s2) << endl;//默认从0开始，从头开始找
	cout << (int)s1.find(s2, 8) << endl;//默认从0开始，从第8位开始找
	cout << (int)s1.find("22", 1, 3) << endl;//没有默认位置，从第1位开始到第1+3位找
	cout << (int)s1.find('4', 0) << endl;//默认从0开始

	
	cout << (int)s1.rfind(s2) << endl;//默认从npos开始（string最大容量）
	pos = s1.rfind("11", 9, 4);
	cout << pos << endl;//从第9位往前找4位
	cout << (int)s1.rfind('3', 8) << endl;//默认从npos开始

	cout << s1.replace(2, 4, "qqqq") << endl;
	cout << s1.replace(6, 2, s2) << endl;
	
}

/*   字符比较
int compare(const string &s) const;//与字符串s比较
int compare(const char *s) const;//与字符串s比较
*/
void test06()
{
	string s1 = "hello";
	string s2 = "hello ";
	cout << s1.compare(s2) << endl;
	cout << s1.compare("hello") << endl;
	if (s1 < s2)
	{
		cout << "s1 < s2" << endl;
	}
	if (s1 == "hello")
	{
		cout << "s1 == hello" << endl;
	}
}

/*    按位置来切割字符串
string substr(int pos = 0, int n = npos) const;//返回由pos开始的n个字符组成的字符串
*/
void test07()
{
	string s1 = "hello";
	cout << s1.substr(1, 3) << endl;
}

/*   插入删除字符或字符串
string& insert(int pos, const char* s); //插入字符串
string& insert(int pos, const string& str); //插入字符串
string& insert(int pos, int n, char c);//在指定位置插入n个字符c
string& erase(int pos, int n = npos);//删除从Pos开始的n个字符
*/
void test08()
{
	string s1 = "hello";
	string s2 = "ppp";
	cout << s1.insert(1, "DD") << endl;
	cout << s1.insert(3, s2) << endl;
	cout << s1.insert(2, 3, '6') << endl;
	cout << s1.erase(2, 5) << endl;

}

//C++与c字符串转化
void test09()
{
	string s1 = "abcd";
	const char * str1 = s1.c_str();
	cout << str1 << endl;
	const char *str2 = "haha";
	string s2(str2);
	cout << s2 << endl;

}

void test10()
{
	string s1 = "aaaa";
	char &a = s1[1];
	char &b = s1[2];
	a = '1';
	b = '2';

	cout << (int)&s1[0] << endl;
	cout << s1 << endl;

	//string类在字符串在一定长度内，字符串是存在类的对象内部
	//但是当字符串超过一定长度，字符串就会存放在类对象中指针指向的堆空间中
	//所以引用访问string字符串，可能字符串的首地址发生改变，导致内存非法访问
	//在string提供的下标访问和at()访问方法都是返回引用
	s1 = "ssssssssssssssss";
	//a = '4';
	//b = '5';
	
	cout << (int)&s1[0] << endl;//与上一次地址是不同的,测试最多存15个有效字符，超过地址发生改变
	cout << s1 << endl;
}
int main()
{
	//test01();
	//test02();
	//test03();
	//test04();
	test05();
	//test06();
	//test07();
	//test08();
	//test09();
	//test10();
	return 0;
}