#include <iostream>
using namespace std;
/*
���д���ӻ��࣬���ӻ��п����͹ػ�״̬������������Ƶ����
�ṩ���������ķ�����Ƶ�������ķ��������ڵ��ӻ�ֻ����һ����Ƶ����
����ָ��Ƶ��������ң���࣬ң�������ӵ�е��ӻ����еĹ��ܣ�
�����Ӹ��������̨���ܡ�
*/
class Televation
{
	friend class Rmote;
public:
	enum {off, on};
	enum {minvol, maxvol = 100};
	enum {minchan = 1, maxchan = 255};

	//Ĭ������µĵ��ӵ���������
	Televation()
	{
		Tstatus = off;
		Tvolume = minvol;
		Tchannle = minchan;
	}

	//�򿪵���
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
		cout << "���ӣ�" << (this->Tstatus == on ? "�ѿ���" : "�ѹػ�") << endl;
		cout << "������" << this->Tvolume << endl;
		cout << "Ƶ����" << this->Tchannle << endl;
	}

private:
	int Tstatus;//����״̬
	int Tvolume;//��������
	int Tchannle;//����Ƶ��
};

class Rmote
{
public:
	Rmote(Televation &televation)
	{
		this->_Televation = televation;
	}
	//�򿪵���
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

//���Ӳ���
void test1()
{
	Televation t;
	t.showTelevetion();
	t.statusSet();//����
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
//ң��������
void test2()
{
	Televation t;
	Rmote r(t);
	r.statusSet();//����
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