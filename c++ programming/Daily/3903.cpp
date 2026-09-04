// Date: 04/09/2026
#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution
{
    public:
        int firstStableIndex(vector<int> &nums, int k)
        {
            int n = nums.size();

            vector<int> suffixMin(n);
            int minimum = INT_MAX;

            for (int i = n - 1; i >= 0; i--)
            {
                minimum = min(minimum, nums[i]);
                suffixMin[i] = minimum;
            }

            int maximum = 0;
            for (int i = 0; i < n; i++)
            {
                maximum = max(maximum, nums[i]);
                if((maximum - suffixMin[i]) <= k) return i;
            }
            
            return -1;
        }
};

int main()
{
    vector<int> nums = {5, 0, 1, 4};
    int k = 3;

    Solution s;
    cout << s.firstStableIndex(nums, k)<<endl;

    return 0;
}