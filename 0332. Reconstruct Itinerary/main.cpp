#include "../head/leetCode.h"
#include <iostream>

using namespace std;

class Solution
{
private:
    unordered_map<string, map<string, int>> targets;
    
    bool findItineraryBT(int ticketsNums, vector<string>& res)
    {
        if(res.size() == ticketsNums + 1)
            return true;

        for(auto& target: targets[res[res.size() - 1]])
        {
            if(target.second > 0)
            {
                res.push_back(target.first);
                target.second--;

                if(findItineraryBT(ticketsNums, res))
                    return true;

                res.pop_back();
                target.second++;
            }
        }
        return false;
    }

public:
    vector<string> findItinerary(vector<vector<string>>& tickets)
    {
        targets.clear();
        vector<string> res;
        for(const vector<string>& vec: tickets)
        {
            targets[vec[0]][vec[1]]++;
        }
        res.push_back("JFK");
        findItineraryBT(tickets.size(), res);

        return res;
    }
};

int main(int argc, char* argv[])
{
    return 0;
}