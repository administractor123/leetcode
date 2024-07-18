#include "../head/leetCode.h"
#include <iostream>

using namespace std;

class Solution
{
public:
    bool canJump(vector<int>& nums)
    {
        int lastPos = 0;
        for (size_t i = 0; i <= lastPos; i++)
        {
            int maxPos = i + nums[i];
            if(maxPos > lastPos)
                lastPos = maxPos;
            if(lastPos >= nums.size()-1)
                return true;
        }
        
        return false;
    }
};

int main(int argc, char* argv[])
{
    return 0;
}