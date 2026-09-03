// Date: 03/09/2026
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
        bool uniformArray(vector<int> &nums1)
        {
            int minimum = nums1[0];
            bool hasOdd = false;

            // if min is even and all the numbers are not odd return true
            for(int val: nums1)
            {
                if(val < minimum) minimum = val;
                if(val & 1) hasOdd = true;
            }

            // If min is odd return true
            if(minimum & 1) return true;

            return !hasOdd;
        }
};

int main()
{
    vector<int> nums1 = {1, 4, 7};

    Solution s;
    if(s.uniformArray(nums1) == true) cout << "True" <<endl;
    else cout << "False"<<endl;

    return 0;
}