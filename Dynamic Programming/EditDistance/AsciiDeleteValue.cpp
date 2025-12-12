#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution
{
    public:
        int LCS(string s1,string s2)
        {
            int m=s1.size();
            int n=s2.size();
            vector<vector<int>> dp(m+1,vector<int>(n+1,0));

            for (int i = 1; i <= m; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    if(s1[i-1]==s2[j-1])
                    {
                        dp[i][j]=dp[i-1][j-1]+s1[i-1]; // Add ASCII value
                    }
                    else
                    {
                        dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
                    }
                }
            }
            return dp[m][n];
        }
        int AsciiValue(string s)
        {
            int sum=0;
            for (int i = 0; i < s.size(); i++)
            {
                sum+=s[i];
            }
            return sum;
        }
        // Time Complexity: O(m × n) where m = len(s1), n = len(s2)
        // Space Complexity: O(m × n) for the dp table
        int minimumDeleteValue(string s1,string s2)
        {
            int lcs=LCS(s1,s2);
            return (AsciiValue(s1)-lcs)+(AsciiValue(s2)-lcs);
        }
};


int main()
{
    string s1 = "sea";
    string s2 = "eat";
    Solution s;
    cout << s.minimumDeleteValue(s1, s2) << endl;
    return 0;
}
