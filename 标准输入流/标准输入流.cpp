#include <iostream>
using namespace std;
#pragma warning(disable:4996)

void test1()
{
	char c = cin.get();//�ӻ������ã������ַ������������û���ַ��������ȴ��û����룬֪�����뻻�з�����
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
	//û�ж�ȡ���У����л��ڻ�����
	cin.get(buf, 10);//��ָ������һ��Ԥ�����һ��λ�ø�\0,�������д���
	cout << buf << endl;
	char c = cin.get();
	if ( c == '\n')
	{
		cout << "���л��ڻ�����" << endl;
	}
}

void test3()
{
	//���Ե�ǰ�ַ�
	cin.ignore(2);//cout ���c
	char c = cin.get();//abc
	//cin.ignore(2);д������ĺ��棬û��Ч����cout���a
	cout << c << endl;

}

void test4()
{
	char ch, c;
	
	ch = cin.get();//����abc��������a
	ch = cin.peek();
	cout << ch << endl;//���b
	cout << ch << endl;//���b

	//͵����������ǰ�ַ���ֻ������
	c = cin.peek();
	cout << c << endl;//���a
	c = cin.get();//�������� ����abc������a
	cout << c << endl;//���a
	
}

void test5()
{
	char ch = cin.get();
	cout << "���ߵ��ַ���" << ch << endl;

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