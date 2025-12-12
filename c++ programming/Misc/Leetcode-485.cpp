#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxConsecutive(vector<int> &nums)
    {
        int maxCount = INT_MIN;
        int count = 0, left = 0;

        for (int val : nums)
        {
            if (val == 1)
            {
                count++;
            }
            else
            {
                count = 0;
            }
            maxCount = max(maxCount, count);
        }
        cout << maxCount << endl;
    }
};

int main()
{
    vector<int> nums = {1, 1, 0, 1, 1, 1};

    Solution s;
    cout<<s.maxConsecutive(nums)<<endl;
    return 0;
}