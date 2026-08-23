// Date: 04/08/2026
#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

// Time Complexity: O(n *logn)
// Space Complexity: O(n)
class Solution
{
    public:
        vector<int> findMissingElements(vector<int> &nums)
        {
            int maxNum = nums[0];
            int minNum = nums[0];
            int len = nums.size();

            for (int i = 0; i < len; i++)
            {
                maxNum = max(maxNum, nums[i]);
                minNum = min(minNum, nums[i]);
            }
            
            vector<int> result;
            sort(nums.begin(), nums.end());
            for (int i = minNum; i <= maxNum; i++)
            {
                if(!binary_search(nums.begin(), nums.end(), i)) result.push_back(i);
            }
            return result;
        }
};

int main()
{
    vector<int> nums = {1, 4, 2, 5};

    Solution s;

    vector<int> ans = s.findMissingElements(nums);

    for(int val: ans) cout<< val<< endl;

    return 0;
}