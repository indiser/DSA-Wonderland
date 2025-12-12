#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution
{
    public:
        void findPaths(vector<vector<int>> &graph, int currentNode, int target,vector<int> &currentPath, vector<vector<int>> &ans)
        {

            currentPath.push_back(currentNode);

            if(currentNode==target)
            {
                ans.push_back(currentPath);
            }
            else
            {
                for(int neighbour:graph[currentNode])
                {
                    findPaths(graph,neighbour,target,currentPath,ans);
                }
            }

            currentPath.pop_back();
        }
        vector<vector<int>> allPaths(vector<vector<int>> &graph, int source, int target)
        {
            vector<vector<int>> ans;
            vector<int> currentPath;

            findPaths(graph,source,target,currentPath,ans);

            return ans;
        }

};

int main()
{
    vector<vector<int>> graph={{1,2},{3},{3},{}};
    int source=0,target=3;
    Solution s;
    vector<vector<int>> ans=s.allPaths(graph,source,target);
    for(const auto& val:ans)
    {
        for(auto v:val)
        {
            cout<<v<<" ";
        }
        cout<<endl;
    }
}