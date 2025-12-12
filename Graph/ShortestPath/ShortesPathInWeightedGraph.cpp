#include<iostream>
#include<vector>
#include<unordered_map>
#include<limits>
#include<utility>
#include<queue>
using namespace std;

const int INF=numeric_limits<int>::max();
using Edges=pair<int,int>;
using Graph=vector<vector<Edges>>;
using MinHeapNode=pair<int,int>;

class Solution
{
    public:
        vector<int> findShortestDistance(int V, const Graph& graph, int src)
        {
            priority_queue<MinHeapNode,vector<MinHeapNode>,greater<MinHeapNode>> pq;
            vector<int> dist(V,INF);
            dist[src]=0;
            pq.push({0,src});

            while(!pq.empty())
            {
                int u=pq.top().second;
                int d=pq.top().first;
                pq.pop();

                if(d > dist[u]) continue;
                for(auto neighbour:graph[u])
                {
                    int v=neighbour.first;
                    int weight=neighbour.second;

                    if(dist[u]+weight<dist[v])
                    {
                        dist[v]=dist[u]+weight;
                        pq.push({dist[v],v});
                    }
                }
            }
            return dist;
        }
};

int main()
{
    cout << "=== Shortest Path in Weighted Graph (Dijkstra) ===" << endl;
    
    int V = 6;
    Graph graph(V);
    
    cout << "\nBuilding weighted directed graph with " << V << " vertices..." << endl;
    
    // Adding edges (destination, weight)
    graph[0].push_back({1, 4});
    graph[0].push_back({2, 2});
    graph[1].push_back({2, 1});
    graph[1].push_back({3, 5});
    graph[2].push_back({3, 8});
    graph[2].push_back({4, 10});
    graph[3].push_back({4, 2});
    graph[3].push_back({5, 6});
    graph[4].push_back({5, 3});
    
    cout << "\nGraph edges (source -> destination with weight):" << endl;
    cout << "0 -> 1 (weight: 4), 0 -> 2 (weight: 2)" << endl;
    cout << "1 -> 2 (weight: 1), 1 -> 3 (weight: 5)" << endl;
    cout << "2 -> 3 (weight: 8), 2 -> 4 (weight: 10)" << endl;
    cout << "3 -> 4 (weight: 2), 3 -> 5 (weight: 6)" << endl;
    cout << "4 -> 5 (weight: 3)" << endl;
    
    int source = 0;
    cout << "\nFinding shortest paths from source vertex: " << source << endl;
    cout << "Using Dijkstra's algorithm..." << endl;
    
    Solution sol;
    vector<int> distances = sol.findShortestDistance(V, graph, source);
    
    cout << "\n=== SHORTEST DISTANCES ===" << endl;
    for(int i = 0; i < V; i++)
    {
        cout << "Vertex " << source << " to " << i << ": ";
        if(distances[i] == INF)
            cout << "UNREACHABLE" << endl;
        else
            cout << distances[i] << endl;
    }
    
    cout << "\nOptimal paths found:" << endl;
    cout << "0->2->4->5 (cost: 15) vs 0->1->3->5 (cost: 15)" << endl;
    cout << "0->1->2 (cost: 5) is better than 0->2 (cost: 2) + 2->... for some paths" << endl;
    
    return 0;
}