#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<numeric>
#include<algorithm>
using namespace std;

class DSU
{
    private:
        vector<int> parent;
        vector<int> sz;
    public:
        DSU(int n)
        {
            parent.resize(n);
            iota(parent.begin(),parent.end(),0);
            sz.assign(n,1);
        }

        int find(int i)
        {
            return(parent[i]==i) ? i : find(parent[i]);
        }

        void unite(int i, int j)
        {
            int root_i=find(i);
            int root_j=find(j);

            if(root_i != root_j)
            {
                if(sz[root_i] < sz[root_j]) swap(root_i,root_j);
                parent[root_j]=root_i;
                sz[root_i]+=sz[root_j];
            }
        }
};

struct Edge
{
    int u, v, weight;

    bool operator<(const Edge& other) const
    {
        return weight < other.weight;
    }
};

vector<Edge> kruskalMST(int V, vector<Edge> &edges)
{
    sort(edges.begin(),edges.end());

    DSU dsu(V);
    vector<Edge> resultMST;
    int mst_Weight=0;

    for(auto edge:edges)
    {
        if(dsu.find(edge.u) != dsu.find(edge.v))
        {
            dsu.unite(edge.u,edge.v);
            resultMST.push_back(edge);
            mst_Weight+=edge.weight;
        }
    }

    return resultMST;
}

int main()
{
    cout << "=== Kruskal's Minimum Spanning Tree Algorithm ===" << endl;
    
    int V = 6;
    vector<Edge> edges = {
        {0, 1, 4}, {0, 2, 3}, {1, 2, 1}, {1, 3, 2},
        {2, 3, 4}, {3, 4, 2}, {4, 5, 6}, {2, 4, 5}
    };
    
    cout << "\nGraph with " << V << " vertices and " << edges.size() << " edges:" << endl;
    cout << "Original edges (u, v, weight):" << endl;
    for(auto edge : edges)
    {
        cout << "Edge (" << edge.u << ", " << edge.v << ") with weight " << edge.weight << endl;
    }
    
    cout << "\nRunning Kruskal's algorithm..." << endl;
    cout << "Sorting edges by weight..." << endl;
    
    vector<Edge> mst = kruskalMST(V, edges);
    
    cout << "\n=== MINIMUM SPANNING TREE ===" << endl;
    int totalWeight = 0;
    cout << "Selected edges:" << endl;
    
    for(auto edge : mst)
    {
        cout << "Edge (" << edge.u << ", " << edge.v << ") with weight " << edge.weight << endl;
        totalWeight += edge.weight;
    }
    
    cout << "\nTotal MST weight: " << totalWeight << endl;
    cout << "Number of edges in MST: " << mst.size() << endl;
    cout << "Expected edges for MST: " << V-1 << endl;
    
    return 0;
}