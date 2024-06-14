#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

string removeDuplicateLetters(string s)
{
	unordered_map<char, int> map;
	vector<char> stack;
	int size = s.size();
	for (int i = 0; i < size; i++)
	{
		map[s[i]] = s[i];
	}

	for (int i = 0; i < size; i++)
	{
		if (find(stack.begin(), stack.end(), s[i]) != stack.end())
		{
			continue;
		}

		while (!stack.empty() && stack.back() > s[i] && map[stack.back()] > i)
		{
			stack.pop_back();
		}

		stack.push_back(s[i]);
	}

	return string(stack.begin(), stack.end());
}

int main()
{

}