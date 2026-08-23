#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(n)
class DisjointSetUnion
{
    public:
        int n;
        vector<int> parent;
        vector<int> rank;

        DisjointSetUnion(int n)
        {
            this->n = n;

            for (int i = 0; i < n; i++)
            {
                parent.push_back(i);
                rank.push_back(0);
            }
        }
        int find(int x) // Practically O(1)
        {
            if(parent[x] == x) return x;
            return parent[x] = find(parent[x]);
        }

        void unionByRank(int a, int b)  // Practically O(1)
        {
            int parA = parent[a];
            int parB = parent[b];

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

int main()
{
    DisjointSetUnion dsu(6);
    
    dsu.unionByRank(0, 1);
    cout << "Find(0): " << dsu.find(0) << endl;
    dsu.unionByRank(2, 3);
    cout << "Find(3): " << dsu.find(3) << endl;
    dsu.unionByRank(1, 2);
    cout << "Find(4): " << dsu.find(3) << endl;
    return 0;
}