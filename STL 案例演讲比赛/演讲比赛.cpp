#include <iostream>
using namespace std;
#include <vector>
#include <map>
#include <deque>
#include <algorithm>
#include <functional>
#include <numeric>
#include <string>
#include <ctime>
/*
1）某市举行一场演讲比赛（ speech_contest ），共有24个人参加。比赛共三轮，前两轮为淘汰赛，第三轮为决赛。
2）比赛方式：分组比赛，每组6个人；选手每次要随机分组，进行比赛；
第一轮分为4个小组，每组6个人。比如100-105为一组，106-111为第二组，依次类推，
每人分别按照抽签（draw）顺序演讲。当小组演讲完后，淘汰组内排名最后的三个选手，然后继续下一个小组的比赛。
第二轮分为2个小组，每组6人。比赛完毕，淘汰组内排名最后的三个选手，然后继续下一个小组的比赛。
第三轮只剩下6个人，本轮为决赛，选出前三名。
4）比赛评分：10个评委打分，去除最低、最高分，求平均分
每个选手演讲完由10个评委分别打分。该选手的最终得分是去掉一个最高分和一个最低分，求得剩下的8个成绩的平均分。
选手的名次按得分降序排列，若得分一样，按参赛号升序排名。
*/
class player
{
	friend void createPlayer(map<int, player> &plist, vector<int> &pid);
	friend void playerMatch(int round, vector<int> &pid, map<int, player>&plist, vector<int>&uppid);
	friend void showPlayer(int round, map<int, player> &plist, vector<int> &uppid);

private:
	string name;
	int score[3];//分别存储每轮选手的成绩
};
void createPlayer(map<int, player> &plist, vector<int> &pid)
{
	string nameseed = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	for (int i = 0; i < 24; i++)
	{
		player templayer;
		templayer.name = "选手";
		templayer.name += nameseed[i];
		for (int j = 0; j < 3; j++)
		{
			templayer.score[j] = 0;
		}

		int id = 100 + i;
		pid.push_back(id);

		plist.insert(make_pair(id, templayer));	
	}
}
void drawCuts(vector<int> &pid)
{
	srand((unsigned int)time(NULL));
	random_shuffle(pid.begin(), pid.end());
}

void playerMatch(int round, vector<int> &pid, map<int, player>&plist, vector<int>&uppid)
{
	//存储选手的分数和编号，根据分数排序后（默认升序，要自己定义降序）
	//取前三名选手晋级
	multimap<int, int, greater<int>> group;
	srand((unsigned int)time(NULL));
	for (vector<int>::iterator it = pid.begin(); it != pid.end(); it++)
	{
		//为这轮比赛的每个选手打分
		deque<int> sco;
		for (int i = 0; i < 10; i++)
		{
			int n = rand() % 51 + 50;
			sco.push_back(n);
		}
		sco.pop_back();
		sco.pop_front();
		//得到每个选手的平均分
		int avg = accumulate(sco.begin(), sco.end(), 0) / sco.size();
		//将选手的分数存到保存选手信息的容器中
		plist[*it].score[round - 1] = avg;//*****
#if 0
		//完全错误的写法，应该像上面的写法通过编号来找到选手的信息
		map<int, player>::iterator pit = plist.begin();
		pit->second.score[round - 1] = avg;
#endif

		map<int, player>::iterator pit = plist.begin();
		pit->second.score[round - 1] = avg;
		//对选手进行分组,筛选出晋级选手
		/*策略：将选手的分数，编号放在mulitmap中
		当mulitmap的元素的个数满了6个刚好分为一组
		将前三位晋级的选手存到晋级的容器中
		*/
		group.insert(make_pair(avg, *it));

		if (group.size() == 6)//达到六名选手可以分为一组
		{
			multimap<int, int, greater<int>>::iterator it = group.begin();
			for (int i = 0; i < 3; i++)
			{
				//把前三名的选手编号放大晋级容器中
				uppid.push_back(it->second);
				it++;//*********
			}
			group.clear();
		}
	}
}

void showPlayer(int round, map<int, player> &plist, vector<int> &uppid)
{
	cout << "第" << round << "轮晋级选手比赛成绩：" << endl;
	for (auto it : uppid)
	{
		cout << "name:" << plist[it].name << " score:" << plist[it].score[round - 1] << endl;
	}
	cout << "==================" << endl;
}
int main()
{
	//创建24个选手的信息
	map<int, player> playerlist;
	vector<int> playerid;

	createPlayer(playerlist, playerid);

	//参加比赛
	//1------抽签分组（打乱编号,按照顺序每6个分为一组）
	//2------评委打分
	//3------保存晋级选手
	
	//轮数
	int round = 1;

	for (int i = 0; i < 3; i++)
	{
		vector<int> upplayerid;
		drawCuts(playerid);
		playerMatch(round, playerid, playerlist, upplayerid);
		showPlayer(round, playerlist, upplayerid);

		playerid = upplayerid;
		round++;
	}
	
	return 0;
}