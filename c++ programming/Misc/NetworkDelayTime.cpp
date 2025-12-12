#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<climits>
#include<unordered_set>
#include<utility>
using namespace std;

// Dijkstra's Algorithm
// Time Complexity: O(E log V) where E = edges, V = vertices
// Space Complexity: O(V + E)

class Solution
{
    public:
        int networkDelay(vector<vector<int>> &times, int n, int k)
        {
            vector<vector<pair<int,int>>> adj(n+1);

            for (int i = 0; i < times.size(); i++)
            {
                int u=times[i][0];
                int v=times[i][1];
                int w=times[i][2];
                adj[u].push_back({v,w});
            }
            

            vector<int> dist(n+1, INT_MAX);
            dist[k]=0;
            priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
            pq.push({0,k});

            while(!pq.empty())
            {
                int nodeDist=pq.top().first;
                int node=pq.top().second;
                pq.pop();

                for(auto it:adj[node])
                {
                    int neight=it.first;
                    int weight=it.second;

                    if(dist[neight] > nodeDist+weight)
                    {
                        dist[neight]=nodeDist+weight;
                        pq.push({dist[neight],neight});
                    }
                }
            }

            int ans=0;
            for (int i = 1; i < n+1; i++)
            {
                ans=max(ans,dist[i]);
            }
            if(ans==INT_MAX) return -1;
            return ans;
        }
};

int main()
{
    vector<vector<int>> times={{2,1,1},{2,3,1},{3,4,1}};
    int n=4, k=2;
    Solution s;
    cout<<s.networkDelay(times,n,k)<<endl;
    return 0;
}