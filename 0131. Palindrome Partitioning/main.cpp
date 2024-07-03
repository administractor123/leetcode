#include <iostream>
#include "../head/leetCode.h"

using namespace std;

class Solution
{
private:
    vector<vector<string>> res;
    vector<string> path;

    bool isPalindrome(const string& str)
    {
        string strRe = str;
        reverse(strRe.begin(), strRe.end());
        return (str == strRe) ? true: false;
    }

    void partitionBT(const string& str, int start)
    {
        if(start == str.size())
        {
            res.push_back(path);
            return;
        }

        for (int i = start; i < str.size(); i++)
        {
            string strSub = str.substr(start, i-start+1);
            if(!isPalindrome(strSub))
            {
                continue;
            }

            path.push_back(strSub);
            partitionBT(str, i+1);
            path.pop_back();
        }
    }


public:
    vector<vector<string>> partition(string s)
    {
        res.clear();
        if(s.empty())
            return res;

        path.clear();
        
        partitionBT(s, 0);

        return res;
    }
};

int main()
{
    return 0;
}