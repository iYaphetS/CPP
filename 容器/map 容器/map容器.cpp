#include <iostream>
using namespace std;
#include <map>
#include <string>

/*--------˫�������
map<T1, T2> mapTT;//mapĬ�Ϲ��캯��:
map(const map &mp);//�������캯��
map& operator=(const map &mp);//���صȺŲ�����
swap(mp);//����������������
size();//����������Ԫ�ص���Ŀ
empty();//�ж������Ƿ�Ϊ��

map.insert(...); //����������Ԫ�أ�����pair<iterator,bool>
map<int, string> mapStu;
// ��һ�� ͨ��pair�ķ�ʽ�������
mapStu.insert(pair<int, string>(3, "С��"));
// �ڶ��� ͨ��pair�ķ�ʽ�������
mapStu.inset(make_pair(-1, "У��"));
// ������ ͨ��value_type�ķ�ʽ�������

mapStu.insert(map<int, string>::value_type(1, "С��"));
// ������ ͨ������ķ�ʽ����ֵ
mapStu[3] = "С��";
mapStu[5] = "С��";

clear();//ɾ������Ԫ��
erase(pos);//ɾ��pos��������ָ��Ԫ�أ�������һ��Ԫ�صĵ�������
erase(beg,end);//ɾ������[beg,end)������Ԫ�� ��������һ��Ԫ�صĵ�������
erase(keyElem);//ɾ��������keyΪkeyElem�Ķ��顣

find(key);//���Ҽ�key�Ƿ����,�����ڣ����ظü���Ԫ�صĵ�������/�������ڣ�����map.end();
count(keyElem);//����������keyΪkeyElem�Ķ����������map��˵��Ҫô��0��Ҫô��1����multimap��˵��ֵ���ܴ���1��
lower_bound(keyElem);//���ص�һ��key>=keyElemԪ�صĵ�������
upper_bound(keyElem);//���ص�һ��key>keyElemԪ�صĵ�������
equal_range(keyElem);//����������key��keyElem��ȵ������޵�������������
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
	//���ֲ��뷽ʽ
	m.insert(pair<int, string>(-1, "wang"));
	m.insert(make_pair(1, "zhao"));//����ʧ��
	m.insert(make_pair(4, "zhao"));
	m.insert(map<int, string>::value_type(2, "liu"));
	//���ֲ��뷽ʽ������������ֲ�ͬ�����Բ�����ͬ��keyֵ���Ḳ��ԭ����
	m[3] = "ou";
	m[5] = "wen";
	//Ĭ���ǰ�����key��������������
	printMap(m);
	cout << "=============" << endl;
	//���յ�����ָ���λ��ɾ��
	m.erase(++m.begin());
	//���ռ�ɾ��
	m.erase(5);
	printMap(m);
	cout << "=============" << endl;

	//������Һ�ǰ�治ͬ��ǰ����ݶ������壬�������key
	map<int, string>::iterator ret = m.find(3);
	if (ret == m.end())
	{
		cout << "����ʧ��" << endl;
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
		pai = m.equal_range(1);//keyֵ�������ֵ��Խ��
	cout << "key:" << pai.first->first << " value:" << pai.first->second << endl;
	cout << "key:" << pai.second->first << " value:" << pai.second->second << endl;



}
int main()
{
	test01();
	return 0;
}