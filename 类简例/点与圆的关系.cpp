#include <iostream>
using namespace std;
#include "circle.h"
#include "point.h"

int main()
{
	point p;//���ʵ����
	p.set_x(10);
	p.set_y(20);

	circle c;//Բ��ʵ����
	c.set_mp(5, 6);
	c.set_mr(8);

	c.pointANDcircle(p);
	return 0;
}