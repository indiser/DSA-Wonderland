#include<iostream>
#include<vector>
#include<unordered_map>
#include<stack>
using namespace std;


// T.C=O(n)
// S.C=O(n)
int main()
{
    vector<int> arr={6,8,0,1,3};
    stack<int> s;
    vector<int> ans(arr.size(),0);

    for (int i = arr.size()-1; i >= 0; i--)
    {
        while (s.size() > 0 && s.top() <= arr[i])
        {
            s.pop();
        }
        
        if (s.empty())
        {
            ans[i]=-1;
        }
        else
        {
            ans[i]=s.top();
        }
        s.push(arr[i]);
        
    }
    
    for(int i:ans)
    {
        cout<<i<<endl;
    }
    return 0;
}