#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Formula: Catalans Formula
// C(n)=(2n)!/(n+1)!n!

class Solution
{
public:
    void findParethesis(int n, string currentString, int openCount, int closeCount, vector<string> &ans)
    {
        if (currentString.length() == n * 2)
        {
            ans.push_back(currentString);
            return;
        }

        if (openCount < n)
        {
            currentString.push_back('(');
            findParethesis(n, currentString, openCount + 1, closeCount, ans);
            currentString.pop_back();
        }
        if (closeCount < openCount)
        {
            currentString.push_back(')');
            findParethesis(n, currentString, openCount, closeCount + 1, ans);
        }
    }
    vector<string> generateParenthesis(int n)
    {
        string currentString = "";
        vector<string> ans;
        findParethesis(n, currentString, 0, 0, ans);
        return ans;
    }
};

int main()
{
    int n = 3;
    Solution s;
    vector<string> ans = s.generateParenthesis(n);
    for (const auto &val : ans)
    {
        for (auto v : val)
        {
            cout << v << " ";
        }
        cout << endl;
    }
}
