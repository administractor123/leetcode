#include "../head/leetCode.h"
#include <iostream>

using namespace std;

class Solution
{
public:
    int maxProfit(vector<int>& prices)
    {
        int res = 0;
        for (size_t i = 1; i < prices.size(); i++)
        {
            int count = prices[i] - prices[i-1];
            if(count > 0)
            {
                res += count;
            }
        }
        return res;
    }
};

int main(int argc, char* argv[])
{
    return 0;
}