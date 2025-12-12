#include<iostream>
#include<vector>
using namespace std;

class Solution
{
    public:
        bool isSafe(vector<vector<char>> &board,int row, int col)
        {
            for (int c = 0; c < col; c++)
            {
                if(board[row][c]=='Q')
                {
                    return false;
                }
            }
            
            for(int r=row, c=col; r >= 0 && c >= 0 ; r--,c--)
            {
                if(board[r][c]=='Q')
                {
                    return false;
                }
            }
            for(int r=row, c=col; r < board.size() && c >= 0; r++,c--)
            {
                if(board[r][c]=='Q')
                {
                    return false;
                }
            }
            return true;
        }
        bool solve(vector<vector<char>> &board, int col)
        {
            if(col==board.size())
            {
                return true;
            }

            for (int row = 0; row < board.size(); row++)
            {
                if(isSafe(board,row,col))
                {
                    board[row][col]='Q';
                    if(solve(board,col+1))
                    {
                        return true;
                    }
                    board[row][col]='.';
                }
            }
            return false;
            
        }
        
        void printBoard(vector<vector<char>> &board)
        {
            int n = board.size();
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    cout << board[i][j] << " ";
                }
                cout << endl;
            }
            cout << endl;
        }

};

int main()
{
    int n = 8;
    vector<vector<char>> board(n, vector<char>(n,'.'));
    Solution s;
    
    cout << "N-Queens solution for n=" << n << ":" << endl;
    if(s.solve(board, 0))
    {
        s.printBoard(board);
    }
    else
    {
        cout << "No solution exists" << endl;
    }
    
    return 0;
}