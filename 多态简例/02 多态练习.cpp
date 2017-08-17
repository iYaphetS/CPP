#include <iostream>
using namespace std;
/*
ʹ�ö�̬ʵ��һ��ͼ�λ��࣬�������ࣺ���κ�Բ��
��������������󷽷����ܳ������
����ֱ���д����������
����дһ��ȫ�ֵļ��㷽��������Ϊ����ָ�룬�����������ʱ��
�����Ӧ���ܳ������
*/
//ͼ�λ���
class graph
{
public:
	//�õ��ܳ�
	virtual double getgirth() = 0;
	//�õ����
	virtual double getarea() = 0;
};

class rectangle : public graph
{
public:
	virtual double getgirth()
	{
		return 2 * (len + wid);
	}
	virtual double getarea()
	{
		return len * wid;
	}
	rectangle(double l, double w)
	{
		this->len = l;
		this->wid = w;
	}
private:
	double len;
	double wid;
};

class circle : public graph
{
public:
	virtual double getgirth()
	{
		return 3.14 * 2 * r;
	}
	virtual double getarea()
	{
		return 3.14 * r * r;
	}
	circle(double x, double y, double r)
	{
		this->pointX = x;
		this->pointY = y;
		this->r = r;
	}
private:
	double pointX;
	double pointY;
	double r;
};

void calcgraph(graph &g)
{
	cout << "�ܳ���" << g.getgirth() << endl;
	cout << "�����" <<g.getarea() << endl;
}
void test()
{
	rectangle rec(3, 7);
	cout << "���ε���Ϣ��" << endl;
	calcgraph(rec);

	circle cir(2, 3, 5);
	cout << "Բ����Ϣ��" << endl;
	calcgraph(cir);
}
int main()
{
	test();
	return 0;
}