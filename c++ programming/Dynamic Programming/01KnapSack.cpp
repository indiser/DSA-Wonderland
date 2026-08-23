// Date: 23/07/2026
#include<iostream>
#include<vector>
#include<unordered_map>
#include<chrono>
using namespace std;

// Time Complexity: O(2 ^ n)
// Space Complexity: O(n)
class SolutionRecursive
{
    public:
        int recursiveSol(int W, int n, vector<int> &val, vector<int> &wt)
        {
            if(W == 0 || n == 0) return 0;

            if(wt[n - 1] <= W)
            {
                int include = val[n - 1] + recursiveSol(W - wt[n - 1], n - 1, val, wt);
                int exclude = recursiveSol(W, n - 1, val, wt);

                return max(include, exclude);
            }
            else return recursiveSol(W, n - 1, val, wt);
        }
        int knapSack(int W, vector<int> &val, vector<int> &wt)
        {
            int n = wt.size();

            return recursiveSol(W, n, val, wt);
        }
};

// Time Complexity: O(n * W)
// Space Complexity: O(n * W) + O(n)
class SolutionMemo
{
    public:
        int Memo(int W, int n, vector<int> &val, vector<int> &wt, vector<vector<int>> &dp)
        {
            if(W == 0 || n == 0) return 0;

            if(dp[n][W] != -1) return dp[n][W];

            if(wt[n - 1] <= W)
            {
                int include = val[n - 1] + Memo(W - wt[n - 1], n - 1, val, wt, dp);
                int exclude = Memo(W, n - 1, val, wt, dp);

                return dp[n][W] = max(include, exclude);
            }
            else return dp[n][W] = Memo(W, n - 1, val, wt, dp);
        }
        int knapSack(int W, vector<int> &val, vector<int> &wt)
        {
            int n = wt.size();
            vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));
            return Memo(W, n, val, wt, dp);
        }
};

// Time Complexity: O(n * W)
// Space Complexity: O(n * W)
class SolutionTabu
{
    public:
        int knapSack(int W, vector<int> &val, vector<int> &wt)
        {
            int n = wt.size();
            vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= W; j++)
                {
                    if(wt[i - 1] <= j) dp[i][j] = max((val[i - 1] + dp[i - 1][j - wt[i - 1]]), dp[i - 1][j]);
                    else dp[i][j] =  dp[i - 1][j];
                }
            }
            return dp[n][W];
        }
};

int main()
{
    int W = 10;
    vector<int> val = {20, 30, 50, 60, 100};
    vector<int> wt = {2, 3, 4, 5, 9};

    SolutionRecursive sr;

    auto t0 = std::chrono::steady_clock::now();
    cout << sr.knapSack(W, val, wt)<< endl;
    auto t1 = chrono::steady_clock::now();
    double ms1 = chrono::duration<double, std::milli>(t1 - t0).count();
    cout<<"Recursive Time: "<< ms1 <<" .ms"<< endl;



    SolutionMemo sm;

    auto t2 = std::chrono::steady_clock::now();
    cout << sm.knapSack(W, val, wt)<< endl;
    auto t3 = chrono::steady_clock::now();
    double ms2 = chrono::duration<double, std::milli>(t3 - t2).count();
    cout<<"Momraization Time: "<< ms2 <<" .ms"<< endl;

    SolutionMemo st;

    auto t4 = std::chrono::steady_clock::now();
    cout << sm.knapSack(W, val, wt)<< endl;
    auto t5 = chrono::steady_clock::now();
    double ms3 = chrono::duration<double, std::milli>(t5 - t4).count();
    cout<<"Tabulation Time: "<< ms3 <<" .ms"<< endl;

    return 0;
}