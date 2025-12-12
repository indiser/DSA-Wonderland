#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

class Solution
{
    public:
        int doors(map<int,int> &board)
        {
            queue<int> q;
            vector<bool> visited(101, false);
            q.push(1);
            visited[1]=true;

            int roll=0;

            while (!q.empty())
            {
                int levelSize=q.size();

                for (int i = 0; i < levelSize; i++)
                {
                    int currPosition=q.front();
                    q.pop();
                    if(currPosition==100) return roll;

                    for (int d = 1; d <= 6; d++)
                    {
                        int nextMove=currPosition+d;
                        int finalDestination;
                        if(board.count(nextMove))
                        {
                            finalDestination=board[nextMove];
                        }
                        else
                        {
                            finalDestination=nextMove;
                        }

                        if(finalDestination <= 100 && !visited[finalDestination])
                        {
                            visited[finalDestination]=true;
                            q.push(finalDestination);
                        }
                    }
                    
                }
                roll++;
            }
            return -1;
        }
};

int main() {
    // A simple way is to use a map for sparse connections.
    // Key = start of snake/ladder, Value = end of snake/ladder
    map<int, int> board;

    // Ladders
    board[4] = 14;
    board[9] = 31;
    board[20] = 38;
    board[28] = 84;
    board[40] = 59;
    board[63] = 81;
    board[71] = 91;

    // Snakes
    board[17] = 7;
    board[54] = 34;
    board[62] = 19;
    board[64] = 60;
    board[87] = 24;
    board[93] = 73;
    board[95] = 75;
    board[99] = 78;

    Solution s;
    cout << "Minimum rolls needed: " << s.doors(board) << endl;

    return 0;
}