#include <iostream>
#include <vector>
#include <unordered_map>
#include <numeric>
#include<limits>
#include<string>
using namespace std;

const int INF = numeric_limits<int>::max();

vector<int> bellmanFord(int V, vector<vector<int>> &edges, int src)
{
    vector<int> dist(V, INF);
    dist[src] = 0;
    
    cout << "\nInitial distances from source " << src << ": ";
    for(int i = 0; i < V; i++)
        cout << (dist[i] == INF ? "INF" : to_string(dist[i])) << " ";
    cout << endl;

    // Relax edges V-1 times
    for (int i = 0; i < V - 1; i++)
    {
        cout << "\nIteration " << i + 1 << ":" << endl;
        bool updated = false;
        
        for (auto edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            if (dist[u] != INF && dist[u] + wt < dist[v])
            {
                cout << "  Relaxing edge (" << u << "," << v << ") weight " << wt;
                cout << ": " << (dist[v] == INF ? "INF" : to_string(dist[v])) << " -> " << dist[u] + wt << endl;
                dist[v] = dist[u] + wt;
                updated = true;
            }
        }
        
        if(!updated)
        {
            cout << "  No updates in this iteration - converged early" << endl;
            break;
        }
    }
    
    // Check for negative cycles
    cout << "\nChecking for negative cycles..." << endl;
    for (auto edge : edges)
    {
        int u = edge[0];
        int v = edge[1];
        int wt = edge[2];

        if (dist[u] != INF && dist[u] + wt < dist[v])
        {
            cout << "Negative cycle detected!" << endl;
            return {-1};
        }
    }
    
    cout << "No negative cycles found." << endl;
    return dist;
}

int main()
{
    cout << "=== Bellman-Ford Single Source Shortest Path ===" << endl;
    
    // Test case 1: Graph without negative cycle
    cout << "\nTest Case 1: Graph without negative cycle" << endl;
    int V1 = 5;
    vector<vector<int>> edges1 = {
        {0, 1, -1}, {0, 2, 4}, {1, 2, 3}, {1, 3, 2},
        {1, 4, 2}, {3, 2, 5}, {3, 1, 1}, {4, 3, -3}
    };
    
    cout << "Graph with " << V1 << " vertices and " << edges1.size() << " edges" << endl;
    cout << "Edges (u, v, weight):" << endl;
    for(auto edge : edges1)
    {
        cout << "  (" << edge[0] << ", " << edge[1] << ", " << edge[2] << ")" << endl;
    }
    
    int source1 = 0;
    cout << "\nRunning Bellman-Ford from source vertex " << source1 << endl;
    
    vector<int> result1 = bellmanFord(V1, edges1, source1);
    
    if(result1.size() == 1 && result1[0] == -1)
    {
        cout << "\nResult: Negative cycle detected!" << endl;
    }
    else
    {
        cout << "\n=== FINAL SHORTEST DISTANCES ===" << endl;
        for(int i = 0; i < V1; i++)
        {
            cout << "Distance from " << source1 << " to " << i << ": ";
            if(result1[i] == INF)
                cout << "UNREACHABLE" << endl;
            else
                cout << result1[i] << endl;
        }
    }
    
    // Test case 2: Graph with negative cycle
    cout << "\n\nTest Case 2: Graph with negative cycle" << endl;
    int V2 = 3;
    vector<vector<int>> edges2 = {
        {0, 1, 1}, {1, 2, -3}, {2, 0, 1}
    };
    
    cout << "Graph with " << V2 << " vertices and " << edges2.size() << " edges" << endl;
    cout << "Edges (u, v, weight):" << endl;
    for(auto edge : edges2)
    {
        cout << "  (" << edge[0] << ", " << edge[1] << ", " << edge[2] << ")" << endl;
    }
    
    int source2 = 0;
    cout << "\nRunning Bellman-Ford from source vertex " << source2 << endl;
    
    vector<int> result2 = bellmanFord(V2, edges2, source2);
    
    if(result2.size() == 1 && result2[0] == -1)
    {
        cout << "\nResult: Negative cycle detected!" << endl;
    }
    else
    {
        cout << "\n=== FINAL SHORTEST DISTANCES ===" << endl;
        for(int i = 0; i < V2; i++)
        {
            cout << "Distance from " << source2 << " to " << i << ": ";
            if(result2[i] == INF)
                cout << "UNREACHABLE" << endl;
            else
                cout << result2[i] << endl;
        }
    }
    
    cout << "\nAlgorithm: Relaxes all edges V-1 times, then checks for negative cycles" << endl;
    cout << "Time Complexity: O(VE), Space Complexity: O(V)" << endl;
    
    return 0;
}