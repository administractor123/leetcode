#include<iostream>
#include<vector>
#include<unordered_map>
#include <queue>
using namespace std;

class Solution
{
public:
    class CompareMap
    {
        public:
        bool operator()(const pair<int,int>& left, const pair<int,int>& right)
        {
            return left.second > right.second;
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++)
        {
            map[nums[i]]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, CompareMap> pri_que;

        for (unordered_map<int, int>::iterator it = map.begin(); it != map.end(); it++)
        {
            pri_que.push(*it);
            if (pri_que.size() > k)
            {
                pri_que.pop();
            }
        }

        vector<int> result(k);
        for (int i = k - 1; i >= 0; --i)
        {
            result[i] = pri_que.top().first;
            pri_que.pop();
        }

        return result;
    }
};