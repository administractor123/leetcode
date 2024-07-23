#include "../head/leetCode.h"
#include <iostream>

using namespace std;

class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) 
    {
        if(intervals.empty()) return 0;

        sort(intervals.begin(), intervals.end()
            , [](const vector<int>& left, const vector<int>& right)
            {
                return left[1] < right[1];
            });

        int count = 1;
        int end = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++)
        {
            if(end <= intervals[i][0])
            {
                end = intervals[i][1];
                ++count;
            }
        }
        
        return intervals.size() - count;
    }
};

int main(int argc, char* argv[])
{
    return 0;
}