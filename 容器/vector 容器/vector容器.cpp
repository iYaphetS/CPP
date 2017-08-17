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
vector<T> v; //����ģ��ʵ����ʵ�֣�Ĭ�Ϲ��캯��
vector(v.begin(), v.end());//��v[begin(), end())�����е�Ԫ�ؿ���������
vector(n, elem);//���캯����n��elem����������
vector(const vector &vec);//�������캯����
*/
void test01()
{
	vector<int> v;
	int arr[6] = { 1, 2, 3, 4, 5, 6 };
	//���õڶ������캯������ʵ����Ҳ��һ������ �׵�ַ�൱��v.begin()
	vector<int> v1(arr, arr + sizeof(arr) / sizeof(arr[0]));
	vector<int> v2(v1);
	vector<int> v3(3, 6);
	vector<int> v4(v3.begin(), v3.end());
	printVector(v1);
	printVector(v2);
	printVector(v3);
	printVector(v4);

}

/*  ------��ֵ
assign(beg, end);//��[beg, end)�����е����ݿ�����ֵ������
assign(n, elem);//��n��elem������ֵ������
vector& operator=(const vector  &vec);//���صȺŲ�����
swap(vec);// ��vec�뱾���Ԫ�ػ�����
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
size();//����������Ԫ�صĸ���
empty();//�ж������Ƿ�Ϊ��
resize(int num);//����ָ�������ĳ���Ϊnum���������䳤������Ĭ��ֵ�����λ�á����������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ����
resize(int num, elem);//����ָ�������ĳ���Ϊnum���������䳤������elemֵ�����λ�á����������̣���ĩβ����������>�ȵ�Ԫ�ر�ɾ����
capacity();//����������
reserve(int len);//����Ԥ��len��Ԫ�س��ȣ�Ԥ��λ�ò���ʼ����Ԫ�ز��ɷ��ʡ�
*/

/*
resize��reserve������
reserveֻ�������������������޸�
	1����Ҫ���õ�����С��ԭ������������������
	2����Ҫ���õ���������ԭ�����������������������õ�
resize���ö���ĳ��ȣ���Ӧ���ܻ�ı�����
	1����Ҫ���õĳ���С��ԭ���ĳ��ȣ����ȱ�С���������ȵ�Ԫ�ر�ɾ������������
	2����Ҫ���õĳ��ȴ���ԭ���ĳ��ȣ����ȱ��������λ�õ�Ԫ����Ĭ��ֵ��䣬
	   ����С���������������䣬���ȴ��������������
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
		cout << "������Ϊ��" << endl;
	}
}

/*
at(int idx); //��������idx��ָ�����ݣ����idxԽ�磬�׳�out_of_range�쳣��
operator[];//��������idx��ָ�����ݣ�Խ��ʱ������ֱ�ӱ���
front();//���������е�һ������Ԫ��
back();//�������������һ������Ԫ��
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
		cout << "�������" << endl;
	}
}
/*
insert(const_iterator pos, int count,ele);//������ָ��λ��pos����count��Ԫ��ele.
push_back(ele); //β������Ԫ��ele
pop_back();//ɾ�����һ��Ԫ��
erase(const_iterator start, const_iterator end);//ɾ����������start��end֮���Ԫ��
erase(const_iterator pos);//ɾ��������ָ���Ԫ��
clear();//ɾ������������Ԫ��
*/
void test05()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);

	//��һ������������ָ���λ��ǰ�����n��Ԫ��
	v.insert(v.begin() + 1, 3, 6);
	v.insert(v.end() - 1, 1, 9);
	printVector(v);
	//ɾ��β��Ԫ��
	v.pop_back();
	printVector(v);//1 6 6 6 2 3 4 9
	//ɾ��������ָ��Ķ�����Ԫ��----����ҿ�
	v.erase(v.begin() + 1, v.begin() + 3);//1 6 2 3 4 9
	printVector(v);
	//ɾ��������ָ��λ��
	//v.erase(v.end());//����ɾ��ָ������Ч����λ��
	v.erase(v.end() - 1);
	printVector(v);
}

//����swap�����;ֲ�������������������С
void test06()
{
	vector<int> v;
	v.resize(1000);
	v.resize(10);
	cout << v.size() << " " << v.capacity() << endl;
	
	vector<int>(v).swap(v);//���Կ���vector�Ŀ������캯������ʼ����ʱ�򣩣�
	//�¶���������Ǹ��ݱ���������ĳ���������ģ����Ǹ����������ķ����
	//������������ԭ�����󽻻��������������������������
	cout << v.size() << " " << v.capacity() << endl;
}

//����ʹ��reserve����ʹ����Ч�����
void test07()
{
	int *p = NULL;
	int count = 0;
	vector<int> v;
	//v.reserve(1000);//����ʹ��������Ƶ���������ڴ�ռ䣬��������
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