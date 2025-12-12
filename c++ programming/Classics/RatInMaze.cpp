#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Time Complexity:O(4^(n^2))
// Space Complexity:O(n^2)

class Solution
{
public:
    void mazeTraveller(vector<vector<int>> &maze, int row, int col, vector<vector<bool>> &visited, string result, vector<string> &ans)
    {
        if (row < 0 || row >= maze.size() || col < 0 || col >= maze[0].size() || maze[row][col] == 0 || visited[row][col]==true)
        {
            return;
        }
        int n = maze.size();
        if (row == n - 1 && col == n - 1)
        {
            ans.push_back(result);
            return;
        }

        visited[row][col] = true;
        mazeTraveller(maze, row + 1, col, visited, result + 'D', ans);
        mazeTraveller(maze, row - 1, col, visited, result + 'U', ans);
        mazeTraveller(maze, row, col + 1, visited, result + 'R', ans);
        mazeTraveller(maze, row, col - 1, visited, result + 'L', ans);
        visited[row][col] = false;
    }
    vector<string> ratInMaze(vector<vector<int>> &maze)
    {
        vector<vector<bool>> visited(maze.size(), vector<bool>(maze[0].size(), false));
        vector<string> ans;
        string result = "";

        mazeTraveller(maze, 0, 0, visited, result, ans);

        return ans;
    }
};

int main()
{
    vector<vector<int>> maze = {{1, 0, 0, 0},
                                {1, 1, 0, 1},
                                {1, 1, 0, 1},
                                {0, 1, 1, 1}};
    Solution s;
    vector<string> ans = s.ratInMaze(maze);
    for (string s : ans)
    {
        cout << s << endl;
    }
}