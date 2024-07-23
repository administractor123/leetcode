#include "../head/leetCode.h"
#include <iostream>

using namespace std;

class Solution
{
private:
    static bool cmp(const vector<int>& left, const vector<int>& right)
    {
        if(left[0] == right[0]) return left[1] < right[1];
        return left[0] > right[0];
    }

public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) 
    {
        sort(people.begin(), people.end(), cmp);
        list<vector<int>> que;

        for (int i = 0; i < people.size(); i++)
        {
            int pos = people[i][1];
            list<vector<int>>::iterator it = que.begin();
            while (pos--)
                ++it;
            
            que.insert(it, people[i]);
        }
        return vector<vector<int>>(que.begin(), que.end());
    }
};

int main(int argc, char* argv[])
{
    vector<vector<int>> v1{{7,0}, {4,4}, {7,1}, {5,0}, {6,1}, {5,2}};
    Solution s1;
    auto vv = s1.reconstructQueue(v1);
    
    return 0;
}