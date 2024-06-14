#include<iostream>
using namespace std;
#include<vector>

int removeDuplicates(vector<int>& nums)
{
	if (nums.size() < 2)
		return nums.size();
	int slow = 2;
	for (int fast = 2; fast < nums.size(); fast++)
	{
		if (nums[fast] != nums[slow - 2])
		{
			nums[slow] = nums[fast];
			++slow;
		}
	}
	return slow;
}

int main()
{

}