#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

class Solution
{
    public:
        vector<int> shortestPath(int V, vector<vector<int>> &edges, int src, int dest)
        {
            // Build adjacency list
            vector<vector<int>> adj(V);
            for(auto edge : edges)
            {
                adj[edge[0]].push_back(edge[1]);
                adj[edge[1]].push_back(edge[0]);
            }
            
            // BFS
            vector<int> parent(V, -1);
            queue<int> q;
            q.push(src);
            parent[src] = src;
            
            while(!q.empty())
            {
                int curr = q.front();
                q.pop();
                
                if(curr == dest) break;
                
                for(int neighbor : adj[curr])
                {
                    if(parent[neighbor] == -1)
                    {
                        parent[neighbor] = curr;
                        q.push(neighbor);
                    }
                }
            }
            
            // Build path
            vector<int> path;
            if(parent[dest] == -1) return path;
            
            int node = dest;
            while(node != src)
            {
                path.push_back(node);
                node = parent[node];
            }
            path.push_back(src);
            
            reverse(path.begin(), path.end());
            return path;
        }
};

int main()
{
    vector<vector<int>> graph = {{0,1},{0,2},{1,3},{1,4},{2,5},{3,6},{4,7},{5,8},{6,9},{7,9},{8,9},{2,4},{3,5},{6,8}};
    int V = 10;
    int src = 0, dest = 9;
    Solution s;
    vector<int> ans = s.shortestPath(V, graph, src, dest);
    for(int val:ans)
    {
        cout<<val<<" ";
    }
    return 0;

}