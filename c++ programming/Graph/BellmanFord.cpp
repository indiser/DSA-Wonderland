// Date: 10/07/2026
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// Time Compplexity: O(V * E)
// Space Complexity: O(V)
class Solution
{
    public:
        vector<int> bellmanFord(int V, vector<vector<int>> &edges, int src)
        {
            vector<int> dist(V, 1e8);
            dist[src] = 0;

            for (int i = 0; i < V; i++)
            {
                for(auto edge: edges)
                {
                    int u = edge[0];
                    int v = edge[1];
                    int wt = edge[2];

                    if(dist[u] != 1e8 && dist[u] + wt < dist[v])
                    {
                        if(i == V - 1) return {-1};
                        dist[v] = dist[u] + wt;
                    }
                }
            }
            return dist;
        }
};

int main()
{
    int V = 5;
    int src = 0;
    vector<vector<int>> edges = {
        {1, 3, 2}, {4, 3, -1}, {2, 4, 1}, {1, 2, 1}, {0, 1, 5}
    };

    Solution s;
    vector<int> result = s.bellmanFord(V, edges, src);

    for(int val: result)
    {
        cout<<val<<" ";
    }
    return 0;
}