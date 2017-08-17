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
deque<T> deqT;//Ĭ�Ϲ�����ʽ
deque(beg, end);//���캯����[beg, end)�����е�Ԫ�ؿ���������
deque(n, elem);//���캯����n��elem����������
deque(const deque &deq);//�������캯��
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
assign(beg, end);//��[beg, end)�����е����ݿ�����ֵ������
assign(n, elem);//��n��elem������ֵ������
deque& operator=(const deque &deq); //���صȺŲ�����
swap(deq);// ��deq�뱾���Ԫ�ػ���
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
deque.size();//����������Ԫ�صĸ���
deque.empty();//�ж������Ƿ�Ϊ��
deque.resize(num);//����ָ�������ĳ���Ϊnum,�������䳤������Ĭ��ֵ�����λ�á����������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ����
deque.resize(num, elem); //����ָ�������ĳ���Ϊnum,�������䳤������elemֵ�����λ��,���������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ����
*/

void test03()
{
	int arr[5] = { 1, 2, 3, 4, 5 };
	deque<int> d1(arr, arr + sizeof(arr) / sizeof(arr[0]));
	deque<int> d2(5, 6);
	cout << d1.size() << endl;
	if (!d1.empty())
	{
		cout << "������Ϊ��" << endl;
	}
	d1.resize(10);//���ȱ䳤��Ĭ����0���
	printDeque(d1);
	d1.resize(15, 9);
	printDeque(d1);
}
/*
push_back(elem);//������β�����һ������
push_front(elem);//������ͷ������һ������
pop_back();//ɾ���������һ������
pop_front();//ɾ��������һ������
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
at(idx);//��������idx��ָ�����ݣ����idxԽ�磬�׳�out_of_range��
operator[];//��������idx��ָ�����ݣ����idxԽ�磬���׳��쳣��ֱ�ӳ���
front();//���ص�һ�����ݡ�
back();//�������һ������
*/
void test05()
{
	int arr[5] = { 1, 2, 3, 4, 5 };
	deque<int> d1(arr, arr + sizeof(arr) / sizeof(arr[0]));
	cout << d1.front() << endl;//���ص�һ��Ԫ�ص�ֵ
	cout << d1.back() << endl;
	cout << d1.at(3) << endl;
	cout << d1[2] << endl;
}
/*
insert(pos, elem);//��posλ�ò���һ��elemԪ�صĿ��������������ݵ�λ�á�
insert(pos, n, elem);//��posλ�ò���n��elem���ݣ��޷���ֵ��
insert(pos, beg, end);//��posλ�ò���[beg,end)��������ݣ��޷���ֵ��

clear();//�Ƴ���������������
erase(beg,end);//ɾ��[beg,end)��������ݣ�������һ�����ݵ�λ�á�
erase(pos);//ɾ��posλ�õ����ݣ�������һ�����ݵ�λ�á�
*/
void test06()
{
	deque<int> d(3, 8);
	deque<int> d1;
	d1.push_back(1);

	//��һ�������ǵ�����ָ���λ��
	d1.insert(d1.begin(), 2);
	d1.insert(d1.end(), 3, 6);
	d1.insert(d1.begin() + 1, d.begin(), d.end());
	printDeque(d1);
	d1.erase(d1.begin() + 2, d1.end() - 1);//����ҿ�
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