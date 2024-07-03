#include <iostream>
#include "../head/leetCode.h"

using namespace std;

class Solution
{
private:
    vector<int> path;
    vector<vector<int>> res;
    int sum;

    void comSumBT(vector<int>& cand, int target, int start)
    {
        if(sum == target)
        {
            res.push_back(path);
            return;
        }

        for (int i = start; i < cand.size() && sum + cand[i] <= target; i++)
        {
            if(i > start && cand[i] == cand[i-1])
                continue;

            sum += cand[i];
            path.push_back(cand[i]);
            comSumBT(cand, target, i+1);
            path.pop_back();
            sum -= cand[i];
        }
        
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
    {
        res.clear();
        if(candidates.empty())
            return res;

        path.clear();
        sum = 0;
        sort(candidates.begin(), candidates.end());

        comSumBT(candidates, target, 0);

        return res;
    }
};

int main()
{
    return 0;
}