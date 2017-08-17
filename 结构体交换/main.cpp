#include <iostream>
using namespace std;

void myswap(void *d1, void *d2, int size)
{
	void *temp = calloc(1, size);
	memcpy(temp, d1, size);
	memcpy(d1, d2, size);
	memcpy(d2, temp, size);
	
	free(temp);
}
struct Person
{
	int id;
	int age;

};
int main()
{
	int a = 10, b = 20;
	double c = 3.14, d = 10.0;

	Person p1 = {1, 10};
	Person p2 = {2, 20};

	int size1 = sizeof(int);
	myswap(&a, &b, size1);
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	int size2 = sizeof(double);
	myswap(&c, &d, size2);
	cout << "c = " << c << endl;
	cout << "d = " << d << endl;

	int size3 = sizeof(Person);
	myswap(&p1, &p2, size3);
	cout << "p1.id = " << p1.id << "\np1.age = " << p1.age <<endl;
	cout << "p2.id = " << p2.id << "\np2.age = " << p2.age << endl;

	return 0;
}