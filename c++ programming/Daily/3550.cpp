// Date: 24/09/2026
#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution
{
    public:
        int sumOfDigits(int num)
        {
            int sum = 0;
            while(num != 0)
            {
                sum += num% 10;
                num /= 10;
            }
            return sum;
        }
        int smallestIndex(vector<int> &nums)
        {
            int len = nums.size();
            int findMinimum = INT_MAX;

            for (int i = 0; i < len; i++)
            {
                if(i == sumOfDigits(nums[i]))
                {
                    findMinimum = min(findMinimum, i);
                }
            }
            if(findMinimum < INT_MAX)
                return findMinimum;
            return -1;
        }
};

int main()
{
    vector<int> nums = {1, 10, 11};

    Solution s;
    cout << s.smallestIndex(nums)<< endl;

    return 0;
}