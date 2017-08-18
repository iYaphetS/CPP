#include "circle.h"

void circle::set_mp(int x, int y)
{
	mp.set_x(x);
	mp.set_y(y);
}
void circle::set_mr(int r)
{
	mr = r;
}
point& circle::get_mp()
{
	return mp;
}
int circle::get_mr()
{
	return mr;
}

void circle::pointANDcircle(point &p)
{
	int p2distance = (mp.get_x() - p.get_x()) * (mp.get_x() - p.get_x())
		+ (mp.get_y() - mp.get_y()) * (mp.get_y() - p.get_y());
	int r2distance = mr * mr;

	if (p2distance == r2distance)
	{
		cout << "point(" << p.get_x() << "," << p.get_y() << ")在圆上" << endl;
	}
	else if (p2distance > r2distance)
	{
		cout << "point(" << p.get_x() << "," << p.get_y() << ")在圆外" << endl;
	}
	else
	{
		cout << "point(" << p.get_x() << "," << p.get_y() << ")在圆内" << endl;
	}
}