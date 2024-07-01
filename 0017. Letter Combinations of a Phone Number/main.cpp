#include <iostream>
#include "../head/leetCode.h"
#include <cstring>
#include <map>

using namespace std;

class Solution
{
private:
    map<int, string> map; 
    vector<string> res;
    string path;

    void initMap()
    {
        map[2] = "abc";
        map[3] = "def";
        map[4] = "ghi";
        map[5] = "jkl";
        map[6] = "mno";
        map[7] = "pqrs";
        map[8] = "tuv";
        map[9] = "wxyz";
    }

    void letterBT(string digits, int starti)
    {
        if(digits.size() == starti && path.size() == digits.size())
        {
            res.push_back(path);
            return;
        }

        int i, j;
        for ( i = starti; i < digits.size(); i++)
        {
            for ( j = 0; j < map[digits[i]-'0'].size(); j++)
            {
                path.push_back(map[digits[i]-'0'][j]); 
                letterBT(digits, i+1);
                path.pop_back();
            }
            
        }
        
    }


public:
    vector<string> letterCombinations(string digits)
    {
        res.clear();
        if(digits.empty())
            return res;

        path.clear();
        initMap();

        letterBT(digits, 0);

        return res;
    }
};

int main()
{
    return 0;
}