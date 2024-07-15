#include "../head/leetCode.h"
#include <iostream>

using namespace std;

class Solution
{
public:
    int findContentChildren(vector<int>& g, vector<int>& s) 
    {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int idx = s.size() - 1;
        int res = 0;
        for (int i = g.size()-1; i >= 0 ; --i)
        {
            if(idx >= 0 && s[idx] >= g[i])
            {
                res++;
                idx--;
            }
        }

        return res; 
    }
};

int main(int argc, char* argv[])
{
    return 0;
}