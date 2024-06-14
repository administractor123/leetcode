#include<iostream>
#include<string>
#include<vector>
using namespace std;

void getNext(vector<int>& next, const string s)
{
	int j = -1;
	next[0] = -1;

	for (int i = 1; i < s.size(); i++)
	{
		while (j>=0 && s[i]!=s[j+1])
		{
			j = next[j];
		}

		if (s[i] == s[j + 1])
		{
			j++;
		}
		next[i] = j;
	}
}

bool repeatedSubstringPattern(string s)
{
	vector<int> next(s.size());
	getNext(next, s);

	int len = s.size();
	if (next[len - 1] != -1 && len % (len - (next[len - 1] + 1)) == 0)
		return true;

	return false;
}

int main()
{
	string s = "abcabcabcabc";
	cout << repeatedSubstringPattern(s);

	return 0;
}