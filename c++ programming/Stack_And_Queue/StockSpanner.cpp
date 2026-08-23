#include<iostream>
#include<vector>
#include<stack>
using namespace std;

// Time Complexity: O(1) amortized per next() call
// Space Complexity: O(n) where n is number of calls
class StockSpanner
{
    stack<pair<int,int>> st;
    public:
        StockSpanner()
        {

        }
        int next(int price)
        {
            int span = 1;
            while(!st.empty() && st.top().first <= price)
            {
                span += st.top().second;
                st.pop();
            }
            st.push({price, span});
            return span;
        }
};

int main()
{
    StockSpanner *ss= new StockSpanner();
    cout << ss->next(100) << endl;
    cout << ss->next(80) << endl;
    cout << ss->next(60) << endl;
    cout << ss->next(70) << endl;
    cout << ss->next(60) << endl;
    cout << ss->next(75) << endl;
    cout << ss->next(85) << endl;
    delete ss;
    return 0;
}

// int main()
// {
//     vector<int> stockspan={100,80,60,70,60,75,85};
//     stack<int> st;
//     vector<int> ans(stockspan.size());

//     for (int i = 0; i < stockspan.size(); i++)
//     {
//         while(!st.empty() && stockspan[st.top()] <= stockspan[i])
//             st.pop();
//         ans[i]=st.empty() ? (i+1) : (i - st.top());
//         st.push(i);
//     }
    
//     for(int val:ans)
//         cout<<val<<" ";
//     return 0;
// }