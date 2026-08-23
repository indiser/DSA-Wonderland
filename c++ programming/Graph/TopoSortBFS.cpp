// Date: 17/07/2026
#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;

// Kahn's Algorithm
// Time Complexity: O(E + V)
// Space Complexity: O(V)
class Solution
{
    public:
        unordered_map<int, vector<int>> adj;    //Adjacenecy List
        vector<int> topoSort(int V, vector<vector<int>> &edges)
        {
            for(auto &edge : edges)
            {
                adj[edge[0]].push_back(edge[1]);
            }

            vector<int> ans;
            vector<int> indegree(V, 0);

            for (int u = 0; u < V; u++)
            {
                for(int v : adj[u])
                {
                    indegree[v]++;
                }
            }

            queue<int> q;

            for (int i = 0; i < V; i++)
            {
                if(indegree[i] == 0) q.push(i);
            }
            
            while(!q.empty())
            {
                int curr = q.front();
                q.pop();
                ans.push_back(curr);

                for(auto neighbour: adj[curr])
                {
                    indegree[neighbour]--;
                    if(indegree[neighbour] == 0) q.push(neighbour);
                }
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