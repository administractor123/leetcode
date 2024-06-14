#include<iostream>
#include<vector>

using namespace std;

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

vector<int> sortedSquares(vector<int>& nums)
{
	int n = nums.size();

	for (int i = n - 1; i >= 0; i--)
	{
		if (nums[i] < 0)
		{
			nums[i] *= nums[i];
			int j = i + 1;
			while (j < n && nums[j - 1] > nums[j])
			{
				swap(&nums[j - 1], &nums[j]);
				j++;
			}
		}
		else
		{
			nums[i] *= nums[i];
		}
	}
	return nums;
}

int main()
{
	vector<int> arr = { -1 };
	vector<int> arr2 = sortedSquares(arr);

	return 0;
}