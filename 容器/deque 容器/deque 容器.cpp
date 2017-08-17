#include <iostream>
using namespace std;
#include <deque>

void printDeque(deque<int> &d)
{
	for (deque<int>::iterator it = d.begin(); it != d.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
}
/*
deque<T> deqT;//默认构造形式
deque(beg, end);//构造函数将[beg, end)区间中的元素拷贝给本身。
deque(n, elem);//构造函数将n个elem拷贝给本身。
deque(const deque &deq);//拷贝构造函数
*/
void test01()
{
	deque<int> d;
	int arr[5] = {1, 2, 3, 4, 5};
	deque<int> d1(arr, arr + sizeof(arr) / sizeof(arr[0]));
	deque<int> d2(5, 6);
	deque<int> d3(d1);

	printDeque(d1);
	printDeque(d2);
	printDeque(d3);
}
/*
assign(beg, end);//将[beg, end)区间中的数据拷贝赋值给本身。
assign(n, elem);//将n个elem拷贝赋值给本身。
deque& operator=(const deque &deq); //重载等号操作符
swap(deq);// 将deq与本身的元素互换
*/
void test02()
{
	int arr[5] = { 1, 2, 3, 4, 5 };
	deque<int> d1(arr, arr + sizeof(arr) / sizeof(arr[0]));
	deque<int> d2(5, 6);

	d1.assign(10, 8);
	printDeque(d1);
	
	d1.swap(d2);
	printDeque(d1);

	d1 = d2;
	printDeque(d1);

}
/*
deque.size();//返回容器中元素的个数
deque.empty();//判断容器是否为空
deque.resize(num);//重新指定容器的长度为num,若容器变长，则以默认值填充新位置。如果容器变短，则末尾超出容器长度的元素被删除。
deque.resize(num, elem); //重新指定容器的长度为num,若容器变长，则以elem值填充新位置,如果容器变短，则末尾超出容器长度的元素被删除。
*/

void test03()
{
	int arr[5] = { 1, 2, 3, 4, 5 };
	deque<int> d1(arr, arr + sizeof(arr) / sizeof(arr[0]));
	deque<int> d2(5, 6);
	cout << d1.size() << endl;
	if (!d1.empty())
	{
		cout << "容器不为空" << endl;
	}
	d1.resize(10);//长度变长，默认以0填充
	printDeque(d1);
	d1.resize(15, 9);
	printDeque(d1);
}
/*
push_back(elem);//在容器尾部添加一个数据
push_front(elem);//在容器头部插入一个数据
pop_back();//删除容器最后一个数据
pop_front();//删除容器第一个数据
*/
void test04()
{
	int arr[5] = { 1, 2, 3, 4, 5 };
	deque<int> d1(arr, arr + sizeof(arr) / sizeof(arr[0]));
	d1.pop_back();
	d1.pop_front();
	printDeque(d1);

	d1.push_back(12);
	d1.push_front(10);
	printDeque(d1);
	
}
/*
at(idx);//返回索引idx所指的数据，如果idx越界，抛出out_of_range。
operator[];//返回索引idx所指的数据，如果idx越界，不抛出异常，直接出错。
front();//返回第一个数据。
back();//返回最后一个数据
*/
void test05()
{
	int arr[5] = { 1, 2, 3, 4, 5 };
	deque<int> d1(arr, arr + sizeof(arr) / sizeof(arr[0]));
	cout << d1.front() << endl;//返回第一个元素的值
	cout << d1.back() << endl;
	cout << d1.at(3) << endl;
	cout << d1[2] << endl;
}
/*
insert(pos, elem);//在pos位置插入一个elem元素的拷贝，返回新数据的位置。
insert(pos, n, elem);//在pos位置插入n个elem数据，无返回值。
insert(pos, beg, end);//在pos位置插入[beg,end)区间的数据，无返回值。

clear();//移除容器的所有数据
erase(beg,end);//删除[beg,end)区间的数据，返回下一个数据的位置。
erase(pos);//删除pos位置的数据，返回下一个数据的位置。
*/
void test06()
{
	deque<int> d(3, 8);
	deque<int> d1;
	d1.push_back(1);

	//第一个参数是迭代器指向的位置
	d1.insert(d1.begin(), 2);
	d1.insert(d1.end(), 3, 6);
	d1.insert(d1.begin() + 1, d.begin(), d.end());
	printDeque(d1);
	d1.erase(d1.begin() + 2, d1.end() - 1);//左闭右开
	printDeque(d1);
	d1.erase(d1.begin());
	printDeque(d1);
	d1.clear();
	printDeque(d1);
}
int main()
{
	//test01();
	//test02();
	//test03();
	//test04();
	//test05();
	test06();
	return 0;
}