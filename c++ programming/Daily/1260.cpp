// Date: 20/07/2026
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// Time Complexity: O(n^2)
// Space Complexity: O(n)
class Solution
{
    public:
        vector<vector<int>> shiftGrid(vector<vector<int>> &grid, int k)
        {
            int m = grid.size();
            int n = grid[0].size();

            int total = m * n;

            k %= total;

            vector<vector<int>> ans(m, vector<int>(n));

            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    int oldIndex = i * n + j;
                    int newIndex = (oldIndex + k) % total;

                    int newRow = newIndex / n;
                    int newCol = newIndex % n;

                    ans[newRow][newCol] = grid[i][j];
                }
            }
            return ans;
        }
};

int main()
{
    vector<vector<int>> grid = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int k = 1;

    Solution s;
    vector<vector<int>> result = s.shiftGrid(grid, k);

    for(auto val: result)
    {
        for(auto v : val)
        {
            cout<< v <<" ";
        }
        cout<<endl;
    }

    return 0;
}