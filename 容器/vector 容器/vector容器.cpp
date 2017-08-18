#include <iostream>
using namespace std;
#include <vector>


void printVector(vector<int> &v)
{
	for (auto it : v)
	{
		cout << it << " ";
	}
	cout << endl;
}
/*
vector<T> v; //采用模板实现类实现，默认构造函数
vector(v.begin(), v.end());//将v[begin(), end())区间中的元素拷贝给本身。
vector(n, elem);//构造函数将n个elem拷贝给本身。
vector(const vector &vec);//拷贝构造函数。
*/
void test01()
{
	vector<int> v;
	int arr[6] = { 1, 2, 3, 4, 5, 6 };
	//利用第二个构造函数，其实数组也是一个容器 首地址相当于v.begin()
	vector<int> v1(arr, arr + sizeof(arr) / sizeof(arr[0]));
	vector<int> v2(v1);
	vector<int> v3(3, 6);
	vector<int> v4(v3.begin(), v3.end());
	printVector(v1);
	printVector(v2);
	printVector(v3);
	printVector(v4);

}

/*  ------赋值
assign(beg, end);//将[beg, end)区间中的数据拷贝赋值给本身。
assign(n, elem);//将n个elem拷贝赋值给本身。
vector& operator=(const vector  &vec);//重载等号操作符
swap(vec);// 将vec与本身的元素互换。
*/

void test02()
{
	int arr[5] = {1, 2, 3, 4, 5};
	vector<int> v1(arr, arr + sizeof(arr) / sizeof(arr[0]));
	printVector(v1);
	cout << v1.size() << " " << v1.capacity() << endl;

	int arr1[9] = { 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	v1.assign(arr1, arr1 + sizeof(arr1) / sizeof(arr1[0]));
	printVector(v1);
	cout << v1.size() << " " << v1.capacity() << endl;

	vector<int> v2;
	v2 = v1;
	printVector(v2);

	v2.assign(6, 6);
	printVector(v2);

	v2.swap(v1);
	printVector(v1);
	printVector(v2);

}
/*
size();//返回容器中元素的个数
empty();//判断容器是否为空
resize(int num);//重新指定容器的长度为num，若容器变长，则以默认值填充新位置。如果容器变短，则末尾超出容器长度的元素被删除。
resize(int num, elem);//重新指定容器的长度为num，若容器变长，则以elem值填充新位置。如果容器变短，则末尾超出容器长>度的元素被删除。
capacity();//容器的容量
reserve(int len);//容器预留len个元素长度，预留位置不初始化，元素不可访问。
*/

/*
resize和reserve的区别
reserve只会对容器对象的容量做修改
	1》当要设置的容量小于原来的容量，容量不变
	2》当要设置的容量大于原来的容量，容量按照新设置的
resize设置对象的长度，相应可能会改变容量
	1》当要设置的长度小于原来的长度，长度变小，超出长度的元素被删除，容量不变
	2》当要设置的长度大于原来的长度，长度变大，新增的位置的元素以默认值填充，
	   长度小于容量，容量不变，长度大于容量容量变大
*/
void test03()
{
	int arr1[9] = { 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	vector<int>  v1(arr1, arr1 + sizeof(arr1) / sizeof(arr1[0]));
	cout << v1.size() << " " << v1.capacity() << endl;//9  9
#if 0
	v1.resize(5);
	cout << v1.size() << " " << v1.capacity() << endl;//5  9
#endif
#if 0
	v1.resize(15);
	cout << v1.size() << " " << v1.capacity() << endl;//15 15
#endif
#if 0
	v1.reserve(5);
	cout << v1.size() << " " << v1.capacity() << endl;//9  9
#endif
	v1.reserve(15);
	cout << v1.size() << " " << v1.capacity() << endl;//9  15
	v1.resize(12, 0);
	cout << v1.size() << " " << v1.capacity() << endl;//10  15
	printVector(v1);
	if (!v1.empty())
	{
		cout << "容器不为空" << endl;
	}
}

/*
at(int idx); //返回索引idx所指的数据，如果idx越界，抛出out_of_range异常。
operator[];//返回索引idx所指的数据，越界时，运行直接报错
front();//返回容器中第一个数据元素
back();//返回容器中最后一个数据元素
*/
void test04()
{
	int arr1[9] = { 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	vector<int>  v1(arr1, arr1 + sizeof(arr1) / sizeof(arr1[0]));
	cout << v1.front() << endl;
	cout << v1.back() << endl;
#if 0
	try
	{
		v1[18] = 2;
	}
	catch (exception &ex)
	{
		ex.what();
	}
#endif
	try
	{
		v1.at(18) = 2;
	}
	catch (exception &ex)
	{
		ex.what();
		cout << "访问溢出" << endl;
	}
}
/*
insert(const_iterator pos, int count,ele);//迭代器指向位置pos插入count个元素ele.
push_back(ele); //尾部插入元素ele
pop_back();//删除最后一个元素
erase(const_iterator start, const_iterator end);//删除迭代器从start到end之间的元素
erase(const_iterator pos);//删除迭代器指向的元素
clear();//删除容器中所有元素
*/
void test05()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);

	//第一个参数迭代器指向的位置前面插入n个元素
	v.insert(v.begin() + 1, 3, 6);
	v.insert(v.end() - 1, 1, 9);
	printVector(v);
	//删除尾部元素
	v.pop_back();
	printVector(v);//1 6 6 6 2 3 4 9
	//删除迭代器指向的段数据元素----左闭右开
	v.erase(v.begin() + 1, v.begin() + 3);//1 6 2 3 4 9
	printVector(v);
	//删除迭代器指定位置
	//v.erase(v.end());//不能删除指向不是有效数据位置
	v.erase(v.end() - 1);
	printVector(v);
}

//利用swap函数和局部变量将容器的容量缩小
void test06()
{
	vector<int> v;
	v.resize(1000);
	v.resize(10);
	cout << v.size() << " " << v.capacity() << endl;
	
	vector<int>(v).swap(v);//可以看出vector的拷贝构造函数（初始化的时候），
	//新对象的容量是根据被拷贝对象的长度来分配的，不是根据容量来的分配的
	//新匿名对象与原来对象交换，匿名对象此行语句结束被析构
	cout << v.size() << " " << v.capacity() << endl;
}

//合理使用reserve可以使程序效率提高
void test07()
{
	int *p = NULL;
	int count = 0;
	vector<int> v;
	//v.reserve(1000);//可以使容器不用频繁的申请内存空间，拷贝数据
	for (int i = 0; i < 1000; i++)
	{
		v.push_back(i + 10);
		if (p != &v[0])
		{
			++count;
			p = &v[0];
		}
	}
	
	cout << count << endl;
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