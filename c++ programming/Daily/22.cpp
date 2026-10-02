// Date: 02/10/2026
#include<iostream>
#include<vector>
#include<unordered_map>
#include<stack>
using namespace std;

// Time Complexity: O(4^n / sqrt(n))
// Space Complexity: O(n)
class Solution
{
    public:
        vector<string> sol;
        void backTrack(string &temp, int open, int close)
        {
            if(open == 0 && close == 0)
            {
                sol.push_back(temp);
                return;
            }

            if(open > 0)
            {
                temp.push_back('(');
                backTrack(temp, open - 1, close);
                temp.pop_back();
            }
            if(close > open)
            {
                temp.push_back(')');
                backTrack(temp, open, close - 1);
                temp.pop_back();
            }
        }
        vector<string> generateParenthesis(int n)
        {
            string str = "";
            backTrack(str, n, n);
            return sol;
        }
};

int main()
{
    int n = 3;

    Solution s;
    for(auto val: s.generateParenthesis(n)) cout << val<< endl;

    return 0;
}