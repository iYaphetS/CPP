#include <iostream>
#include <map>
#include <vector>
#include <deque>
#include <algorithm>
#include <numeric>
#include <ctime>
#include <string>
#include <functional>
using namespace std;


class player
{

public:
	string Name;
	int score[3];
};

void createPlayer(map<int, player> &plist, vector<int> &pid)
{
	string nameseed = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	for (int i = 0; i < 24; i++)
	{
		player temp;
		temp.Name = "选手";
		temp.Name += nameseed[i];

		for (int j = 0; j < 3; j++)
		{
			temp.score[j] = 0;
		}
		int id = 100 + i;
		plist.insert(make_pair(id, temp));
		pid.push_back(id);
	}
}

void drawCuts(vector<int> &pid)
{
	srand((unsigned int)time(NULL));

	random_shuffle(pid.begin(), pid.end());
}

void playerMatch(int round, vector<int> &pid, map<int, player> &plist, vector<int>&uppid)
{
	multimap<int, int, greater<int>> group;
	srand((unsigned int)time(NULL));
	for (vector<int>::iterator it = pid.begin(); it != pid.end(); it++)
	{
		deque<int> sco;
		for (int i = 0; i < 10; i++)
		{
			int n = rand() % 50 + 50;
			sco.push_back(n);
		}
		sco.pop_back();
		sco.pop_front();
		int avg = accumulate(sco.begin(), sco.end(), 0) / sco.size();

		//plist[*it].score[round - 1] = avg;
#if 0
		//完全错误的写法
		map<int, player>::iterator pit = plist.begin();
		pit->second.score[round - 1] = avg;
#endif

		//筛选出晋级选手
		group.insert(make_pair(avg, *it));

		if (group.size() == 6)
		{
			//vector<int>::iterator it = pid.begin();
			multimap<int, int, greater<int>>::iterator it = group.begin();
			for (int i = 0; i < 3; i++)
			{
				uppid.push_back(it->second);
				it++;//******
			}
			group.clear();
		}
	}
}

void showPlayer(int round, vector<int>&uppid, map<int, player> &plist)
{
	cout << "第" << round << "晋级选手的成绩：" << endl;

	for (vector<int>::iterator it = uppid.begin(); it != uppid.end(); it++)
	{
		cout << "name:" << plist[*it].Name << " score:" << plist[*it].score[round - 1] << endl;
	}
	cout << "===============" << endl;
}
int main()
{
	map<int, player> playerlist;
	vector<int> playerid;

	createPlayer(playerlist, playerid);

	int round = 1;
	for (int i = 0; i < 3; i++)
	{
		vector<int> upplayerid;
		drawCuts(playerid);
		playerMatch(round, playerid, playerlist, upplayerid);
		showPlayer(round, upplayerid, playerlist);
		playerid = upplayerid;
		round++;
	}

	return 0;
}