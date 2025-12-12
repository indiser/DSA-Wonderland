#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

//Time Complexity:O(n^2)
//Space Complexity:O(n)

// class Solution
// {
//     public:
//         bool isAnagram(string s1, string s2)
//         {
//             int s1len=s1.length();
//             int s2len=s2.length();

//             if(s1len != s2len)
//                 return false;
            
//             vector<int> freq(26,0);


//             for(char c:s1)
//                 freq[c-'a']++;
//             for(char c:s2)
//                 freq[c-'a']--;
            
//             for(int val:freq)
//             {
//                 if(val!=0)
//                     return false;
//             }
//             return true;
//         }
//         vector<vector<string>> groupAnagram(vector<string> &strs)
//         {
//             vector<vector<string>> ans;

//             if(strs.size() == 0)
//                 ans.push_back(vector<string>());
            
            
//             vector<bool> visited(strs.size(), false);

//             for (int i = 0; i < strs.size(); i++)
//             {
//                 if (visited[i]) continue;
//                 vector<string> group;
//                 group.push_back(strs[i]);
//                 visited[i] = true;
//                 for (int j = i + 1; j < strs.size(); j++)
//                 {
//                     if (!visited[j] && isAnagram(strs[i], strs[j]))
//                     {
//                         group.push_back(strs[j]);
//                         visited[j] = true;
//                     }
//                 }
//                 ans.push_back(group);
//             }
//             return ans;
//         }
// };


//Time Complexity:O(n)
//Space Complexity:O(n)

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (const string& s : strs) {
            string key = s;
            sort(key.begin(), key.end());
            mp[key].push_back(s);
        }
        vector<vector<string>> ans;
        for (auto& p : mp) {
            ans.push_back(move(p.second));
        }
        return ans;
    }
};

int main()
{
    vector<string> strs={"eat","tea","tan","ate","nat","bat"};
    // vector<string> strs={""};
    Solution s;
    vector<vector<string>> ans=s.groupAnagrams(strs);
    for(const auto& group : ans)
    {
        for(const auto& str : group)
        {
            cout << str << " ";
        }
        cout << endl;
    }
    return 0;
}