/*
A* Search Algorithm Implementation

Time Complexity: O(b^d)
- b = branching factor (4 in this case - up, down, left, right)
- d = depth of optimal solution
- In worst case: O(V * log V) where V = number of vertices (grid cells)
- Priority queue operations: O(log V) for each vertex

Space Complexity: O(V)
- closedList: O(rows * cols)
- cellDetails: O(rows * cols) 
- openList (priority queue): O(V) in worst case
- Overall: O(rows * cols) = O(V)

Optimal: Yes, with admissible heuristic (Manhattan distance)
Complete: Yes, will find solution if one exists
*/

#include<iostream>
#include<vector>
#include<unordered_map>
#include<stack>
#include<queue>
#include<limits>
#include<cmath>
#include<utility>
using namespace std;

struct Point
{
    int x,y;
        
    bool operator<(const Point& other) const 
    {
        if (x != other.x) return x < other.x;
        return y < other.y;
    }
};

struct Node
{
    int y,x;
    int parent_y,parent_x;
    double f,g,h;
};

bool isValid(int row, int col, int max_row, int max_col)
{
    return (row>=0) && (row < max_row) && (col >= 0) && (col < max_col);
}

bool unBlocked(vector<vector<int>> &grid, int row, int col)
{
    return grid[row][col]==0;
}

double calculateHValue(int row, int col, const  Point& dest)
{
    return static_cast<double>(abs(row-dest.y)+abs(col-dest.x));
}

void tracePath(vector<vector<Node>>& cellDetails, const Point& dest)
{
    cout << "The path is: ";
    stack<Point> path;
    int row=dest.y;
    int col=dest.x;

    while(!(cellDetails[row][col].parent_y==row && cellDetails[row][col].parent_x==col))
    {
        path.push({col,row});
        int temp_row=cellDetails[row][col].parent_y;
        int temp_col=cellDetails[row][col].parent_x;
        row=temp_row;
        col=temp_col;
    }

    path.push({col,row});
    while(!path.empty())
    {
        Point p=path.top();
        path.pop();
        cout << "-> (" << p.y << "," << p.x << ") ";
    }
    cout<<endl;
}

void aStarSearch(vector<vector<int>> &grid,const Point& src, const Point& dest)
{
    int max_row=grid.size();
    int max_col=grid[0].size();

    if(!isValid(src.y, src.x, max_row, max_col) || !isValid(dest.y, dest.x, max_row, max_col))
    {
        cout << "Source or Destination is invalid." << std::endl;
        return;
    }
    if(!unBlocked(grid,src.y,src.x) || !unBlocked(grid,dest.y,dest.x))
    {
        cout << "Source or Destination is blocked." << std::endl;
        return;
    }
    if(src.x==dest.x && src.y==dest.y)
    {
        cout << "We are already at the destination." << std::endl;
        return;
    }

    vector<vector<bool>> closedList(max_row, vector<bool>(max_col,false));
    vector<vector<Node>> cellDetails(max_row,vector<Node>(max_col));

    int i=src.y, j=src.x;
    cellDetails[i][j].g=0.0;
    cellDetails[i][j].h=0.0;
    cellDetails[i][j].f=0.0;
    cellDetails[i][j].parent_y=i;
    cellDetails[i][j].parent_x=j;

    priority_queue<pair<double,Point>, vector<pair<double,Point>>, greater<pair<double,Point>>> openList;
    openList.push({0.0,{j,i}});

    while(!openList.empty())
    {
        const auto& p=openList.top();
        i=p.second.y;
        j=p.second.x;
        openList.pop();

        closedList[i][j]=true;
        int dRow[]={-1,1,0,0};
        int dCol[]={0,0,-1,1};

        for (int k = 0; k < 4; k++)
        {
            int new_Row=i+dRow[k];
            int new_Col=j+dCol[k];

            if(isValid(new_Row,new_Col,max_row,max_col) && unBlocked(grid,new_Row,new_Col) && !closedList[new_Row][new_Col])
            {
                if(new_Row==dest.y && new_Col==dest.x)
                {
                    cellDetails[new_Row][new_Col].parent_x=j;
                    cellDetails[new_Row][new_Col].parent_y=i;
                    cout << "Destination found!" << endl;
                    tracePath(cellDetails,dest);
                    return;
                }
                double gNew=cellDetails[i][j].g+1.0;
                double hNew=calculateHValue(new_Row,new_Col,dest);
                double fNew=gNew+hNew;

                if(cellDetails[new_Row][new_Col].f == 0.0 || fNew < cellDetails[new_Row][new_Col].f)
                {
                    openList.push({fNew,{new_Col,new_Row}});
                    cellDetails[new_Row][new_Col].f=fNew;
                    cellDetails[new_Row][new_Col].g=gNew;
                    cellDetails[new_Row][new_Col].h=hNew;
                    cellDetails[new_Row][new_Col].parent_x=j;
                    cellDetails[new_Row][new_Col].parent_y=i;
                }
            }
        }
    }
    cout << "Failed to find a path to the destination." << endl;
}

