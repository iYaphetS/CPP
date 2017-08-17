#include <iostream>
using namespace std;
#include <stack>
#include <string>

/*---------���޵����Խṹ��֧�ֱ�����Ҳ��û�е�����
stack<T> stkT;//stack����ģ����ʵ�֣� stack�����Ĭ�Ϲ�����ʽ��
stack(const stack &stk);//�������캯��
stack& operator=(const stack &stk);//���صȺŲ�����
push(elem);//��ջ�����Ԫ��
pop();//��ջ���Ƴ���һ��Ԫ��
top();//����ջ��Ԫ��
empty();//�ж϶�ջ�Ƿ�Ϊ��
size();//���ض�ջ�Ĵ�С
*/
//������������
void test01()
{
	stack<int> s;//����Ĭ�Ϲ��캯��
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);

	//��ӡջ�е�ÿ��Ԫ��
	while (!s.empty())
	{
		int val = s.top();//���ջ��Ԫ��
		cout << val << " ";
		s.pop();
	}
}

class person
{
public:
	person(string name, int age)
	{
		this->name = name;
		this->age = age;
	}
	void print()
	{
		cout << "name:" << this->name << " age:" << this->age << endl;
	}
private:
	string name;
	int age;
};
//������������
void test02()
{
	stack<person> s;
	s.push(person("aa", 10));
	s.push(person("bb", 20));
	s.push(person("cc", 30));
	s.push(person("dd", 40));

	//��ӡԪ��
	while (s.size() > 0)
	{
		person p = s.top();
		p.print();
		s.pop();
	}
}

//�洢����ָ�����ջ�ϣ�����ָ��ָ������ݷ��ڶ���
void test03()
{
	stack<person *> s;
	s.push(new person("A", 10));
	s.push(new person("B", 20));
	s.push(new person("C", 30));
	s.push(new person("D", 40));

	while (s.size() > 0)
	{
		person *p = s.top();
		p->print();
		s.pop();
		delete p;
	}

}
//�洢�Ķ���ָ���ڶ��ϣ�����ָ��Ҳ�ڶ���
void test04()
{
	stack<person *> *s = new stack<person *>;
	s->push(new person("AA", 10));
	s->push(new person("BB", 20));
	s->push(new person("CC", 30));
	s->push(new person("DD", 40));

	while (s->size() > 0)
	{
		person *p = s->top();
		p->print();
		s->pop();
		if (p != NULL)
		{
			delete p;
			p = NULL;
		}
	}
	delete s;

}
int main()
{
	//test01();
	//test02();
	test03();
	return 0;
}