#include <iostream>
using namespace std;

/*
����������Ϊ�˴���c�к����ܶ�ȱ��
���滻����Ԥ�����������򵥵��ı��滻�����ܵõ����������Ҫ�Ľ��
��c++��Ԥ�������ǲ��ܷ�����ĳ�Ա�����Ǻ���û��������ģ����԰Ѻ꺯����Ϊ
��ĳ�Ա�����ǲ��е�
�����������ɱ����������������������ʡȥ�˺������ã���������Ժ����Ĳ���
����ֵ�������Ͱ�ȫ���
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