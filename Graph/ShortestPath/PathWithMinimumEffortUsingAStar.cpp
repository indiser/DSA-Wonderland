#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<utility>
#include<climits>
#include<cmath>
using namespace std;

struct Node {
    int x, y, effort;
    double f; // f = g + h (total cost)
    
    bool operator>(const Node& other) const {
        return f > other.f;
    }
};

class Solution
{
    public:
        // Time Complexity: O(m * n * log(m * n))
        // Space Complexity: O(m * n)
        int minimumEffortPath(vector<vector<int>> &heights)
        {
            int m = heights.size(), n = heights[0].size();
            vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
            priority_queue<Node, vector<Node>, greater<Node>> pq;
            vector<pair<int,int>> dirs = {{0,1}, {1,0}, {0,-1}, {-1,0}};
            
            // Heuristic: 0 (making it equivalent to Dijkstra for correctness)
            // Manhattan distance is not admissible for min-max effort problem
            auto heuristic = [&](int x, int y) -> double {
                return 0.0; // Admissible heuristic
            };
            
            pq.push({0, 0, 0, heuristic(0, 0)});
            dist[0][0] = 0;
            
            while (!pq.empty()) {
                Node curr = pq.top();
                pq.pop();
                
                if (curr.x == m-1 && curr.y == n-1) {
                    return curr.effort;
                }
                
                if (curr.effort > dist[curr.x][curr.y]) continue;
                
                for (auto& dir : dirs) {
                    int nx = curr.x + dir.first;
                    int ny = curr.y + dir.second;
                    
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                        int newEffort = max(curr.effort, abs(heights[nx][ny] - heights[curr.x][curr.y]));
                        
                        if (newEffort < dist[nx][ny]) {
                            dist[nx][ny] = newEffort;
                            double f = newEffort + heuristic(nx, ny);
                            pq.push({nx, ny, newEffort, f});
                        }
                    }
                }
            }
            
            return dist[m-1][n-1];
        }
};

int main()
{
    Solution sol;
    
    cout << "=== Path With Minimum Effort (A* Algorithm) ===\n\n";
    
    // Test Case 1
    vector<vector<int>> heights1 = {{1,2,2},{3,8,2},{5,3,5}};
    cout << "Test Case 1: 3x3 Grid" << endl;
    cout << "Heights matrix:" << endl;
    for(int i = 0; i < heights1.size(); i++) {
        cout << "  ";
        for(int j = 0; j < heights1[i].size(); j++) {
            cout << heights1[i][j] << " ";
        }
        cout << endl;
    }
    int result1 = sol.minimumEffortPath(heights1);
    cout << "Minimum effort: " << result1 << endl;
    cout << "Expected: 2\n" << endl;
    
    // Test Case 2
    vector<vector<int>> heights2 = {{1,2,1,1,1},{1,2,1,2,1},{1,2,1,2,1},{1,2,1,2,1},{1,1,1,2,1}};
    cout << "Test Case 2: 5x5 Grid" << endl;
    cout << "Heights matrix:" << endl;
    for(int i = 0; i < heights2.size(); i++) {
        cout << "  ";
        for(int j = 0; j < heights2[i].size(); j++) {
            cout << heights2[i][j] << " ";
        }
        cout << endl;
    }
    int result2 = sol.minimumEffortPath(heights2);
    cout << "Minimum effort: " << result2 << endl;
    cout << "Expected: 0\n" << endl;
    
    // Test Case 3
    vector<vector<int>> heights3 = {{0}};
    cout << "Test Case 3: Single Cell" << endl;
    cout << "Heights matrix: [[0]]" << endl;
    int result3 = sol.minimumEffortPath(heights3);
    cout << "Minimum effort: " << result3 << endl;
    cout << "Expected: 0\n" << endl;
    
    cout << "Algorithm: A* with admissible heuristic (h=0, equivalent to Dijkstra)" << endl;
    cout << "Time Complexity: O(m * n * log(m * n))" << endl;
    cout << "Space Complexity: O(m * n)" << endl;
    
    return 0;
}