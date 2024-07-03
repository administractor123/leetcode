#include <iostream>
#include "../head/leetCode.h"

using namespace std;

class Solution
{
private:
    vector<string> res;
    string IP;
    int point;

    bool isSafty(const string& s)
    {
        if(s.empty())
            return false;

        if(s.size() > 1 && s[0] == '0')
            return false;

        long num = stol(s);
        if(num < 0 || num > 255)
            return false;
        
        return true;
    }

    void restoreIPBT(const string& s, int start)
    {
        if(point == 3)
        {
            string strLast = s.substr(start);
            if(isSafty(strLast))
            {
                IP += strLast;    
                res.push_back(IP);
            }

            return;
        }

        for(int i = start; i < s.size(); ++i)
        {
            string str = s.substr(start, i-start+1);
            if(!isSafty(str))
                break;

            int n = IP.size();
            IP += str;
            IP += '.';
            point++;
            restoreIPBT(s, i+1);
            IP.resize(n);
            point--;
        }
    }

public:
    vector<string> restoreIpAddresses(string s) 
    {
        res.clear();
        IP.clear();
        point = 0;

        restoreIPBT(s, 0);

        return res;
    }
};

int main()
{
    return 0;
}