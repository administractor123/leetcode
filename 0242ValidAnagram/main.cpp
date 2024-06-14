#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

bool isAnagram(string s, string t)
{
	if (s.length() != t.length())
	{
		return false;
	}

	unordered_map<char, int> count;
	for (auto it : s)
	{
		count[it]++;
	}

	for (auto it : t)
	{
		if (count[it] > 0)
		{
			count[it]--;
		}
		else
		{
			return false;
		}
	}

	for (auto& pair : count)
	{
		if (pair.second != 0)
		{
			return false;
		}
	}

	return true;
}