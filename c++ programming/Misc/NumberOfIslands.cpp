#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// Time Complexity: O(m * n)
// Space Complexity: O(m * n)

class Solution
{
    public:
        void helper(vector<vector<char>> &grid, int row, int col, vector<vector<bool>> &visited)
        {
            if(row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || visited[row][col]==true || grid[row][col]=='0')
            {
                return;
            }

            visited[row][col]=true;
            helper(grid, row + 1, col, visited);
            helper(grid, row - 1, col, visited);
            helper(grid, row, col + 1, visited);
            helper(grid, row, col - 1, visited);
        }
        int numOfIslands(vector<vector<char>> &grid)
        {
            int row=grid.size(), col=grid[0].size();
            vector<vector<bool>> visited(row, vector<bool>(col, false));
            int count=0;

            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < col; j++)
                {
                    if(grid[i][j]=='1' && visited[i][j]==false)
                    {
                        helper(grid,i,j,visited);
                        count++;
                    }
                }
            }
            return count;
        }
};

int main()
{
    vector<vector<char>> grid = {
        {'1', '1', '0', '0'},
        {'1', '1', '0', '0'},
        {'0', '0', '1', '0'},
        {'0', '0', '0', '1'},
        {'1', '0', '0', '1'}
    };

    cout << "Grid:" << endl;
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    
    Solution s;
    cout<<"Number Of Islands: "<<s.numOfIslands(grid)<<endl;
}