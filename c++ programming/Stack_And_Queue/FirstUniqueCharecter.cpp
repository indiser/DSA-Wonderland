#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;

// Time Complexity: O(n^2) - nested loops for frequency counting
// Space Complexity: O(n) - vector stores at most n unique characters
// class Solution
// {
//     public:
//         int firstUnique(string s)
//         {
//             int len=s.size();
//             char unique;
//             vector<pair<char,int>> mp;

//             for(char c:s)
//             {
//                 bool found=false;
//                 for(auto &p:mp)
//                 {
//                     if(p.first == c)
//                     {
//                         p.second++;
//                         found = true;
//                         break;
//                     }
//                 }
//                 if(!found)
//                     mp.push_back({c,1});
//             }
//             for(const auto& pair : mp)
//             {
//                 if(pair.second == 1)
//                 {
//                     unique=pair.first;
//                     break;
//                 }
//             }
//             for (int i = 0; i < s.size(); i++)
//             {
//                 if(s[i]==unique)
//                 {
//                     return i;
//                     break;
//                 }
            
//             }
//             return -1;
//         }

// };

// Time Complexity: O(n) - two passes through the string
// Space Complexity: O(1) - at most 26 lowercase letters (or 128 ASCII chars)
class Solution
{
    public:
        int firstUnique(string s)
        {
            unordered_map<char, int> freq;
    
            for(char c : s)
                freq[c]++;
    
            for(int i = 0; i < s.size(); i++)
                if(freq[s[i]] == 1)
                    return i;
    
            return -1;
        }

};


int main()
{
    string s="loveleetcode";
    
    Solution sol;
    cout<<"Original: "<<sol.firstUnique(s)<<endl;
    
    return 0;
}
