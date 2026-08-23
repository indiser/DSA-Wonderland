// Date: 02/07/2026
#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;

// TIme Complexity: O(nlogk)
// Space Comeplxity: O(k)
class Solution
{
    public:
        vector<int> smallestRange(vector<vector<int>> &nums)
        {
            priority_queue<vector<int>,vector<vector<int>>, greater<vector<int>>> minHeap;
            int currMax = INT_MIN;
            int n = nums.size();

            for (int i = 0; i < n; i++)
            {
                minHeap.push({nums[i][0], i, 0});
                currMax = max(currMax, nums[i][0]);
            }

            vector<int> ans = {-100000, 100000};

            while(!minHeap.empty())
            {
                vector<int>vec = minHeap.top();
                minHeap.pop();

                int currMin = vec[0];
                int listidx = vec[1];
                int eleidx = vec[2];

                if(currMax - currMin < ans[1] - ans[0])
                {
                    ans[0] = currMin;
                    ans[1] = currMax;
                }
                if(eleidx + 1 < nums[listidx].size())
                {
                    eleidx += 1;
                    minHeap.push({nums[listidx][eleidx], listidx, eleidx});
                    currMax = max(currMax, nums[listidx][eleidx]);
                }
                else
                    break;
            }
            return ans;
        }
};

int main()
{
    vector<vector<int>> nums = {
        {4, 10, 15, 24, 26},
        {0, 9, 12, 20},
        {5, 18, 22, 30}
    };

    Solution s;
    vector<int> result = s.smallestRange(nums);

    for(int val: result)
    {
        cout<<val<<" ";
    }
    return 0;
}