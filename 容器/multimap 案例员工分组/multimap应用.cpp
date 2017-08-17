#include <iostream>
using namespace std;
#include <list>
#include <map>
#include <ctime>
#include <string>
#define SALE_DEPATMENT 1 //���۲���
#define DEVELOP_DEPATMENT 2 //�з�����
#define FINACIAL_DEPATMENT 3 //������

/*
��Ա������Ϣ����list��������
Ȼ�󽫲��ź�Ա������mulitmap��
*/
class Employee
{
	friend void createEmployee(list<Employee> &worker);
	friend void showEmployeeByDepartment(multimap<int, Employee> &group, int partmentid);

private:
	string name;
	int salary;
};
void createEmployee(list<Employee> &worker)
{
	string nameseed = "ABCDEFGHIK";
	srand((unsigned int)time(NULL));
	for (int i = 0; i < nameseed.size(); ++i)
	{
		Employee temp;
		temp.name = "Ա��";
		temp.name += nameseed[i];

		temp.salary = rand() % 5001 + 5000;

		worker.push_back(temp);
	}
}

void setGroup(list<Employee> &worker, multimap<int, Employee> &group)
{
	srand((unsigned int)time(NULL));

	for (auto it : worker)
	{
		int id = rand() % 3 + 1;
		group.insert(make_pair(id, it));
	}

}
void showEmployeeByDepartment(multimap<int, Employee> &group, int partmentid)
{
	int num = group.count(partmentid);//���ݲ��ű��ȷ���˲����µ�Ա����
	auto pos = group.find(partmentid);//���ݲ��ű�ţ���ȷ���˲��ŵ�����Ա��

	for (int i = 0; i < num; i++)
	{
		cout << "����:" << pos->second.name << "  нˮ:" << pos->second.salary << endl;
		pos++;
	}
}
void showEveryGroupEmployee(multimap<int, Employee> &group)
{
	cout << "���۲�����Ϣ��-------" << endl;
	showEmployeeByDepartment(group, SALE_DEPATMENT);
	cout << "�з�������Ϣ��-------" << endl;
	showEmployeeByDepartment(group, DEVELOP_DEPATMENT);
	cout << "��������Ϣ��--------" << endl;
	showEmployeeByDepartment(group, FINACIAL_DEPATMENT);

}
int main()
{
	list<Employee> worker;
	multimap<int, Employee> group;
	createEmployee(worker);
	setGroup(worker, group);
	showEveryGroupEmployee(group);
	return 0;
}