int main()
{
    cout << "=== A* Search Algorithm ===" << endl;
    
    // Test case 1: Simple path finding
    cout << "\nTest Case 1: Simple pathfinding" << endl;
    vector<vector<int>> grid1 = {
        {0, 0, 0, 0, 0},
        {0, 1, 1, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 0, 0, 0}
    };
    
    cout << "Grid (0=free, 1=blocked):" << endl;
    for(int i = 0; i < grid1.size(); i++)
    {
        cout << "  ";
        for(int j = 0; j < grid1[i].size(); j++)
        {
            cout << grid1[i][j] << " ";
        }
        cout << endl;
    }
    
    Point src1 = {0, 0};
    Point dest1 = {4, 4};
    cout << "\nFinding path from (" << src1.y << "," << src1.x << ") to (" << dest1.y << "," << dest1.x << ")" << endl;
    aStarSearch(grid1, src1, dest1);
    
    // Test case 2: No path available
    cout << "\nTest Case 2: Blocked destination" << endl;
    vector<vector<int>> grid2 = {
        {0, 0, 0},
        {1, 1, 1},
        {0, 0, 1}
    };
    
    cout << "Grid (0=free, 1=blocked):" << endl;
    for(int i = 0; i < grid2.size(); i++)
    {
        cout << "  ";
        for(int j = 0; j < grid2[i].size(); j++)
        {
            cout << grid2[i][j] << " ";
        }
        cout << endl;
    }
    
    Point src2 = {0, 0};
    Point dest2 = {2, 2};
    cout << "\nFinding path from (" << src2.y << "," << src2.x << ") to (" << dest2.y << "," << dest2.x << ")" << endl;
    aStarSearch(grid2, src2, dest2);
    
    // Test case 3: Complex maze
    cout << "\nTest Case 3: Complex maze" << endl;
    vector<vector<int>> grid3 = {
        {0, 1, 0, 0, 0, 0},
        {0, 1, 0, 1, 1, 0},
        {0, 0, 0, 1, 0, 0},
        {1, 1, 0, 1, 0, 1},
        {0, 0, 0, 0, 0, 0}
    };
    
    cout << "Grid (0=free, 1=blocked):" << endl;
    for(int i = 0; i < grid3.size(); i++)
    {
        cout << "  ";
        for(int j = 0; j < grid3[i].size(); j++)
        {
            cout << grid3[i][j] << " ";
        }
        cout << endl;
    }
    
    Point src3 = {0, 0};
    Point dest3 = {4, 5};
    cout << "\nFinding path from (" << src3.y << "," << src3.x << ") to (" << dest3.y << "," << dest3.x << ")" << endl;
    aStarSearch(grid3, src3, dest3);
    
    // Test case 4: Single row path
    cout << "\nTest Case 4: Single row path" << endl;
    vector<vector<int>> grid4 = {{0, 0, 0, 0, 0}};
    cout << "Grid (0=free, 1=blocked):" << endl;
    for(int i = 0; i < grid4.size(); i++)
    {
        cout << "  ";
        for(int j = 0; j < grid4[i].size(); j++)
        {
            cout << grid4[i][j] << " ";
        }
        cout << endl;
    }
    Point src4 = {0, 0}; Point dest4 = {4, 0};
    cout << "\nFinding path from (" << src4.y << "," << src4.x << ") to (" << dest4.y << "," << dest4.x << ")" << endl;
    aStarSearch(grid4, src4, dest4);
    
    // Test case 5: Single column path
    cout << "\nTest Case 5: Single column path" << endl;
    vector<vector<int>> grid5 = {{0}, {0}, {0}, {0}};
    cout << "Grid (0=free, 1=blocked):" << endl;
    for(int i = 0; i < grid5.size(); i++)
    {
        cout << "  ";
        for(int j = 0; j < grid5[i].size(); j++)
        {
            cout << grid5[i][j] << " ";
        }
        cout << endl;
    }
    Point src5 = {0, 0}; Point dest5 = {0, 3};
    cout << "\nFinding path from (" << src5.y << "," << src5.x << ") to (" << dest5.y << "," << dest5.x << ")" << endl;
    aStarSearch(grid5, src5, dest5);
    
    // Test case 6: Same position
    cout << "\nTest Case 6: Same position" << endl;
    vector<vector<int>> grid6 = {{0, 0}, {0, 0}};
    cout << "Grid (0=free, 1=blocked):" << endl;
    for(int i = 0; i < grid6.size(); i++)
    {
        cout << "  ";
        for(int j = 0; j < grid6[i].size(); j++)
        {
            cout << grid6[i][j] << " ";
        }
        cout << endl;
    }
    Point src6 = {1, 1}; Point dest6 = {1, 1};
    cout << "\nFinding path from (" << src6.y << "," << src6.x << ") to (" << dest6.y << "," << dest6.x << ")" << endl;
    aStarSearch(grid6, src6, dest6);
    
    // Test case 7: L-shaped path
    cout << "\nTest Case 7: L-shaped path" << endl;
    vector<vector<int>> grid7 = {
        {0, 1, 1, 1},
        {0, 1, 0, 0},
        {0, 0, 0, 1},
        {1, 1, 0, 0}
    };
    cout << "Grid (0=free, 1=blocked):" << endl;
    for(int i = 0; i < grid7.size(); i++)
    {
        cout << "  ";
        for(int j = 0; j < grid7[i].size(); j++)
        {
            cout << grid7[i][j] << " ";
        }
        cout << endl;
    }
    Point src7 = {0, 0}; Point dest7 = {3, 3};
    cout << "\nFinding path from (" << src7.y << "," << src7.x << ") to (" << dest7.y << "," << dest7.x << ")" << endl;
    aStarSearch(grid7, src7, dest7);
    
    // Test case 8: Spiral maze
    cout << "\nTest Case 8: Spiral maze" << endl;
    vector<vector<int>> grid8 = {
        {0, 0, 0, 0, 0},
        {1, 1, 1, 1, 0},
        {0, 0, 0, 0, 0},
        {0, 1, 1, 1, 1},
        {0, 0, 0, 0, 0}
    };
    cout << "Grid (0=free, 1=blocked):" << endl;
    for(int i = 0; i < grid8.size(); i++)
    {
        cout << "  ";
        for(int j = 0; j < grid8[i].size(); j++)
        {
            cout << grid8[i][j] << " ";
        }
        cout << endl;
    }
    Point src8 = {0, 0}; Point dest8 = {4, 4};
    cout << "\nFinding path from (" << src8.y << "," << src8.x << ") to (" << dest8.y << "," << dest8.x << ")" << endl;
    aStarSearch(grid8, src8, dest8);
    
    // Test case 9: Narrow corridor
    cout << "\nTest Case 9: Narrow corridor" << endl;
    vector<vector<int>> grid9 = {
        {0, 1, 1, 1, 0},
        {0, 0, 0, 0, 0},
        {0, 1, 1, 1, 0}
    };
    cout << "Grid (0=free, 1=blocked):" << endl;
    for(int i = 0; i < grid9.size(); i++)
    {
        cout << "  ";
        for(int j = 0; j < grid9[i].size(); j++)
        {
            cout << grid9[i][j] << " ";
        }
        cout << endl;
    }
    Point src9 = {0, 0}; Point dest9 = {4, 0};
    cout << "\nFinding path from (" << src9.y << "," << src9.x << ") to (" << dest9.y << "," << dest9.x << ")" << endl;
    aStarSearch(grid9, src9, dest9);
    
    // Test case 10: Diagonal blocks
    cout << "\nTest Case 10: Diagonal blocks" << endl;
    vector<vector<int>> grid10 = {
        {0, 0, 0, 0},
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 0}
    };
    cout << "Grid (0=free, 1=blocked):" << endl;
    for(int i = 0; i < grid10.size(); i++)
    {
        cout << "  ";
        for(int j = 0; j < grid10[i].size(); j++)
        {
            cout << grid10[i][j] << " ";
        }
        cout << endl;
    }
    Point src10 = {0, 0}; Point dest10 = {3, 3};
    cout << "\nFinding path from (" << src10.y << "," << src10.x << ") to (" << dest10.y << "," << dest10.x << ")" << endl;
    aStarSearch(grid10, src10, dest10);
    
    // Test case 11: Large empty grid
    cout << "\nTest Case 11: Large empty grid" << endl;
    vector<vector<int>> grid11(8, vector<int>(8, 0));
    cout << "Grid (0=free, 1=blocked): 8x8 empty grid" << endl;
    Point src11 = {0, 0}; Point dest11 = {7, 7};
    cout << "\nFinding path from (" << src11.y << "," << src11.x << ") to (" << dest11.y << "," << dest11.x << ")" << endl;
    aStarSearch(grid11, src11, dest11);
    
    cout << "\nAlgorithm: A* uses f(n) = g(n) + h(n)" << endl;
    cout << "- g(n): actual cost from start to current node" << endl;
    cout << "- h(n): heuristic estimate from current to goal (Manhattan distance)" << endl;
    cout << "- Guarantees optimal path with admissible heuristic" << endl;
    
    return 0;
}
