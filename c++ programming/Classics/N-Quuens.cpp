#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

/*
Time Complexity: O(N!)
- In the worst case, we try to place N queens on N rows
- For first row: N choices, second row: (N-1) choices, and so on
- This gives us N × (N-1) × (N-2) × ... × 1 = N! possibilities
- Each isSafe() call takes O(N) time, making it O(N × N!)

Space Complexity: O(N²)
- Board storage: O(N²) for the N×N grid
- Recursion stack: O(N) depth (one call per row)
- Result storage: O(N² × number of solutions)
- Overall: O(N²) for the algorithm itself
*/
class Solution
{
    public:
        bool isSafe(vector<string> &board, int row, int col, int n)
        {
            if(row < 0 || row >= board.size() || col < 0 || col >= board[0].size())
            {
                return false;
            }

            for (int i = 0; i < n; i++)
            {
                if(board[row][i]=='Q')
                {
                    return false;
                }
            }

            for (int i = 0; i < n; i++)
            {
                if(board[i][col]=='Q')
                {
                    return false;
                }
            }

            for (int i = row, j = col; i >= 0 && j >=0; i--,j--)
            {
                if(board[i][j]=='Q')
                {
                    return false;
                }
            }

            for (int i = row, j = col; i >=0 && j <n; i--,j++)
            {
                if(board[i][j]=='Q')
                {
                    return false;
                }
            }
            return true;
        }
        void nQueens(vector<string> &board, int row, int n, vector<vector<string>> &ans)
        {
            if(row==n)
            {
                ans.push_back(board);
            }

            for (int i = 0; i < n; i++)
            {
                if(isSafe(board,row,i,n))
                {
                    board[row][i]='Q';
                    nQueens(board,row+1,n,ans);
                    board[row][i]='.';
                }
            }
            
        }
        vector<vector<string>> solve(int n)
        {
            vector<string> board(n,string(n,'.'));
            vector<vector<string>> ans;

            nQueens(board,0,n,ans);
            return ans;
        }
};


int main()
{
    int n = 2;
    Solution sol;
    vector<vector<string>> result = sol.solve(n);
    
    cout << "Number of solutions: " << result.size() << endl;
    
    for(int i = 0; i < result.size(); i++)
    {
        cout << "Solution " << i + 1 << ":" << endl;
        for(int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j] << endl;
        }
        cout << endl;
    }
    
    return 0;
}