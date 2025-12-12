#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<utility>
#include<limits>
using namespace std;


/*
Time Complexity: O((V + E) log V)
- V: number of nodes (vertices)
- E: number of edges (times)
- Building adjacency list: O(E)
- Dijkstra's algorithm: O((V + E) log V)
  - Each vertex is extracted from priority queue once: O(V log V)
  - Each edge is relaxed at most once: O(E log V)
- Final loop to find maximum: O(V)

Space Complexity: O(V + E)
- Adjacency list: O(V + E) to store all edges
- Distance array: O(V)
- Priority queue: O(V) in worst case
*/
class Solution
{
    public:
        const int INF=numeric_limits<int>::max();
        vector<vector<pair<int,int>>> adjList(vector<vector<int>> &times, int n)
        {
            vector<vector<pair<int,int>>> adj(n+1);

            for(auto i:times)
            {
                int u=i[0];
                int v=i[1];
                int w=i[2];
                adj[u].push_back({v,w});
            }
            return adj;
        }
        int networkDelayTime(vector<vector<int>> &times, int n, int k)
        {
            vector<vector<pair<int,int>>> adj=adjList(times, n);
            vector<int> dist(n+1,INF);
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
            dist[k]=0;
            pq.push({0,k});

            while(!pq.empty())
            {
                int u=pq.top().second;
                int d=pq.top().first;
                pq.pop();

                if(d > dist[u]) continue;

                for(auto neighbour:adj[u])
                {
                    int v=neighbour.first;
                    int weight=neighbour.second;

                    if(dist[u]+weight < dist[v])
                    {
                        dist[v]=dist[u]+weight;
                        pq.push({dist[v],v});
                    }
                }
            }
            int ans=0;
            for (int i =1; i <= n; i++)
            {
                if(dist[i]==INF) return -1;
                ans=max(ans,dist[i]);
            }

            return ans;
        }
};

int main()
{
    cout << "=== Network Delay Time Problem ===" << endl;
    
    Solution sol;
    
    // Test case 1: All nodes reachable
    cout << "\nTest Case 1:" << endl;
    vector<vector<int>> times1 = {{2,1,1},{2,3,1},{3,4,1}};
    int n1 = 4, k1 = 2;
    
    cout << "Network with " << n1 << " nodes, signal starts from node " << k1 << endl;
    cout << "Edges (source -> destination, time):" << endl;
    for(auto edge : times1)
    {
        cout << "Node " << edge[0] << " -> Node " << edge[1] << " (time: " << edge[2] << ")" << endl;
    }
    
    int delay1 = sol.networkDelayTime(times1, n1, k1);
    cout << "\nMinimum time for signal to reach all nodes: ";
    if(delay1 == -1)
        cout << "IMPOSSIBLE (some nodes unreachable)" << endl;
    else
        cout << delay1 << " units" << endl;
    
    // Test case 2: Some nodes unreachable
    cout << "\nTest Case 2:" << endl;
    vector<vector<int>> times2 = {{1,2,1}};
    int n2 = 3, k2 = 1;
    
    cout << "Network with " << n2 << " nodes, signal starts from node " << k2 << endl;
    cout << "Edges (source -> destination, time):" << endl;
    for(auto edge : times2)
    {
        cout << "Node " << edge[0] << " -> Node " << edge[1] << " (time: " << edge[2] << ")" << endl;
    }
    
    int delay2 = sol.networkDelayTime(times2, n2, k2);
    cout << "\nMinimum time for signal to reach all nodes: ";
    if(delay2 == -1)
        cout << "IMPOSSIBLE (some nodes unreachable)" << endl;
    else
        cout << delay2 << " units" << endl;
    
    cout << "\nAlgorithm: Uses Dijkstra's shortest path to find minimum time" << endl;
    cout << "Returns the maximum time among all reachable nodes" << endl;
    
    return 0;
}