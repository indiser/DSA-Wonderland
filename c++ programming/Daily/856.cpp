// Date: 05/10/2026
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution
{
    public:
        int scoreOfParenthsis(string s)
        {
            int depth = 0;
            int score = 0;

            for (int i = 0; i < s.size(); i++)
            {
                if(s[i] == '(') depth++;
                else
                {
                    depth--;
                    if(s[i-1] == '(')
                        score += 1 << depth;
                }
            }
            return score;
        }
};

int main()
{
    string str = "()()";

    Solution s;
    cout << s.scoreOfParenthsis(str)<< endl;

    return 0;
}