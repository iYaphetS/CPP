#include <iostream>
using namespace std;
#include <set>
#include <string>


/*-------ֻ��˫������������Ǻ������ƽ�����������set��mulitset������set���ܲ���ֵval��Ԫ�أ�����mulitset����
set<T> st;//setĬ�Ϲ��캯����
mulitset<T> mst; //multisetĬ�Ϲ��캯��:
set(const set &st);//�������캯��

set& operator=(const set &st);//���صȺŲ�����
swap(st);//����������������

size();//����������Ԫ�ص���Ŀ
empty();//�ж������Ƿ�Ϊ��

insert(elem);//�������в���Ԫ�ء�
clear();//�������Ԫ��
erase(pos);//ɾ��pos��������ָ��Ԫ�أ�������һ��Ԫ�صĵ�������
erase(beg, end);//ɾ������[beg,end)������Ԫ�� ��������һ��Ԫ�صĵ�������
erase(elem);//ɾ��������ֵΪelem��Ԫ�ء�

find(key);//���Ҽ�key�Ƿ����,�����ڣ����ظü���Ԫ�صĵ��������������ڣ�����set.end();
count(key);//���Ҽ�key��Ԫ�ظ���
lower_bound(keyElem);//���ص�һ��key>=keyElemԪ�صĵ�������
upper_bound(keyElem);//���ص�һ��key>keyElemԪ�صĵ�������
equal_range(keyElem);//����������key��keyElem��ȵ������޵�������������
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
	s.insert(6);//����ʧ��
	//���Զ������������
	printSet(s);

	set<int>::iterator ret = s.find(2);
	if (ret == s.end())
	{
		cout << "����ʧ��" << endl;
	}

	cout << "count = " << s.count(6) << endl;

	set<int>::iterator it1 = s.lower_bound(2);//��һ�����ڵ���2��������λ��
	set<int>::iterator it2 = s.upper_bound(2);//��һ������2��������λ��

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
	//Ĭ�������Ǽ򵥵�ֵ���򣬸�����������Ҫ�Լ��ṩ�ȽϹ���
	bool operator<(const person&p) const//ֻ��������
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
	//Ĭ���ź���Ĺ���ֻ�ǶԼ򵥵�������Ч����������
	//1.��Ĭ�ϵ�<��������
	set<person> s = {person("aa", 10), person("bb", 20)};
	s.insert(person("cc", 60));
	s.insert(person("dd", 30));
	printSet(s);
	//2.�ԱȽϹ�������д
	//set(_Kty, _Pr = less<_Kty>, _Alloc = allocator<_Kty>)
	//_Kty��������  _PrĬ����less�࣬ 
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
	
	//����findԪ��
	//�������ص�<С�ںţ����������Զ��Ƚϵ�ǰ this < p1���ؼ�
	//����p1 < thisҲ�Ƿ��ؼ�----�Ƴ�this��p1����ȵ�
#if 1
	set<person>::iterator ret = s.find(person("mm", 40));
	if (ret == s.end())
	{
		cout << "����ʧ��" << endl;
		//������ʧ�ܺ�ret == s.end()��Խ����(ָ�����һ��Ԫ�غ���)��
		//�������*ret�ͻ�������
	}
	else
	{
		cout << *ret << endl;
	}
#endif

	//�������ֲ���Ҳ��Խ�磬����ʧ�ܷ������һ��Ԫ�صĵ�����
	auto it1 = s.lower_bound(person("dd", 30));
	set<person>::iterator it2 = s.upper_bound(person("dd", 30));
	cout << *it1 << endl;
	cout << *it2 << endl;
	pair<set<person>::iterator, set<person>::iterator> p 
		//= s.equal_range(person("ff", 80));//Խ��
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