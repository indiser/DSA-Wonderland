// Date: 16/07/2026
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class DisjointSetUnion
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

// Time Complexity: O(n^2)
// Time Complexity: O(n)
class Solution
{
    public:
        int findCircleNum(vector<vector<int>> &isConnected)
        {
            int n = isConnected.size();
            DisjointSetUnion dsu(n + 1);
            

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if(isConnected[i][j] == 1 && i != j) dsu.unionByRank(i, j);
                }
            }
            
            int province = 0;
            for (int i = 0; i < n; i++)
            {
                if(dsu.find(i) == i) province++;
            }
            return province;
        }
};

int main()
{
    cout << "=== Number of Provinces Problem ===" << endl;

    vector<vector<int>> isConnected = {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 1}};

    cout << "\nAdjacency Matrix (3x3):" << endl;
    cout << "  0 1 2" << endl;
    for (int i = 0; i < isConnected.size(); i++)
    {
        cout << i << " ";
        for (int j = 0; j < isConnected[i].size(); j++)
        {
            cout << isConnected[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nConnections:" << endl;
    cout << "City 0 <-> City 1 (connected)" << endl;
    cout << "City 2 is isolated" << endl;
    cout << "Expected provinces: 2" << endl;

    Solution sol;
    int provinces = sol.findCircleNum(isConnected);
    cout << "\nNumber of provinces found: " << provinces << endl;

    return 0;
}