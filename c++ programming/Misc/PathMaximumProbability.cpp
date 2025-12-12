#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution
{
    public:
        double maxProbability(int n, vector<vector<int>> &edges, vector<double> &succProb, int start_node, int end_node)
        {
            
        }
};

int main()
{
    int n=3;
    vector<vector<int>> edges={{0,1},{1,2},{0,2}};
    vector<double> succProb={0.5,0.5,0.2};
    int start_node=0;
    int end_node=2;
    Solution s;
    cout<<s.maxProbability(n,edges,succProb,start_node,end_node);
    return 0;
}