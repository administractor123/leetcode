#include<iostream>
using namespace std;
#include<vector>

int removeElement(vector<int>& nums, int val)
{
	int n = nums.size();
	int slow = 0;
	for (int fast = 0; fast < n; fast++)
	{
		if (nums[fast] != val)
		{
			nums[slow] = nums[fast];
			++slow;
		}
	}
	return slow;
}

int main()
{
	vector<int> nums = {3};
	int n = removeElement(nums, 2);
	for (int i = 0; i < n; i++)
	{
		cout << nums[i] << " ";
	}
}