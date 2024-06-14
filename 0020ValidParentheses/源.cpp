#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool isValid(string s)
{
	stack<char> stack1;
	bool isValid = true;
	for (auto it : s)
	{
		if (it=='{')
		{
			stack1.push('}');
		}
		else if (it=='(')
		{
			stack1.push(')');
		}
		else if (it == '[')
		{
			stack1.push(']');
		}
		else if (it == '}')
		{
			if (stack1.empty()==true|| stack1.top() != '}')
			{
				return false;
			}
			stack1.pop();
		}
		else if (it == ')')
		{
			if ( stack1.empty()==true|| stack1.top() != ')')
			{
				return false;
			}
			stack1.pop();
		}
		else if (it == ']')
		{
			if ( stack1.empty()==true|| stack1.top() != ']')
			{
				return false;
			}
			stack1.pop();
		}
	}
	if (!stack1.empty())
	{
		return false;
	}
	return true;
}