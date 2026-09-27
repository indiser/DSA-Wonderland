// Date: 27/09/2026
#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<stack>
using namespace std;

// Time Complexity: O(n^2)
// Space Compelxity: O(h)
class Solution
{
    public:
        string reverseParenthesis(string s)
        {
            string result = "";
            stack<int> st;

            for (int i = 0; i < s.size(); i++)
            {
                if(s[i] == '(')
                {
                    st.push(result.length());
                }
                else if(s[i] == ')')
                {
                    int start = st.top();
                    st.pop();

                    reverse(result.begin() + start, result.end());
                }
                else
                {
                    result += s[i];
                }
            }
            return result;
        }
};

// Wormhole Teleportation Technique
// class Solution {
// public:
//     string reverseParentheses(string s) {
//         int n = s.length();
//         stack<int> openParenthesesIndices;
//         vector<int> pair(n);

//         // First pass: Pair up parentheses
//         for (int i = 0; i < n; ++i) {
//             if (s[i] == '(') {
//                 openParenthesesIndices.push(i);
//             }
//             if (s[i] == ')') {
//                 int j = openParenthesesIndices.top();
//                 openParenthesesIndices.pop();
//                 pair[i] = j;
//                 pair[j] = i;
//             }
//         }

//         // Second pass: Build the result string
//         string result;
//         for (int currIndex = 0, direction = 1; currIndex < n;
//              currIndex += direction) {
//             if (s[currIndex] == '(' || s[currIndex] == ')') {
//                 currIndex = pair[currIndex];
//                 direction = -direction;
//             } else {
//                 result += s[currIndex];
//             }
//         }
//         return result;
//     }
// };

int main()
{
    string str = "(u(love)i)";

    Solution s;
    cout << s.reverseParenthesis(str)<< endl;

    return 0;
}