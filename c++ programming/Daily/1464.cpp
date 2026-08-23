// Date: 27/07/2026
#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

// Time Compelxity: O(n *logn)
// Space Complexity: O(1)
class Solution
{
    public:
        int maxProduct(vector<int> &nums)
        {
            sort(nums.begin(), nums.end());
            int n = nums.size();

            int lastIndex = n - 1;
            int secondListIndex = lastIndex - 1;

            return (nums[lastIndex] - 1) * (nums[secondListIndex] - 1);
        }
};

int main()
{
    vector<int> nums = {3, 4, 5, 2};

    Solution s;
    cout << s.maxProduct(nums) <<endl;
    return 0;
}