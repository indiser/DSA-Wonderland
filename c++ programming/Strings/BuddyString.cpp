#include <iostream>
#include <set>
#include <unordered_set>
#include <vector>
using namespace std;

// LeetCode-859: Buddy Strings

class Solution
{
public:
    bool buddyString(string s, string goal)
    {
        // method-1
        // int len = s.length();
        // if (len != goal.length())
        // {
        //     return false;
        // }
        // if (s == goal)
        // {
        //     set<char> temp(s.begin(), s.end()); //Filtering out nay duplictes
        //     return temp.size() < s.size();
        // }

        // int i = 0, j = len - 1;
        // while (i < len && s[i] == goal[i])
        // {
        //     i++;
        // }
        // while (j >= 0 && s[j] == goal[j])
        // {
        //     j--;
        // }
        // if (i < j)
        // {
        //     swap(s[i], s[j]);
        // }
        // return s == goal;

        // method-2
        if (s.length() != goal.length())
        {
            return false;
        }

        if (s == goal)
        {
            unordered_set<char> unique_chars(s.begin(), s.end());
            return unique_chars.size() < s.size();
        }

        vector<int> diff_indices;
        for (int i = 0; i < s.length(); ++i)
        {
            if (s[i] != goal[i])
            {
                diff_indices.push_back(i);
            }
        }

        if (diff_indices.size() != 2)
        {
            return false;
        }

        swap(s[diff_indices[0]], s[diff_indices[1]]);
        return s == goal;
    }
};

int main()
{
    string str = "abc";
    string goal = "bca";
    Solution s;
    cout << s.buddyString(str, goal) << endl;
    return 0;
}