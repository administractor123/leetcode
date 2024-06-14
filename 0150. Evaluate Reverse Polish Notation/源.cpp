#include<stack>
#include<vector>
#include<string>
using namespace std;

int calc(int num1, int num2, string s)
{
	if (s == "+")
		return num1 + num2;
	else if (s == "-")
		return num2 - num1;
	else if (s == "*")
		return num1 * num2;
	else if (s == "/")
		return num2 / num1;
}

int evalRPN(vector<string>& tokens)
{
	stack<int> stCalc;
	for (int i = 0; i < tokens.size(); i++)
	{
		if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
		{
			int num1 = stCalc.top();
			stCalc.pop();
			int num2 = stCalc.top();
			stCalc.pop();
			stCalc.push(calc(num1, num2, tokens[i]));
		}
		else
		{
			stCalc.push(stoi(tokens[i]));
		}
	}

	return stCalc.top();
}