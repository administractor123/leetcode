#include<iostream>
#include<string>
using namespace std;

string addStrings(string num1, string num2)
{
	int n1 = num1.size();
	int n2 = num2.size();
	int nMin = min(n1, n2);
	int isUp = 0;
	string res = "";
	int i = 0;
	for (; i < nMin; i++)
	{
		int temp = (num1[n1 - i - 1] - '0') + (num2[n2 - i - 1] - '0') + isUp;
		if (temp >= 10)
		{
			isUp = 1;
			temp -= 10;
		}
		else
		{
			isUp = 0;
		}
		res += static_cast<char>(temp + '0');
	}

	int nMax = max(n1, n2);
	while (i < nMax && n1 == nMax)
	{
		int temp = (num1[n1 - i - 1] - '0')  + isUp;
		if (temp >= 10)
		{
			isUp = 1;
			temp -= 10;
		}
		else
		{
			isUp = 0;
		}
		res += static_cast<char>(temp + '0');
		i++;
	}	
	while (i < nMax && n2 == nMax)
	{
		int temp = (num2[n2 - i - 1] - '0') + isUp;
		if (temp >= 10)
		{
			isUp = 1;
			temp -= 10;
		}
		else
		{
			isUp = 0;
		}
		res += static_cast<char>(temp + '0');
		i++;
	}
	if (isUp)
	{
		res += '1';
	}
	reverse(res.begin(), res.end());
	return res;
}