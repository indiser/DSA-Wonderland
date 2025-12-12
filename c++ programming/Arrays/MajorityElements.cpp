#include <iostream>
#include <vector>
#include <map>
using namespace std;

// LeetCode 169. Majority Element
 
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        map<int, int> mp;
        int n = nums.size(),ans=0;
        for (auto val : nums)
        {
            mp[val]++;
        }
        for (auto i = mp.begin(); i != mp.end(); i++)
        {
            if (i->second > n / 2)
                ans=i->first;
        }
        return ans;

        // Time Complexity: O(n)
        // Space Complexity: O(n)
    }
};

int main()
{
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    // vector<int> nums = {3 , 2 , 3};


    Solution s;
    cout<<s.majorityElement(nums)<<endl;
    return 0;
}