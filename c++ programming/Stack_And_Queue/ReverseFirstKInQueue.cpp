#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<stack>
using namespace std;

// Time Complexity:O(n^2)
// Space Complexity:O(n)
// class Solution //Time limit exceeded.
// {
//     public:
//         queue<int> reverseKElements(queue<int> &q, int k)
//         {
//             queue<int> res;
//             vector<int> vec;

//             if(q.size() < k) return q;

//             while (!q.empty())
//             {
//                 vec.push_back(q.front());
//                 q.pop();
//             }

//             for (int i = 0; i < vec.size(); i++)
//             {
//                 for (int j = i; j < k; j++)
//                 {
//                     swap(vec[i],vec[j]);
//                 }
                
//             }
            
//             for(const auto& val: vec)
//                 res.push(val);
            
//             return res;
            
//         }
// };

// Time Complexity: O(n)
// Space Complexity: O(k)
class Solution
{
    public:
        queue<int> reverseKElements(queue<int> &q, int k)
        {
            if(k <= 0 || k > q.size()) return q;
            
            stack<int> st;
            
            for(int i = 0; i < k; i++)
            {
                st.push(q.front());
                q.pop();
            }
            
            while(!st.empty())
            {
                q.push(st.top());
                st.pop();
            }
            
            for(int i = 0; i < q.size() - k; i++)
            {
                q.push(q.front());
                q.pop();
            }
            
            return q;
        }
};


int main()
{
    queue<int> qe;
    int k=3;
    qe.push(1);
    qe.push(2);
    qe.push(3);
    qe.push(4);
    qe.push(5);
    Solution s;

    queue<int> result=s.reverseKElements(qe,k);
    while(!result.empty())
    {
        cout<<qe.front()<<endl;
        qe.pop();
    }
    return 0;
}