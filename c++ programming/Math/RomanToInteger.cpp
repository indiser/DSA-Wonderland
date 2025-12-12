#include<iostream>
#include<map>
using namespace std;

// Leetcode-13. Roman to Integer

class Solution 
{
    public:
        int romanToINT(string s)
        {
            map<char,int> mp={{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
            int n=s.size();
            int sum=0;
            for(int i=0;i<n;i++)
            {
                if(mp[s[i]]<mp[s[i+1]])
                {
                    sum+=mp[s[i+1]]-mp[s[i]];
                    i++;
                }
                else
                {
                    sum+=mp[s[i]];
                }
            }
            return sum;
        }
};

int main()
{
    Solution s;
    string str="MCMXCIV";
    cout<<s.romanToINT(str)<<endl;
    return 0;
}
