#include <iostream>
#include "../head/leetCode.h"

using namespace std;

class Solution
{
private:
    vector<vector<int>> res;
    vector<int> path;

    void permuteBT(vector<int>& nums, int start)
    {
        if(nums.empty())
        {
            res.push_back(path);
            return;
        }

        for (int i = start; i < nums.size(); i++)
        {
            path.push_back(nums[i]);
            vector<int> temp(nums);
            temp.erase(temp.begin() + i);

            permuteBT(temp, 0);

            path.pop_back();
        }
        
    }
public:
    vector<vector<int>> permute(vector<int>& nums) 
    {
        res.clear();
        path.clear();

        permuteBT(nums, 0);

        return res;
    }
};

int main()
{
    return 0;
}