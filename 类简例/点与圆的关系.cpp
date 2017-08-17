#include <iostream>
using namespace std;
#include "circle.h"
#include "point.h"

int main()
{
	point p;//点的实例化
	p.set_x(10);
	p.set_y(20);

	circle c;//圆的实例化
	c.set_mp(5, 6);
	c.set_mr(8);

	c.pointANDcircle(p);
	return 0;
}