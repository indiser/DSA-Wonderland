#include<iostream>
#include<string>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;

//Time Complexity:O(n*m)
//Space Complexity:O(1)

class Solution
{
    public:
        bool isFreq(vector<int> &freq1,vector<int> &freq2)
        {
            for (int i = 0; i < 26; i++)
            {
                if(freq1[i] != freq2[i])
                    return false;
            }
            return true;
        }
        bool permutaionString(string s1, string s2)
        {
            int s1len=s1.length();
            int s2len=s2.length();
            vector<int> freq(26,0);

            for(char c:s1)
                freq[c-'a']++;
            
            for (int i = 0; i < s2len; i++)
            {
                int windIdx=0,idx=i;
                vector<int> winFreq(26,0);

                while(windIdx < s1len && idx<s2len)
                {
                    winFreq[s2[idx]-'a']++;
                    windIdx++,idx++;
                }

                if(isFreq(freq,winFreq))
                {
                    return true;
                }
            }
            return false;
            
        }
};

int main()
{
    string s1="ab";
    string s2="eidba000";
    Solution s;
    cout<<s.permutaionString(s1,s2)<<endl;
    return 0;
}