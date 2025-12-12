#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution
{
    public:
        // Time Complexity: O(m × n) where m = len(text1), n = len(text2)
        // Space Complexity: O(m × n) for the dp table
        // int longestCommonSubsequnce(string text1, string text2)
        // {
        //     int len1=text1.size();
        //     int len2=text2.size();

        //     vector<vector<int>> dp(len1+1,vector<int>(len2+1,0));

        //     for (int i = 1; i <= len1; i++)
        //     {
        //         for (int j = 1; j <= len2; j++)
        //         {
        //             if(text1[i-1]==text2[j-1])
        //             {
        //                 dp[i][j]=dp[i-1][j-1]+1;
        //             }
        //             else
        //             {
        //                 dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        //             }
        //         }
                
        //     }
        //     return dp[len1][len2];
        // }
        string longestCommonSubsequnce(string text1, string text2)
        {
            int len1=text1.size();
            int len2=text2.size();

            vector<vector<int>> dp(len1+1,vector<int>(len2+1,0));

            for (int i = 1; i <= len1; i++)
            {
                for (int j = 1; j <= len2; j++)
                {
                    if(text1[i-1]==text2[j-1])
                    {
                        dp[i][j]=dp[i-1][j-1]+1;
                    }
                    else
                    {
                        dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                    }
                }
            }
            int index=dp[len1][len2];
            string lcs(index,'\0');
            int i=len1, j=len2;
            while(i>0 && j>0)
            {
                if(text1[i-1]==text2[j-1])
                {
                    lcs[index-1]=text1[i-1];
                    i--;
                    j--;
                    index--;
                }
                else if(dp[i-1][j]>dp[i][j-1])
                {
                    i--;
                }
                else
                {
                    j--;
                }
            }
            return lcs;
        }

};

int main()
{
    string text1="abcde";
    string text2="ace";
    Solution s;
    // cout<<"The longest Common Subsequence of the string is: "<< s.longestCommonSubsequnce(text1,text2)<<endl;
    cout<<"The longest Common Subsequence of the string is: "<< s.longestCommonSubsequnce(text1, text2)<<endl;
    return 0;
}