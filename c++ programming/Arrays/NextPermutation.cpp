#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Time Complexity:O(n)
//Space Complexity:O(1)
class Solution
{
    public:
        void nextPermutation(vector<int> &nums)
        {
            //First Step: Find the pivot index
            int pivot=-1, len = nums.size();

            for (int i = len-2; i >= 0; i--)
            {
                if(nums[i] < nums[i+1])
                {
                    pivot=i;
                    break;
                }
            }
            
            if(pivot==-1)
            {
                reverse(nums.begin(),nums.end());
                return;
            }

            //Second step: Swap the leftmost element with pivot
            for (int i = len-1; i > pivot; i--)
            {
                if(nums[i]>nums[pivot])
                {
                    swap(nums[i],nums[pivot]);
                    break;
                }
            }

            //Third Step: Reverse the last part of the array
            int i = pivot+1,j=len-1;
            while(i<=j)
            {
                swap(nums[i++],nums[j--]);
            }
            
        }
};

int main()
{
    vector<int> nums = {1, 2, 3, 5, 4};
    // next_permutation(nums.begin(),nums.end());
    Solution s;
    s.nextPermutation(nums);
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    return 0;
}