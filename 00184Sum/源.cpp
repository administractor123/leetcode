#include<vector>
#include<iostream>
#include <algorithm>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target)
{
	vector<vector<int>> res;
	sort(nums.begin(), nums.end());
	int n = nums.size();

	for (int i = 0; i < n; i++)
	{
		if (nums[i] > target && nums[i] >= 0)
			break;
		
		if (i > 0 && nums[i] == nums[i - 1]) continue;

		for (int j = i + 1; j < n; j++)
		{
			if (nums[i] + nums[j] > target && nums[i] + nums[j] >= 0)
				break;

			if (j > i + 1 && nums[j] == nums[j - 1]) continue;

			int left = j + 1, right = n - 1;
			while (left<right)
			{
				if ((long)nums[i] + nums[j] + nums[left] + nums[right] > target) right--;
				else if ((long)nums[i] + nums[j] + nums[left] + nums[right] < target) left++;
				else
				{
					res.push_back(vector<int>{nums[i], nums[j], nums[left], nums[right]});

					while (left < right && nums[left] == nums[left + 1]) left++;
					while (left < right && nums[right] == nums[right - 1]) right--;

					left++;
					right--;
				}
			}
		}
	}
	return res;
}