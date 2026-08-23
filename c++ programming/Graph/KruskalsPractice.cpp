// Date: 17/07/2026
#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Edges
{
    public:
        int u, v, wt;

        Edges(int u, int v, int wt)
        {
            this->u = u;
            this->v = v;
            this->wt = wt;
        }

        bool operator<(const Edges &other) const{ return wt < other.wt;}
};

class DisjointSetUnion // Time Complexity: O(1)
{
    public:
        int n;
        vector<int> parent, rank;

        DisjointSetUnion(int n)
        {
            this->n = n;
            for (int i = 0; i < n; i++)
            {
                parent.push_back(i);
                rank.push_back(0);
            }
        }

        int find(int x)
        {
            if(parent[x] == x) return x;
            return parent[x] = find(parent[x]);
        }

        void unionByRank(int a, int b)
        {
            int parA = find(a);
            int parB = find(b);

            if(parA == parB) return;

            if(rank[parA] == rank[parB])
            {
                parent[parB] = parA;
                rank[parA]++;
            }
            else if(rank[parA] > rank[parB]) parent[parB] = parA;
            else parent[parA] = parB;
        }
};

// Time Complexity: O(E * logE)
// Space Complexity: O(V + E)
class Solution
{
    public: 
        int kruskalsMST(int V, vector<vector<int>> &edges)
        {
            vector<Edges> edgeList;
            for(auto edge: edges)
            {
                edgeList.push_back(Edges(edge[0], edge[1], edge[2]));
            }

            sort(edgeList.begin(), edgeList.end());

            DisjointSetUnion dsu(V);
            int mstCost = 0, count = 0;

            for (int i = 0; i < edges.size() && count < V - 1; i++)
            {
                Edges e = edgeList[i];

                if(dsu.find(e.u) != dsu.find(e.v)) // No Cycle
                {
                    mstCost += e.wt;
                    dsu.unionByRank(e.u, e.v);
                }
            }
            return mstCost;
        }
};

int main()
{
    int V = 3;
    vector<vector<int>> edges = {
        {0, 1, 5},
        {1, 2, 3},
        {0, 2, 1}
    };

    Solution s;
    cout << s.kruskalsMST(V, edges) <<endl;

    return 0;
}