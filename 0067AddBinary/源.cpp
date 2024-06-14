#include<iostream>
#include<string>
using namespace std;

string addBinary(string a, string b)
{
	int n1 = a.size();
	int n2 = b.size();
	int isUp = 0;
	string strBin = "";

	int i = 0;
	for (; i < min(n1,n2); i++)
	{
		int n = (a[n1 - i - 1] - '0') + (b[n2 - i - 1] - '0') + isUp;
		if (n == 0 || n == 1)
		{
			char chr = static_cast<char>(n+'0');
			strBin.push_back(chr);
			isUp = 0;
		}
		else
		{
			char chr = static_cast<char>(n - 2+'0');
			strBin.push_back(chr);
			isUp = 1;
		}
	}

	int maxN = max(n1, n2);
	while (i < maxN && n1 == maxN)
	{
		int n = (a[n1 - i - 1] - '0') + isUp;
		if (n == 0 || n == 1)
		{
			char chr = static_cast<char>(n + '0');
			strBin.push_back(chr);
			isUp = 0;
		}
		else
		{
			char chr = static_cast<char>(n - 2 + '0');
			strBin.push_back(chr);
			isUp = 1;
		}
		i++;
	}

	while (i < maxN && n2 == maxN)
	{
		int n = (b[n2 - i - 1] - '0') + isUp;
		if (n == 0 || n == 1)
		{
			char chr = static_cast<char>(n + '0');
			strBin.push_back(chr);
			isUp = 0;
		}
		else
		{
			char chr = static_cast<char>(n - 2 + '0');
			strBin.push_back(chr);
			isUp = 1;
		}
		i++;
	}
	if (isUp==1)
	{
		strBin.push_back('1');
	}

	reverse(strBin.begin(), strBin.end());
	return strBin;
}

int main()
{
	string a = "1110110101";
	string b = "1110111011";
	string c = addBinary(a, b);
	cout << c;
}