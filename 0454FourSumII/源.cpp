#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4)
{
	int cout = 0;
	int n = nums1.size();
	unordered_map<int, int> map;

	for (auto a:nums1)
	{
		for (auto b:nums2)
		{
			map[a + b]++;
		}
	}

	for (auto c:nums3)
	{
		for (auto d:nums4)
		{
			if (map.find(0 - (c + d)) != map.end())cout += map[0 - (c + d)];
		}
	}

	return cout;
}