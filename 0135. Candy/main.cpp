#include "../head/leetCode.h"
#include <iostream>

using namespace std;

class Solution
{
public:
    int candy(vector<int>& ratings)
    {
        int n = ratings.size();
        vector<int> candyVec(n, 1);
        for (int i = 1; i < n; ++i)
        {
            if(ratings[i] > ratings[i - 1])
                candyVec[i] = candyVec[i - 1] + 1;
        }

        for (int i = n - 1; i > 0; --i)
        {
            if(ratings[i - 1] > ratings[i] && candyVec[i - 1] <= candyVec[i]) 
                candyVec[i - 1] = candyVec[i] + 1;
        }
        return std::accumulate(candyVec.begin(), candyVec.end(), 0);
    }
};

int main(int argc, char* argv[])
{
    return 0;
}