#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution
{
    public:
        vector<vector<vector<double>>> memo;
        double findProbabilities(int N, int k ,int row, int col)
        {
            if(row < 0 || row >= N || col < 0 || col >= N)
            {
                return 0.0;
            }
            if(k==0)
            {
                return 1.0;
            }
            if(memo[k][row][col] != -1.0)
            {
                return memo[k][row][col];
            }

            double total_probability=0;
            total_probability+=findProbabilities(N,k-1,row+2,col+1);
            total_probability+=findProbabilities(N,k-1,row+2,col-1);
            total_probability+=findProbabilities(N,k-1,row-2,col+1);
            total_probability+=findProbabilities(N,k-1,row-2,col-1);
            total_probability+=findProbabilities(N,k-1,row+1,col+2);
            total_probability+=findProbabilities(N,k-1,row-1,col+2);
            total_probability+=findProbabilities(N,k-1,row+1,col-2);
            total_probability+=findProbabilities(N,k-1,row-1,col-2);

            total_probability/=8.0;
            return memo[k][row][col] = total_probability;
        }
        double knightProbability(int N, int K, int r, int c)
        {
            memo.assign(K+1,vector<vector<double>>(N,vector<double>(N,-1.0)));
            return findProbabilities(N,K,r,c);
        }
};

int main()
{
    int N = 3;
    int K = 2;
    int startRow = 0;
    int startCol = 0;

    Solution s;
    cout << "Probability: " << s.knightProbability(N, K, startRow, startCol) << endl; // Expected: 0.0625

    return 0;
}