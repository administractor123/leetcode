#include<iostream>
#include<queue>
using namespace std;

class MyStack
{
	queue<int> queStone;
	queue<int> queTemp;
public:
	MyStack()
	{

	}

	void push(int x)
	{
		queStone.push(x);
	}

	int pop()
	{
		int n = queStone.size();
		while (n > 1)
		{
			int x = queStone.front();
			queTemp.push(x);
			queStone.pop();

			n--;
		}

		int val = queStone.front();
		queStone.pop();


		while (queTemp.empty() != true)
		{
			int x = queTemp.front();
			queStone.push(x);
			queTemp.pop();
		}

		return val;
	}

	int top()
	{
		return queStone.back();
	}

	bool empty()
	{
		return (queStone.size() == 0) ? true : false;
	}
};

int main()
{
	MyStack* stack1 = new MyStack();
	stack1->push(1);
	stack1->push(2);
	cout << stack1->top() << endl;
	stack1->pop();
	cout << stack1->empty() << endl;

	return 0;
}