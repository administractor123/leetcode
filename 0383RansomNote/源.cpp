#include<unordered_map>
#include<vector>
using namespace std;

bool canConstruct01(string ransomNote, string magazine)
{
	unordered_map<char, int> map;
	for (auto itM : magazine)
	{
		map[itM]++;
	}

	for (auto itR:ransomNote)
	{
		if (map.find(itR) == map.end()) return false;
		else map[itR]--;
	}

	for (auto itMap:map)
	{
		if (itMap.second < 0)
			return false;
	}
	return true;
}

bool canConstruct(string ransomNote, string magazine)
{
	vector<int> num(26, 0);
	if (ransomNote.size() > magazine.size())
		return false;

	for (auto itM : magazine)
	{
		num[itM-'a']++;
	}
	for (auto itR : ransomNote)
	{
		num[itR - 'a']--;
		if (num[itR - 'a'] < 0)
			return false;
	}

	return true;
}
