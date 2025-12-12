#include<iostream>
#include<set>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

//Time complexity:O(n)
//Space complexity:O(n)

class Solution
{
    public:
        int longestSubstring(string &s)
        {
            int l=0;
            int len=s.length();
            set<int> sett;
            int longest=0;
        
            for (int r = 0; r < len; r++)
            {
                while(sett.count(s[r])) //To check if s[r] is in set
                {
                    sett.erase(s[l]);
                    l++;
                }
                int w=(r-l)+1;
                longest=max(longest,w);
                sett.insert(s[r]);
            }
            return longest; 
        }  
};

int main()
{
    string s="abcabcbb";
    
    Solution lo;
    cout<<lo.longestSubstring(s)<<endl;
    return 0;

}