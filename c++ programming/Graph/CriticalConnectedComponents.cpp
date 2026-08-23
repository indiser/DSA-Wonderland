// Date: 18/07/2026
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// Tarjan's Algorithm
// Time Complexity: O(V + E)
// Space Complexity: O(V + E)
class Solution
{
    public:
        int time;
        vector<int> dt, low;
        void dfs(int u, int parU, vector<vector<int>> &adj, vector<vector<int>> &connections)
        {
            dt[u] = low[u] = ++time;

            for(auto v: adj[u])
            {
                if(dt[v] == -1)
                {
                    dfs(v, u, adj, connections);
                    low[u] = min(low[u], low[v]);

                    if(low[v] > dt[u]) connections.push_back({u, v});
                }
                else if(v != parU) low[u] = min(low[u], dt[v]);
            }
        }
        vector<vector<int>> adjList(int n, vector<vector<int>> &connections)
        {
            vector<vector<int>> adj(n);

            for(auto connection : connections)
            {
                int u = connection[0];
                int v = connection[1];
                adj[u].push_back(v);
                adj[v].push_back(u);
            }

            return adj;
        }
        vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
        {
            vector<vector<int>> adj = adjList(n, connections);
            vector<vector<int>> bridges;
            time = 0;
            dt.resize(n , -1);
            low.resize(n);

            for (int i = 0; i < n; i++)
            {
                if(dt[i] == -1) dfs(i, -1, adj, bridges);
            }
            
            return bridges;
        }
};

int main()
{
    int n = 4;
    vector<vector<int>> connnections = {
        {0, 1},
        {1, 2},
        {2, 0},
        {1, 3}
    };

    Solution s;
    vector<vector<int>> ans = s.criticalConnections(n, connnections);

    for(auto val: ans)
    {
        for(auto v : val)
        {
            cout<< v <<" ";
        }
        cout<<endl;
    }

    return 0;
}