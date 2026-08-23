// Date: 16/07/2026
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class DisjointSet
{
    public:
        int n;
        vector<int> parent;
        vector<int> rank;
        DisjointSet(int n)
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

// TIme Complexity: O(n)
// Space Complexity: O(n)
class Solution
{
    public:
        int removeStones(vector<vector<int>> &stones)
        {
            int n = stones.size();
            DisjointSet dsu(20005);

            for (int i = 0; i < n; i++)
            {
                dsu.unionByRank(stones[i][0], stones[i][1] + 10001);
            }

            unordered_map<int, int> unique;
            for (int i = 0; i < n; i++)
            {
                unique[dsu.find(stones[i][0])] = 1;
            }
            
            return n - unique.size();
        }
};

int main()
{
    vector<vector<int>> stones = {
        {0, 0},
        {0, 1},
        {1, 0},
        {1, 2},
        {2, 1},
        {2, 2}
    };

    Solution s;
    cout << s.removeStones(stones) << endl;

    return 0;
}