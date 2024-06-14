#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string countAndSay(int n)
{
	string prev = "1";
	for (int i = 2; i <= n; i++)
	{
		string curr = "";
		int start = 0;
		int pos = 0;

		while (pos < prev.size())
		{
			while (pos < prev.size() && prev[pos] == prev[start])
			{
				pos++;
			}
			curr += to_string(pos - start) + prev[start];
			start = pos;
		}
		prev = curr;
	}
	return prev;
}

int main()
{
	int n = 4;
	string s = countAndSay(n);
	cout << s;
}