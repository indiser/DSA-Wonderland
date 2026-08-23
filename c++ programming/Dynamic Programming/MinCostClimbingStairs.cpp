// Date: 21/07/2026
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


// Time Complxity: O(n)
// Space Complexity: O(n)
class Solution
{
    public:
        int minCostClimbingStairs(vector<int> &cost)
        {
            int n = cost.size();

            if(n == 1) return 0;
            vector<int> dp(n + 1);

            dp[0] = 0;
            dp[1] = 0;

            for (int i = 2; i <= n; i++)
            {
                dp[i] = min((dp[i - 1] + cost[i - 1]), (dp[i - 2] + cost[i - 2]));
            }
            return dp[n];
        }
};

int main()
{
    vector<int> cost = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1}; 
    // vector<int> cost = {10, 15, 20};

    Solution s;
    cout<< s.minCostClimbingStairs(cost)<< endl;
    return 0;
}