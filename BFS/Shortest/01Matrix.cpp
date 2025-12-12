#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<utility>
using namespace std;

class Solution
{
    public:
        vector<vector<int>> newMatrix(vector<vector<int>> &matrix)
        {
            int row=matrix.size();
            int col=matrix[0].size();
            if(row==0) return {};

            queue<pair<int,int>> q;

            vector<vector<int>> distances(row, vector<int>(col, -1));
            
            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < col; j++)
                {
                    if(matrix[i][j]==0)
                    {
                        q.push({i,j});
                        distances[i][j]=0;
                    }
                }
            }

            int rows[]={-1, 1, 0, 0};
            int cols[]={0, 0, -1, 1};

            while(!q.empty())
            {
                pair<int,int> location=q.front();
                q.pop();
                for (int j = 0; j < 4; j++)
                {
                    int newRow=location.first+rows[j];
                    int newCol=location.second+cols[j];

                    if(newRow < row && newRow >= 0 && newCol < col && newCol >= 0 && distances[newRow][newCol]==-1)
                    {
                        distances[newRow][newCol]=distances[location.first][location.second]+1;
                        q.push({newRow,newCol});
                    }
                }
            }
            return distances;
        }
};

int main()
{
    vector<vector<int>> matrix = {
        {0, 0, 0},
        {0, 1, 0},
        {1, 1, 1}
    };

    // --- Key ---
    // 0: A source cell (distance is 0)
    // 1: A cell where we need to find the distance to the nearest 0

    Solution s;
    vector<vector<int>> ans=s.newMatrix(matrix);

    for (const auto& row : ans) {
        for (const auto& cell : row) {
            cout << cell << " ";
        }
        cout << ::endl;
    }
}