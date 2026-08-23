// date: 18/08/2026
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int sum = 0, count = 0;
        
        for (int x : nums) {
            sum += x;
            if (mp.count(sum - k)) {
                count += mp[sum - k];
            }
            mp[sum]++;
        }

        return count;
    }
};


int main()
{
    vector<int> nums = {1, 1, 1};
    int k = 2;

    Solution s;
    cout << s.subarraySum(nums, k)<< endl;

    return 0;
}