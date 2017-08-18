#include <iostream>
using namespace std;
#include <vector>
#include <deque>
#include <algorithm>
#include <string>
#include <ctime>

//6个学生表演，10个评委打分，按照平局分将学生打印出来
class Students
{
public:
	bool operator<(Students &s)
	{
		return this->score < s.score;
	}
public:
	string name;
	int score;
};

void createStudent(vector<Students> &v)
{
	char nameArr[7] = "ABCDEF";
	for (int i = 0; i < 6; ++i)
	{
		Students stu;
		stu.score = 0;
		stu.name = "学生";
		stu.name += nameArr[i];
		v.push_back(stu);
	}
}
void setScore(vector<Students> &v)
{
	srand((unsigned)time(NULL));
	//for (vector<Students>::iterator it = v.begin(); it != v.end(); it++)
	for (auto &it : v)//要用引用，不然是局部变量。。。。。。
	{
		deque<int> d1;
		for (int i = 0; i < 10; i++)
		{
			int sco = rand() % 51 + 50;
			d1.push_back(sco);
		}
		sort(d1.begin(),d1.end());//默认升序
		d1.pop_back();
		d1.pop_front();
		int sum = 0;
		for (auto &it : d1)
		{
			sum += it;
		}
		int avr = sum / d1.size();
		//it->score = avr;
		it.score = avr;
	}
}

void showStudents(vector<Students> &v)
{
	sort(v.begin(), v.end());//由小到大
	for (vector<Students>::reverse_iterator rit = v.rbegin(); rit != v.rend(); rit++)
	//for (auto it : v)
	{
		cout << "name:" << (*rit).name << " score:" << (*rit).score << endl;
		//cout << "name:" << it.name << " score:" << it.score << endl;

	}
}
int main()
{
	vector<Students> v;
	createStudent(v);
	setScore(v);
	showStudents(v);
	return 0;
}