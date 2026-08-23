// Date: 11/07/2026
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// Time Complexity: O(V + E)
// Space Complexity: O(V)
class Solution
{
    public:
        bool dfs(int node, int color, vector<int> &colors, vector<vector<int>> &adj)
        {
            colors[node] = color;

            for(auto neighbour: adj[node])
            {
                if(colors[neighbour] == -1)
                {
                    if(!dfs(neighbour, 1 - color, colors, adj)) return false;
                }
                else if(colors[neighbour] == color) return false;
            }
            return true;
        }
        bool isBipartite(vector<vector<int>> &graph)
        {
            int V = graph.size();
            vector<int> colors(V, -1);

            for (int i = 0; i < V; i++)
            {
                if(colors[i] == -1)
                {
                    if(!dfs(i, 0, colors, graph)) return false;
                }
            }
            return true;
        }
};

int main()
{
    // 0-indexed graph. 4 vertices, square shape.
    // 0-1, 1-2, 2-3, 3-0. Bipartite.
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 3}, {3, 0}};
    
    // graph size is 4
    vector<vector<int>> graph(4);
    for(auto edge : edges) {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }

    Solution solver;
    if(solver.isBipartite(graph)) {
        cout << "Graph is bipartite" << endl;
    } else {
        cout << "Graph is not bipartite" << endl;
    }

    return 0;
}