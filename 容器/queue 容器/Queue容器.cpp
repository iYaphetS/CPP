#include <iostream>
using namespace std;
#include <queue>
#include <string>

/*------不支持遍历---没有迭代器
queue<T> queT;//queue采用模板类实现，queue对象的默认构造形式：
queue(const queue &que);//拷贝构造函数

push(elem);//往队尾添加元素
pop();//从队头移除第一个元素
back();//返回最后一个元素
front();//返回第一个元素

queue& operator=(const queue &que);//重载等号操作符

empty();//判断队列是否为空
size();//返回队列的大小
*/
//普通类型
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
		int val = q.front();//获得对头元素
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
//复杂类型
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

//对象存在堆上
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