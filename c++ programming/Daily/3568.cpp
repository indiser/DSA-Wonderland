// Date: 01/09/2026
#include<iostream>
#include<vector>
#include<queue>
#include<string>
using namespace std;

// Time Complexity: O(n * m * 2^k)
// Space Complexity: O(n * m * 2^k)
class Solution
{
    public:
        int minMoves(vector<string> &classroom, int energy)
        {
            int m = classroom.size();
            if(m == 0) return -1;
            int n = classroom[0].size();

            int startX = 0, startY = 0, l_cnt = 0;
            vector<vector<int>> l_idx(m, vector<int>(n, -1));

            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if(classroom[i][j] == 'S')
                    {
                        startX = i;
                        startY = j;
                    }
                    else if(classroom[i][j] == 'L')
                    {
                        l_idx[i][j] = l_cnt++;
                    }
                }
            }

            if(l_cnt == 0) return 0;

            int targetMask = (1 << l_cnt) - 1;
            vector<vector<vector<int>>> bestEnergy(m, vector<vector<int>>(n, vector<int>(1 << l_cnt, -1)));

            queue<vector<int>> q;
            q.push({startX, startY, energy, 0});
            bestEnergy[startX][startY][0] = energy;

            int row[]= {-1, 1, 0, 0};
            int col[]= {0, 0, -1, 1};
            int moves = 0;

            while(!q.empty())
            {
                int qlen = q.size();
                for (int i = 0; i < qlen; i++)
                {
                    auto curr = q.front();
                    q.pop();

                    int cx = curr[0], cy = curr[1], cur_e = curr[2], cmask = curr[3];

                    if(cmask == targetMask) return moves;

                    for (int d = 0; d < 4; d++)
                    {
                        int nx = cx + row[d];
                        int ny = cy + col[d];

                        if(nx >= 0 && nx < m && ny >= 0 && ny < n && classroom[nx][ny] != 'X')
                        {
                            int n_energy = cur_e - 1;
                            
                            if(n_energy < 0) continue;

                            if(classroom[nx][ny] == 'R') 
                            {
                                n_energy = energy;
                            }

                            int n_mask = cmask;
                            if(classroom[nx][ny] == 'L')
                            {
                                n_mask |= (1 << l_idx[nx][ny]);
                            }

                            if(n_energy > bestEnergy[nx][ny][n_mask])
                            {
                                bestEnergy[nx][ny][n_mask] = n_energy;
                                q.push({nx, ny, n_energy, n_mask});
                            }
                        }
                    }
                }
                moves++;
            }
            
            return -1;
        }
};

int main()
{
    vector<string> classroom = {"L", "R", ".", "S", "."};
    int energy = 1;

    Solution s;
    cout<<"Minimum Moves To collect the litter is: "<<s.minMoves(classroom, energy)<<endl;
    return 0;
}