#include<iostream>
#include<unordered_map>
#include<stack>
using namespace std;

class MinStack
{
public:
	MinStack();
	~MinStack();

	void push(int val)
	{
		this->stack1[this->topSub] = val;
		if (this->minS->empty())
		{
			this->minS->push(val);
		}
		else
		{
			int minN = min(val, this->minS->top());
			this->minS->push(minN);
		}
		this->topSub++;
	}
	
	void pop()
	{
		this->topSub--;
		this->minS->pop();
	}

	int top()
	{
		return this->stack1[--(this->topSub)];
	}

	int getMin()
	{
		return this->minS->top();
	}

private:
	int* stack1;
	int topSub;
	stack<int>* minS;
};

MinStack::MinStack()
{
	this->stack1 = new int[3 * 10000];
	this->topSub = 0;
}

MinStack::~MinStack()
{
	delete[] this->stack1;
	delete[] this;
}


int main()
{
	MinStack* stack = new MinStack();
	stack->push(1);

	return 0;
}