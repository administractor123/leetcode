#include <iostream>
#include "../head/leetCode.h"

using namespace std;

class Solution
{
private:
    vector<vector<int>> res;
    vector<int> path;

    void subsetsBT(const vector<int>& nums, int start)
    {
        res.push_back(path);
        
        for (int i = start; i < nums.size(); i++)
        {
            path.push_back(nums[i]);
            subsetsBT(nums, i+1);
            path.pop_back(); 
        }
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        res.clear();
        path.clear();

        subsetsBT(nums, 0);

        return res;
    }
};

int main()
{
    return 0;
}