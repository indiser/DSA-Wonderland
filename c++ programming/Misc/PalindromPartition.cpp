#include<iostream>
#include<vector>
#include<string>
#include<ctype.h>
#include<algorithm>
using namespace std;

//Time Complexity:O(n * 2^n)
//Space Complexity:O(m*n)

class Solution
{
    public:
        bool isPalindrom(string str)
        {
            int len=str.length();
            string temp="";
            for (int i = 0; i < len; i++)
            {
                if(isalnum(str[i]))
                {
                    temp.push_back(str[i]);
                }
            }
            string rev = temp;
            reverse(rev.begin(), rev.end());
            
            return (temp == rev) ? true : false;
        }
        void getAllParts(string str, vector<string> &partition, vector<vector<string>> &ans)
        {

            if(str.empty())
            {
                ans.push_back(partition);
                return;
            }
            for (int i = 0,len = str.length(); i < len; i++)
            {
                string parts=str.substr(0,i+1);
                if(isPalindrom(parts))
                {
                    partition.push_back(parts);
                    getAllParts(str.substr(i+1,len-1),partition,ans);
                    partition.pop_back();
                }
            }
        }
        vector<vector<string>> partition(string str)
        {
            int len=str.length();
            vector<vector<string>> ans;
            vector<string> partition;

            getAllParts(str,partition,ans);
            return ans;
        }
};

int main()
{
    string str="aab";
    Solution s;
    vector<vector<string>> ans=s.partition(str);
    for(const auto& strs:ans)
    {
        for(string val:strs)
        {
            cout<<val<<" ";
        }
        cout<<endl;
    }
    return 0;
}