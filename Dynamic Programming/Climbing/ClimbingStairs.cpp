#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution
{
    public:
        // Time Complexity: O(n) - Single loop iterating n times
        // Space Complexity: O(n) - DP array of size n+1
        int climbStairs(int n)
        {
            vector<long int> dp(n+1);
            dp[0]=1;
            dp[1]=2;

            for (int i = 2; i <= n; i++)
            {
                dp[i]=dp[i-2]+dp[i-1];
            }
            return dp[n-1];
        }
};

int main()
{
    int n=5;
    Solution s;
    cout<<"The Number Of Stairs: "<<s.climbStairs(n)<<endl;;
    return 0;
}