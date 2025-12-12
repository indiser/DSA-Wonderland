#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

//Approach1:Sorting
//Time Complexity:O(nlogn)
//Space Complexity:O(1)
// class Solution
// {
//     public:
//         bool isAnagram(string s, string t)
//         {
//             int len1=s.size();
//             int len2=t.size();

//             if(len1!=len2)
//                 return false;

//             sort(s.begin(),s.end());
//             sort(t.begin(),t.end());

//             return s==t;
//         }
// };


//Frequency counting Method
//Time Complexity:O(n)
//Space Complexity:O(n)
class Solution
{
    public:
        bool isAnagram(string s, string t)
        {
            int len1=s.size();
            int len2=t.size();

            if(len1!=len2)
                return false;

            vector<int> count(26,0);

            for(char c:s)
            {
                count[c-'a']++;
            }
            for(char c:t)
            {
                count[c-'a']--;
            }

            for(int val:count)
            {
                if(val != 0)
                    return false;
            }
            return true;
        }
};
int main()
{
    string s="car";
    string t="rat";
    Solution st;
    cout<<st.isAnagram(s,t)<<endl;
    return 0;
}
