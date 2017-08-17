#include <iostream>
using namespace std;

/*
内联函数是为了处理c中函数很多缺陷
宏替换：由预编译器处理，简单的文本替换，可能得到结果不是想要的结果
在c++中预处理器是不能访问类的成员，但是宏是没有作用域的，所以把宏函数作为
类的成员函数是不行的
内联函数：由编译器处理，它可以像宏那样省去了函数调用，但是它会对函数的参数
返回值进行类型安全检查
*/
#define ADD(a, b) a + b
#define MAX(x, y) ((x) < (y) ? (x) : (y))

inline int add(int a, int b)
{
	return a + b;
}
inline int max(int x, int y)
{
	return x < y ? x : y;
}
int main()
{
	int ret1 = ADD(10, 20) * 10;
	int ret2 = add(10, 20) * 10;
	cout << ret1 << endl;//210
	cout << ret2 << endl;//300

	int a = 10;
	int c = 10;
	int b = 20;

	int ret3 = MAX(++a, b);
	int ret4 = max(++c, b);
	cout << ret3 << endl;//12
	cout << ret4 << endl;//11
	return 0;
}