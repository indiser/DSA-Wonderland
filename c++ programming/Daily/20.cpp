// Date: 01/10/2026
#include<iostream>
#include<vector>
#include<unordered_map>
#include<stack>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution
{
    public:
        bool isValid(string s)
        {
            stack<char> st;
            for (int i = 0, len = s.size(); i < len; i++)
            {
                if(s[i] == '(' || s[i] == '{' || s[i] == '[') st.push(s[i]);
                else
                {
                    if(st.empty()) return false;
                    else if((s[i]==')' && st.top()=='(') || (s[i]=='}' && st.top()=='{') || (s[i]==']' && st.top()=='[')) st.pop();
                    else return false;
                }
            }
            return st.empty();
        }
};

int main()
{
    string str = "(]";

    Solution s;
    if(s.isValid(str)) cout << "TRUE"<< endl;
    else cout << "FALSE"<< endl;

    return 0;
}