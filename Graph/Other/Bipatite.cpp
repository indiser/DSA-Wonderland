#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// BFS Approach (commented out)
// Time Complexity: O(V + E) where V = vertices, E = edges
// Space Complexity: O(V) for color array + O(V) for BFS queue

// class Solution
// {
//     public:
//         bool isBipartite(vector<vector<int>> &graph)
//         {
//             vector<int> color(graph.size(),-1);
//             queue<int> q;

//             for (int i = 0; i < graph.size(); i++)
//             {
//                 if(color[i]==-1)
//                 {
//                     q.push(i);
//                     color[i]=0;
//                     while(!q.empty())
//                     {
//                         int curr=q.front();
//                         q.pop();

//                         for(auto neighbour:graph[curr])
//                         {
//                             if(color[neighbour]==-1)
//                             {
//                                 color[neighbour]=1-color[curr];
//                                 q.push(neighbour);
//                             }
//                             else if(color[neighbour]==color[curr])
//                             {
//                                 return false;
//                             }
//                         }
//                     }
//                 }
//             }
//             return true;
//         }
// };

// DFS Approach
// Time Complexity: O(V + E) where V = vertices, E = edges
// Space Complexity: O(V) for color array + O(V) for recursion stack

class Solution
{
    public:
        bool dfs(int node, int color, vector<int> &colors, vector<vector<int>> &graph)
        {
            colors[node]=color;

            for(auto neighbour:graph[node])
            {
                if(colors[neighbour]==-1)
                {
                    if(!dfs(neighbour,1-color,colors,graph))
                    {
                        return false;
                    }
                }
                else if(colors[neighbour]==colors[node]) return false;
            }
            return true;
        }
        bool isBipartite(vector<vector<int>> &graph)
        {
            vector<int> color(graph.size(),-1);
            
            for (int i = 0; i < graph.size(); i++)
            {
                if(color[i]==-1)
                {
                    if(!dfs(i,0,color,graph)) return false;
                }
            }
            return true;
        }
};

int main()
{
    vector<vector<int>> graph = {{1,3},{0,2},{1,3},{0,2}};
    Solution s;
    if(s.isBipartite(graph))
    {
        cout<<"True"<<endl;
    }
    else
    {
        cout<<"False"<<endl;
    }
}