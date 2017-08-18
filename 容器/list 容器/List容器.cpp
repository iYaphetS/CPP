#include <iostream>
using namespace std;
#include <list>
#include <string>

/*
list<T> lstT;//list采用采用模板类实现,对象的默认构造形式：
list(beg,end);//构造函数将[beg, end)区间中的元素拷贝给本身。
list(n,elem);//构造函数将n个elem拷贝给本身。
list(const list &lst);//拷贝构造函数。

push_back(elem);//在容器尾部加入一个元素
pop_back();//删除容器中最后一个元素
push_front(elem);//在容器开头插入一个元素
pop_front();//从容器开头移除第一个元素
insert(pos,elem);//在pos位置插elem元素的拷贝，返回新数据的位置。
insert(pos,n,elem);//在pos位置插入n个elem数据，无返回值。
insert(pos,beg,end);//在pos位置插入[beg,end)区间的数据，无返回值。
clear();//移除容器的所有数据
erase(beg,end);//删除[beg,end)区间的数据，返回下一个数据的位置。
erase(pos);//删除pos位置的数据，返回下一个数据的位置。
remove(elem);//删除容器中所有与elem值匹配的元素。

size();//返回容器中元素的个数
empty();//判断容器是否为空
resize(num);//重新指定容器的长度为num，
若容器变长，则以默认值填充新位置。
如果容器变短，则末尾超出容器长度的元素被删除。
resize(num, elem);//重新指定容器的长度为num，
若容器变长，则以elem值填充新位置。
如果容器变短，则末尾超出容器长度的元素被删除。

assign(beg, end);//将[beg, end)区间中的数据拷贝赋值给本身。
assign(n, elem);//将n个elem拷贝赋值给本身。
list& operator=(const list &lst);//重载等号操作符
swap(lst);//将lst与本身的元素互换。

front();//返回第一个元素。
back();//返回最后一个元素。

reverse();//反转链表，比如lst包含1,3,5元素，运行此方法后，lst就包含5,3,1元素。
sort(); //list排序
*/
template <class T>
void printList(T &v)
{
	for (T::iterator it = v.begin(); it != v.end();++it)
	{
		cout << *it << endl;
	}

}
//简单数据类型
void test01()
{
	list<int> lst;
	lst.push_back(10);
	lst.push_front(20);
	lst.push_front(13);
	lst.push_back(30);

	printList(lst);

	//拷贝构造
	list<int> mylist1(lst);
	printList(mylist1);

	//多个值拷贝构造
	list<int> mylist2(4, 6);
	printList(mylist2);

	//区间拷贝构造
	list<int>::iterator it = lst.begin();
	it++;
	it++;
	it--;
	//it + 5;不允许随机访问
	list<int> mylist3(it, lst.end());
	printList(mylist3);
}

void test02()
{
	list<int> lst;
	lst.push_back(10);
	lst.push_front(20);
	lst.push_front(13);
	lst.push_back(30);
	printList(lst);
	cout << lst.front() << endl;//队友元素
	cout << lst.back() << endl;//队尾元素

	lst.pop_back();//删除队尾元素
	printList(lst);
	lst.pop_front();//删除对头元素
	printList(lst);
}

void test03()
{
	list<int> lst;
	lst.push_back(10);
	lst.push_front(20);
	lst.push_front(13);
	lst.push_back(30);
	printList(lst);

	list<int>::iterator it1 = lst.begin();
	list<int>::iterator it2 = lst.end();
	it1++;
	it1++;
	it2--;

	//it + 5;不允许随机访问
	//	list<int> mylist(it1, lst.end()--);//后置--,计算表达式后--
	list<int> mylist(it1, it2);//list<int> mylist(it1, --lst.end());
	printList(mylist);

	//三种插入
	lst.insert(lst.begin(), 3);
	lst.insert(lst.end(), 3, 6);
	lst.insert(lst.begin(), mylist.begin(), mylist.end());

	printList(lst);
}

void test04()
{
	list<int> lst;
	lst.push_back(10);
	lst.push_front(20);
	lst.push_front(13);
	lst.push_back(30);
	lst.push_back(10);
	lst.push_back(10);
	printList(lst);

	//三种删除
	lst.erase(++lst.begin());
	lst.remove(10);//删除所有值为10的元素
	printList(lst);
	lst.erase(lst.begin(), lst.end());
	printList(lst);

}

void test05()
{
	list<int> lst;
	lst.push_back(10);
	lst.push_front(20);
	printList(lst);

	list<int> mylist(3, 6);

	//赋值
	mylist = lst;
	printList(mylist);

	mylist.assign(lst.begin(), --lst.end());
	printList(mylist);

	mylist.assign(3, 8);
	printList(mylist);

	mylist.swap(lst);
	printList(mylist);
	printList(lst);

}
//重设元素的大小
void test06()
{
	list<int> lst;
	lst.push_back(10);
	lst.push_front(20);
	lst.push_front(13);
	lst.push_back(30);
	printList(lst);

	lst.resize(6);
	printList(lst);

	lst.resize(10, 13);
	printList(lst);

	lst.sort();
	printList(lst);

	lst.reverse();
	printList(lst);
}


class person
{
	friend ostream & operator<<(ostream &os, const person&p)
	{
		os << "name:" << p.Name << " age:" << p.Age;
		return os;
	}
	friend bool mypersoncompare(const person &p1, const person &p2)
	{
		return p1.Age < p2.Age;
	}
	friend bool removeperson(const person &p)
	{
		return p.Age == 20;
	}
public:
	person(string name, int age)
	{
		Name = name;
		Age = age;
	}

	bool operator<(const person &p)
	{
		return this->Age < p.Age;
	}
	bool operator==(const person &p)
	{
		return this->Age == p.Age;//这要两个对象的年龄相同就行
	}

private:
	string Name;
	int Age;
};


//复杂数据类型
void test07()
{
	list<person> lst;
	lst.push_back(person("aa", 10));
	lst.push_front(person("bb", 20));
	lst.push_back(person("cc", 30));
	lst.push_front(person("dd", 40));
	lst.push_front(person("bb", 20));

	
	printList(lst);

	cout << "==============" << endl;
	//复杂数据类型无法对数据进行排序--
	//1.可提供<(默认是<，对简单值比较)重载
	lst.sort();//-----------------------list不是随机迭代器，是双向迭代器，不能调用算法sort排序
	/*
	sort(less<>());
	*/
	printList(lst);
	cout << "==============" << endl;
	//2.提供回调函数
	lst.sort(mypersoncompare);
	printList(lst);
	cout << "==============" << endl;

	//同样对复杂数据类型删除
	//1.对==重载（默认是简单的值比较）
	lst.remove(person("bb", 20));
	printList(lst);
	cout << "==============" << endl;

	//2.提供删除规则的函数
	//lst.remove_if(removeperson);//不能复用，规则定死了
	//printList(lst);

}
int main()
{
	//test01();
	//test02();
	//test03();
	//test04();
	//test05();
	//test06();

	test07();
	return 0;
}