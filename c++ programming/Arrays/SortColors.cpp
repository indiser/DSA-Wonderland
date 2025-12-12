#include<iostream>
#include<vector>
using namespace std;

// Leetcode-75: Sort Colors
// Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.
//Bubble sort
class Solution
{
    public:
        void sortColors(vector<int> &nums)
        {
            int len=nums.size();
            for (int i = 0; i < len-1; i++)
            {
                for (int j = 0; j < len-i-1; j++)
                {
                    if(nums[j]>nums[j+1])
                    {
                        swap(nums[j],nums[j+1]);
                    }
                }
                
            }
        }
};

//Time complexity: O(n^2)
//Space complexity: O(1)

int main()
{
    vector<int> nums={2,0,2,1,1,0};
    Solution s;
    s.sortColors(nums);
    for(int val:nums)
    {
        cout<<val<<endl;
    }
    return 0;
}