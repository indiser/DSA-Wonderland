// Date: 10/07/2026
#include<iostream>
#include<vector>
#include<unordered_map>
#include<stack>
using namespace std;

// Kosarajus Algorithm
// Time Complexity: O(V + E)
// Space Complexity: O(V + E)
class Solution
{
    public:
        void topologicalDFS(int u, vector<vector<int>> &adj, vector<bool> &visited, stack<int> &st)
        {
            visited[u] = true;
            for(auto neighbour : adj[u])
            {
                if(!visited[neighbour]) topologicalDFS(neighbour, adj, visited, st);
            }
            st.push(u);
        }

        void reverseTopoLogicalDFS(int u, vector<vector<int>> &adj, vector<bool> &visited)
        {
            visited[u] = true;
            for(auto neighbour : adj[u])
            {
                if(!visited[neighbour]) reverseTopoLogicalDFS(neighbour, adj, visited);
            }
        }
        vector<vector<int>> adjList(int V, vector<vector<int>> &edges)
        {
            vector<vector<int>> adj(V);
            for(auto edge: edges)
            {
                int u = edge[0];
                int v = edge[1];
                adj[u].push_back(v);
            }
            return adj;
        }
        int kosaraju(int V, vector<vector<int>> &edges)
        {
            vector<vector<int>> adj = adjList(V, edges);

            vector<bool> visited(V, false);
            stack<int> st;

            // First: Perform normal topological DFS
            for (int i = 0; i < V; i++)
            {
                if(!visited[i]) topologicalDFS(i, adj, visited, st);
            }

            // Second: Reverse The Graph
            vector<vector<int>> revEdges(V);
            for (int u = 0; u < V; u++)
            {
                for(auto v : adj[u])
                {
                    revEdges[v].push_back(u);
                }
            }

            // Third: Perform Normal DFS according to stack elements on reversed graph
            fill(visited.begin(), visited.end(), false);
            int sccCount = 0;

            while(!st.empty())
            {
                int u = st.top();
                st.pop();

                if(!visited[u])
                {
                    reverseTopoLogicalDFS(u, revEdges, visited);
                    sccCount++;
                }
            }
            return sccCount;
        }
};

int main()
{
    int V = 5;
    vector<vector<int> > edges{
        { 1, 3 }, { 1, 4 }, { 2, 1 }, { 3, 2 },
    };

    Solution s;
    cout<< s.kosaraju(V, edges)<< endl;
    return 0;
}