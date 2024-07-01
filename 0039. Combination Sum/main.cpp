#include <iostream>
#include "../head/leetCode.h"

using namespace std;

class Solution
{
private:
    vector<vector<int>> res;
    vector<int> path;
    int sum;

    void combSumBT(vector<int>& cand, int target, int start)
    {
        if(sum == target)
        {
            res.push_back(path);
            return;
        }
        
        
        for (int i = start; i < cand.size() && sum+cand[i] <= target; i++)
        {
            sum+=cand[i];
            path.push_back(cand[i]);
            combSumBT(cand, target, i);
            sum-=cand[i];
            path.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)    
    {
        res.clear();
        path.clear();
        sum = 0;
        if(candidates.empty())
        {
            return res;
        }
        sort(candidates.begin(), candidates.end());

        combSumBT(candidates, target, 0);

        return res;
    }
};

int main()
{
    return 0;
}