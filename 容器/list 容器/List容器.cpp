#include <iostream>
using namespace std;
#include <list>
#include <string>

/*
list<T> lstT;//list���ò���ģ����ʵ��,�����Ĭ�Ϲ�����ʽ��
list(beg,end);//���캯����[beg, end)�����е�Ԫ�ؿ���������
list(n,elem);//���캯����n��elem����������
list(const list &lst);//�������캯����

push_back(elem);//������β������һ��Ԫ��
pop_back();//ɾ�����������һ��Ԫ��
push_front(elem);//��������ͷ����һ��Ԫ��
pop_front();//��������ͷ�Ƴ���һ��Ԫ��
insert(pos,elem);//��posλ�ò�elemԪ�صĿ��������������ݵ�λ�á�
insert(pos,n,elem);//��posλ�ò���n��elem���ݣ��޷���ֵ��
insert(pos,beg,end);//��posλ�ò���[beg,end)��������ݣ��޷���ֵ��
clear();//�Ƴ���������������
erase(beg,end);//ɾ��[beg,end)��������ݣ�������һ�����ݵ�λ�á�
erase(pos);//ɾ��posλ�õ����ݣ�������һ�����ݵ�λ�á�
remove(elem);//ɾ��������������elemֵƥ���Ԫ�ء�

size();//����������Ԫ�صĸ���
empty();//�ж������Ƿ�Ϊ��
resize(num);//����ָ�������ĳ���Ϊnum��
�������䳤������Ĭ��ֵ�����λ�á�
���������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ����
resize(num, elem);//����ָ�������ĳ���Ϊnum��
�������䳤������elemֵ�����λ�á�
���������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ����

assign(beg, end);//��[beg, end)�����е����ݿ�����ֵ������
assign(n, elem);//��n��elem������ֵ������
list& operator=(const list &lst);//���صȺŲ�����
swap(lst);//��lst�뱾���Ԫ�ػ�����

front();//���ص�һ��Ԫ�ء�
back();//�������һ��Ԫ�ء�

reverse();//��ת��������lst����1,3,5Ԫ�أ����д˷�����lst�Ͱ���5,3,1Ԫ�ء�
sort(); //list����
*/
template <class T>
void printList(T &v)
{
	for (T::iterator it = v.begin(); it != v.end();++it)
	{
		cout << *it << endl;
	}

}
//����������
void test01()
{
	list<int> lst;
	lst.push_back(10);
	lst.push_front(20);
	lst.push_front(13);
	lst.push_back(30);

	printList(lst);

	//��������
	list<int> mylist1(lst);
	printList(mylist1);

	//���ֵ��������
	list<int> mylist2(4, 6);
	printList(mylist2);

	//���俽������
	list<int>::iterator it = lst.begin();
	it++;
	it++;
	it--;
	//it + 5;�������������
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
	cout << lst.front() << endl;//����Ԫ��
	cout << lst.back() << endl;//��βԪ��

	lst.pop_back();//ɾ����βԪ��
	printList(lst);
	lst.pop_front();//ɾ����ͷԪ��
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

	//it + 5;�������������
	//	list<int> mylist(it1, lst.end()--);//����--,������ʽ��--
	list<int> mylist(it1, it2);//list<int> mylist(it1, --lst.end());
	printList(mylist);

	//���ֲ���
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

	//����ɾ��
	lst.erase(++lst.begin());
	lst.remove(10);//ɾ������ֵΪ10��Ԫ��
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

	//��ֵ
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
//����Ԫ�صĴ�С
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
		return this->Age == p.Age;//��Ҫ���������������ͬ����
	}

private:
	string Name;
	int Age;
};


//������������
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
	//�������������޷������ݽ�������--
	//1.���ṩ<(Ĭ����<���Լ�ֵ�Ƚ�)����
	lst.sort();//-----------------------list�����������������˫������������ܵ����㷨sort����
	/*
	sort(less<>());
	*/
	printList(lst);
	cout << "==============" << endl;
	//2.�ṩ�ص�����
	lst.sort(mypersoncompare);
	printList(lst);
	cout << "==============" << endl;

	//ͬ���Ը�����������ɾ��
	//1.��==���أ�Ĭ���Ǽ򵥵�ֵ�Ƚϣ�
	lst.remove(person("bb", 20));
	printList(lst);
	cout << "==============" << endl;

	//2.�ṩɾ������ĺ���
	//lst.remove_if(removeperson);//���ܸ��ã���������
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