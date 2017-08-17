#include <iostream>

using namespace std;

void SwapString1(char **p1, char **p2)
{
	char *temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}
void SwapString2(char *&p1, char *&p2)
{
	char *temp = p1;
	p1 = p2;
	p2 = temp;
}
int main()
{
	char *p1 = "hello c!";
	char *p2 = "hello c++";

	//SwapString1(&p1, &p2);
	SwapString2(p1, p2);
	cout << "p1 = " << p1 << "\np2 = " << p2 << endl;
	return 0;
}