#include "../head/leetCode.h"
#include <iostream>

using namespace std;

class Solution
{
public:
    int findMinArrowShots(vector<vector<int>>& points)
    {
        int res = 0;
        if(points.empty())
            return res;
        else    
            ++res;

        sort(points.begin(), points.end(), [](const vector<int>& v1, const vector<int>& v2)->bool{
            return v1[0] < v2[0];
        });

        for (int i = 1; i < points.size(); i++)
        {
            if(points[i][0] > points[i - 1][1]) 
                ++res; 
            else
                points[i][1] = min(points[i - 1][1], points[i][1]);

        }
        return res; 
    }
};

int main(int argc, char* argv[])
{
    vector<vector<int>> ps {{1, 3}, {3, 4}, {4, 7}, {8, 9}};
    Solution s1;
    s1.findMinArrowShots(ps);

    return 0;
}