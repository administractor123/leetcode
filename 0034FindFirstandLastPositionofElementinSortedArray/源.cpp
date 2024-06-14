#include<vector>
#include<iostream>

using namespace std;

int searchBegin(vector<int>& nums,int target)
{
	int left = 0;
	int right = nums.size() - 1;

	while (left<=right)
	{
		int mid = left + (right - left >> 1);
		int cmp = target - nums[mid];
		if (cmp<0)
		{
			right = mid - 1;
		}
		else if (cmp>0)
		{
			left = mid + 1;
		}
		else
		{
			if (mid==left||nums[mid-1]<target)
			{
				return mid;
			}
			right = mid - 1;
		}
	}
	return -1;
}

int searchEnd(vector<int>& nums, int target)
{
	int left = 0;
	int right = nums.size() - 1;

	while (left<=right)
	{
		int mid = left + (right - left >> 1);
		int cmp = target - nums[mid];
		if (cmp<0)
		{
			right = mid - 1;
		}
		else if (cmp>0)
		{
			left = mid + 1;
		}
		else
		{
			if (mid==right||nums[mid+1]>target)
			{
				return mid;
			}
			left = mid + 1;
		}
	}
	return -1;
}

vector<int> searchRange(vector<int>& nums, int target)
{
	return vector<int> () = { searchBegin(nums,target),searchEnd(nums,target) };
}

int main()
{
	vector<int> nums = { 1 };
	vector<int> res =searchRange(nums, 1);

	for (auto it:res)
	{
		cout << it << " ";
	}
}