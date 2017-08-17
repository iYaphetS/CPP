#include <iostream>
using namespace std;
#include <queue>
#include <string>

/*------��֧�ֱ���---û�е�����
queue<T> queT;//queue����ģ����ʵ�֣�queue�����Ĭ�Ϲ�����ʽ��
queue(const queue &que);//�������캯��

push(elem);//����β���Ԫ��
pop();//�Ӷ�ͷ�Ƴ���һ��Ԫ��
back();//�������һ��Ԫ��
front();//���ص�һ��Ԫ��

queue& operator=(const queue &que);//���صȺŲ�����

empty();//�ж϶����Ƿ�Ϊ��
size();//���ض��еĴ�С
*/
//��ͨ����
void test01()
{
	queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);

	while (q.size() > 0)
	{
		int val = q.front();//��ö�ͷԪ��
		cout << val << " ";
		q.pop();
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
//��������
void test02()
{
	queue<person> q;
	q.push(person("a", 10));
	q.push(person("b", 20));
	q.push(person("c", 30));
	q.push(person("d", 40));

	while (!q.empty())
	{
		person p = q.front();
		p.print();
		q.pop();
	}

}

//������ڶ���
void test03()
{
	queue<person *> *q = new queue<person *>;
	q->push(new person("A", 10));
	q->push(new person("B", 20));
	q->push(new person("C", 30));
	q->push(new person("D", 40));

	while (q->size() > 0)
	{
		person *p = q->front();
		p->print();
		q->pop();
		if (p != NULL)
		{
			delete p;
			p = NULL;
		}
	}

	if(q != NULL)
	{
		delete q;
		q = NULL;
	}
}
int main()
{
	//test01();
	//test02();
	test03();
	return 0;
}