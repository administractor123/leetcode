#include <iostream>
#include "../head/leetCode.h"

using namespace std;

class Solution
{
private:
    vector<vector<int>> res;
    vector<int> path;
    
    void subsetsWithDupBT(vector<int>& nums, int start)
    {
        res.push_back(path);

        for(int i = start; i < nums.size(); ++i)
        {
            if(i > start && nums[i] == nums[i-1])
                continue;
            
            path.push_back(nums[i]);
            subsetsWithDupBT(nums, i+1);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums)
    {
        res.clear();
        path.clear();

        sort(nums.begin(), nums.end());
        subsetsWithDupBT(nums, 0);

        return res;
    }
};

int main()
{
    return 0;
}