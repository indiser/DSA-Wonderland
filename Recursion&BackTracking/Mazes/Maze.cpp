#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution
{
    public:
        bool solveMaze(vector<vector<char>> &maze, int row, int col)
        {
            if(row < 0 || row >= maze.size() || col < 0 || col >= maze[0].size() || maze[row][col]=='#' || maze[row][col]=='*')
            {
                return false;
            }
            if(maze[row][col]=='E')
            {
                return true;
            }
            maze[row][col]='*';
            if(solveMaze(maze,row+1,col)) return true;
            if(solveMaze(maze,row-1,col)) return true;
            if(solveMaze(maze,row,col+1)) return true;
            if(solveMaze(maze,row,col-1)) return true;

            maze[row][col]='.';

            return false;
        }
};

int main()
{
    vector<vector<char>> maze = {
        {'S', '.', '.', '#', '.', '.'},
        {'#', '#', '.', '#', '.', '#'},
        {'.', '.', '.', '.', '.', '.'},
        {'.', '#', '#', '#', '#', '.'},
        {'.', '.', '.', '.', '#', 'E'},
        {'#', '#', '#', '.', '.', '#'}
    };

    Solution s;

    int startRow=-1,startCol=-1;

    for (int i = 0; i < maze.size(); i++)
    {
        for (int j = 0; j < maze[0].size(); j++)
        {
            if(maze[i][j]=='S')
            {
                startRow=i;
                startCol=j;
                break;
            }
        }
    }

    // if(s.solveMaze(maze,startRow,startCol))
    // {
    //     cout<<"Found"<<endl;
    // }
    // else
    // {
    //     cout<<"Not Found"<<endl;
    // }
    if (startRow != -1) {
        if (s.solveMaze(maze, startRow, startCol)) {
            cout << "Path Found! Solved Maze:" << endl;
            // Mark the start position for clarity in the output
            maze[startRow][startCol] = 'S'; 
            for (const auto &row_val : maze) {
                for (char cell : row_val) {
                    cout << cell << " ";
                }
                cout << endl;
            }
        } else {
            cout << "No path found." << endl;
        }
    } else {
        cout << "Start 'S' not found in the maze." << endl;
    }
    
    return 0;

}