#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
// Levenshtein Distance (Edit Distance)
// Minimum number of single-character edits (insert, delete, replace) needed to transform one string into another

class Solution
{
    public:
        // Time Complexity: O(m × n) where m = len(word1), n = len(word2)
        // Space Complexity: O(m × n) for the dp table
        int minDistance(string word1, string word2)
        {
            int m=word1.size();
            int n=word2.size();

            vector<vector<int>> dp(m+1,vector<int>(n+1,0));

            for (int i = 0; i <= m; i++)
            {
                dp[i][0]=i;
            }
            for (int j = 0; j <= n; j++)
            {
                dp[0][j]=j;
            }
            

            for (int i = 1; i <= m; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    if(word1[i-1]==word2[j-1])
                    {
                        dp[i][j]=dp[i-1][j-1];
                    }
                    else
                    {
                        dp[i][j]=1+min(
                            dp[i][j-1],min(        //Insert
                            dp[i-1][j],         //Remove
                            dp[i-1][j-1])        //Replace
                        );
                    }
                }
                
            }
            return dp[m][n];
            
        }
};

int main()
{
    string word1 = "horse";
    string word2 = "ros";

    
    Solution s;
    cout << "The min Distance is: "<< s.minDistance(word1, word2) << endl;
    return 0;
}