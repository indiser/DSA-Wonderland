// Date: 01/07/2026
#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<algorithm>
using namespace std;


// Time Complexity: O(n^2 logk)
// Space Complexity: O(k)
class Solution
{
    public:
        int kthSamallest(vector<vector<int>> &matrix, int k)
        {
            priority_queue<int> maxHeap;
            int n = matrix.size();
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    maxHeap.push(matrix[i][j]);

                    if(maxHeap.size() > k) maxHeap.pop();
                }
            }
            return maxHeap.top();
        }
};

int main()
{
    vector<vector<int>> matrix = {{1, 5, 9}, {10, 11, 13}, {12, 13, 15}};
    int k = 8;

    Solution s;
    cout << s.kthSamallest(matrix, k)<<endl;
    return 0;
}