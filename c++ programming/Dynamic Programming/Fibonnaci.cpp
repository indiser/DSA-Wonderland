// Date: 19/07/2026
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution
{
    public:
        // Time Complexity: O(2 ^ n)
        int fib(int n)
        {
            if(n == 0) return 0;
            if(n == 1) return 1;

            return fib(n-1) + fib(n-2);
        }

        // Time Complexity: O(n)
        int fibMemoDP(int n, vector<int> &dp)
        {
            if(n == 0) return 0;
            if(n == 1) return 1;

            if(dp[n] != -1) return dp[n];

            return dp[n] = fibMemoDP(n - 1, dp) + fibMemoDP(n - 2, dp);
        }

        // Time Complexity: O(n)
        int fibTabDP(int n)
        {
            if (n <= 1) return n;

            vector<int> dp(n + 1);
            dp[0] = 0;
            dp[1] = 0;

            for (int i = 2; i <= n; i++)
            {
                dp[i] = dp[i - 1] + dp[i - 2];
            }
            return dp[n];
        }
};

int main()
{
    int n = 6;

    Solution s;
    cout<<s.fib(n)<<endl;

    vector<int> dp(n + 1, -1);
    cout<<s.fibMemoDP(n, dp)<<endl;

    cout<<s.fibTabDP(n)<<endl;
    return 0;
}