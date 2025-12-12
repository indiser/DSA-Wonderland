#include <iostream>
#include <vector>
#include <unordered_map>
#include <numeric>
#include <utility>
#include <algorithm>
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
        iota(parent.begin(), parent.end(), 0);
        sz.assign(n, 1);
    }

    int find(int i)
    {
        return (parent[i] == i) ? i : find(parent[i]);
    }

    void unite(int i, int j)
    {
        int root_i = find(i);
        int root_j = find(j);

        if (root_i != root_j)
        {
            if (sz[root_i] < sz[root_j])
            {
                swap(root_i, root_j);
            }
            parent[root_i] = root_j;
            sz[root_i] += sz[root_j];
        }
    }
};

/*
Time Complexity: O(n² * α(n))
- n²: nested loops to check all pairs in adjacency matrix
- α(n): inverse Ackermann function for DSU operations (nearly constant)
- Final counting loop: O(n * α(n))

Space Complexity: O(n)
- DSU parent array: O(n)
- DSU size array: O(n)
- No additional space for adjacency matrix (given as input)
*/
class Solution
{
public:
    int numberOfProvinces(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size();
        DSU dsu(n);

        // Union connected cities
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (isConnected[i][j] == 1 && i != j)
                {
                    dsu.unite(i, j);
                }
            }
        }

        // Count unique provinces
        int provinces = 0;
        for (int i = 0; i < n; i++)
        {
            if (dsu.find(i) == i)
            {
                provinces++;
            }
        }

        return provinces;
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
    int provinces = sol.numberOfProvinces(isConnected);
    cout << "\nNumber of provinces found: " << provinces << endl;

    return 0;
}