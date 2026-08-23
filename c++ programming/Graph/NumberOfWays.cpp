// Date: 16/07/2026
#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;

// Modified Dikstar's Algorithm
// Time Complexity: O(m * logn)
// Space Complexity: O(n + m)
class Solution
{
    public:
        vector<vector<pair<long, long>>> adjList(int n, vector<vector<int>> &roads)
        {
            vector<vector<pair<long,long>>> adj(n);

            for(auto road : roads)
            {
                int u = road[0];
                int v = road[1];
                int time = road[2];
                adj[u].push_back({v, time});
                adj[v].push_back({u, time});
            }
            return adj;
        }
        int countPaths(int n, vector<vector<int>> &roads)
        {
            vector<vector<pair<long, long>>> adj = adjList(n, roads);
            int val = 1e9 + 7;
            priority_queue<pair<long, long>, vector<pair<long, long>>, greater<pair<long, long>>> pq;
            vector<long long> dist(n, LONG_LONG_MAX);
            vector<long long> ways(n, 0);
            ways[0] = 1;
            int src = 0;
            dist[src] = 0;
            pq.push({0, src});

            while(!pq.empty())
            {
                int t = pq.top().first;
                int u = pq.top().second;
                pq.pop();

                if(t > dist[u]) continue;

                for(auto neighbour: adj[u])
                {
                    int v = neighbour.first;
                    int time = neighbour.second;

                    if(dist[u] + time < dist[v])
                    {
                        dist[v] = dist[u] + time;
                        ways[v] = ways[u];
                        pq.push({dist[v], v});
                    }
                    else if(dist[u] + time == dist[v]) ways[v] = (ways[v] + ways[u]) % val;
                }
            }

            return ways[n - 1];
        }
};

int main()
{
    int n = 7;
    vector<vector<int>> roads = {
        {0, 6, 7},
        {0, 1, 2},
        {1, 2, 3},
        {1, 3, 3},
        {6, 3, 3},
        {3, 5, 1},
        {6, 5, 1},
        {2, 5, 1},
        {0, 4, 5},
        {4, 6, 2}
    };

    Solution s;
    cout<< s.countPaths(n, roads)<< endl;
    return 0;
}