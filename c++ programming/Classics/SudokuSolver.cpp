#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution
{
    public:
        bool isSafe(vector<vector<char>> &board, int row, int col, char digit)
        {
            for (int i = 0; i < 9; i++)
            {
                if(board[i][col]==digit)
                {
                    return false;
                }
            }
            for (int j = 0; j < 9; j++)
            {
                if(board[row][j]==digit)
                {
                    return false;
                }
            }

            int startRow=(row/3)*3;
            int startCol=(col/3)*3;

            for (int r = startRow; r < startRow+3; r++)
            {
                for (int c = startCol; c < startCol+3; c++)
                {
                    if(board[r][c]==digit)
                    {
                        return false;
                    }
                }
            }
            return true;
        }
        bool helper(vector<vector<char>> &board, int row, int col)
        {
            if(row == 9) return true;
            if(col == 9) return helper(board, row + 1, 0);
            if(board[row][col] != '.') return helper(board, row, col + 1);
            
            for (char digit = '1'; digit <= '9'; digit++)
            {
                if(isSafe(board, row, col, digit))
                {
                    board[row][col] = digit;
                    if(helper(board, row, col + 1))
                        return true;
                    board[row][col] = '.';
                }
            }
            return false;
        }
        void solveSudoku(vector<vector<char>> &board)
        {
            helper(board, 0, 0);
        }
        void printBoard(vector<vector<char>> &board)
        {
            for (int i = 0; i < 9; i++)
            {
                for (int j = 0; j < 9; j++)
                {
                    cout<<board[i][j]<<" ";
                }
                cout<<endl;
            }
            
        }
};

int main()
{
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    
    Solution s;
    s.solveSudoku(board);
    
    s.printBoard(board);
    return 0;
}