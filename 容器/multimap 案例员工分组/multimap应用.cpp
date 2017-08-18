#include <iostream>
using namespace std;
#include <list>
#include <map>
#include <ctime>
#include <string>
#define SALE_DEPATMENT 1 //销售部门
#define DEVELOP_DEPATMENT 2 //研发部门
#define FINACIAL_DEPATMENT 3 //财务部门

/*
将员工的信息放在list的容器中
然后将部门和员工放在mulitmap中
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
		temp.name = "员工";
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
	int num = group.count(partmentid);//根据部门编号确定此部门下的员工数
	auto pos = group.find(partmentid);//根据部门编号，来确定此部门的所有员工

	for (int i = 0; i < num; i++)
	{
		cout << "姓名:" << pos->second.name << "  薪水:" << pos->second.salary << endl;
		pos++;
	}
}
void showEveryGroupEmployee(multimap<int, Employee> &group)
{
	cout << "销售部门信息：-------" << endl;
	showEmployeeByDepartment(group, SALE_DEPATMENT);
	cout << "研发部门信息：-------" << endl;
	showEmployeeByDepartment(group, DEVELOP_DEPATMENT);
	cout << "财务部门信息：--------" << endl;
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