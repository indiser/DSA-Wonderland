// Date: 20/07/2026
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution
{
    public:
        int climbStairs(int n)
        {
            if(n <= 2) return n;
            vector<long long> dp(n+1);

            dp[0] = 1;
            dp[1] = 2;

            for (int i = 2; i <= n; i++)
            {
                dp[i] = dp[i - 1] + dp[i - 2];
            }
            return dp[n -1];
        }
};

int main()
{
    int n = 5;
    Solution s;
    cout<<s.climbStairs(n)<<endl;

    return 0;
}