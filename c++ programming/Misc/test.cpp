#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<stack>
using namespace std;

int main()
{
    string s="thm$ g**ood a##t codi*ng";
    string ans="";
    int len=s.length();
    stack<char> st;
    for(int i=0; i<len;i++)
    {
        if(s[i]!='#' && s[i]!='*'&&s[i]!='$')
        {
            st.push(s[i]);
        }
    }

    while(!st.empty())
    {
        ans+=st.top();
        st.pop();
    }
    reverse(ans.begin(),ans.end());
    cout<<ans<<endl;
    return 0;
}