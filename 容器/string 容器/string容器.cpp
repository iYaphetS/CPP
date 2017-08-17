#include <iostream>
using namespace std;
#include <string>

/*   �ַ�����ʼ��
string();//����һ���յ��ַ��� ����: string str;
string(const string& str);//ʹ��һ��string�����ʼ����һ��string����
string(const char* s);//ʹ���ַ���s��ʼ��
string(int n, char c);//ʹ��n���ַ�c��ʼ��
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

/*                 �ַ�����ֵ-------���Ų����ͺ�������
string& operator=(const char* s);//char*�����ַ��� ��ֵ����ǰ���ַ���
string& operator=(const string &s);//���ַ���s������ǰ���ַ���
string& operator=(char c);//�ַ���ֵ����ǰ���ַ���
string& assign(const char *s);//���ַ���s������ǰ���ַ���
string& assign(const char *s, int n);//���ַ���s��ǰn���ַ�������ǰ���ַ���
string& assign(const string &s);//���ַ���s������ǰ�ַ���
string& assign(int n, char c);//��n���ַ�c������ǰ�ַ���
string& assign(const string &s, int start, int n);//��s��start��ʼn���ַ���ֵ���ַ���
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

/*         �����ַ����е��ַ�-------���Ų����ͺ�������
char& operator[](int n);//ͨ��[]��ʽȡ�ַ�---�������ֱ�ӱ���
char& at(int n);//ͨ��at������ȡ�ַ�-----��������ܲ����쳣
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
		cout << "�������" << endl;
	}

}
/*       �ַ���ƴ��-----���Ų����ͺ�������
string& operator+=(const string& str);//����+=������
string& operator+=(const char* str);//����+=������
string& operator+=(const char c);//����+=������
string& append(const char *s);//���ַ���s���ӵ���ǰ�ַ�����β
string& append(const char *s, int n);//���ַ���s��ǰn���ַ����ӵ���ǰ�ַ�����β
string& append(const string &s);//ͬoperator+=()
string& append(const string &s, int pos, int n);//���ַ���s�д�pos��ʼ��n���ַ����ӵ���ǰ�ַ�����β
string& append(int n, char c);//�ڵ�ǰ�ַ�����β���n���ַ�c
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
/*    ��ͷ��ʼ����β�������ض��ַ����ַ���
int find(const string& str, int pos = 0) const; //����str��һ�γ���λ��,��pos��ʼ����
int find(const char* s, int pos = 0) const;  //����s��һ�γ���λ��,��pos��ʼ����
//posû��Ĭ��ֵ
int find(const char* s, int pos, int n) const;  //��posλ�ò���s��ǰn���ַ���һ��λ��
int find(const char c, int pos = 0) const;  //�����ַ�c��һ�γ���λ��
int rfind(const string& str, int pos = npos) const;//����str���һ��λ��,��pos��ʼ����
int rfind(const char* s, int pos = npos) const;//����s���һ�γ���λ��,��pos��ʼ����
//posû��Ĭ��ֵ
int rfind(const char* s, int pos, int n) const;//��pos����s��ǰn���ַ����һ��λ��
int rfind(const char c, int pos = npos) const; //�����ַ�c���һ�γ���λ��
string& replace(int pos, int n, const string& str); //�滻��pos��ʼn���ַ�Ϊ�ַ���str
string& replace(int pos, int n, const char* s); //�滻��pos��ʼ��n���ַ�Ϊ�ַ���s
*/
void test05()
{
	//find�ķ���ֵ��unsigned int ����ֱ�������ܴ�
	int pos;
	string s1 = "1122334455";
	string s2(2, '3');
	cout << (int)s1.find(s2) << endl;//Ĭ�ϴ�0��ʼ����ͷ��ʼ��
	cout << (int)s1.find(s2, 8) << endl;//Ĭ�ϴ�0��ʼ���ӵ�8λ��ʼ��
	cout << (int)s1.find("22", 1, 3) << endl;//û��Ĭ��λ�ã��ӵ�1λ��ʼ����1+3λ��
	cout << (int)s1.find('4', 0) << endl;//Ĭ�ϴ�0��ʼ

	
	cout << (int)s1.rfind(s2) << endl;//Ĭ�ϴ�npos��ʼ��string���������
	pos = s1.rfind("11", 9, 4);
	cout << pos << endl;//�ӵ�9λ��ǰ��4λ
	cout << (int)s1.rfind('3', 8) << endl;//Ĭ�ϴ�npos��ʼ

	cout << s1.replace(2, 4, "qqqq") << endl;
	cout << s1.replace(6, 2, s2) << endl;
	
}

/*   �ַ��Ƚ�
int compare(const string &s) const;//���ַ���s�Ƚ�
int compare(const char *s) const;//���ַ���s�Ƚ�
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

/*    ��λ�����и��ַ���
string substr(int pos = 0, int n = npos) const;//������pos��ʼ��n���ַ���ɵ��ַ���
*/
void test07()
{
	string s1 = "hello";
	cout << s1.substr(1, 3) << endl;
}

/*   ����ɾ���ַ����ַ���
string& insert(int pos, const char* s); //�����ַ���
string& insert(int pos, const string& str); //�����ַ���
string& insert(int pos, int n, char c);//��ָ��λ�ò���n���ַ�c
string& erase(int pos, int n = npos);//ɾ����Pos��ʼ��n���ַ�
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

//C++��c�ַ���ת��
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

	//string�����ַ�����һ�������ڣ��ַ����Ǵ�����Ķ����ڲ�
	//���ǵ��ַ�������һ�����ȣ��ַ����ͻ������������ָ��ָ��Ķѿռ���
	//�������÷���string�ַ����������ַ������׵�ַ�����ı䣬�����ڴ�Ƿ�����
	//��string�ṩ���±���ʺ�at()���ʷ������Ƿ�������
	s1 = "ssssssssssssssss";
	//a = '4';
	//b = '5';
	
	cout << (int)&s1[0] << endl;//����һ�ε�ַ�ǲ�ͬ��,��������15����Ч�ַ���������ַ�����ı�
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