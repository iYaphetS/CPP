#include <iostream>
using namespace std;
#include <map>
#include <string>

/*--------双向迭代器
map<T1, T2> mapTT;//map默认构造函数:
map(const map &mp);//拷贝构造函数
map& operator=(const map &mp);//重载等号操作符
swap(mp);//交换两个集合容器
size();//返回容器中元素的数目
empty();//判断容器是否为空

map.insert(...); //往容器插入元素，返回pair<iterator,bool>
map<int, string> mapStu;
// 第一种 通过pair的方式插入对象
mapStu.insert(pair<int, string>(3, "小张"));
// 第二种 通过pair的方式插入对象
mapStu.inset(make_pair(-1, "校长"));
// 第三种 通过value_type的方式插入对象

mapStu.insert(map<int, string>::value_type(1, "小李"));
// 第四种 通过数组的方式插入值
mapStu[3] = "小刘";
mapStu[5] = "小王";

clear();//删除所有元素
erase(pos);//删除pos迭代器所指的元素，返回下一个元素的迭代器。
erase(beg,end);//删除区间[beg,end)的所有元素 ，返回下一个元素的迭代器。
erase(keyElem);//删除容器中key为keyElem的对组。

find(key);//查找键key是否存在,若存在，返回该键的元素的迭代器；/若不存在，返回map.end();
count(keyElem);//返回容器中key为keyElem的对组个数。对map来说，要么是0，要么是1。对multimap来说，值可能大于1。
lower_bound(keyElem);//返回第一个key>=keyElem元素的迭代器。
upper_bound(keyElem);//返回第一个key>keyElem元素的迭代器。
equal_range(keyElem);//返回容器中key与keyElem相等的上下限的两个迭代器。
*/

template <class T1, class T2>
void printMap(map<T1, T2> &m)
{
	for (map<T1, T2>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "key:" << it->first << " value:"<< it->second << endl;
	}
}
void test01()
{
	map<int, string> m = { {1, "zhang"}, {3, "li"} };
	//四种插入方式
	m.insert(pair<int, string>(-1, "wang"));
	m.insert(make_pair(1, "zhao"));//插入失败
	m.insert(make_pair(4, "zhao"));
	m.insert(map<int, string>::value_type(2, "liu"));
	//这种插入方式，与上面的三种不同，可以插入相同的key值，会覆盖原来的
	m[3] = "ou";
	m[5] = "wen";
	//默认是按照了key进行升序排序了
	printMap(m);
	cout << "=============" << endl;
	//按照迭代器指向的位置删除
	m.erase(++m.begin());
	//按照键删除
	m.erase(5);
	printMap(m);
	cout << "=============" << endl;

	//这里查找和前面不同，前面根据对象整体，这个根据key
	map<int, string>::iterator ret = m.find(3);
	if (ret == m.end())
	{
		cout << "查找失败" << endl;
	}
	else
	{
		cout << "key:" << ret->first << " value:" << ret->second << endl;
	}
	cout << "=============" << endl;

	map<int, string>::iterator it1 = m.lower_bound(2);
	auto it2 = m.upper_bound(2);
	cout << "key:" << it1->first << " value:" << it1->second << endl;
	cout << "key:" << it2->first << " value:" << it2->second << endl;
	cout << "=============" << endl;

	pair<map<int, string>::iterator, map<int, string>::iterator>
		pai = m.equal_range(1);//key值超过最大值会越界
	cout << "key:" << pai.first->first << " value:" << pai.first->second << endl;
	cout << "key:" << pai.second->first << " value:" << pai.second->second << endl;



}
int main()
{
	test01();
	return 0;
}