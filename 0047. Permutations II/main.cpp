#include <iostream>
#include "../head/leetCode.h"

using namespace std;

class Solution
{
private:
    vector<vector<int>> res;
    vector<int> path;

    void permuteUniqueBT(vector<int>& nums, vector<bool>& used)
    {
        if(path.size() == nums.size())
        {
            res.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); ++i)
        {
            if(i>0 && nums[i] == nums[i-1] && used[i-1] == false)
                continue;
            
            if(used[i] == false)
            {
                used[i] = true;
                path.push_back(nums[i]);

                permuteUniqueBT(nums, used);

                path.pop_back();
                used[i] = false;
            }
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums)
    {
        res.clear();
        path.clear();
        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end());

        permuteUniqueBT(nums, used);

        return res;
    }
};

int main()
{
    return 0;
}