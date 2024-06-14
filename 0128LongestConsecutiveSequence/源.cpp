#include<iostream>
using namespace std;
#include<vector>
#include<unordered_set>
#include<algorithm>


int longestConsecutive(vector<int>& nums)
{
	int longestCount = 0;
	unordered_set<int> numSet(nums.begin(), nums.end());
	for (auto num : nums)
	{
		if (!numSet.count(num - 1))
		{
			int currentCount = 1;
			int currentNum = num;
			while (numSet.count(currentNum+1))
			{
				++currentNum;
				++currentCount;
			}
			longestCount = max(currentCount, longestCount);
		}
	}
	return longestCount;

}