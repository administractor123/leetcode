#include "../head/leetCode.h"
#include <iostream>

using namespace std;

class Solution
{
private:
    vector<vector<string>> res;

    void solveNQueensBT(vector<string>& path, int pos_y)
    {
        if(pos_y == path.size())
        {
            res.push_back(path);
            return;
        }

        for (int pos_x = 0; pos_x < path.size(); ++pos_x)
        {
            if(isValid(path, pos_x, pos_y) == false)
                continue;

            path[pos_y][pos_x] = 'Q';
            solveNQueensBT(path, pos_y+1);
            path[pos_y][pos_x] = '.';
        }
    }

    bool isValid(const vector<string>& path, int pos_x, int pos_y)
    {
        for(int i = 0; i < pos_y; ++i)
        {
            if(path[i][pos_x] == 'Q')
                return false;
        }

        for (int i=pos_x-1, j=pos_y-1; i>=0 && j>=0; --i, --j)
        {
            if(path[j][i] == 'Q')
                return false;
        }
        
        for(int i=pos_x+1, j=pos_y-1; i<path.size() && j>=0; ++i, --j)
        {
            if(path[j][i] == 'Q')
                return false;
        }

        return true;    
    }

public:
    vector<vector<string>> solveNQueens(int n)
    {
        res.clear();
        string line(n, '.');
        vector<string> board(n, line);
        solveNQueensBT(board, 0);

        return res;
    }
};

int main(int argc, char* argv[])
{
    return 0;
}