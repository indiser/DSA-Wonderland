#include<iostream>
#include<vector>
#include<stack>
#include<string>
using namespace std;

class Solution {

    public:
        bool isValid(string s) {
            stack<char> st;
            int len=s.length();

            for(int i=0;i<len;i++)
            {
                if(s[i]=='(' || s[i]=='{' || s[i]=='[')
                {
                    st.push(s[i]);
                }
                else
                {
                    if(st.empty())
                    {
                        return false;
                    }
                    if(st.top()=='(' && s[i]==')' || st.top()=='{' && s[i]=='}' || st.top()=='[' && s[i]==']')
                    {
                        st.pop();
                    }
                    else
                    {
                        return false;
                    }
                }
            }
            return st.empty();
        }
};

int main()
{
    string s="(){}[]";
    
    Solution st;
    cout<<st.isValid(s);

    return 0;

}