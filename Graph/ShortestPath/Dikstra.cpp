#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<utility>
#include<limits>
using namespace std;

const int INF = numeric_limits<int>::max();
using MinHeapNode=pair<int,int>;
using Edge=pair<int,int>;
using Graph=vector<vector<Edge>>;

// Time Complexity: O((V + E) * log V) - Each vertex/edge processed with priority queue operations
// Space Complexity: O(V) - Distance array and priority queue storage
vector<int> dijkstra(int V, const Graph &graph, int src)
{
    priority_queue<MinHeapNode,vector<MinHeapNode>,greater<MinHeapNode>> pq;
    vector<int> dist(V, INF);
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

int main()
{
    cout << "=== Dijkstra's Shortest Path Algorithm ===" << endl;
    
    int V = 5;
    Graph graph(V);
    
    cout << "\nBuilding weighted graph with " << V << " vertices..." << endl;
    
    graph[0].push_back({1, 10});
    graph[0].push_back({4, 5});
    graph[1].push_back({2, 1});
    graph[1].push_back({4, 2});
    graph[2].push_back({3, 4});
    graph[3].push_back({2, 6});
    graph[4].push_back({1, 3});
    graph[4].push_back({2, 9});
    graph[4].push_back({3, 2});
    
    cout << "\nGraph edges added:" << endl;
    cout << "0 -> 1 (weight: 10), 0 -> 4 (weight: 5)" << endl;
    cout << "1 -> 2 (weight: 1), 1 -> 4 (weight: 2)" << endl;
    cout << "2 -> 3 (weight: 4)" << endl;
    cout << "3 -> 2 (weight: 6)" << endl;
    cout << "4 -> 1 (weight: 3), 4 -> 2 (weight: 9), 4 -> 3 (weight: 2)" << endl;
    
    int source = 0;
    cout << "\nRunning Dijkstra from source vertex: " << source << endl;
    
    vector<int> distances = dijkstra(V, graph, source);
    
    cout << "\n=== SHORTEST DISTANCES ===" << endl;
    for(int i = 0; i < V; i++)
    {
        cout << "Vertex " << source << " to " << i << ": ";
        if(distances[i] >= INF)
            cout << "UNREACHABLE" << endl;
        else
            cout << distances[i] << endl;
    }
    
    cout << "\nOptimal paths found:" << endl;
    cout << "0->4->1 (cost: 8) is better than 0->1 (cost: 10)" << endl;
    cout << "0->4->3 (cost: 7) is the shortest to vertex 3" << endl;
    
    return 0;
}