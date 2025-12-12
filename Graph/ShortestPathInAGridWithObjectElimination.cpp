#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<string>
#include<utility>
using namespace std;

/*
Time Complexity: O(m * n * k)
- m: number of rows, n: number of columns
- k: maximum obstacles that can be eliminated
- Each cell can be visited at most k+1 times (with 0 to k obstacles eliminated)
- BFS processes each state once: O(m * n * k)
- Each state explores 4 directions: O(1) per state

Space Complexity: O(m * n + m * n * k)
- Visited array: O(m * n) to track minimum obstacles per cell
- BFS queue: O(m * n * k) in worst case when all states are queued
- Total: O(m * n * k) dominated by queue space
*/
class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) 
    {
        int m = grid.size(), n = grid[0].size();
        if(m == 1 && n == 1) return 0;
        
        queue<vector<int>> q; // {row, col, steps, obstacles}
        vector<vector<int>> visited(m, vector<int>(n, -1));
        
        q.push({0, 0, 0, 0});
        visited[0][0] = 0;
        
        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};

        while(!q.empty())
        {
            auto curr = q.front();
            q.pop();
            
            int x = curr[0], y = curr[1], steps = curr[2], obs = curr[3];

            for(int i = 0; i < 4; i++)
            {
                int nx = x + dx[i], ny = y + dy[i];
                
                if(nx >= 0 && nx < m && ny >= 0 && ny < n)
                {
                    int newObs = obs + grid[nx][ny];
                    
                    if(newObs <= k && (visited[nx][ny] == -1 || visited[nx][ny] > newObs))
                    {
                        if(nx == m-1 && ny == n-1) return steps + 1;
                            
                        visited[nx][ny] = newObs;
                        q.push({nx, ny, steps+1, newObs});
                    }
                }
            }
        }
        
        return -1;
    }
};

int main()
{
    cout << "=== Shortest Path in Grid with Obstacle Elimination ===" << endl;
    
    Solution s;
    
    // Test case 1: Original grid
    cout << "\nTest Case 1: Grid with obstacles" << endl;
    vector<vector<int>> grid1 = {{0,0,0},{1,1,0},{0,0,0},{0,1,1},{0,0,0}};
    int k1 = 1;
    
    cout << "Grid (0=empty, 1=obstacle):" << endl;
    for(int i = 0; i < grid1.size(); i++)
    {
        cout << "  ";
        for(int j = 0; j < grid1[i].size(); j++)
        {
            cout << grid1[i][j] << " ";
        }
        cout << endl;
    }
    
    cout << "Maximum obstacles that can be eliminated: " << k1 << endl;
    cout << "Path from (0,0) to (" << grid1.size()-1 << "," << grid1[0].size()-1 << ")" << endl;
    
    int result1 = s.shortestPath(grid1, k1);
    cout << "Shortest path length: " << (result1 == -1 ? "No path possible" : to_string(result1)) << endl;
    
    // Test case 2: Simple path without obstacles
    cout << "\nTest Case 2: Clear path" << endl;
    vector<vector<int>> grid2 = {{0,0,0},{0,0,0},{0,0,0}};
    int k2 = 0;
    
    cout << "Grid (0=empty, 1=obstacle):" << endl;
    for(int i = 0; i < grid2.size(); i++)
    {
        cout << "  ";
        for(int j = 0; j < grid2[i].size(); j++)
        {
            cout << grid2[i][j] << " ";
        }
        cout << endl;
    }
    
    cout << "Maximum obstacles that can be eliminated: " << k2 << endl;
    cout << "Path from (0,0) to (" << grid2.size()-1 << "," << grid2[0].size()-1 << ")" << endl;
    
    int result2 = s.shortestPath(grid2, k2);
    cout << "Shortest path length: " << (result2 == -1 ? "No path possible" : to_string(result2)) << endl;
    
    // Test case 3: Blocked path requiring elimination
    cout << "\nTest Case 3: Blocked path needing elimination" << endl;
    vector<vector<int>> grid3 = {{0,1,1},{1,1,1},{1,0,0}};
    int k3 = 2;
    
    cout << "Grid (0=empty, 1=obstacle):" << endl;
    for(int i = 0; i < grid3.size(); i++)
    {
        cout << "  ";
        for(int j = 0; j < grid3[i].size(); j++)
        {
            cout << grid3[i][j] << " ";
        }
        cout << endl;
    }
    
    cout << "Maximum obstacles that can be eliminated: " << k3 << endl;
    cout << "Path from (0,0) to (" << grid3.size()-1 << "," << grid3[0].size()-1 << ")" << endl;
    
    int result3 = s.shortestPath(grid3, k3);
    cout << "Shortest path length: " << (result3 == -1 ? "No path possible" : to_string(result3)) << endl;
    
    cout << "\nAlgorithm: BFS with state tracking (row, col, obstacles_used)" << endl;
    cout << "Finds shortest path while allowing elimination of up to k obstacles" << endl;
    
    return 0;
}