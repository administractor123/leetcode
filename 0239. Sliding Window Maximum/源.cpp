#include<iostream>
#include<vector>
#include<deque>
using namespace std;

class MyQueue
{
public:
	deque<int> que;

	void pop(int value)
	{
		if (!que.empty() && value == que.front())
		{
			que.pop_front();
		}
	}

	void push(int value)
	{
		while (!que.empty() && value>que.back())
		{
			que.pop_back();
		}
		que.push_back(value);
	}

	int front()
	{
		return que.front();
	}
};

class Solution
{
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k)
	{
		MyQueue que;
		vector<int> res;

		for (int i = 0; i < k; i++)
		{
			que.push(nums[i]);
		}

		res.push_back(que.front());

		int n = nums.size();
		for (int i = k; i < n; i++)
		{
			que.pop(nums[i - k]);
			que.push(nums[i]);
			res.push_back(que.front());
		}
		
		return res;
	}
};