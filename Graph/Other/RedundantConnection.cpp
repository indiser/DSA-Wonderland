#include<iostream>
#include<vector>
#include<unordered_map>
#include<numeric>
#include<algorithm>
using namespace std;

/*
Time Complexity: O(E * α(V))
- E: number of edges
- V: number of vertices (nodes)
- α(V): inverse Ackermann function (practically constant, ≤ 4)
- For each edge: find() and unite() operations take O(α(V)) time
- Early termination when redundant edge is found

Space Complexity: O(V)
- DSU parent array: O(V)
- DSU size array: O(V)
- No additional space for processing edges
*/
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
            return (parent[i]==i) ? i : find(parent[i]);
        }
        void unite(int i, int j)
        {
            int root_i=find(i);
            int root_j=find(j);

            if(root_i != root_j)
            {
                if(sz[root_i] < sz[root_j])
                {
                    swap(root_i,root_j);
                }
                parent[root_i]=root_j;
                sz[root_i]+=sz[root_j];
            }
        }
};

class Solution
{
public:
    vector<int> redundantConnection(vector<vector<int>> &edges)
    {
        DSU dsu(edges.size() + 1); // 1-indexed nodes
        
        for(auto edge : edges)
        {
            int u = edge[0];
            int v = edge[1];

            if(dsu.find(u) == dsu.find(v))
            {
                return {u, v};
            }
            dsu.unite(u, v);
        }
        return {};
    }
};

int main()
{
    cout << "=== Redundant Connection Problem ===" << endl;
    
    Solution sol;
    
    // Test case 1: Simple cycle
    cout << "\nTest Case 1:" << endl;
    vector<vector<int>> edges1 = {{1,2},{1,3},{2,3}};
    
    cout << "Edges in the graph:" << endl;
    for(int i = 0; i < edges1.size(); i++)
    {
        cout << "Edge " << i+1 << ": " << edges1[i][0] << " -- " << edges1[i][1] << endl;
    }
    
    vector<int> redundant1 = sol.redundantConnection(edges1);
    cout << "\nRedundant edge that creates cycle: [" << redundant1[0] << ", " << redundant1[1] << "]" << endl;
    cout << "Explanation: This edge connects two already connected components" << endl;
    
    // Test case 2: Larger graph
    cout << "\nTest Case 2:" << endl;
    vector<vector<int>> edges2 = {{1,2},{2,3},{3,4},{1,4},{1,5}};
    
    cout << "Edges in the graph:" << endl;
    for(int i = 0; i < edges2.size(); i++)
    {
        cout << "Edge " << i+1 << ": " << edges2[i][0] << " -- " << edges2[i][1] << endl;
    }
    
    vector<int> redundant2 = sol.redundantConnection(edges2);
    cout << "\nRedundant edge that creates cycle: [" << redundant2[0] << ", " << redundant2[1] << "]" << endl;
    cout << "Explanation: This edge creates a cycle in the existing tree structure" << endl;
    
    cout << "\nAlgorithm: Uses Union-Find (DSU) to detect when an edge" << endl;
    cout << "connects two nodes that are already in the same component" << endl;
    
    return 0;
}