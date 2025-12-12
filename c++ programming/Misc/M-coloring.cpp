#include<iostream>
#include<vector>
// Time Complexity: O(N * m^N) where N is the number of vertices and m is the number of colors.
//   - The algorithm explores a recursion tree. For each of the N nodes, it tries m colors.
//   - In the worst case, this leads to m^N states. For each state, it calls isSafe(), which takes O(N).
// Space Complexity: O(N) for the recursion stack depth and the color array.
using namespace std;

class Solution
{
    public:
        bool isSafe(vector<vector<int>> &graph, vector<int> &color ,int node, int n, int col)
        {
            for (int i = 0; i < n; i++)
            {
                if(i != node && graph[i][node]==1 && color[i]==col)
                {
                    return false;
                }
            }
            return true;
        }
        bool solve(vector<vector<int>> &graph, vector<int> &color, int node, int m, int N)
        {
            if(node==N)
            {
                return true;
            }
            for (int i = 1; i <= m; i++)
            {
                if(isSafe(graph,color,node,N,i))
                {
                    color[node]=i;
                    if(solve(graph,color,node+1,m,N)) return true;
                    color[node]=0;
                }
            }
            return false;
        }
        bool graphColoring(vector<vector<int>> &graph, int m, int N)
        {
            vector<int> color(N,0);
            if(solve(graph,color,0,m,N)) return true;
            return false;
        }

};

int main()
{
    // Number of vertices
    int N=4;
    // Number of colors
    int m=3;

    // The graph should be an adjacency matrix for the provided solution.
    // The following matrix represents a graph with edges from the original example:
    // (0,1), (1,3), (2,3), (3,0), (0,2)
    vector<vector<int>> graph = { {0, 1, 1, 1},
                                  {1, 0, 0, 1},
                                  {1, 0, 0, 1},
                                  {1, 1, 1, 0} };
    Solution s;
    cout << boolalpha << s.graphColoring(graph, m, N) << endl;
}