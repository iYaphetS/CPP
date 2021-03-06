#include <iostream>

using namespace std;

const int b = 20;//默认是当前文件作用域，内部链接，即static const int b = 20;
int main()
{
	//相同：都是在栈中分配内存，只是一个可读的变量
	const int a = 10;
	int *p = (int *)&a;
	*p = 100;
	
	cout << "a = " << a << endl;//10
	/*不同：
	这里与c中结果不同，是编译器做了优化，类似全局的const那样，进行常量折叠
	可以手动的volatile const int a = 10;告诉编译器不要对a进行优化
	*/
	cout << "*p = " << *p << endl;//100

	volatile const int c = 30;
	int *m = (int *)&c;
	*m = 300;
	cout << "c = " << c << endl;//300
	cout << "*m = " << *m << endl;//300

#if 0
	//相同：
	//c++全局的const与c中的全局const都是存放在常量区，只读不可写
	//不同点：
	/*1.作用域不同-- c++默认是当前文件作用域 /c默认是全局作用域
	2.c++中的全局const变量不一定分配内存,c中的所用const变量都分配内存
		2.1当const变量取地址的时候 
		2.2当const变量显示声明为外部链接（extern）时
		2.3没有进行优化---常量折叠，那么就需要寻址找变量的值
		都会为const变量分配内存
		其他情况，const变量不会分配内存，当在作用域内使用到const变量的时候
		都会像宏替换那样，把变量替换为初始化的值----常量折叠（或者叫简单的值拷贝，这也就是
		为什么复合数据类型例如结构体有指针成员（指向另一片内存空间）的时候是没有办法
		进行简单拷贝的，但是基本类型编译器已经非常清楚变量有多大
		），这样做是为了是提高效率
		但是有3种情况下不会做这样的优化
		-------1.const int a = b;用变量赋值给const变量
		-------2.当const变量是复合数据类型（非基本数据类型）变量时
		-------3.手动告诉编译器不要优化volatile
		**********不能进行优化的变量一定分配内存，分配内存也是可以进行优化**********
	*/
	int *q = (int *)&b;
	*q = 200;//程序崩溃
	cout << "b = " << b << endl;
	cout << "*q = " << *q << endl;
#endif
	return 0;
}