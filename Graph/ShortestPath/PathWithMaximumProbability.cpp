#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<limits>
using namespace std;

/*
Time Complexity: O((V + E) log V)
- V: number of nodes, E: number of edges
- Building adjacency list: O(E)
- Modified Dijkstra with priority queue:
  - Each node extracted from heap at most once: O(V log V)
  - Each edge relaxed at most once: O(E log V)
- Total: O((V + E) log V)

Space Complexity: O(V + E)
- Adjacency list: O(V + E) to store graph
- Probability array: O(V) to track maximum probabilities
- Priority queue: O(V) maximum size
- Total: O(V + E)
*/
class Solution {
public:
    vector<vector<pair<int,double>>> adjList(int n, vector<vector<int>> &edges, vector<double> &succProb)
    {
        vector<vector<pair<int,double>>> adj(n);
        for (int i = 0; i < edges.size(); i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            double wt=succProb[i];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        return adj;
    }
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int,double>>> adj = adjList(n, edges, succProb);
        priority_queue<pair<double,int>> pq; // Max heap for probabilities
        vector<double> dist(n, 0.0);
        
        pq.push({1.0, start_node});
        dist[start_node] = 1.0;

        while(!pq.empty())
        {
            double currentProb = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if(currentProb < dist[u]) continue;
            
            if(u == end_node) return currentProb;

            for(auto neighbor : adj[u])
            {
                int v = neighbor.first;
                double edgeProb = neighbor.second;
                double newProb = currentProb * edgeProb;

                if(newProb > dist[v])
                {
                    dist[v] = newProb;
                    pq.push({newProb, v});
                }
            }
        }
        return dist[end_node];
    }
};

int main()
{
    cout << "=== Path With Maximum Probability ===" << endl;
    
    Solution sol;
    
    // Test case 1: Simple path with multiple routes
    cout << "\nTest Case 1: Multiple paths available" << endl;
    int n1 = 3;
    vector<vector<int>> edges1 = {{0,1},{1,2},{0,2}};
    vector<double> succProb1 = {0.5, 0.5, 0.2};
    int start1 = 0, end1 = 2;
    
    cout << "Graph with " << n1 << " nodes" << endl;
    cout << "Edges with success probabilities:" << endl;
    for(int i = 0; i < edges1.size(); i++)
    {
        cout << "  " << edges1[i][0] << " <-> " << edges1[i][1] << " (prob: " << succProb1[i] << ")" << endl;
    }
    
    cout << "\nFinding path from node " << start1 << " to node " << end1 << endl;
    double result1 = sol.maxProbability(n1, edges1, succProb1, start1, end1);
    cout << "Maximum probability: " << result1 << endl;
    cout << "Explanation: Direct path 0->2 (0.2) vs indirect 0->1->2 (0.5*0.5=0.25)" << endl;
    
    // Test case 2: No path exists
    cout << "\nTest Case 2: Disconnected nodes" << endl;
    int n2 = 3;
    vector<vector<int>> edges2 = {{0,1}};
    vector<double> succProb2 = {0.5};
    int start2 = 0, end2 = 2;
    
    cout << "Graph with " << n2 << " nodes" << endl;
    cout << "Edges with success probabilities:" << endl;
    for(int i = 0; i < edges2.size(); i++)
    {
        cout << "  " << edges2[i][0] << " <-> " << edges2[i][1] << " (prob: " << succProb2[i] << ")" << endl;
    }
    
    cout << "\nFinding path from node " << start2 << " to node " << end2 << endl;
    double result2 = sol.maxProbability(n2, edges2, succProb2, start2, end2);
    cout << "Maximum probability: " << result2 << endl;
    cout << "Explanation: No path exists between nodes 0 and 2" << endl;
    
    // Test case 3: Complex network
    cout << "\nTest Case 3: Complex network" << endl;
    int n3 = 4;
    vector<vector<int>> edges3 = {{0,1},{1,2},{2,3},{0,3},{1,3}};
    vector<double> succProb3 = {0.4, 0.6, 0.8, 0.2, 0.3};
    int start3 = 0, end3 = 3;
    
    cout << "Graph with " << n3 << " nodes" << endl;
    cout << "Edges with success probabilities:" << endl;
    for(int i = 0; i < edges3.size(); i++)
    {
        cout << "  " << edges3[i][0] << " <-> " << edges3[i][1] << " (prob: " << succProb3[i] << ")" << endl;
    }
    
    cout << "\nFinding path from node " << start3 << " to node " << end3 << endl;
    double result3 = sol.maxProbability(n3, edges3, succProb3, start3, end3);
    cout << "Maximum probability: " << result3 << endl;
    cout << "Explanation: Algorithm finds the path with highest probability product" << endl;
    
    cout << "\nAlgorithm: Modified Dijkstra using max-heap for probabilities" << endl;
    cout << "Maximizes probability product instead of minimizing distance sum" << endl;
    
    return 0;
}