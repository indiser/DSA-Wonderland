// Date : 18/07/2026
#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

// Time Compelxity: O(n)
// Space Complexity: O(1)
class Solution
{
    public:
        int gcd(int a, int b)
        {
            return b == 0 ? a : gcd(b, a % b); 
        }
        int findGCD(vector<int> &nums)
        {
            int minN = nums[0];
            int maxN = nums[0];

            for (int i = 0; i < nums.size(); i++)
            {
                minN = min(minN, nums[i]);
                maxN = max(maxN, nums[i]);
            }
            
            return gcd(minN, maxN);
        }
};

int main()
{
    vector<int> nums = {2, 3, 4, 5, 6, 7, 8, 9, 10};

    Solution s;
    cout<<"Greatest Common Devisor OF Array:"<< s.findGCD(nums) <<endl;

    return 0;
}