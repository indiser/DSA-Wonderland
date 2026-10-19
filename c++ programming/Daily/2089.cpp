// Date: 19/10/2026
#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

// Time Complexity: O(nlogn)
// Space Compelxity: O(n)
class Solution
{
    public:
        vector<int> targetIndices(vector<int> &nums, int target)
        {
            sort(nums.begin(), nums.end());

            int lower = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
            int upper = upper_bound(nums.begin(), nums.end(), target) - nums.begin();

            vector<int> ans;
            for (int i = lower; i < upper; i++)
            {
                ans.push_back(i);
            }
            return ans;
        }
};

int main()
{
    vector<int> nums = {1, 2, 5, 2, 3};
    int target = 2;

    Solution s;
    vector<int> ans = s.targetIndices(nums, target);

    for(auto val: ans) cout << val << endl;

    return 0;
}