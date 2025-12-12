#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <limits>
#include <stack>
#include<cfloat>
#include<cmath>
using namespace std;

// class Solution
// {
//     public:
//         // Time Complexity: O(n^2) - BFS visits each cell at most once
//         // Space Complexity: O(n^2) - visited array and queue storage
//         int shortestPathInBinaryMatrix(vector<vector<int>> &grid)
//         {
//             int n = grid.size();
//             if(grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;

//             queue<pair<pair<int,int>, int>> q; // {row, col}, distance
//             vector<vector<bool>> visited(n, vector<bool>(n, false));
//             vector<pair<int,int>> dir = {{1,0}, {0,1}, {-1,0}, {0,-1}, {1,1}, {-1,-1}, {1,-1}, {-1,1}};

//             q.push({{0,0}, 1});
//             visited[0][0] = true;

//             while(!q.empty())
//             {
//                 auto curr = q.front();
//                 q.pop();
//                 int row = curr.first.first;
//                 int col = curr.first.second;
//                 int dist = curr.second;

//                 if(row == n-1 && col == n-1) return dist;

//                 for(int i = 0; i < 8; i++)
//                 {
//                     int newRow = row + dir[i].first;
//                     int newCol = col + dir[i].second;

//                     if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < n &&
//                        !visited[newRow][newCol] && grid[newRow][newCol] == 0)
//                     {
//                         q.push({{newRow, newCol}, dist + 1});
//                         visited[newRow][newCol] = true;
//                     }
//                 }
//             }
//             return -1;
//         }

// };

// A* hurestics Search
struct Point
{
    int x, y;
};

struct Node
{
    int y, x;
    double f, g, h;
    int parent_x, parent_y;

    bool operator>(const Node &other) const
    {
        return f > other.f;
    }
};
bool isValid(int row, int col, int max_Row, int max_Col)
{
    return (row >= 0) && (row < max_Row) && (col >= 0) && (col < max_Col);
}

bool unBlocked(vector<vector<int>> &grid, int row, int col)
{
    return grid[row][col] == 0;
}

double calculateHValue(int row, int col, const Point &dest)
{
    return static_cast<double>(abs(row - dest.y) + abs(col - dest.x));
}

// NOT Neccesary Only For Visualization
void tracePath(vector<vector<Node>> &cellDetails, const Point &dest)
{
    cout << "The path is: ";
    stack<Point> path;
    int row = dest.y;
    int col = dest.x;

    while (!(cellDetails[row][col].parent_x == col && cellDetails[row][col].parent_y == row))
    {
        path.push({col, row});
        int temp_row = cellDetails[row][col].parent_y;
        int temp_col = cellDetails[row][col].parent_x;
        row = temp_row;
        col = temp_col;
    }

    path.push({col, row});
    while (!path.empty())
    {
        Point p = path.top();
        path.pop();
        cout << "-> (" << p.y << "," << p.x << ") ";
    }
    cout << endl;
}

