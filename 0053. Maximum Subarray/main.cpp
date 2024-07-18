#include "../head/leetCode.h"
#include <iostream>

using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int>& nums) 
    {
        int res = INT32_MIN;
        int count = 0;
        for (size_t i = 0; i < nums.size(); i++)
        {
            count += nums[i];
            if(count > res)
                res = count;
            if(count <= 0)
                count = 0;
        }
        return res;
    }
};

int main(int argc, char* argv[])
{
    return 0;
}