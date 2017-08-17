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
1��ĳ�о���һ���ݽ������� speech_contest ��������24���˲μӡ����������֣�ǰ����Ϊ��̭����������Ϊ������
2��������ʽ�����������ÿ��6���ˣ�ѡ��ÿ��Ҫ������飬���б�����
��һ�ַ�Ϊ4��С�飬ÿ��6���ˡ�����100-105Ϊһ�飬106-111Ϊ�ڶ��飬�������ƣ�
ÿ�˷ֱ��ճ�ǩ��draw��˳���ݽ�����С���ݽ������̭����������������ѡ�֣�Ȼ�������һ��С��ı�����
�ڶ��ַ�Ϊ2��С�飬ÿ��6�ˡ�������ϣ���̭����������������ѡ�֣�Ȼ�������һ��С��ı�����
������ֻʣ��6���ˣ�����Ϊ������ѡ��ǰ������
4���������֣�10����ί��֣�ȥ����͡���߷֣���ƽ����
ÿ��ѡ���ݽ�����10����ί�ֱ��֡���ѡ�ֵ����յ÷���ȥ��һ����߷ֺ�һ����ͷ֣����ʣ�µ�8���ɼ���ƽ���֡�
ѡ�ֵ����ΰ��÷ֽ������У����÷�һ����������������������
*/
class player
{
	friend void createPlayer(map<int, player> &plist, vector<int> &pid);
	friend void playerMatch(int round, vector<int> &pid, map<int, player>&plist, vector<int>&uppid);
	friend void showPlayer(int round, map<int, player> &plist, vector<int> &uppid);

private:
	string name;
	int score[3];//�ֱ�洢ÿ��ѡ�ֵĳɼ�
};
void createPlayer(map<int, player> &plist, vector<int> &pid)
{
	string nameseed = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	for (int i = 0; i < 24; i++)
	{
		player templayer;
		templayer.name = "ѡ��";
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
	//�洢ѡ�ֵķ����ͱ�ţ����ݷ��������Ĭ������Ҫ�Լ����彵��
	//ȡǰ����ѡ�ֽ���
	multimap<int, int, greater<int>> group;
	srand((unsigned int)time(NULL));
	for (vector<int>::iterator it = pid.begin(); it != pid.end(); it++)
	{
		//Ϊ���ֱ�����ÿ��ѡ�ִ��
		deque<int> sco;
		for (int i = 0; i < 10; i++)
		{
			int n = rand() % 51 + 50;
			sco.push_back(n);
		}
		sco.pop_back();
		sco.pop_front();
		//�õ�ÿ��ѡ�ֵ�ƽ����
		int avg = accumulate(sco.begin(), sco.end(), 0) / sco.size();
		//��ѡ�ֵķ����浽����ѡ����Ϣ��������
		plist[*it].score[round - 1] = avg;//*****
#if 0
		//��ȫ�����д����Ӧ���������д��ͨ��������ҵ�ѡ�ֵ���Ϣ
		map<int, player>::iterator pit = plist.begin();
		pit->second.score[round - 1] = avg;
#endif

		map<int, player>::iterator pit = plist.begin();
		pit->second.score[round - 1] = avg;
		//��ѡ�ֽ��з���,ɸѡ������ѡ��
		/*���ԣ���ѡ�ֵķ�������ŷ���mulitmap��
		��mulitmap��Ԫ�صĸ�������6���պ÷�Ϊһ��
		��ǰ��λ������ѡ�ִ浽������������
		*/
		group.insert(make_pair(avg, *it));

		if (group.size() == 6)//�ﵽ����ѡ�ֿ��Է�Ϊһ��
		{
			multimap<int, int, greater<int>>::iterator it = group.begin();
			for (int i = 0; i < 3; i++)
			{
				//��ǰ������ѡ�ֱ�ŷŴ����������
				uppid.push_back(it->second);
				it++;//*********
			}
			group.clear();
		}
	}
}

void showPlayer(int round, map<int, player> &plist, vector<int> &uppid)
{
	cout << "��" << round << "�ֽ���ѡ�ֱ����ɼ���" << endl;
	for (auto it : uppid)
	{
		cout << "name:" << plist[it].name << " score:" << plist[it].score[round - 1] << endl;
	}
	cout << "==================" << endl;
}
int main()
{
	//����24��ѡ�ֵ���Ϣ
	map<int, player> playerlist;
	vector<int> playerid;

	createPlayer(playerlist, playerid);

	//�μӱ���
	//1------��ǩ���飨���ұ��,����˳��ÿ6����Ϊһ�飩
	//2------��ί���
	//3------�������ѡ��
	
	//����
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