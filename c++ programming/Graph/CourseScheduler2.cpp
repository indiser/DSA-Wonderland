// Date: 13/07/2026
#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;

// Time Complexity: O(V + E)
// Space Complexity: O(V + E)
class Solution
{
    public:
        vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
        {
            vector<vector<int>> adj(numCourses);
            vector<int> inDegree(numCourses, 0);
            vector<int> ans;
        
            for (auto& course : prerequisites)
            {
                adj[course[1]].push_back(course[0]);
                inDegree[course[0]]++;
            }
        
            queue<int> q;
            for (int i = 0; i < numCourses; i++)
            {
                if (inDegree[i] == 0) q.push(i);
            }
        
            int processed = 0;
            while (!q.empty())
            {
                int curr = q.front();
                ans.push_back(curr);
                q.pop();
                processed++;
            
                for (int neighbor : adj[curr])
                {
                    inDegree[neighbor]--;
                    if (inDegree[neighbor] == 0)
                        q.push(neighbor);
                }
            }
        
            if(processed == numCourses) return ans;
            else 
                return {};
        }
};

int main()
{
    int numCourses = 4;
    vector<vector<int>> prerequisites = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};

    Solution s;
    vector<int> ans = s.findOrder(numCourses, prerequisites);

    for(int val : ans) cout<< val <<" ";

    return 0;
}