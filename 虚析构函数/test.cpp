#include <iostream>
using namespace std;

class base
{
public:
	base()
	{
		cout << "base:���캯��" << endl;
	}
	void test01()
	{
		cout << "base:test01" << endl;

	}
	virtual void test02()
	{
		cout << "derived:test02" << endl;
	}
	virtual ~base()
	{
		cout << "base:��������" << endl;
	}
};


class derived :public base
{
public:
	derived()
	{
		cout << "derived:���캯��" << endl;
	}
	void test01()
	{
		cout << "derived:test01" << endl;

	}
	virtual void test02()
	{
		cout << "derived:test02" << endl;
	}
	virtual void test03()
	{
		cout << "derived:test03" << endl;

	}
	virtual ~derived()
	{
		cout << "derived:��������" << endl;
	}
	
};
#if 0
class ss : public derived
{
public:

	virtual void test02()
	{
		cout << "derived:test02" << endl;
	}
};
#endif
int main()
{
	base * p = new derived;
	//ss s;
	p->test01();
	delete p;
	/*�ڱ���delete p��ʱ����base����������û��virtual�ؼ���
	��̬�����ʱ��p��ȷָ����һ���ڴ�ռ䣬��������ڴ�ռ�
	�����ݣ��������ǲ�֪���ģ����ͱ���int a = 10;����ֻ�����a������
	Ϊ������4���ֽڵĿռ䵫��aΪ�����ǲ�֪���ģ������ڱ����ʱ���
	Ĭ����base�󶨣���󶨣���
	�����������ָ����������󶨣���̬����ݶ�������������ú����ģ�
	������delete p��ֻ�����base�����������
	���Ǳ�������������ĳ��������virtual���Ͳ����ڱ��뺯�����õ�ʱ�򽫺��������
	���а󶨣�������ν�Ķ�̬����
	����������ʼ�������ù��캯����Լ̳й�������ָ����¸�ֵ��
	��̳й������麯��ָ��ָ�����仯�ͻ�ָ��������麯����
	�����н׶ε�p���õĺ�����������󶨣�p�ͻ����������麯��ָ��ָ�����������
	
	�ڱ���ĳ��������ʱ�򣬿���������������Ķ���ʵ���������û��virtual
	�ؼ��֣��ͻ��ڱ����ʱ�������������а�
	����������ʵ�����������virtual�ؼ��֣���ô��������Ͳ�����������
	�������е�ʱ�����ʵ�ʵĶ�����֮��
	*/

	return 0;
}