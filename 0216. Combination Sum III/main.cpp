#include <iostream>
#include "../head/leetCode.h"

using namespace std;

class Solution
{
private:
    vector<vector<int>> res;
    vector<int> path;
    int sum = 0;
    void combinatinoSum3BT(int k, int n, int start)
    {
        sum = 0;
        for(auto it:path)
        {
            sum+=it;
        }
 
        if(path.size() == k)
        {
            if(sum == n)
                res.push_back(path);
            return;
        }

        for (int i = start; i <= 9; i++)
        {
            path.push_back(i);
            combinatinoSum3BT(k, n, i+1);
            path.pop_back(); 
        }
        
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) 
    {
        res.clear();
        path.clear();
        combinatinoSum3BT(k, n, 1);
        return res; 
    }
};

int main()
{
    return 0;
}