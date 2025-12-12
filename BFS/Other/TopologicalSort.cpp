#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;

// Kanh's Algorithm for Topological Sorting

// Time Complexity:O(V+E)
// Space Complexity:O(V)

class Solution
{
    public:
        vector<vector<int>> constructj(int V, vector<vector<int>> &edges)
        {
            vector<vector<int>> adj(V);

            for(auto it:edges)
            {
                adj[it[0]].push_back(it[1]);
            }
            return adj;
        }
        vector<int> topologicalSort(int V, vector<vector<int>> &edges)
        {
            vector<vector<int>> adj=constructj(V,edges);

            vector<int> indegree(V);
            for (int i = 0; i < V; i++)
            {
                for(auto it:adj[i])
                {
                    indegree[it]++;
                }
            }
            
            queue<int> q;

            for (int i = 0; i < V; i++)
            {
                if(indegree[i]==0)
                {
                    q.push(i);
                }
            }
            
            vector<int> sorted;
            while(!q.empty())
            {
                int node=q.front();
                sorted.push_back(node);
                q.pop();

                for(auto it: adj[node])
                {
                    indegree[it]--;
                    if(indegree[it]==0)
                    {
                        q.push(it);
                    }
                }
            }

            if(sorted.size() != V)
            {
                cout<<"Graph has Cycles"<<endl;
                return {};
            }

            return sorted;
        }

};

int main()
{
    int V = 6;

    vector<vector<int> > edges
        = {{0, 1}, {1, 2}, {2, 3},
           {4, 5}, {5, 1}, {5, 2}};

    Solution s;
    vector<int> result = s.topologicalSort(V, edges);

    // Displaying result
    for (auto i : result) {
        cout << i << " ";
    }

    return 0;
}