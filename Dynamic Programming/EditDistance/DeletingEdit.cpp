#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution
{
    public:
        int LCS(string word1,string word2)
        {
            int m=word1.size();
            int n=word2.size();
            vector<vector<int>> dp(m+1,vector<int>(n+1,0));
            for (int i = 1; i <= m; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    if(word1[i-1]==word2[j-1]) dp[i][j]=dp[i-1][j-1]+1;
                    else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
            return dp[m][n];
        }
        // Time Complexity: O(m × n)
        // Space Complexity: O(m × n)
        int minDistance(string word1,string word2)
        {
            int lcs=LCS(word1,word2);
            return (word1.size()-lcs)+(word2.size()-lcs);
        }
};

int main()
{
    string word1="sea";
    string word2="eat";
    Solution s;
    cout<<"Minimum deletions required: "<<s.minDistance(word1,word2)<<endl;
    return 0;
}