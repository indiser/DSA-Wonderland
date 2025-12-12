#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// DFS Approach
/*
Time Complexity: O(V + E)
- V: number of vertices, E: number of edges
- Each vertex is visited once, each edge is traversed once

Space Complexity: O(V)
- Adjacency list: O(V + E)
- Visited array: O(V)
- Recursion stack array: O(V)
- DFS recursion depth: O(V) in worst case
*/
class Solution
{
    public:
        vector<vector<int>> adjList(int V, vector<vector<int>> &graph)
        {
            vector<vector<int>> adj(V);

            for(auto edge:graph)
            {
                int u=edge[0];
                int v=edge[1];
                adj[u].push_back(v);
            }
            return adj;
        }
        bool helper(int node, int V, vector<vector<int>> &adj, vector<bool> &visited, vector<bool> &recStack)
        {
            visited[node]=true;
            recStack[node]=true;

            for(auto neighbour:adj[node])
            {
                if(!visited[neighbour])
                {
                    if(helper(neighbour,V,adj,visited,recStack))
                    {
                        return true;
                    }
                }
                else if(recStack[neighbour]) return true;
            }

            recStack[node]=false;
            return false;
        }
        bool hasCycle(int V,vector<vector<int>> &graph)
        {
            vector<vector<int>> adj=adjList(V,graph);
            vector<bool> visited(V,false);
            vector<bool> recStack(V,false);

            for (int i = 0; i < V; i++)
            {
                if(!visited[i])
                {
                    if(helper(i,V,adj,visited,recStack)) return true;
                }
            }
            return false;
        }
};

int main()
{
    vector<vector<int>> graph={{0,1},{1,2},{2,3},{3,1}}; // Cycle: 1->2->3->1
    int V = 4;
    Solution s;
    if(s.hasCycle(V,graph))
    {
        cout<<"True"<<endl;
    }
    else
    {
        cout<<"False"<<endl;
    }
    return 0;
}