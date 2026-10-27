// Date: 27/10/2026
#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
using namespace std;

// Time Complexity: O(n)
// Space Compelxity: O(n)
class Solution
{
    public:
        vector<string> createGrid(int m, int n)
        {
            vector<string> grid(m);
            grid[0] = string(n , '.');
            string row = string(n - 1, '#') + '.';
            for (int i = 1; i < m; i++)
            {
                grid[i] = row;
            }
            return grid;
        }
};

int main()
{
    int m = 2;
    int n = 3;

    Solution s;
    vector<string> ans = s.createGrid(m, n);

    for(auto val: ans) cout << val << endl;

    return 0;
}