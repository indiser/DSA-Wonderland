#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<climits>
using namespace std;

/*
Time Complexity: O(K * E)
- K: maximum number of stops allowed
- E: number of flights (edges)
- BFS runs for at most K+1 levels (0 to K stops)
- Each level processes all edges once in worst case
- Total: O(K * E)

Space Complexity: O(V + E)
- V: number of cities (vertices)
- E: number of flights (edges)
- Adjacency list: O(V + E)
- Distance array: O(V)
- BFS queue: O(V) maximum size
*/
class Solution
{
    public:
        vector<vector<pair<int,int>>> adjList(int n, vector<vector<int>> &flights)
        {
            vector<vector<pair<int,int>>> adj(n);
            for(auto flight:flights)
            {
                int u=flight[0];
                int v=flight[1];
                int cost=flight[2];
                adj[u].push_back({v,cost});
            }
            return adj;
        }

        int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k)
        {
            vector<vector<pair<int,int>>> adj = adjList(n, flights);
            queue<pair<int, int>> q; // {city, cost}
            vector<int> dist(n, INT_MAX);
            
            q.push({src, 0});
            dist[src] = 0;
            int stops = 0;
            
            while(!q.empty() && stops <= k)
            {
                int size = q.size();
                
                // Process all nodes at current level (stops)
                for(int i = 0; i < size; i++)
                {
                    int city = q.front().first;
                    int cost = q.front().second;
                    q.pop();
                    
                    for(auto neighbor : adj[city])
                    {
                        int nextCity = neighbor.first;
                        int flightCost = neighbor.second;
                        int newCost = cost + flightCost;
                        
                        if(newCost < dist[nextCity])
                        {
                            dist[nextCity] = newCost;
                            q.push({nextCity, newCost});
                        }
                    }
                }
                stops++;
            }
            
            return (dist[dst] == INT_MAX) ? -1 : dist[dst];
        }
};

int main()
{
    cout << "=== Cheapest Flights Within K Stops ===" << endl;
    
    Solution sol;
    
    // Test case 1: Direct and indirect flights
    cout << "\nTest Case 1: Multiple flight options" << endl;
    int n1 = 3;
    vector<vector<int>> flights1 = {{0,1,100},{1,2,100},{0,2,500}};
    int src1 = 0, dst1 = 2, k1 = 1;
    
    cout << "Cities: " << n1 << " (numbered 0 to " << n1-1 << ")" << endl;
    cout << "Available flights (from, to, price):" << endl;
    for(auto flight : flights1)
    {
        cout << "  City " << flight[0] << " -> City " << flight[1] << " (cost: $" << flight[2] << ")" << endl;
    }
    
    cout << "\nSearching for cheapest flight:" << endl;
    cout << "From: City " << src1 << " To: City " << dst1 << endl;
    cout << "Maximum stops allowed: " << k1 << endl;
    
    int result1 = sol.findCheapestPrice(n1, flights1, src1, dst1, k1);
    cout << "\nCheapest price: ";
    if(result1 == -1)
        cout << "No valid route found" << endl;
    else
        cout << "$" << result1 << endl;
    
    cout << "Explanation: Direct flight costs $500, but 0->1->2 costs $200 with 1 stop" << endl;
    
    // Test case 2: No valid route within k stops
    cout << "\nTest Case 2: Limited stops constraint" << endl;
    int n2 = 3;
    vector<vector<int>> flights2 = {{0,1,100},{1,2,100},{0,2,500}};
    int src2 = 0, dst2 = 2, k2 = 0;
    
    cout << "Cities: " << n2 << " (numbered 0 to " << n2-1 << ")" << endl;
    cout << "Available flights (from, to, price):" << endl;
    for(auto flight : flights2)
    {
        cout << "  City " << flight[0] << " -> City " << flight[1] << " (cost: $" << flight[2] << ")" << endl;
    }
    
    cout << "\nSearching for cheapest flight:" << endl;
    cout << "From: City " << src2 << " To: City " << dst2 << endl;
    cout << "Maximum stops allowed: " << k2 << " (direct flights only)" << endl;
    
    int result2 = sol.findCheapestPrice(n2, flights2, src2, dst2, k2);
    cout << "\nCheapest price: ";
    if(result2 == -1)
        cout << "No valid route found" << endl;
    else
        cout << "$" << result2 << endl;
    
    cout << "Explanation: Only direct flight 0->2 allowed, costs $500" << endl;
    
    // Test case 3: Complex routing
    cout << "\nTest Case 3: Complex flight network" << endl;
    int n3 = 4;
    vector<vector<int>> flights3 = {{0,1,1},{0,2,5},{1,2,1},{2,3,1}};
    int src3 = 0, dst3 = 3, k3 = 1;
    
    cout << "Cities: " << n3 << " (numbered 0 to " << n3-1 << ")" << endl;
    cout << "Available flights (from, to, price):" << endl;
    for(auto flight : flights3)
    {
        cout << "  City " << flight[0] << " -> City " << flight[1] << " (cost: $" << flight[2] << ")" << endl;
    }
    
    cout << "\nSearching for cheapest flight:" << endl;
    cout << "From: City " << src3 << " To: City " << dst3 << endl;
    cout << "Maximum stops allowed: " << k3 << endl;
    
    int result3 = sol.findCheapestPrice(n3, flights3, src3, dst3, k3);
    cout << "\nCheapest price: ";
    if(result3 == -1)
        cout << "No valid route found" << endl;
    else
        cout << "$" << result3 << endl;
    
    cout << "Explanation: Route 0->2->3 costs $6 with 1 stop" << endl;
    
    cout << "\nAlgorithm: Modified BFS considering both cost and stop constraints" << endl;
    cout << "Finds minimum cost path with at most K intermediate stops" << endl;
    
    return 0;
}