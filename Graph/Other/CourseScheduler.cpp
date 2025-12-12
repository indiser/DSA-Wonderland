#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

// Kahn's Algorithm:Topological Sort

/*
Time Complexity: O(V + E)
- V: number of courses (vertices)
- E: number of prerequisites (edges)
- Building adjacency list: O(E)
- Initial queue population: O(V)
- BFS traversal: O(V + E) - each vertex and edge processed once

Space Complexity: O(V + E)
- Adjacency list: O(V + E) to store all edges
- In-degree array: O(V)
- Queue: O(V) in worst case (all vertices with 0 in-degree)
*/
class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> adj(numCourses);
        vector<int> inDegree(numCourses, 0);
        
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
            q.pop();
            processed++;
            
            for (int neighbor : adj[curr])
            {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0)
                    q.push(neighbor);
            }
        }
        
        return processed == numCourses;
    }
};

int main()
{
    cout << "=== Course Scheduler Problem ===" << endl;
    
    Solution sol;
    
    // Test case 1: Can finish courses
    cout << "\nTest Case 1:" << endl;
    int numCourses1 = 4;
    vector<vector<int>> courses1 = {{1, 0}, {2, 1}, {3, 2}};
    
    cout << "Number of courses: " << numCourses1 << endl;
    cout << "Prerequisites (course -> prerequisite):" << endl;
    for(auto course : courses1)
    {
        cout << "Course " << course[0] << " requires Course " << course[1] << endl;
    }
    
    bool canComplete1 = sol.canFinish(numCourses1, courses1);
    cout << "Can finish all courses: " << (canComplete1 ? "YES" : "NO") << endl;
    
    // Test case 2: Circular dependency (cannot finish)
    cout << "\nTest Case 2:" << endl;
    int numCourses2 = 2;
    vector<vector<int>> courses2 = {{1, 0}, {0, 1}};
    
    cout << "Number of courses: " << numCourses2 << endl;
    cout << "Prerequisites (course -> prerequisite):" << endl;
    for(auto course : courses2)
    {
        cout << "Course " << course[0] << " requires Course " << course[1] << endl;
    }
    
    bool canComplete2 = sol.canFinish(numCourses2, courses2);
    cout << "Can finish all courses: " << (canComplete2 ? "YES" : "NO") << endl;
    
    return 0;
}