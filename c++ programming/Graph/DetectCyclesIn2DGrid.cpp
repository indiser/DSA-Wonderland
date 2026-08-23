// Date: 07/07/2026
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// Time Complexity: O(m * n)
// Space Complexity: O(m * n)
class Solution
{
    public:
        bool helper(vector<vector<char>> &grid, int row, int col,int parentRow, int parentCol, vector<vector<bool>> &visited)
        {
            if(row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size()) return false;

            char target = (parentRow == -1) ? grid[row][col] : grid[parentRow][parentCol];
            if (grid[row][col] != target) return false;
            if (visited[row][col])
            {
                if (row == parentRow && col == parentCol) return false;
                return true;
            }
            visited[row][col] = true;
            if((row + 1 != parentRow || col != parentCol) && helper(grid, row + 1, col, row, col, visited)) return true;
            if((row - 1 != parentRow || col != parentCol) && helper(grid, row - 1, col, row, col, visited)) return true;
            if((row != parentRow || col + 1 != parentCol) && helper(grid, row, col + 1, row, col, visited)) return true;
            if((row != parentRow || col - 1 != parentCol) && helper(grid, row, col - 1, row, col, visited)) return true;
            return false;
        }
        bool containsCycle(vector<vector<char>> &grid)
        {
            int row = grid.size();
            int col = grid[0].size();
            vector<vector<bool>> visited(row, vector<bool>(col, false));

            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < col; j++)
                {
                    if(!visited[i][j])
                    {
                        if(helper(grid,i,j,-1,-1,visited)) return true;
                    }
                }
            }
            return false;
        }
};

int main()
{
    vector<vector<char>> grid ={
        {'a', 'a', 'a', 'a'},
        {'a', 'b', 'b', 'a'},
        {'a', 'b', 'b', 'a'},
        {'a', 'a', 'a', 'a'},
    };

    Solution s;
    if(s.containsCycle(grid)) 
        cout<<"True"<<endl;
    else 
        cout<<"False"<<endl;

    return 0;
}