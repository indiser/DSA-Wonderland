#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

/*
Time Complexity: O(V + E)
- V: number of vertices, E: number of edges
- Each vertex is visited once, each edge is traversed twice (once from each end)

Space Complexity: O(V)
- Adjacency list: O(V + E)
- Visited array: O(V)
- DFS recursion depth: O(V) in worst case
*/
class Solution
{
    public:
        vector<vector<int>> adjList(vector<vector<int>> &edges, int n)
        {
            vector<vector<int>> adj(n);
            for(auto edge:edges)
            {
                int u=edge[0];
                int v=edge[1];
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
            return adj;
        }
        bool dfs(int node, vector<vector<int>> &adj, vector<bool> &visited, int parent)
        {
            visited[node]=true;

            for(auto neighbour:adj[node])
            {
                if(!visited[neighbour])
                {
                    if(dfs(neighbour,adj,visited,node))
                        return true;
                }
                else if(neighbour!=parent) return true;
            }
            return false;
        }
        bool hasCycle(vector<vector<int>> &edges)
        {
            int n = 6; // Number of nodes (0 to 5)
            vector<vector<int>> adj = adjList(edges, n);
            vector<bool> visited(n, false);

            for (int i = 0; i < n; i++)
            {
                if(visited[i]==false)
                {
                    if(dfs(i,adj,visited,-1)) return true;
                }
            }
            return false;
        }

};

int main()
{
    vector<vector<int>> edges={{1,2},{2,3},{3,4},{1,4},{1,5}};
    Solution s;
    if(s.hasCycle(edges))
    {
        cout<<"True"<<endl;
    }
    else
    {
        cout<<"False"<<endl;
    }
    return 0;
}