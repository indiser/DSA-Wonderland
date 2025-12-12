#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

// Time Complexity:O(n*m)
// Space Complexity:O(n*m)

class Solution
{
    public:
        int multiSourceBFS(vector<vector<int>> &grid)
        {
            int row = grid.size();
            int col = grid[0].size();
            if(row==0) return 0;

            int freshCount = 0;
            int minutes = -1;
            queue<pair<int,int>> q;

            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < col; j++)
                {
                    if(grid[i][j]==1)
                    {
                        freshCount++;
                    }
                    else if(grid[i][j]==2)
                    {
                        q.push({i,j});
                    }
                }
            }

            if(freshCount==0) return 0;
            if(q.empty()) return -1;


            const int rows[] = {-1, 1 , 0, 0};
            const int cols[] = {0, 0, -1, 1};

            while(!q.empty())
            {
                minutes++;
                int levelSize=q.size();

                for (int i = 0; i < levelSize; i++)
                {
                    pair<int,int> corordinates=q.front();
                    q.pop();
                    for (int j = 0; j < 4; j++)
                    {
                        int newRow=corordinates.first+rows[j];
                        int newCol=corordinates.second+cols[j];

                        if(newRow < row && newCol < col && newRow >= 0 && newCol >= 0 && grid[newRow][newCol]==1)
                        {
                            grid[newRow][newCol]=2;
                            freshCount--;
                            q.push({newRow,newCol});
                        }
                    }
                }
            }
            
            return (freshCount==0) ? minutes : -1;
        }
};


// Memory Optimized
// class Solution
// {
//     public:
//         int multiSourceBFS(vector<vector<int>> &grid)
//         {
//             int row = grid.size();
//             int col = grid[0].size();
            
//             int freshCount = 0;
//             int minutes = -1;
//             queue<pair<int,int>> q;

//             for (int i = 0; i < row; i++)
//             {
//                 for (int j = 0; j < col; j++)
//                 {
//                     if(grid[i][j]==1) freshCount++;
//                     else if(grid[i][j]==2) q.push({i,j});
//                 }
//             }

//             if(freshCount==0) return 0;
//             if(q.empty()) return -1;

//             const int dx[] = {-1, 1, 0, 0};
//             const int dy[] = {0, 0, -1, 1};

//             while(!q.empty())
//             {
//                 minutes++;
//                 int size = q.size();

//                 for (int i = 0; i < size; i++)
//                 {
//                     auto [x, y] = q.front();
//                     q.pop();
                    
//                     for (int j = 0; j < 4; j++)
//                     {
//                         int nx = x + dx[j];
//                         int ny = y + dy[j];

//                         if(nx >= 0 && nx < row && ny >= 0 && ny < col && grid[nx][ny]==1)
//                         {
//                             grid[nx][ny] = 2;
//                             freshCount--;
//                             q.push({nx, ny});
//                         }
//                     }
//                 }
//             }
            
//             return freshCount == 0 ? minutes : -1;
//         }
// };

int main() {
    vector<vector<int>> grid = {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1}
    };

    // --- Key ---
    // 2: Rotten Orange
    // 1: Fresh Orange
    // 0: Empty Cell

    Solution s;
    cout<<s.multiSourceBFS(grid)<<endl;

    return 0;
}