#include <iostream>
using namespace std;
#include <stack>
#include <string>

/*---------受限的线性结构，支持遍历，也就没有迭代器
stack<T> stkT;//stack采用模板类实现， stack对象的默认构造形式：
stack(const stack &stk);//拷贝构造函数
stack& operator=(const stack &stk);//重载等号操作符
push(elem);//向栈顶添加元素
pop();//从栈顶移除第一个元素
top();//返回栈顶元素
empty();//判断堆栈是否为空
size();//返回堆栈的大小
*/
//基本数据类型
void test01()
{
	stack<int> s;//调用默认构造函数
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);

	//打印栈中的每个元素
	while (!s.empty())
	{
		int val = s.top();//获得栈顶元素
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
//复杂数据类型
void test02()
{
	stack<person> s;
	s.push(person("aa", 10));
	s.push(person("bb", 20));
	s.push(person("cc", 30));
	s.push(person("dd", 40));

	//打印元素
	while (s.size() > 0)
	{
		person p = s.top();
		p.print();
		s.pop();
	}
}

//存储对象指针放在栈上，对象指针指向的内容放在堆上
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
//存储的对象指针在堆上，对象指针也在堆上
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