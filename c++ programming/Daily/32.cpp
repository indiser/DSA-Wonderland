// Date: 03/10/2026
#include<iostream>
#include<vector>
#include<unordered_map>
#include<stack>
#include<algorithm>
using namespace std;

// Time Compelxity: O(n)
// Space Compelxity: O(n)
class Solution
{
    public:
        int longValidParenthesis(string s)
        {
            int len = s.size();
            stack<int> st;

            if(len < 2) return 0;
            vector<int> dp(len, 0);

            int ans = 0;
            for (int i = 0; i < len; i++)
            {
                if(s[i] == '(') st.push(i);
                else
                {
                    if(!st.empty())
                    {
                        int p = st.top();
                        dp[i] = i - p + 1; // substring s[p:i+1] is valid
                        if(p >= 1) dp[i] += dp[p - 1];
                        st.pop();
                    }
                }
                ans = max(ans, dp[i]);
            }

            return ans;
        }
};

int main()
{
    string str = ")()())";

    Solution s;
    cout << s.longValidParenthesis(str)<< endl;

    return 0;
}