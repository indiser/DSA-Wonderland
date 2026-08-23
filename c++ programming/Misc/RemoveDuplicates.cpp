// Date: 29/07/2026
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution
{
    public:
        int removeDuplicates(vector<int> &nums)
        {
            int n = nums.size();

            if(n == 0) return 0;

            int k = 1;

            for (int i = 1; i < n; i++)
            {
                if(nums[i] != nums[i - 1])
                {
                    nums[k] = nums[i];
                    k++;
                }
            }
            return k;
        }
};

int main()
{
    vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};

    Solution s;
    cout << s.removeDuplicates(nums) << endl;
}