#include <iostream>
using namespace std;
/*
请编写电视机类，电视机有开机和关机状态，有音量，有频道，
提供音量操作的方法，频道操作的方法。由于电视机只能逐一调整频道，
不能指定频道，增加遥控类，遥控类除了拥有电视机已有的功能，
再增加根据输入调台功能。
*/
class Televation
{
	friend class Rmote;
public:
	enum {off, on};
	enum {minvol, maxvol = 100};
	enum {minchan = 1, maxchan = 255};

	//默认情况下的电视的三种属性
	Televation()
	{
		Tstatus = off;
		Tvolume = minvol;
		Tchannle = minchan;
	}

	//打开电视
	void statusSet()
	{
		this->Tstatus = this->Tstatus == off ? on : off;
	}

	void volumeUp()
	{
		if (this->Tvolume >= maxvol)
		{
			return;
		}
		this->Tvolume++;
	}
	void volumeDown()
	{
		if (this->Tvolume <= minvol)
		{
			return;
		}
		this->Tvolume--;
	}

	void channleUp()
	{
		if (this->Tchannle >= maxchan)
		{
			return;
		}
		this->Tchannle++;
	}

	void channleDown()
	{
		if (this->Tchannle <= minchan)
		{
			return;
		}
		this->Tchannle--;
	}
	void showTelevetion()
	{
		cout << "电视：" << (this->Tstatus == on ? "已开机" : "已关机") << endl;
		cout << "音量：" << this->Tvolume << endl;
		cout << "频道：" << this->Tchannle << endl;
	}

private:
	int Tstatus;//电视状态
	int Tvolume;//电视音量
	int Tchannle;//电视频道
};

class Rmote
{
public:
	Rmote(Televation &televation)
	{
		this->_Televation = televation;
	}
	//打开电视
	void statusSet()
	{
		this->_Televation.statusSet();
	}

	void volumeUp()
	{
		this->_Televation.volumeUp();
	}
	void volumeDown()
	{
		this->_Televation.volumeDown();
	}

	void channleUp()
	{
		this->_Televation.channleUp();
	}

	void channleDown()
	{
		this->_Televation.channleDown();
	}
	void showTelevetion()
	{
		this->_Televation.showTelevetion();
	}
	void setchannle(int channle)
	{
		this->_Televation.Tchannle = channle;
	}

private:
	Televation  _Televation;
};

//电视操作
void test1()
{
	Televation t;
	t.showTelevetion();
	t.statusSet();//开机
	cout << "------" << endl;
	for (int i = 0; i < 10; i++)
	{
		t.volumeUp();
	}
	for (int i = 0; i < 10; i++)
	{
		t.channleUp();
	}
	t.showTelevetion();
	cout << "------" << endl;
	t.channleDown();
	t.volumeDown();
	t.showTelevetion();
}
//遥控器操作
void test2()
{
	Televation t;
	Rmote r(t);
	r.statusSet();//开机
	cout << "------" << endl;
	for (int i = 0; i < 10; i++)
	{
		r.volumeUp();
	}
	for (int i = 0; i < 10; i++)
	{
		r.channleUp();
	}
	r.showTelevetion();
	cout << "------" << endl;
	r.channleDown();
	r.setchannle(20);
	r.volumeDown();
	r.showTelevetion();

}
int main()
{
	//test1();
	test2();
	return 0;
}