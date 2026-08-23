#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
    public:
        void fill(vector<vector<int>> &board, int row, int col, int originalColor, int newColor)
        {
            if(row<0 || row >= board.size() || col < 0 || col >=board[0].size() || board[row][col] != originalColor)
            {
                return;
            }
            board[row][col]=newColor;
            fill(board,row+1,col,originalColor,newColor);
            fill(board,row-1,col,originalColor,newColor);
            fill(board,row,col+1,originalColor,newColor);
            fill(board,row,col-1,originalColor,newColor);
        }

        vector<vector<int>> solvedBoard(vector<vector<int>> &board, int row, int col, int newColor)
        {
            int originalColor=board[row][col];

            if(board[row][col] != newColor)
            {
                fill(board,row,col,originalColor,newColor);
            }
            return board;
        }
};

int main()
{
    vector<vector<int>> board = {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 1}};

    int startRow = 1;
    int startCol = 1;
    int newColor = 2;

    Solution s;
    s.solvedBoard(board,startRow,startCol,newColor);
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    

    return 0;
}
