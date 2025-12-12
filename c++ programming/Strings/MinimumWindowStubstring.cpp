#include<iostream>
#include<string>
#include<vector>
#include<climits>
#include<unordered_map>
using namespace std;

//Time Complexity:O(m+n)
//Space Complexity:O(1)

class Solution
{
    public:
        string minWindow(string s, string t)
        {
            if(s.empty()||t.empty())
                return "";
            int l=0,r=0,minlen=INT_MAX,ind=-1;
            vector<int> hash(256,0);
            int m=s.length();
            int n=t.length(),count=n;

            for(char c:t)
                hash[c]++;
        
            while(r<m)
            {
                if(hash[s[r++]]-->0)
                {
                    count--;
                }
                while(count==0)
                {
                    if(r-l<minlen)
                    {
                        ind=l;
                        minlen=r-l;
                    }
                    if(hash[s[l++]]++==0)
                    {
                        count++;
                    }
                }
            }
            return minlen==INT_MAX?"":s.substr(ind,minlen);
        }
};

int main()
{
    string s="ADOBECODEBANC";
    string t="ABC";
    Solution st;
    cout<<st.minWindow(s,t)<<endl;
    return 0;
}