// Date: 10/07/2026
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// Time Complexity: O(n^3)
// Space Complexity: O(n^2)
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int>(n,INT_MAX));

        for(auto edge:edges)
        {
            int u=edge[0];
            int v=edge[1];
            int wt=edge[2];
            dist[u][v]=wt;
            dist[v][u]=wt;
        }

        for(int k=0; k < n; k++)
        {
            for(int i=0; i < n; i++)
            {
                for(int j=0; j<n;j++)
                {
                    if(dist[i][k] != INT_MAX && dist[k][j] != INT_MAX)
                    {
                        dist[i][j]=min(dist[i][j] , dist[i][k]+dist[k][j]);
                    }
                }
            }
        }

        int minNeighbours=n, resultNeighbour=0;

        for(int i=0; i < n; i++)
        {
            int neighbours=0;
            for(int j=0; j < n; j++)
            {
                if(i!=j && dist[i][j] <= distanceThreshold)
                {
                    neighbours++;
                }
            }
            if(neighbours <= minNeighbours)
            {
                minNeighbours=neighbours;
                resultNeighbour=i;
            }
        }

        return resultNeighbour;
    }
};

int main()
{
    int n = 4;
    int distanceThreshold = 4;

    vector<vector<int>> edges = {
        {0, 1, 3},
        {1, 2, 1},
        {1, 3, 4},
        {2, 3, 1}
    };

    Solution s;
    cout << s.findTheCity(n, edges, distanceThreshold)<< endl;
}