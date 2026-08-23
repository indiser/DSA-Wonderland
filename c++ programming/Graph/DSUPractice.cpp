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
            
            for(int i = 0; i < n; i++)
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
            
            // if(rank[parA] == rank[parB])
            // {
            //     parent[parB] = parA;
            //     rank[parA]++;
            // }
            // else if(rank[parA] > rank[parB]) parent[parB] = parA;
            // else parent[parA] = parB;

            parent[parA] = parB;
        }
};
class Solution {
  public:
    vector<int> DSU(int n, vector<vector<int>>& queries) {
        // code here
        vector<int> ans;
        DisjointSetUnion dsu(n + 1);
        
        for (int i = 0; i < queries.size(); i++)
        {
            if(queries[i][0] == 1 && queries[i].size() >= 3) dsu.unionByRank(queries[i][1], queries[i][2]);
            else if(queries[i][0] == 2 && queries[i].size() >= 2) ans.push_back(dsu.find(queries[i][1]));
        }
        
        return ans;
    }
};

int main()
{
    int n = 4;
    vector<vector<int>> queries = {
        {2, 4},
        {2, 1},
        {1, 3, 1},
        {2, 3}
    };

    Solution s;
    vector<int> ans = s.DSU(n, queries);
    for(int val: ans) cout<< val<< endl;

    return 0;
}