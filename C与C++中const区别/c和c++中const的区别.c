#include <stdio.h>

const int b = 20;

int main()
{
	//�����ջ����ֻ��������������������ֻ�����﷨���
	const int a = 10;
	int *p = (int *)&a;
	*p = 100;
	printf("a = %d\n", a);//100

	printf("*p = %d\n", *p);//100

#if 0
	//���������������ڴ治��д
	int *q = (int *)&b;
	*q = 200;
	printf("b = %d\n", b);

	printf("*q = %d\n", *q);
#endif
	return 0;
}