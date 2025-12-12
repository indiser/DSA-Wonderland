#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// DFS Approach
// Time Complexity: O(V + E) where V = vertices, E = edges
// Space Complexity: O(V + E) for adjacency list + O(V) for visited array + O(V) for recursion stack

// class Solution
// {
//     public:
//         vector<vector<int>> adjList(int n, vector<vector<int>> &edges)
//         {
//             vector<vector<int>> adj(n);

//             for(auto edge:edges)
//             {
//                 int u=edge[0];
//                 int v=edge[1];
//                 adj[u].push_back(v);
//                 adj[v].push_back(u);
//             }

//             return adj;
//         }

//         void dfs(int node, vector<vector<int>> &adj, vector<bool> &visited)
//         {
//             visited[node]=true;
//             for(auto neighbour:adj[node])
//             {
//                 if(!visited[neighbour])
//                 {
//                     dfs(neighbour,adj,visited);
//                 }
//             }
//         }
//         int numberOfComponents(int n, vector<vector<int>> &edges)
//         {
//             vector<vector<int>> adj=adjList(n,edges);
//             vector<bool> visited(n,false);
//             int count=0;
//             for (int i = 0; i < n; i++)
//             {
//                 if(!visited[i])
//                 {
//                     dfs(i,adj,visited);
//                     count++;
//                 }
//             }
//             return count;
//         }
// };

// BFS Approach
// Time Complexity: O(V + E) where V = vertices, E = edges
// Space Complexity: O(V + E) for adjacency list + O(V) for visited array + O(V) for BFS queue

class Solution
{
    public:
        vector<vector<int>> adjList(int n, vector<vector<int>> &edges)
        {
            vector<vector<int>> adj(n);

            for(auto edge:edges)
            {
                int u=edge[0];
                int v=edge[1];
                adj[u].push_back(v);
                adj[v].push_back(u);
            }

            return adj;
        }

        void bfs(int node, vector<vector<int>> &adj, vector<bool> &visited)
        {
            queue<int> q;
            q.push(node);
            visited[node]=true;

            while(!q.empty())
            {
                int curr=q.front();
                q.pop();
                for(auto neighbour:adj[curr])
                {
                    if(!visited[neighbour])
                    {
                        q.push(neighbour);
                        visited[neighbour]=true;
                    }
                }
            }
        }
        int numberOfComponents(int n, vector<vector<int>> &edges)
        {
            vector<vector<int>> adj=adjList(n,edges);
            vector<bool> visited(n,false);
            int count=0;
            for (int i = 0; i < n; i++)
            {
                if(!visited[i])
                {
                    bfs(i,adj,visited);
                    count++;
                }
            }
            return count;
        }
};

int main()
{
    vector<vector<int>> edges = {{0,1},{0,2},{1,2},{3,4},{3,5}};
    int n=6;
    Solution s;
    cout << s.numberOfComponents(n,edges) << endl;
    return 0;
}