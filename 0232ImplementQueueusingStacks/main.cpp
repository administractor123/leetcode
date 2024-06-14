#include<iostream>
#include<stack>

using namespace std;

class MyQueue
{
    stack<int> stackStone;
    stack<int> stackTemp;
    int bottom = 0;
public:
    MyQueue()
    {

    }

    void push(int x)
    {
        if (empty())
        {
            bottom = x;
        }
        stackStone.push(x);
    }

    int pop()
    {
        int n = stackStone.size();
        while (n>1)
        {
            int  temp = stackStone.top();
            stackTemp.push(temp);
            stackStone.pop();
            n--;
        }
        int val = stackStone.top();
        stackStone.pop();

        if (!stackTemp.empty())
            bottom = stackTemp.top();

        while (stackTemp.empty() != true)
        {
            int x = stackTemp.top();
            stackStone.push(x);
            stackTemp.pop();
        }

        return val;
    }

    int peek()
    {
        return bottom;
    }

    bool empty()
    {
        return stackStone.empty();
    }
};
