// Date: 19/07/2026
#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution
{
    public:
        string smallestSubsequence(string s)
        {
            vector<int> freq(26, 0);
            for (char c : s)
                freq[c - 'a']++;

            vector<bool> inStack(26, false);

            string st;

            for (char c : s) {
                freq[c - 'a']--;

                if (inStack[c - 'a'])
                    continue;

                while (!st.empty() &&
                        st.back() > c &&
                        freq[st.back() - 'a'] > 0) {

                    inStack[st.back() - 'a'] = false;
                    st.pop_back();
                }

                st.push_back(c);
                inStack[c - 'a'] = true;
            }

            return st;
        }
};

int main() 
{
    string str = "bcabc";

    Solution s;
    cout<< s.smallestSubsequence(str) <<endl;

    return 0;
}