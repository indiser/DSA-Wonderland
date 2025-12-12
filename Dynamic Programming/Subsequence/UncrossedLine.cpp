#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution
{
    public:
        // Time Complexity: O(m × n) where m = len(num1), n = len(num2)
        // Space Complexity: O(m × n) for the dp table
        int maxUncrossedLines(vector<int> &num1, vector<int> &num2)
        {
            int m=num1.size(), n=num2.size();
            vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
            for(int i=1; i<=m; i++)
            {
                for(int j=1; j<=n; j++)
                {
                    if(num1[i-1]==num2[j-1])
                        dp[i][j]=dp[i-1][j-1]+1;
                    else
                        dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
                }
            }
            return dp[m][n];
        }
};

int main()
{
    vector<int> num1={1,4,2};
    vector<int> num2={1,2,4};
    Solution s;
    cout<<s.maxUncrossedLines(num1,num2)<<endl;
    return 0;
}