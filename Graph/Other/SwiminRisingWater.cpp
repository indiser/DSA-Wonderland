#include<iostream>
#include<vector>
#include<unordered_map>
#include<limits>
#include<queue>
#include<utility>
using namespace std;

class Solution
{
    public:
        const int INF=numeric_limits<int>::max();

        int swimInWater(vector<vector<int>>& grid) 
        {
            int n = grid.size();
            vector<vector<int>> dist(n, vector<int>(n, INF));
            priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<>> pq;
            
            pq.push({grid[0][0], {0, 0}});
            dist[0][0] = grid[0][0];
            
            int dx[] = {0, 1, 0, -1};
            int dy[] = {1, 0, -1, 0};
            
            while(!pq.empty())
            {
                int time = pq.top().first;
                auto pos = pq.top().second;
                auto x = pos.first;
                auto y = pos.second;
                pq.pop();
                
                if(x == n-1 && y == n-1) return time;
                if(time > dist[x][y]) continue;
                
                for(int i = 0; i < 4; i++)
                {
                    int nx = x + dx[i], ny = y + dy[i];
                    
                    if(nx >= 0 && nx < n && ny >= 0 && ny < n)
                    {
                        int newTime = max(time, grid[nx][ny]);
                        
                        if(newTime < dist[nx][ny])
                        {
                            dist[nx][ny] = newTime;
                            pq.push({newTime, {nx, ny}});
                        }
                    }
                }
            }
            
            return dist[n-1][n-1];
        }

};

int main()
{
    cout << "=== Swim in Rising Water ===" << endl;
    
    Solution sol;
    
    // Test case 1: Simple 2x2 grid
    cout << "\nTest Case 1: Simple 2x2 grid" << endl;
    vector<vector<int>> grid1 = {{0,2},{1,3}};
    
    cout << "Grid (elevation at each cell):" << endl;
    for(int i = 0; i < grid1.size(); i++)
    {
        cout << "  ";
        for(int j = 0; j < grid1[i].size(); j++)
        {
            cout << grid1[i][j] << " ";
        }
        cout << endl;
    }
    
    cout << "\nFinding minimum time to swim from (0,0) to (" << grid1.size()-1 << "," << grid1[0].size()-1 << ")" << endl;
    int result1 = sol.swimInWater(grid1);
    cout << "Minimum time required: " << result1 << endl;
    cout << "Explanation: Wait until time " << result1 << " when all cells in optimal path are accessible" << endl;
    
    // Test case 2: Larger 3x3 grid
    cout << "\nTest Case 2: 3x3 grid with obstacles" << endl;
    vector<vector<int>> grid2 = {{0,1,2,3,4},{24,23,22,21,5},{12,13,14,15,16},{11,17,18,19,20},{10,9,8,7,6}};
    
    cout << "Grid (elevation at each cell):" << endl;
    for(int i = 0; i < grid2.size(); i++)
    {
        cout << "  ";
        for(int j = 0; j < grid2[i].size(); j++)
        {
            cout << grid2[i][j];
            if(grid2[i][j] < 10) cout << "  ";
            else cout << " ";
        }
        cout << endl;
    }
    
    cout << "\nFinding minimum time to swim from (0,0) to (" << grid2.size()-1 << "," << grid2[0].size()-1 << ")" << endl;
    int result2 = sol.swimInWater(grid2);
    cout << "Minimum time required: " << result2 << endl;
    cout << "Explanation: Must wait for water level to rise enough to access optimal path" << endl;
    
    // Test case 3: High elevation start/end
    cout << "\nTest Case 3: High elevation corners" << endl;
    vector<vector<int>> grid3 = {{7,1,3},{2,4,6},{8,5,9}};
    
    cout << "Grid (elevation at each cell):" << endl;
    for(int i = 0; i < grid3.size(); i++)
    {
        cout << "  ";
        for(int j = 0; j < grid3[i].size(); j++)
        {
            cout << grid3[i][j] << " ";
        }
        cout << endl;
    }
    
    cout << "\nFinding minimum time to swim from (0,0) to (" << grid3.size()-1 << "," << grid3[0].size()-1 << ")" << endl;
    int result3 = sol.swimInWater(grid3);
    cout << "Minimum time required: " << result3 << endl;
    cout << "Explanation: High start elevation requires waiting until time " << result3 << endl;
    
    cout << "\nAlgorithm: Modified Dijkstra's algorithm" << endl;
    cout << "Finds path that minimizes maximum elevation encountered" << endl;
    cout << "Time Complexity: O(n² log(n²)), Space Complexity: O(n²)" << endl;
    
    return 0;
}