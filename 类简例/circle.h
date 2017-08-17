#pragma once 
#include <iostream>
using namespace std;
#include "point.h"

class circle
{
public:
	void set_mp(int x, int y);
	void set_mr(int r);
	point& get_mp();
	int get_mr();
	void pointANDcircle(point &p);
private:
	point mp;
	int mr;
};