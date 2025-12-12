#include <iostream>
#include <vector>
using namespace std;

// Time Complexity:O(9^(n*n))
// Space Complexity:O(n*n)

class Solution
{
    public:
        bool isSafe(vector<vector<char>> &board,int row, int col, char num)
        {
            //coloum
            for (int c = 0; c < 9; c++)
            {
                if(board[row][c]==num)
                {
                    return false;
                }
            }
            //Row
            for (int r = 0; r < 9; r++)
            {
                if(board[r][col]==num)
                {
                    return false;
                }
            }
            //3*3 grid
            for (int r = (row/3)*3; r < (row/3)*3+3; r++)
            {
                for (int c = (col/3)*3; c < (col/3)*3+3; c++)
                {
                    if(board[r][c]==num)
                    {
                        return false;
                    }
                }
            }
            return true;
            
        }

        bool solveSudoku(vector<vector<char>> &board)
        {
            int row=-1,col=-1;
            bool isEmpty=false;

            for (int i = 0; i < 9; i++)
            {
                for (int j = 0; j < 9; j++)
                {
                    if(board[i][j]=='.')
                    {
                        row=i;
                        col=j;
                        isEmpty=true;
                        break;
                    }
                }
                if(isEmpty)
                {
                    break;
                }
            }

            if(!isEmpty)
            {
                return true;
            }

            for (char num = '1'; num <= '9'; num++)
            {
                if(isSafe(board,row,col,num))
                {
                    board[row][col]=num;
                    if(solveSudoku(board))
                    {
                        return true;
                    }
                    board[row][col]='.';
                }
            }
            
            return false;
            
        }
        void printBoard(const vector<vector<char>>& board)
        {
        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                cout << board[i][j] << " ";
            }
            cout << endl;
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

    if(s.solveSudoku(board))
    {
        cout<<"Solved"<<endl;
        s.printBoard(board);
    }
    else
    {
        cout<<"Not Solved"<<endl;
    }
}