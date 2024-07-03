#include <iostream>
#include "../head/leetCode.h"

using namespace std;

class Solution
{
private:
    vector<vector<int>> res;
    vector<int> path;

    void findsubsequencesBT(vector<int>& nums, int start)
    {
        if(path.size() >= 2)
            res.push_back(path);
        
        int used[201] = {0};

        for (int i = start; i < nums.size(); i++)
        {
            if(!path.empty() && nums[i] < path.back())
                continue;;
            if(used[nums[i] + 100] == 1)
                continue;
            
            path.push_back(nums[i]);
            used[nums[i] + 100] = 1;
            findsubsequencesBT(nums, i+1);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> findSubsequences(vector<int>& nums) 
    {
        res.clear();
        path.clear();

        findsubsequencesBT(nums, 0);
 
        return res;
    }
};

int main()
{
    return 0;
}