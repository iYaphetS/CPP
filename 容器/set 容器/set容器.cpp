#include <iostream>
using namespace std;
#include <set>
#include <string>


/*-------只读双向迭代器，都是红黑树（平衡二叉树），set与mulitset区别是set不能插入值val的元素，但是mulitset可以
set<T> st;//set默认构造函数：
mulitset<T> mst; //multiset默认构造函数:
set(const set &st);//拷贝构造函数

set& operator=(const set &st);//重载等号操作符
swap(st);//交换两个集合容器

size();//返回容器中元素的数目
empty();//判断容器是否为空

insert(elem);//在容器中插入元素。
clear();//清除所有元素
erase(pos);//删除pos迭代器所指的元素，返回下一个元素的迭代器。
erase(beg, end);//删除区间[beg,end)的所有元素 ，返回下一个元素的迭代器。
erase(elem);//删除容器中值为elem的元素。

find(key);//查找键key是否存在,若存在，返回该键的元素的迭代器；若不存在，返回set.end();
count(key);//查找键key的元素个数
lower_bound(keyElem);//返回第一个key>=keyElem元素的迭代器。
upper_bound(keyElem);//返回第一个key>keyElem元素的迭代器。
equal_range(keyElem);//返回容器中key与keyElem相等的上下限的两个迭代器。
*/
template <class T>
void printSet(T &v)
{
	for (auto it : v)
	{
		cout << it << "   ";
	}
	cout << endl;
}
void test01()
{
	set<int> s = { 4, 2, 9, 1, 3, 6, 11 };
	s.insert(1);
	s.insert(8);
	s.insert(2);
	s.insert(6);
	s.insert(6);//插入失败
	//会自动帮我们排序好
	printSet(s);

	set<int>::iterator ret = s.find(2);
	if (ret == s.end())
	{
		cout << "查找失败" << endl;
	}

	cout << "count = " << s.count(6) << endl;

	set<int>::iterator it1 = s.lower_bound(2);//第一个大于等于2迭代器的位置
	set<int>::iterator it2 = s.upper_bound(2);//第一个大于2迭代器的位置

	cout << *it1 << endl;
	cout << *it2 << endl;
	
	//pair<iterator, iterator> it = s.equal_range(2);
	auto it = s.equal_range(2);
	cout << *(it.first) << endl;
	cout << *(it.second) << endl;

	s.erase(2);
	printSet(s);

	s.erase(++s.begin());
	printSet(s); 
}

class person
{
	friend ostream& operator<<(ostream &os, const person&p)
	{
		os << "name:" << p.Name << " age:" << p.Age;
		return os;
	}

public:
	person(string name, int age)
	{
		Name = name;
		Age = age;
	}
	//默认排序都是简单的值排序，复杂数据类型要自己提供比较规则
	bool operator<(const person&p) const//只读迭代器
	{
		return this->Age < p.Age;
	}
	//bool operator==(const person&p) const
	//{
	//	return   this->Name == p.Name && this->Age == p.Age;
	//}

private:
	string Name;
	int Age;
};

template <class T>
class mySetcompare
{
public:
	bool operator()(T v1, T v2)
	{
		return v1 < v2;
	}
};
void test02()
{
	//默认排好序的规则只是对简单的类型有效，复杂类型
	//1.对默认的<进行重载
	set<person> s = {person("aa", 10), person("bb", 20)};
	s.insert(person("cc", 60));
	s.insert(person("dd", 30));
	printSet(s);
	//2.对比较规则重新写
	//set(_Kty, _Pr = less<_Kty>, _Alloc = allocator<_Kty>)
	//_Kty数据类型  _Pr默认是less类， 
	/*
	struct less
	{	// functor for operator<
	typedef _Ty first_argument_type;
	typedef _Ty second_argument_type;
	typedef bool result_type;

	constexpr bool operator()(const _Ty& _Left, const _Ty& _Right) const
		{	// apply operator< to operands
		return (_Left < _Right);
		}
	};
	*/
	set<person, mySetcompare<person>> s1 = { person("ff", 10), person("dd", 20) };
	s1.insert(person("mm", 60));
	s1.insert(person("nn", 30));
	printSet(s1);

	//set<person, mySetcompare<person>>::iterator ret = s1.find(person("mm", 60));
	
	//查找find元素
	//根据重载的<小于号，编译器会自动比较当前 this < p1返回假
	//并且p1 < this也是返回假----推出this与p1是相等的
#if 1
	set<person>::iterator ret = s.find(person("mm", 40));
	if (ret == s.end())
	{
		cout << "查找失败" << endl;
		//当查找失败后ret == s.end()就越界了(指向最后一个元素后面)，
		//后面输出*ret就会访问溢出
	}
	else
	{
		cout << *ret << endl;
	}
#endif

	//这三种种查找也会越界，查找失败返回最后一个元素的迭代器
	auto it1 = s.lower_bound(person("dd", 30));
	set<person>::iterator it2 = s.upper_bound(person("dd", 30));
	cout << *it1 << endl;
	cout << *it2 << endl;
	pair<set<person>::iterator, set<person>::iterator> p 
		//= s.equal_range(person("ff", 80));//越界
		= s.equal_range(person("ff", 20));
	cout << *(p.first) << endl;
	cout << *(p.second) << endl;
}
int main()
{
	//test01();
	test02();
	return 0;
}