#include "../head/leetCode.h"
#include <iostream>

using namespace std;

class Solution
{
public:
    // int largestSumAfterKNegations(vector<int>& nums, int k)
    // {
    //     while (k > 0)
    //     {
    //         auto min = std::min_element(nums.begin(), nums.end());
    //         *min *= -1;
    //         --k;
    //     }
    //     return std::accumulate(nums.begin(), nums.end(), 0);
    // }

    static bool com(int a, int b)
    {
        return abs(a) > abs(b);
    }

    int largestSumAfterKNegations(vector<int>& nums, int k)
    {
        std::sort(nums.begin(), nums.end(), com);
        for (int i = 0; i < nums.size(); i++)
        {
            if(nums[i] < 0 && k > 0)
            {
                nums[i] *= -1;
                --k;
            }
        }

        if(k % 2 == 1)
            nums[nums.size() - 1] *= -1;

        return std::accumulate(nums.begin(), nums.end(), 0);
    }
};

int main(int argc, char* argv[])
{
    return 0;
}