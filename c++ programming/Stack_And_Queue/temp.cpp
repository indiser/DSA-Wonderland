#include<iostream>
#include<vector>
#include<unordered_map>
#include<stack>
#include<algorithm>
#include<queue>
#include<climits>
#include<cmath>
using namespace std;


int main()
{
    vector<int> stockspan={100,80,60,70,60,75,85};
    stack<int> st;
    vector<int> ans(stockspan.size());

    for (int i = 0; i < stockspan.size(); i++)
    {
        while(!st.empty() && stockspan[st.top()] <= stockspan[i])
            st.pop();
        ans[i]=st.empty() ? (i+1) : (i - st.top());
        st.push(i);
    }
    
    for(int val:ans)
        cout<<val<<" ";
    return 0;
}