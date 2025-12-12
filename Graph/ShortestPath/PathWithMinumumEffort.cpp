#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<queue>
#include<numeric>
using namespace std;

// class Solution
// {
//     public:
//         bool dfs(vector<vector<int>>& heights, int row, int col, vector<vector<bool>> &visited, int maxEffort)
//         {
//             if(row < 0 || row >= heights.size() || col < 0 || col >= heights[0].size() || visited[row][col]) return false;
            
//             if(row == heights.size()-1 && col == heights[0].size()-1) return true;
            
//             visited[row][col] = true;
            
//             vector<pair<int,int>> directions = {{0,1}, {1,0}, {0,-1}, {-1,0}};
            
//             for(auto dir : directions)
//             {
//                 int newRow = row + dir.first;
//                 int newCol = col + dir.second;
                
//                 if(newRow >= 0 && newRow < heights.size() && newCol >= 0 && newCol < heights[0].size())
//                 {
//                     int effort = abs(heights[newRow][newCol] - heights[row][col]);
//                     if(effort <= maxEffort && dfs(heights, newRow, newCol, visited, maxEffort))
//                     {
//                         return true;
//                     }
//                 }
//             }
            
//             return false;
//         }
//         int minimumEffortPath(vector<vector<int>>& heights)
//         {
//             int left = 0, right = 1000000;
//             int result = right;
            
//             while(left <= right)
//             {
//                 int mid = left + (right - left) / 2;
//                 vector<vector<bool>> visited(heights.size(), vector<bool>(heights[0].size(), false));
                
//                 if(dfs(heights, 0, 0, visited, mid))
//                 {
//                     result = mid;
//                     right = mid - 1;
//                 }
//                 else
//                 {
//                     left = mid + 1;
//                 }
//             }
            
//             return result;
//         }
// };



/*
Time Complexity: O(m * n * log(m * n))
- m: number of rows, n: number of columns
- Building adjacency list: O(m * n) cells × 4 directions = O(m * n)
- Modified Dijkstra: O((V + E) log V) where V = m*n, E = 4*m*n
- Priority queue operations: O(log(m * n)) per operation
- Total: O(m * n * log(m * n))

Space Complexity: O(m * n)
- Adjacency list: O(m * n) nodes with O(4) edges each = O(m * n)
- Distance array: O(m * n)
- Priority queue: O(m * n) in worst case
*/

class Solution
{
    public:
        const int INF=numeric_limits<int>::max();
        vector<vector<pair<int,int>>> adjList(vector<vector<int>> &heights)
        {
            int m = heights.size(), n = heights[0].size();
            vector<vector<pair<int,int>>> adj(m * n);
            vector<pair<int,int>> directions = {{0,1}, {1,0}, {0,-1}, {-1,0}};
            
            for(int i = 0; i < m; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    int u = i * n + j;
                    for(auto dir : directions)
                    {
                        int ni = i + dir.first;
                        int nj = j + dir.second;
                        if(ni >= 0 && ni < m && nj >= 0 && nj < n)
                        {
                            int v = ni * n + nj;
                            int cost = abs(heights[ni][nj] - heights[i][j]);
                            adj[u].push_back({v, cost});
                        }
                    }
                }
            }
            return adj;
        }
        int minimumEffortPath(vector<vector<int>>& heights)
        {
            int m = heights.size(), n = heights[0].size();
            vector<vector<pair<int,int>>> adj = adjList(heights);
            vector<int> dist(m * n, INF);
            priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
            
            pq.push({0, 0});
            dist[0] = 0;

            while(!pq.empty())
            {
                int u = pq.top().second;
                int d = pq.top().first;
                pq.pop();

                if(d > dist[u]) continue;
                
                for(auto neighbour : adj[u])
                {
                    int v = neighbour.first;
                    int wt = neighbour.second;

                    if(max(dist[u], wt) < dist[v])
                    {
                        dist[v] = max(dist[u], wt);
                        pq.push({dist[v], v});
                    }
                }
            }
            
            return dist[m * n - 1];
        }
};

int main()
{
    cout << "=== Path With Minimum Effort ===" << endl;
    
    Solution sol;
    
    // Test case 1: Simple 3x3 grid
    cout << "\nTest Case 1: 3x3 Grid" << endl;
    vector<vector<int>> heights1 = {{1,2,2},{3,8,2},{5,3,5}};
    
    cout << "Grid:" << endl;
    for(int i = 0; i < heights1.size(); i++)
    {
        cout << "  ";
        for(int j = 0; j < heights1[i].size(); j++)
        {
            cout << heights1[i][j] << " ";
        }
        cout << endl;
    }
    
    cout << "\nFinding path from top-left (0,0) to bottom-right (" << heights1.size()-1 << "," << heights1[0].size()-1 << ")" << endl;
    cout << "Goal: Minimize the maximum effort (height difference) in the path" << endl;
    
    int result1 = sol.minimumEffortPath(heights1);
    cout << "\nMinimum effort required: " << result1 << endl;
    cout << "Explanation: Path with max effort " << result1 << " exists from start to end" << endl;
    
    // Test case 2: Larger grid
    cout << "\nTest Case 2: 3x3 Grid with higher differences" << endl;
    vector<vector<int>> heights2 = {{1,2,1,1,1},{1,2,1,2,1},{1,2,1,2,1},{1,2,1,2,1},{1,1,1,2,1}};
    
    cout << "Grid:" << endl;
    for(int i = 0; i < heights2.size(); i++)
    {
        cout << "  ";
        for(int j = 0; j < heights2[i].size(); j++)
        {
            cout << heights2[i][j] << " ";
        }
        cout << endl;
    }
    
    cout << "\nFinding path from top-left (0,0) to bottom-right (" << heights2.size()-1 << "," << heights2[0].size()-1 << ")" << endl;
    
    int result2 = sol.minimumEffortPath(heights2);
    cout << "\nMinimum effort required: " << result2 << endl;
    cout << "Explanation: Optimal path avoids high effort transitions" << endl;
    
    // Test case 3: Single cell
    cout << "\nTest Case 3: Single cell" << endl;
    vector<vector<int>> heights3 = {{0}};
    
    cout << "Grid: [0]" << endl;
    cout << "Path from (0,0) to (0,0) - same cell" << endl;
    
    int result3 = sol.minimumEffortPath(heights3);
    cout << "\nMinimum effort required: " << result3 << endl;
    cout << "Explanation: No movement needed, effort is 0" << endl;
    
    cout << "\nAlgorithm: Modified Dijkstra's algorithm with priority queue" << endl;
    cout << "Time Complexity: O(m * n * log(m * n))" << endl;
    cout << "Space Complexity: O(m * n) for adjacency list and distance array" << endl;
    
    return 0;
}