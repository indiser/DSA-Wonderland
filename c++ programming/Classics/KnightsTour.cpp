#include<iostream>
#include<vector>
using namespace std;

//Time Complexity:O((8)^n^2)
//Space Complexity:O(n^2)

class Solution
{
    public:
        bool isValid(vector<vector<int>> &grid,int row, int col, int n, int expectedValue)
        {
            if(row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] != expectedValue)
            {
                return false;
            }

            if(expectedValue == n*n-1)
            {
                return true;
            }

            if(isValid(grid,row+2,col+1,n,expectedValue+1)) return true;
            if(isValid(grid,row+2,col-1,n,expectedValue+1)) return true;
            if(isValid(grid,row-2,col+1,n,expectedValue+1)) return true;
            if(isValid(grid,row-2,col-1,n,expectedValue+1)) return true;
            if(isValid(grid,row+1,col+2,n,expectedValue+1)) return true;
            if(isValid(grid,row-1,col+2,n,expectedValue+1)) return true;
            if(isValid(grid,row+1,col-2,n,expectedValue+1)) return true;
            if(isValid(grid,row-1,col-2,n,expectedValue+1)) return true;

            return false;

        }
        bool checkValidGrid(vector<vector<int>> &grid)
        {
            if(grid[0][0] != 0)
            {
                return false;
            }

            int n = grid.size();
            return isValid(grid,0,0,n,0);
            
        }
};

int main()
{
    vector<vector<int>> grid={{0,11,16,5,20},{17,4,19,10,15},{12,1,8,21,6},{3,18,23,14,9},{24,13,2,7,22}};
    Solution s;
    cout<<s.checkValidGrid(grid)<<endl;
}