#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// Time Complexity:O(n+e)
// Space Complexity:O(n+e)

class Solution
{
    public:
        bool helper(int n, vector<vector<int>> &edges, int source, int destination, vector<bool> &visited, unordered_map<int, vector<int>> &adj)
        {
            if(source==destination) return true;
            if(visited[source]) return false;
            
            visited[source]=true;
            for(int i=0;i<adj[source].size();i++)
            {
                if(helper(n,edges,adj[source][i],destination,visited,adj)) return true;
            }
            return false;
        }

        bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
        {
            
            vector<bool> visited(n, false);
            unordered_map<int, vector<int>> adj;
            for(int i=0;i<edges.size();i++)
            {
                adj[edges[i][0]].push_back(edges[i][1]);
                adj[edges[i][1]].push_back(edges[i][0]);
            }
            return helper(n, edges, source, destination, visited, adj);
        }
};

int main()
{
    int n=3;
    vector<vector<int>> edges={{0,1},{1,2},{2,0}};
    int source=0;
    int destination=2;
    Solution s;
    if(s.validPath(n,edges,source,destination))
    {
        cout<<"true"<<endl;
    }
    else
    {
        cout<<"false"<<endl;
    }
    return 0;
}