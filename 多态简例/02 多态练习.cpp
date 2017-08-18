#include <iostream>
using namespace std;
/*
使用多态实现一个图形基类，两个子类：矩形和圆形
基类包含两个抽象方法：周长和面积
子类分别重写这两个方法
另外写一个全局的计算方法，参数为基类指针，传入子类对象时，
输出对应的周长和面积
*/
//图形基类
class graph
{
public:
	//得到周长
	virtual double getgirth() = 0;
	//得到面积
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
	cout << "周长：" << g.getgirth() << endl;
	cout << "面积：" <<g.getarea() << endl;
}
void test()
{
	rectangle rec(3, 7);
	cout << "矩形的信息：" << endl;
	calcgraph(rec);

	circle cir(2, 3, 5);
	cout << "圆的信息：" << endl;
	calcgraph(cir);
}
int main()
{
	test();
	return 0;
}