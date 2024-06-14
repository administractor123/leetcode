#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
{
	unordered_map<int, int> interS;
	vector<int> res;
	for (auto it : ((nums1.size() >= nums2.size()) ? nums1 : nums2))
	{
		interS[it]++;
	}

	for (auto it: ((nums1.size() < nums2.size()) ? nums1 : nums2))
	{
		auto temp = interS.find(it);
		if (temp != interS.end())
		{
			if (interS[it] != -1)
				res.push_back(it);
			interS[it] = -1;
		}
	}
	return res;
}