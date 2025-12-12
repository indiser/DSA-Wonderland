#include<iostream>
#include<vector>
#include<unordered_map>
#include<numeric>
#include<algorithm>
using namespace std;

const int INF=numeric_limits<int>::max();

/*
Time Complexity: O(V³)
- V: number of vertices
- Triple nested loops: k, i, j each run V times
- Each iteration does constant work: comparison and addition
- Negative cycle detection: O(V) additional time
- Total: O(V³) + O(V) = O(V³)

Space Complexity: O(V²)
- Distance matrix: O(V²) to store all-pairs distances
- Input adjacency matrix: O(V²) (given)
- No additional space for recursion or auxiliary data structures
- Total auxiliary space: O(V²)
*/
void floydWarshall(vector<vector<int>> &graph)
{
    int n = graph.size();
    vector<vector<int>> dist = graph;

    cout << "\nRunning Floyd-Warshall algorithm..." << endl;
    
    for (int k = 0; k < n; k++)
    {
        cout << "Using vertex " << k << " as intermediate vertex" << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if(dist[i][k] != INF && dist[k][j] != INF)
                {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    // Check for negative cycles
    for (int i = 0; i < n; i++)
    {
        if(dist[i][i] < 0)
        {
            cout << "\nGraph contains a negative-weight cycle!" << endl;
            return;
        }
    }
    
    // Display shortest distances
    cout << "\n=== ALL-PAIRS SHORTEST DISTANCES ===" << endl;
    cout << "     ";
    for(int j = 0; j < n; j++)
        cout << "  " << j << "  ";
    cout << endl;
    
    for (int i = 0; i < n; i++)
    {
        cout << " " << i << " : ";
        for (int j = 0; j < n; j++)
        {
            if(dist[i][j] == INF)
                cout << " INF ";
            else
                cout << " " << dist[i][j] << "  ";
        }
        cout << endl;
    }
}

int main()
{
    cout << "=== Floyd-Warshall All-Pairs Shortest Path ===" << endl;
    
    // Test case 1: Simple weighted graph
    cout << "\nTest Case 1: Simple weighted graph" << endl;
    vector<vector<int>> graph1 = {
        {0, 3, INF, 7},
        {8, 0, 2, INF},
        {5, INF, 0, 1},
        {2, INF, INF, 0}
    };
    
    int n1 = graph1.size();
    cout << "Graph with " << n1 << " vertices" << endl;
    cout << "\nOriginal adjacency matrix:" << endl;
    cout << "     ";
    for(int j = 0; j < n1; j++)
        cout << "  " << j << "  ";
    cout << endl;
    
    for(int i = 0; i < n1; i++)
    {
        cout << " " << i << " : ";
        for(int j = 0; j < n1; j++)
        {
            if(graph1[i][j] == INF)
                cout << " INF ";
            else
                cout << " " << graph1[i][j] << "  ";
        }
        cout << endl;
    }
    
    floydWarshall(graph1);
    
    // Test case 2: Graph with negative edges
    cout << "\n\nTest Case 2: Graph with negative edges" << endl;
    vector<vector<int>> graph2 = {
        {0, -1, 4},
        {INF, 0, 3},
        {INF, INF, 0}
    };
    
    int n2 = graph2.size();
    cout << "Graph with " << n2 << " vertices" << endl;
    cout << "\nOriginal adjacency matrix:" << endl;
    cout << "     ";
    for(int j = 0; j < n2; j++)
        cout << "  " << j << "  ";
    cout << endl;
    
    for(int i = 0; i < n2; i++)
    {
        cout << " " << i << " : ";
        for(int j = 0; j < n2; j++)
        {
            if(graph2[i][j] == INF)
                cout << " INF ";
            else
                cout << " " << graph2[i][j] << "  ";
        }
        cout << endl;
    }
    
    floydWarshall(graph2);
    
    cout << "\nAlgorithm: Finds shortest paths between all pairs of vertices" << endl;
    
    return 0;
}