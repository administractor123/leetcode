#include<vector>
using namespace std;

int searchInsert(vector<int>& nums, int target)
{
	int left = 0;
	int right = nums.size();
	int mid = left + ((right - left) >> 1);

	while (left<right)
	{
		mid = left + ((right - left) >> 1);
		if (nums[mid] < target)
		{
			left = mid + 1;
		}
		else if (nums[mid] > target)
		{
			right = mid;
		}
		else
		{
			return mid;
		}
	}

	return left;
}