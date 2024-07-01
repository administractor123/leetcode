#include <iostream>
#include "../head/leetCode.h"

using namespace std;

class Solution
{
private:
    vector<vector<int>> res;
    vector<int> path;

    void combineBT(int n, int k, int start)
    {
        if(path.size() == k)
        {
            res.push_back(path);
            return;
        }

        for (int i = start; i <= n-(k-path.size())+1; i++)
        {
            path.push_back(i);
            combineBT(n, k, i+1);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> combine(int n, int k)
    {
        res.clear();
        path.clear();
        combineBT(n, k, 1);
        return res;
    }
};

int main()
{
    return 0;
}