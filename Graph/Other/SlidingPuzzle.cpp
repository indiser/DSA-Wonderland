#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<string>
using namespace std;

struct Node {
    string state;
    int g; // actual cost (moves)
    int h; // heuristic cost
    int f; // total cost (g + h)
    
    bool operator>(const Node& other) const {
        return f > other.f;
    }
};

class Solution {
public:
    // Time Complexity: O(b^d) where b is branching factor, d is depth
    // Space Complexity: O(6!) - visited set and priority queue storage
    
    // Manhattan distance heuristic
    int calculateHeuristic(const string& state) {
        int h = 0;
        for(int i = 0; i < 6; i++) {
            if(state[i] != '0') {
                int val = state[i] - '1'; // Convert to 0-4 range
                int currRow = i / 3, currCol = i % 3;
                int targetRow = val / 3, targetCol = val % 3;
                h += abs(currRow - targetRow) + abs(currCol - targetCol);
            }
        }
        return h;
    }
    
    int slidingPuzzle(vector<vector<int>>& board) {
        string target = "123450";
        string start = "";
        
        // Convert board to string
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 3; j++) {
                start += to_string(board[i][j]);
            }
        }
        
        if(start == target) return 0;
        
        // Adjacent positions for each index in 2x3 grid
        vector<vector<int>> neighbors = {
            {1, 3},       // 0 can swap with 1, 3
            {0, 2, 4},    // 1 can swap with 0, 2, 4
            {1, 5},       // 2 can swap with 1, 5
            {0, 4},       // 3 can swap with 0, 4
            {1, 3, 5},    // 4 can swap with 1, 3, 5
            {2, 4}        // 5 can swap with 2, 4
        };
        
        priority_queue<Node, vector<Node>, greater<Node>> pq;
        unordered_set<string> visited;
        
        int startH = calculateHeuristic(start);
        pq.push({start, 0, startH, startH});
        visited.insert(start);
        
        while(!pq.empty()) {
            Node curr = pq.top();
            pq.pop();
            
            if(curr.state == target) return curr.g;
            
            // Find position of 0
            int zeroPos = curr.state.find('0');
            
            // Try all possible swaps
            for(int nextPos : neighbors[zeroPos]) {
                string next = curr.state;
                swap(next[zeroPos], next[nextPos]);
                
                if(visited.find(next) == visited.end()) {
                    visited.insert(next);
                    int g = curr.g + 1;
                    int h = calculateHeuristic(next);
                    pq.push({next, g, h, g + h});
                }
            }
        }
        
        return -1;
    }
};

int main()
{
    Solution sol;
    
    cout << "=== Sliding Puzzle Solver ===\n\n";
    
    // Test Case 1
    vector<vector<int>> board1 = {{1,2,3},{4,0,5}};
    cout << "Test Case 1:" << endl;
    cout << "Initial board:" << endl;
    cout << "  " << board1[0][0] << " " << board1[0][1] << " " << board1[0][2] << endl;
    cout << "  " << board1[1][0] << " " << board1[1][1] << " " << board1[1][2] << endl;
    cout << "Target board:" << endl;
    cout << "  1 2 3" << endl;
    cout << "  4 5 0" << endl;
    int result1 = sol.slidingPuzzle(board1);
    cout << "Minimum moves: " << result1 << endl;
    cout << "Expected: 1\n" << endl;
    
    // Test Case 2
    vector<vector<int>> board2 = {{1,2,3},{5,4,0}};
    cout << "Test Case 2:" << endl;
    cout << "Initial board:" << endl;
    cout << "  " << board2[0][0] << " " << board2[0][1] << " " << board2[0][2] << endl;
    cout << "  " << board2[1][0] << " " << board2[1][1] << " " << board2[1][2] << endl;
    cout << "Target board:" << endl;
    cout << "  1 2 3" << endl;
    cout << "  4 5 0" << endl;
    int result2 = sol.slidingPuzzle(board2);
    cout << "Minimum moves: " << result2 << endl;
    cout << "Expected: -1 (impossible)\n" << endl;
    
    // Test Case 3
    vector<vector<int>> board3 = {{4,1,2},{5,0,3}};
    cout << "Test Case 3:" << endl;
    cout << "Initial board:" << endl;
    cout << "  " << board3[0][0] << " " << board3[0][1] << " " << board3[0][2] << endl;
    cout << "  " << board3[1][0] << " " << board3[1][1] << " " << board3[1][2] << endl;
    cout << "Target board:" << endl;
    cout << "  1 2 3" << endl;
    cout << "  4 5 0" << endl;
    int result3 = sol.slidingPuzzle(board3);
    cout << "Minimum moves: " << result3 << endl;
    cout << "Expected: 5\n" << endl;
    
    cout << "Algorithm: A* with Manhattan distance heuristic" << endl;
    cout << "Time Complexity: O(6!) = O(720)" << endl;
    cout << "Space Complexity: O(6!) for visited states" << endl;
    
    return 0;
}