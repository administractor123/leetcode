#include "../head/leetCode.h"
#include <iostream>

using namespace std;

class Solution
{
public:
    int jump(vector<int>& nums)
    {
        int res = 0;
        int lastPos = 0;
        int nextPos = 0;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            nextPos = max(nums[i] + i, nextPos);
            if(i == lastPos)
            {
                lastPos = nextPos;
                ++res;
            }
        }
        return res;
    }
};

int main(int argc, char* argv[])
{
    return 0;
}