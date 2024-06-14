#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<vector>
using namespace std;

void getNext(vector<int> &next, const string needle)
{
	int j = -1;
	next[0] = -1;
	for (int i = 1; i < needle.size(); i++)
	{
		while (j>=0 && needle[i] != needle[j+1])
		{
			j = next[j];
		}

		if (needle[i] == needle[j + 1])
		{
			j++;
		}
		next[i] = j;
	}
}

int strStr(string haystack, string needle)
{
	vector<int> next(needle.size());
	getNext(next, needle);

	int j = -1;
	for (int i = 0; i < haystack.size(); i++)
	{
		while (j >= 0 && haystack[i] != needle[j + 1])
		{
			j = next[j];
		}

		if (haystack[i] == needle[j + 1])
		{
			j++;
		}

		if (j == needle.size() - 1)
		{
			return i - j;
		}
	}

	return -1;
}

int main()
{
	string haystack = "saodbutsad"
		, needle = "sad";
	int n = strStr(haystack, needle);
	cout << n << endl;
}