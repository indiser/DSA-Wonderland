#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> findMissingRepeatedValues(vector<vector<int>> &grid)
    {
        int n = grid.size();
        unordered_map<int, int> mp;
        vector<int> ans(2);

        for (const auto &row : grid)
        {
            for (int val : row)
            {
                mp[val]++;
            }
        }

        for (int i = 1; i <= n * n; i++)
        {
            if (!mp.count(i))
                ans[1] = i;
            else if (mp[i] == 2)
                ans[0] = i;
        }
        return ans;
    }
};

int main()
{
    vector<vector<int>> grid = {{9, 1, 7}, {8, 9, 2}, {3, 4, 6}};
    Solution s;
    vector<int> ans = s.findMissingRepeatedValues(grid);
    cout << "Missing Value: " << ans[0] << endl;
    cout << "Repeated Value: " << ans[1] << endl;
    return 0;
}