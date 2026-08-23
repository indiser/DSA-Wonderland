#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

// Time Complexity: O(1) - Fixed number of operations (4 comparisons and swaps)
// Space Complexity: O(1) - Only using constant extra space
class Solution
{
    public:
        bool canBeEqual(string s1, string s2)
        {
            if(s1 == s2) return true;
            
            swap(s1[0], s1[2]);
            if(s1 == s2) return true;
            
            swap(s1[1], s1[3]);
            if(s1 == s2) return true;
            
            swap(s1[0], s1[2]);
            if(s1 == s2) return true;
            
            return false;
        }
};

int main()
{
    string s1="abcd";
    string s2="cdab";

    Solution s;
    cout<<s.canBeEqual(s1,s2)<<endl;
    return 0;
}