#include <iostream>
using namespace std;
#include "myqueue.hpp"


int main()
{
	Queue q;
	q.Push(1);
	q.Push(2); 
	q.Push(3);
	q.Push(4);
	q.Push(5);
	

	cout << q.Front() << endl;
	cout << q.Back() << endl;
	cout << q.Size() << endl;

	q.Pop();
	q.Push(10);
	cout << q.Front() << endl;
	cout << q.Back() << endl;
	cout << q.Size() << endl;

	while (!q.Empty())
	{
		int front = q.Front();
		q.Pop();
		cout << front << " ";
	}
	cout << endl;
	cout << q.Size() << endl;
}