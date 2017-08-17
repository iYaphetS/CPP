#include <stdio.h>

const int b = 20;

int main()
{
	//存放在栈区的只读变量，编译器仅仅做只读的语法检查
	const int a = 10;
	int *p = (int *)&a;
	*p = 100;
	printf("a = %d\n", a);//100

	printf("*p = %d\n", *p);//100

#if 0
	//程序会崩，常量区内存不能写
	int *q = (int *)&b;
	*q = 200;
	printf("b = %d\n", b);

	printf("*q = %d\n", *q);
#endif
	return 0;
}