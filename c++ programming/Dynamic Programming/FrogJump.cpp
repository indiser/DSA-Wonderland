// Date: 21/07/2026
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution
{
    public:
        int minCost(vector<int> &height)
        {
            int n = height.size();

            if(n == 1) return 0;

            vector<int> dp(n);

            dp[0] = 0;
            dp[1] = abs(height[1] - height[0]);

            for (int i = 2; i < n; i++)
            {
                dp[i] = min((dp[i - 1] + abs(height[i] - height[i - 1])), (dp[i - 2] + abs(height[i] - height[i - 2])));
            }
            return dp[n - 1];
        }
};

int main()
{
    vector<int> height = {20, 30, 40, 20};
    
    Solution s;
    cout<< s.minCost(height)<< endl;

    return 0;
}