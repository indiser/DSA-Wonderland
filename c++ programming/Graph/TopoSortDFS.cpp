// Date: 09/07/2026
#include<iostream>
#include<vector>
#include<unordered_map>
#include<stack>
using namespace std;

// Time Complexity: O(E + V)
// Space Complexity: O(E + V)
class Solution
{
    public:
        unordered_map<int, vector<int>> adj;    //Adjacenecy List
        void dfs(int currNode, vector<bool> &visited, stack<int> &s)
        {
            visited[currNode] = true;

            for(auto neighbour : adj[currNode])
            {
                if(!visited[neighbour]) dfs(neighbour, visited, s);
            }
            s.push(currNode);
        }
        vector<int> topoSort(int V, vector<vector<int>> &edges)
        {
            for(auto &edge : edges)
            {
                adj[edge[0]].push_back(edge[1]);
            }

            vector<bool> visited(V, false);
            stack<int> s;

            for (int i = 0; i < V; i++)
            {
                if(!visited[i]) dfs(i, visited, s);
            }

            vector<int> ans;
            while(!s.empty())
            {
                ans.push_back(s.top());
                s.pop();
            }

            return ans;
        }
};

int main()
{
    int V = 6;
    vector<vector<int>> edges = {{5, 2}, {5, 0}, {4, 0}, {4, 1}, {2, 3}, {3, 1}};
    
    Solution s;
    vector<int> result = s.topoSort(V, edges);
    
    for(int node : result)
    {
        cout << node << " ";
    }
    cout << "\n";
    
    return 0;
}