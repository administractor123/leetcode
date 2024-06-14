#include<iostream>
#include<string>
#include<vector>
using namespace std;

int myAtoi(string s)
{
	if (s.empty())
		return 0;

	int index = 0,
		n = s.size(),
		sign = 1,
		res = 0,
		bndary = INT_MAX / 10;

	while (index < n && s[index] == ' ')
	{
		++index;
	}

	if (s[index] == '-')
	{
		sign = -1;
	}
	if (s[index] == '-' || s[index] == '+')
	{
		++index;
	}

	for (int j = index; j < n; j++)
	{
		if (!isdigit(s[j]))
		{
			break;
		}

		if (res > bndary || res == bndary && s[j] > '7')
		{
			return (sign == 1) ? INT_MAX : INT_MIN;
		}

		res = res * 10 + (s[j] - '0');
	}
	return sign*res;
}

int main()
{
	string str = "   -4200000000";
	int strInt = myAtoi(str);
	//int strInt = 2147483640, addNum = 8;
	cout << strInt << endl;
}