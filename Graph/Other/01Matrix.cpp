#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<utility>
using namespace std;

/*
Time Complexity: O(m * n)
- m: number of rows, n: number of columns
- Initial scan: O(m * n) to find all 0s and initialize distance matrix
- BFS traversal: O(m * n) - each cell is visited exactly once
- Each cell is added to queue once and processed once
- Total: O(m * n)

Space Complexity: O(m * n)
- Distance matrix: O(m * n) to store distances
- BFS queue: O(m * n) in worst case when all cells are 0s
- Direction arrays: O(1) constant space
- Total auxiliary space: O(m * n)
*/
class Solution
{
    public:
        vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) 
        {
            int row=matrix.size();
            int col=matrix[0].size();
            if(row==0) return {};

            queue<pair<int,int>> q;

            vector<vector<int>> dist(row, vector<int>(col, -1));

            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < col; j++)
                {
                    if(matrix[i][j]==0)
                    {
                        q.push({i,j});
                        dist[i][j]=0;
                    }
                } 
            }

            int qr[]={-1,1,0,0};
            int qc[]={0,0,-1,1};
            while(!q.empty())
            {
                pair<int,int> current=q.front();
                q.pop();
                for (int i = 0; i < 4; i++)
                {
                    int newRow=current.first+qr[i];
                    int newCol=current.second+qc[i];
                    if(newRow < row && newRow >= 0 && newCol < col && newCol >= 0 && dist[newRow][newCol] == -1)
                    {
                        dist[newRow][newCol]=dist[current.first][current.second]+1;
                        q.push({newRow,newCol});
                    }
                }
            }
            return dist;
        }
};

int main()
{
    cout << "=== 01 Matrix - Distance to Nearest 0 ===" << endl;
    
    Solution sol;
    
    // Test case 1: Simple 3x3 matrix
    cout << "\nTest Case 1: Simple 3x3 matrix" << endl;
    vector<vector<int>> matrix1 = {{0,0,0},{0,1,0},{0,0,0}};
    
    cout << "Original matrix:" << endl;
    for(int i = 0; i < matrix1.size(); i++)
    {
        cout << "  ";
        for(int j = 0; j < matrix1[i].size(); j++)
        {
            cout << matrix1[i][j] << " ";
        }
        cout << endl;
    }
    
    vector<vector<int>> result1 = sol.updateMatrix(matrix1);
    cout << "\nDistance matrix (distance to nearest 0):" << endl;
    for(int i = 0; i < result1.size(); i++)
    {
        cout << "  ";
        for(int j = 0; j < result1[i].size(); j++)
        {
            cout << result1[i][j] << " ";
        }
        cout << endl;
    }
    
    // Test case 2: Larger matrix with multiple 1s
    cout << "\nTest Case 2: Larger matrix" << endl;
    vector<vector<int>> matrix2 = {{0,0,0},{0,1,0},{1,1,1}};
    
    cout << "Original matrix:" << endl;
    for(int i = 0; i < matrix2.size(); i++)
    {
        cout << "  ";
        for(int j = 0; j < matrix2[i].size(); j++)
        {
            cout << matrix2[i][j] << " ";
        }
        cout << endl;
    }
    
    vector<vector<int>> result2 = sol.updateMatrix(matrix2);
    cout << "\nDistance matrix (distance to nearest 0):" << endl;
    for(int i = 0; i < result2.size(); i++)
    {
        cout << "  ";
        for(int j = 0; j < result2[i].size(); j++)
        {
            cout << result2[i][j] << " ";
        }
        cout << endl;
    }
    
    // Test case 3: Matrix with corner 0s
    cout << "\nTest Case 3: Corner zeros" << endl;
    vector<vector<int>> matrix3 = {{1,1,1},{1,1,1},{1,1,0}};
    
    cout << "Original matrix:" << endl;
    for(int i = 0; i < matrix3.size(); i++)
    {
        cout << "  ";
        for(int j = 0; j < matrix3[i].size(); j++)
        {
            cout << matrix3[i][j] << " ";
        }
        cout << endl;
    }
    
    vector<vector<int>> result3 = sol.updateMatrix(matrix3);
    cout << "\nDistance matrix (distance to nearest 0):" << endl;
    for(int i = 0; i < result3.size(); i++)
    {
        cout << "  ";
        for(int j = 0; j < result3[i].size(); j++)
        {
            cout << result3[i][j] << " ";
        }
        cout << endl;
    }
    
    cout << "\nAlgorithm: Multi-source BFS starting from all 0s simultaneously" << endl;
    cout << "Each cell gets the minimum distance to any 0 in the matrix" << endl;
    cout << "Time Complexity: O(m*n), Space Complexity: O(m*n)" << endl;
    
    return 0;
}