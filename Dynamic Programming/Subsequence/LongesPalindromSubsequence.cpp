#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<string>
using namespace std;

class Solution
{
    public:
        // Time Complexity: O(n²) where n = len(s)
        // Space Complexity: O(n²) for the dp table
        int longestpalindromSub(string s)
        {
            int m=s.size();
            string rev=string(s.rbegin(),s.rend());
            vector<vector<int>> dp(m+1,vector<int>(m+1,0));

            for (int i = 1; i <= m; i++)
            {
                for (int j = 1; j <= m; j++)
                {
                    if(s[i-1]==rev[j-1]) dp[i][j]=dp[i-1][j-1]+1;
                    else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
                
            }
            return dp[m][m];
        }
};

int main()
{
    string s="bbbab";
    Solution sol;
    cout<<sol.longestpalindromSub(s);
    return 0;
}