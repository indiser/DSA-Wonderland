// Date: 17/07/2026
#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<algorithm>
using namespace std;

// Time Complexity: O(n^2 logn)
// Space Complexity: O(n^2)
class PrimsSolution
{
    public:
        int manHattenDist(vector<vector<int>> &points, int p1, int p2)
        {
            return abs(points[p1][0] - points[p2][0]) + abs(points[p1][1] - points[p2][1]);
            // |X1 - X2| + |Y1 - Y2|
        }
        int minCostConnectPoints(vector<vector<int>> &points)
        {
            int n = points.size();
            priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
            vector<bool> mstSet(n, false);
            int mstCost = 0;
            pq.push({0, 0});

            while(pq.size() > 0)
            {
                auto p = pq.top();
                pq.pop();
                int node = p.second;
                int weight = p.first;

                if(mstSet[node]) continue;

                mstSet[node] = true;
                mstCost += weight;

                for (int i = 0; i < n; i++)
                {
                    if(!mstSet[i])
                    {
                        int edgeWt = manHattenDist(points, node, i);
                        pq.push({edgeWt, i});
                    }
                }
            }

            return mstCost;
        }
};


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

        bool operator<(const Edges &other) const {return wt < other.wt;}
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
class KruskalsSolution
{
    public:
        int manHattenDist(vector<vector<int>> &points, int p1, int p2)
        {
            return abs(points[p1][0] - points[p2][0]) + abs(points[p1][1] - points[p2][1]);
            // |X1 - X2| + |Y1 - Y2|
        }
        int minCostConnectPoints(vector<vector<int>> &points)
        {
            int n = points.size();
            vector<Edges> edgeList;

            for (int i = 0; i < n; i++)
            {
                for (int j = i + 1; j < n; j++)
                {
                    edgeList.push_back(Edges(i, j, manHattenDist(points, i, j)));
                }
            }

            sort(edgeList.begin(), edgeList.end());
            DisjointSetUnion dsu(n);
            int mstCost = 0, count = 0;

            for (int i = 0; i < edgeList.size() && count < n - 1; i++)
            {
                Edges e = edgeList[i];

                if(dsu.find(e.u) != dsu.find(e.v))
                {
                    dsu.unionByRank(e.u, e.v);
                    mstCost += e.wt;
                }
            }
            return mstCost;
        }
};

int main()
{
    vector<vector<int>> points = {
        {0, 0},
        {2, 2},
        {3, 10},
        {5, 2},
        {7, 0}
    };

    PrimsSolution ps;
    cout << "Prims: "<< ps.minCostConnectPoints(points)<< endl;

    KruskalsSolution ks;
    cout << "Kruskals: " << ks.minCostConnectPoints(points) <<endl;
    return 0;
}