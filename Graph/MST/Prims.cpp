#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<limits>
#include<utility>
using namespace std;

const int INF=numeric_limits<int>::max();

using Edges=pair<int,int>;
using Graph=vector<vector<Edges>>;
using MinHeapNode=pair<int,int>;

vector<pair<int,int>> prims(const Graph& graph, int V, int src)
{
    vector<int> parent(V,-1);
    vector<int> key(V,INF);
    vector<bool> inMST(V,false);
    vector<pair<int,int>> mstEdges;

    priority_queue<MinHeapNode,vector<MinHeapNode>,greater<MinHeapNode>> pq;

    key[src]=0;
    pq.push({0,src});

    while(!pq.empty())
    {
        int u=pq.top().second;
        pq.pop();

        if(inMST[u]) continue;

        inMST[u]=true;
        
        if(parent[u] != -1)
        {
            mstEdges.push_back({parent[u], u});
        }

        for(auto neighbours:graph[u])
        {
            int v=neighbours.second;
            int weight=neighbours.first;

            if(!inMST[v] && weight < key[v])
            {
                key[v]=weight;
                parent[v]=u;
                pq.push({key[v],v});
            }
        }
    }
    return mstEdges;
}

int main()
{
    cout << "=== Prim's Minimum Spanning Tree Algorithm ===" << endl;
    
    int V = 5;
    Graph graph(V);
    
    cout << "\nBuilding weighted graph with " << V << " vertices..." << endl;
    
    // Adding edges (weight, vertex)
    graph[0].push_back({2, 1});
    graph[0].push_back({3, 3});
    graph[1].push_back({2, 0});
    graph[1].push_back({3, 2});
    graph[1].push_back({1, 3});
    graph[2].push_back({3, 1});
    graph[2].push_back({6, 4});
    graph[3].push_back({3, 0});
    graph[3].push_back({1, 1});
    graph[3].push_back({5, 4});
    graph[4].push_back({6, 2});
    graph[4].push_back({5, 3});
    
    cout << "\nGraph edges (vertex -> vertex with weight):" << endl;
    cout << "0 -> 1 (weight: 2), 0 -> 3 (weight: 3)" << endl;
    cout << "1 -> 0 (weight: 2), 1 -> 2 (weight: 3), 1 -> 3 (weight: 1)" << endl;
    cout << "2 -> 1 (weight: 3), 2 -> 4 (weight: 6)" << endl;
    cout << "3 -> 0 (weight: 3), 3 -> 1 (weight: 1), 3 -> 4 (weight: 5)" << endl;
    cout << "4 -> 2 (weight: 6), 4 -> 3 (weight: 5)" << endl;
    
    int startVertex = 0;
    cout << "\nStarting Prim's algorithm from vertex: " << startVertex << endl;
    cout << "Growing MST by adding minimum weight edges..." << endl;
    
    vector<pair<int,int>> mstEdges = prims(graph, V, startVertex);
    
    cout << "\n=== MINIMUM SPANNING TREE ===" << endl;
    cout << "MST edges (parent -> child):" << endl;
    
    int totalWeight = 0;
    for(auto edge : mstEdges)
    {
        int u = edge.first;
        int v = edge.second;
        
        // Find weight of this edge
        int weight = 0;
        for(auto neighbor : graph[u])
        {
            if(neighbor.second == v)
            {
                weight = neighbor.first;
                break;
            }
        }
        
        cout << "Edge (" << u << " -> " << v << ") with weight: " << weight << endl;
        totalWeight += weight;
    }
    
    cout << "\nTotal MST weight: " << totalWeight << endl;
    cout << "Number of edges in MST: " << mstEdges.size() << endl;
    cout << "Expected edges for MST: " << V-1 << endl;
    
    return 0;
}