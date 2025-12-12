#include <iostream>
#include <vector>
#include <unordered_map>
#include<queue>
#include<utility>
#include<climits>
using namespace std;

/*
Time Complexity: O(V + E)
- V: number of vertices (nodes)
- E: number of edges (red + blue)
- Building adjacency lists: O(E)
- BFS traversal: O(V + E) - each node visited at most twice (once per color)
- Final result calculation: O(V)

Space Complexity: O(V + E)
- Red adjacency list: O(V + red_edges)
- Blue adjacency list: O(V + blue_edges)
- Distance matrix: O(2V) = O(V) for tracking both color states
- BFS queue: O(V) maximum size
*/
class Solution
{
public:
    vector<vector<int>> adjList(int n, vector<vector<int>> &edges)
    {
        vector<vector<int>> adj(n);
        for (auto edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
        }
        return adj;
    }
    vector<int> shortestPath(int n, vector<vector<int>> &redEdges, vector<vector<int>> &blueEdges)
    {
        vector<vector<int>> adjRed = adjList(n, redEdges);
        vector<vector<int>> adjBlue = adjList(n, blueEdges);
        
        // dist[node][color] = distance, color: 0=red, 1=blue
        vector<vector<int>> dist(n, vector<int>(2, -1));
        queue<pair<int, int>> q; // {node, last_color}
        
        // Start from node 0 with both colors
        q.push({0, 0}); // red
        q.push({0, 1}); // blue
        dist[0][0] = dist[0][1] = 0;
        
        while(!q.empty())
        {
            int node = q.front().first;
            int lastColor = q.front().second;
            q.pop();
            
            // Use opposite color edges
            vector<vector<int>>& adj = (lastColor == 0) ? adjBlue : adjRed;
            int nextColor = 1 - lastColor;
            
            for(int neighbor : adj[node])
            {
                if(dist[neighbor][nextColor] == -1)
                {
                    dist[neighbor][nextColor] = dist[node][lastColor] + 1;
                    q.push({neighbor, nextColor});
                }
            }
        }
        
        // Get minimum distance for each node
        vector<int> result(n);
        for(int i = 0; i < n; i++)
        {
            int minDist = INT_MAX;
            if(dist[i][0] != -1) minDist = min(minDist, dist[i][0]);
            if(dist[i][1] != -1) minDist = min(minDist, dist[i][1]);
            result[i] = (minDist == INT_MAX) ? -1 : minDist;
        }
        
        return result;
    }
};

int main()
{
    cout << "=== Shortest Path with Alternating Colors ===" << endl;
    
    Solution sol;
    
    // Test case 1: Only red edges
    cout << "\nTest Case 1:" << endl;
    int n1 = 3;
    vector<vector<int>> redEdges1 = {{0,1},{1,2}};
    vector<vector<int>> blueEdges1 = {};
    
    cout << "Graph with " << n1 << " nodes" << endl;
    cout << "Red edges: ";
    for(auto edge : redEdges1)
        cout << "[" << edge[0] << "," << edge[1] << "] ";
    cout << endl;
    cout << "Blue edges: None" << endl;
    
    cout << "\nNote: With only red edges, alternating paths are limited" << endl;
    cout << "Path 0->1 uses red, but 1->2 would need blue (unavailable)" << endl;
    
    // Test case 2: Mixed red and blue edges  
    cout << "\nTest Case 2:" << endl;
    int n2 = 4;
    vector<vector<int>> redEdges2 = {{0,1},{2,3}};
    vector<vector<int>> blueEdges2 = {{1,2}};
    
    cout << "Graph with " << n2 << " nodes" << endl;
    cout << "Red edges: ";
    for(auto edge : redEdges2)
        cout << "[" << edge[0] << "," << edge[1] << "] ";
    cout << endl;
    
    cout << "Blue edges: ";
    for(auto edge : blueEdges2)
        cout << "[" << edge[0] << "," << edge[1] << "] ";
    cout << endl;
    
    cout << "\nPossible alternating path: 0->(red)->1->(blue)->2->(red)->3" << endl;
    cout << "This creates a valid alternating color sequence" << endl;
    
    cout << "\nAlgorithm Explanation:" << endl;
    cout << "- Uses BFS with state tracking (node, last_edge_color)" << endl;
    cout << "- Must alternate between red and blue edges in path" << endl;
    cout << "- Finds shortest path respecting color alternation constraint" << endl;
    
    return 0;
}