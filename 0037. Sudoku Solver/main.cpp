#include "../head/leetCode.h"
#include <iostream>

using namespace std;

class Solution
{
private:
    bool solveSudokuBT(vector<vector<char>>& board)
    {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if(board[i][j] == '.')
                {
                    for (char k = '1'; k <= '9'; k++)
                    {
                        if(isValid(board, i, j, k))     
                        {
                            board[i][j] = k;
                            if(solveSudokuBT(board))
                                return true;
                            board[i][j] = '.';
                        }
                    }//for-k

                    return false;
                }

            }//for-j
            
        }//for-i
        return true;
    }

    bool isValid(const vector<vector<char>>& board, int pos_y, int pos_x, char val)
    {
        for (int i = 0; i < 9; i++)
        {
            if(board[pos_y][i] == val)
                return false;
        }

        for (int i = 0; i < 9; i++)
        {
            if(board[i][pos_x] == val)
                return false;
        }
        
        int startPos_y = (pos_y / 3) * 3;
        int startPos_x = (pos_x / 3) * 3;
        for (int i = startPos_y; i < startPos_y + 3; i++)
        {
            for (int j = startPos_x; j < startPos_x+3; j++)
            {
                if(board[i][j] == val)
                    return false;
            }
        }
        
        return true;
    }

public:
    void solveSudoku(vector<vector<char>>& board) 
    {
        solveSudokuBT(board);
    }
};

int main(int argc, char* argv[])
{
    return 0;
}