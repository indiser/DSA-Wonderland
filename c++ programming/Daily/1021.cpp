// Date: 08/10/2026
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution
{
    public:
        string removeOutmostParenthesis(string s)
        {
            int level = 0;
            string res;
            for(char c: s)
            {
                if(c == ')') level--;
                if(level) res.push_back(c);
                if(c == '(') level++;
            }
            return res;
        }
};

int main()
{
    string str = "(()())(())";

    Solution s;
    cout << s.removeOutmostParenthesis(str)<< endl;

    return 0;
}