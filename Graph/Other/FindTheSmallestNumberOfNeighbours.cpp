#include<iostream>
#include<vector>
#include<unordered_map>
#include<limits>
using namespace std;

const int INF=numeric_limits<int>::max();

/*
Time Complexity: O(n³)
- n: number of cities
- Distance matrix initialization: O(n²)
- Processing edges: O(E) where E is number of edges
- Floyd-Warshall algorithm: O(n³) - triple nested loops
- Counting neighbors for each city: O(n²)
- Total: O(n³) dominated by Floyd-Warshall

Space Complexity: O(n²)
- Distance matrix: O(n²) to store all-pairs shortest distances
- No additional space for recursion or auxiliary data structures
- Input edges: O(E) space (given, not counted in auxiliary space)
*/
class Solution {
    public:
        int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) 
        {
            // Initialize distance matrix
            vector<vector<int>> dist(n, vector<int>(n, INF));
            
            // Distance from city to itself is 0
            for(int i = 0; i < n; i++)
                dist[i][i] = 0;
            
            // Fill initial distances from edges
            for(auto& edge : edges)
            {
                int u = edge[0], v = edge[1], w = edge[2];
                dist[u][v] = w;
                dist[v][u] = w; // Undirected graph
            }
            
            // Floyd-Warshall algorithm
            for(int k = 0; k < n; k++)
            {
                for(int i = 0; i < n; i++)
                {
                    for(int j = 0; j < n; j++)
                    {
                        if(dist[i][k] != INF && dist[k][j] != INF)
                        {
                            dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                        }
                    }
                }
            }
            
            // Find city with minimum reachable neighbors
            int minNeighbors = n;
            int resultCity = 0;
            
            for(int i = 0; i < n; i++)
            {
                int neighbors = 0;
                for(int j = 0; j < n; j++)
                {
                    if(i != j && dist[i][j] <= distanceThreshold)
                        neighbors++;
                }
                
                if(neighbors <= minNeighbors)
                {
                    minNeighbors = neighbors;
                    resultCity = i;
                }
            }
            
            return resultCity;
        }
};

int main()
{
    cout << "=== Find The City With Smallest Number of Neighbors ===" << endl;
    
    Solution sol;
    
    // Test case 1: Simple network
    cout << "\nTest Case 1: Simple city network" << endl;
    int n1 = 4;
    vector<vector<int>> edges1 = {{0,1,3},{1,2,1},{1,3,4},{2,3,1}};
    int threshold1 = 4;
    
    cout << "Number of cities: " << n1 << endl;
    cout << "Roads (city1, city2, distance):" << endl;
    for(auto edge : edges1)
    {
        cout << "  City " << edge[0] << " <-> City " << edge[1] << " (distance: " << edge[2] << ")" << endl;
    }
    cout << "Distance threshold: " << threshold1 << endl;
    
    int result1 = sol.findTheCity(n1, edges1, threshold1);
    cout << "\nCity with smallest number of reachable neighbors: City " << result1 << endl;
    cout << "Explanation: This city has the fewest neighbors within threshold distance" << endl;
    
    // Test case 2: Larger network
    cout << "\nTest Case 2: Larger city network" << endl;
    int n2 = 5;
    vector<vector<int>> edges2 = {{0,1,2},{0,4,8},{1,2,3},{1,4,2},{2,3,1},{3,4,1}};
    int threshold2 = 2;
    
    cout << "Number of cities: " << n2 << endl;
    cout << "Roads (city1, city2, distance):" << endl;
    for(auto edge : edges2)
    {
        cout << "  City " << edge[0] << " <-> City " << edge[1] << " (distance: " << edge[2] << ")" << endl;
    }
    cout << "Distance threshold: " << threshold2 << endl;
    
    int result2 = sol.findTheCity(n2, edges2, threshold2);
    cout << "\nCity with smallest number of reachable neighbors: City " << result2 << endl;
    cout << "Explanation: With threshold " << threshold2 << ", this city has minimal connections" << endl;
    
    // Test case 3: Disconnected cities
    cout << "\nTest Case 3: Some disconnected cities" << endl;
    int n3 = 6;
    vector<vector<int>> edges3 = {{0,1,10},{0,2,1},{2,3,1},{1,3,1},{1,4,1},{4,5,10}};
    int threshold3 = 20;
    
    cout << "Number of cities: " << n3 << endl;
    cout << "Roads (city1, city2, distance):" << endl;
    for(auto edge : edges3)
    {
        cout << "  City " << edge[0] << " <-> City " << edge[1] << " (distance: " << edge[2] << ")" << endl;
    }
    cout << "Distance threshold: " << threshold3 << endl;
    
    int result3 = sol.findTheCity(n3, edges3, threshold3);
    cout << "\nCity with smallest number of reachable neighbors: City " << result3 << endl;
    cout << "Explanation: High threshold allows most cities to be reachable" << endl;
    
    cout << "\nAlgorithm: Floyd-Warshall for all-pairs shortest paths" << endl;
    cout << "Then count reachable neighbors for each city within threshold" << endl;
    cout << "Returns city with minimum neighbors (highest index if tie)" << endl;
    
    return 0;
}