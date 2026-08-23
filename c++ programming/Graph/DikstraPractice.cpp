// Date: 17/07/2026
#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;

// Time Complexity: O((V + E) * logV)
// Space  Complexity: O(V)
class Solution
{
    public:
        vector<int> dikstra(int V, vector<vector<int>> &edges, int &src)
        {
            vector<vector<pair<int, int>>> adj(V);

            for(auto edge : edges)
            {
                adj[edge[0]].push_back({edge[1], edge[2]});
                adj[edge[1]].push_back({edge[0], edge[2]});
            }

            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
            vector<int> dist(V, INT_MAX);
            minHeap.push({0, src});
            dist[src] = 0;

            while(!minHeap.empty())
            {
                int u = minHeap.top().second;
                int d = minHeap.top().first;
                minHeap.pop();

                if(d > dist[u]) continue;

                for(auto neighbour: adj[u])
                {
                    int v = neighbour.first;
                    int weight = neighbour.second;

                    if(dist[u] + weight < dist[v])
                    {
                        dist[v] = dist[u] + weight;
                        minHeap.push({dist[v], v});
                    }
                }
            }

            return dist;
        }
};

int main()
{
    int V = 3;
    vector<vector<int>> edges = {
        {0, 1, 1},
        {1, 2, 3},
        {0, 2, 6}
    };
    int src = 2;

    Solution s;
    vector<int> result = s.dikstra(V, edges, src);

    for(int val: result) cout<< val <<" ";

    return 0;
}