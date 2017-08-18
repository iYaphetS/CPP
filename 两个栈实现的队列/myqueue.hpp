#pragma once
#include <iostream>
using namespace std;
#include <stack>

class Queue
{
private:
	stack<int> s1;
	stack<int> s2;
public:
	//s1压栈---入队，s1出栈元素到s2入栈， s2出栈----出队
	//入队
	void Queue::Push(const int& val)
	{
		s1.push(val);
	}
	//出队
	void Queue::Pop()
	{
#if 0
		if (s2.size() > 0)
		{
			s2.pop();
		}
		else
		{
			if (s1.size() > 0)
			{
				while (s1.size() > 0)
				{
					int val = s1.top();
					s2.push(val);
					s1.pop();
				}
				s2.pop();
			}

		}
#endif
		if (Empty())
		{
			return;
		}
		if (s2.empty())
		{
			while (!s1.empty())
			{
				s2.push(s1.top());
				s1.pop();
			}
		}
		s2.pop();
	}
	//返回队首元素
	int& Queue::Front()
	{
		//return s2.top();
		if (s2.empty())
		{
			while (!s1.empty())
			{
				s2.push(s1.top());
				s1.pop();
			}
		}
		return s2.top();
	}
	//返回队尾元素
	int& Queue::Back()
	{
#if 0
		if (s1.size() > 0)
		{
			return s1.top();
		}		
		else
		{
			while (s2.size() > 1)
			{
				int val = s2.top();
				s1.push(val);
			}
			int &ret = s2.top();
			for(unsigned int i = 0; i < s2.size() - 1; i++)
			{
				int val = s1.top();
				s2.push(val);
			}
			return ret;
		}
#endif
		if (s1.empty())
		{
			while (!s2.empty())
			{
				s1.push(s2.top());
				s2.pop();
			}
		}	
		return s1.top();
	}
	//判断队列是否为空
	bool Queue::Empty()
	{
#if 0
		if (s1.size() == 0 && s2.size() == 0)
		{
			return true;
		}
#endif
		return s1.empty() && s2.empty();
	}
	//返回队列大小
	int Queue::Size()
	{
		return s1.size() + s2.size();
	}
};