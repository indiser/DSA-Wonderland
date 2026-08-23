// Date: 11/07/2026
#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;

// Time Complexity: O(m * n)
// Space Complexity: O(m * n)
class Solution
{
    public:
        vector<vector<int>> updatemat(vector<vector<int>> &mat)
        {
            int row=mat.size();
            int col=mat[0].size();
            if(row==0) return {};

            queue<pair<int,int>> q;

            vector<vector<int>> distances(row, vector<int>(col, -1));
            
            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < col; j++)
                {
                    if(mat[i][j]==0)
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
                auto location=q.front();
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

    vector<vector<int>> mat1 = {{0,0,0},{0,1,0},{0,0,0}};
    
    cout << "Original mat:" << endl;
    for(int i = 0; i < mat1.size(); i++)
    {
        cout << "  ";
        for(int j = 0; j < mat1[i].size(); j++)
        {
            cout << mat1[i][j] << " ";
        }
        cout << endl;
    }

    Solution sol;

    vector<vector<int>> result1 = sol.updatemat(mat1);
    cout << "\nDistance mat (distance to nearest 0):" << endl;
    for(int i = 0; i < result1.size(); i++)
    {
        cout << "  ";
        for(int j = 0; j < result1[i].size(); j++)
        {
            cout << result1[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}