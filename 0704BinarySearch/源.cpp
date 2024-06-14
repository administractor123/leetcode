#include<vector>
using namespace std;

int search(vector<int>& nums, int target)
{
	int left = 0;
	int right = nums.size();
	while (left<right)
	{
		int middle = left + ((right - left) >> 1);
		if (nums[middle]>target)
		{
			right = middle;
		}
		else if (nums[middle]<target)
		{
			left = middle + 1;
		}
		else
		{
			return middle;
		}
	}
	return -1;
}

int main()
{
	vector<int> nums = { 1,3,5,7 };
	search(nums, 6);

	return 0;
}