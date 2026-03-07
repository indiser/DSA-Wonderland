#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

// Time Complexity: O(m*n)
// Space Complexity: O(m*n)
class Solution
{
    public:
        string shortestCommonSupersequence(string str1, string str2)
        {
            int len1=str1.size();
            int len2=str2.size();

            vector<vector<int>> dp(len1+1,vector<int>(len2+1,0));
            for (int i = 0; i <= len1; i++)
            {
                dp[i][0]=0;
            }
            for (int j = 0; j <= len2; j++)
            {
                dp[0][j]=0;
            }

            for (int i = 1; i <= len1; i++)
            {
                for (int j = 1; j <= len2; j++)
                {
                    if(str1[i-1]==str2[j-1])
                    {
                        dp[i][j]=1+dp[i-1][j-1];
                    }
                    else
                    {
                        dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                    }
                }
            }

            string ans="";
            int i=len1,j=len2;

            while (i>0 && j>0)
            {
                if(str1[i-1]==str2[j-1])
                {
                    ans+=str1[i-1];
                    i--;
                    j--;
                }
                else if(dp[i-1][j] > dp[i][j-1])
                {
                    ans+=str1[i-1];
                    i--;
                }
                else
                {
                    ans+=str2[j-1];
                    j--;
                }
            }
            while(i>0)
            {
                ans+=str1[i-1];
                i--;
            }
            while(j>0){
                ans+=str2[j-1];
                j--;
            }

            reverse(ans.begin(),ans.end());
            return ans;
        }
};

int main()
{
    string str1="abac";
    string str2="cab";
    Solution s;
    cout<<"The Shortest Common Supersequence is: "<<s.shortestCommonSupersequence(str1,str2)<<endl;
    return 0;
}