class Solution
{
public:
    // Time Complexity: O(n^2 * log(n^2)) = O(n^2 * log(n)) - A* with priority queue
    // Space Complexity: O(n^2) - cellDetails, closedList, and priority queue storage
    int shortestPathInBinaryMatrix(vector<vector<int>> &grid)
    {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
            return -1;
        if (n == 1) return 1;
        const Point &src = {0, 0};
        const Point &dest = {n - 1, n - 1};

        if (!isValid(src.y, src.x, n, n) || !isValid(dest.y, dest.x, n, n))
        {
            cout << "Source or Destination is invalid." << std::endl;
            return -1;
        }

        if (!unBlocked(grid, src.y, src.y) || !unBlocked(grid, dest.y, dest.x))
        {
            cout << "Source or Destination is blocked." << std::endl;
            return -1;
        }

        if (src.x == dest.x && src.y == dest.y)
        {
            cout << "We are already at the destination." << std::endl;
            return -1;
        }

        vector<vector<bool>> closedList(n, vector<bool>(n, false));
        priority_queue<Node, vector<Node>, greater<Node>> openList;
        vector<vector<Node>> cellDetails(n, vector<Node>(n));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cellDetails[i][j].f = DBL_MAX;
                cellDetails[i][j].g = DBL_MAX;
                cellDetails[i][j].h = DBL_MAX;
                cellDetails[i][j].parent_y = -1;
                cellDetails[i][j].parent_x = -1;
                cellDetails[i][j].x = j;
                cellDetails[i][j].y = i;
            }
        }

        int i = src.y, j = src.x;
        cellDetails[i][j].g = 0.0;
        cellDetails[i][j].h = calculateHValue(i,j,dest);
        cellDetails[i][j].f = cellDetails[i][j].g+cellDetails[i][j].h;
        cellDetails[i][j].parent_x = j;
        cellDetails[i][j].parent_y = i;

        openList.push(cellDetails[i][j]);

        while (!openList.empty())
        {
            Node p = openList.top();
            i = p.y;
            j = p.x;
            openList.pop();
            closedList[i][j]=true;
            vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};
            for (int k = 0; k < 8; k++)
            {
                int newRow = i + dir[k].first;
                int newCol = j + dir[k].second;
                if (isValid(newRow, newCol, n, n) && unBlocked(grid, newRow, newCol) && !closedList[newRow][newCol])
                {
                    if (newRow == dest.y && newCol == dest.x)
                    {
                        cellDetails[newRow][newCol].parent_x = j;
                        cellDetails[newRow][newCol].parent_y = i;
                        cout << "Destination found!" << endl;
                        tracePath(cellDetails, dest);
                        return cellDetails[i][j].g+2.0;
                    }
                    double gNew = cellDetails[i][j].g + 1.0;
                    double hNew = calculateHValue(newRow, newCol, dest);
                    double fNew = gNew + hNew;

                    if (cellDetails[newRow][newCol].f == 0.0 || fNew < cellDetails[newRow][newCol].f)
                    {
                        cellDetails[newRow][newCol].f = fNew;
                        cellDetails[newRow][newCol].g = gNew;
                        cellDetails[newRow][newCol].h = hNew;
                        cellDetails[newRow][newCol].parent_x = j;
                        cellDetails[newRow][newCol].parent_y = i;
                        openList.push(cellDetails[newRow][newCol]);
                    }
                }
            }
        }
        cout << "Failed to find a path to the destination." << endl;
        return -1;
    }
};

int main()
{
    Solution sol;

    cout << "=== Shortest Path in Binary Matrix Test Cases ===\n\n";

    // Test Case 1
    vector<vector<int>> grid1 = {{0, 1}, {1, 0}};
    cout << "Test Case 1:" << endl;
    cout << "Grid: [[0,1],[1,0]]" << endl;
    int result1 = sol.shortestPathInBinaryMatrix(grid1);
    cout << "Shortest Path Length: " << result1 << endl;
    cout << "Expected: 2\n"
         << endl;

    // Test Case 2
    vector<vector<int>> grid2 = {{0, 0, 0}, {1, 1, 0}, {1, 1, 0}};
    cout << "Test Case 2:" << endl;
    cout << "Grid: [[0,0,0],[1,1,0],[1,1,0]]" << endl;
    int result2 = sol.shortestPathInBinaryMatrix(grid2);
    cout << "Shortest Path Length: " << result2 << endl;
    cout << "Expected: 4\n"
         << endl;

    // Test Case 3
    vector<vector<int>> grid3 = {{1, 0, 0}, {1, 1, 0}, {1, 1, 0}};
    cout << "Test Case 3:" << endl;
    cout << "Grid: [[1,0,0],[1,1,0],[1,1,0]]" << endl;
    int result3 = sol.shortestPathInBinaryMatrix(grid3);
    cout << "Shortest Path Length: " << result3 << endl;
    cout << "Expected: -1 (no path possible)\n"
         << endl;

    // Test Case 4
    vector<vector<int>> grid4 = {{0}};
    cout << "Test Case 4:" << endl;
    cout << "Grid: [[0]]" << endl;
    int result4 = sol.shortestPathInBinaryMatrix(grid4);
    cout << "Shortest Path Length: " << result4 << endl;
    cout << "Expected: 1\n"
         << endl;

    return 0;
}