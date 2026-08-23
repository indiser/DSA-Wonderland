// Date: 11/08/2026
#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;


// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution
{
    public:
        int missingInteger(vector<int> &nums)
        {
            int n = nums.size();
            unordered_set<int> s(nums.begin(), nums.end());

            int total = nums[0];

            for (int i = 1; i < n; i++)
            {
                if(nums[i] == nums[i - 1] + 1) total += nums[i];
                else break;
            }

            while(s.count(total)) total += 1;

            return total;
        }
};

int main()
{
    vector<int> nums = {1, 2, 3, 2, 5};

    Solution s;
    cout<< s.missingInteger(nums)<< endl;
}