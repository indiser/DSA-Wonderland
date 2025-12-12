#include<iostream>
#include<vector>
using namespace std;

//Time Complexity:O(logn)
//Space Complexity:O(1)

class Solution
{
    public:
        int indexInRotatedSortedArray(vector<int> &nums, int target)
        {
            int len=nums.size();
            int l=0,r=len-1;

            while(l<=r)
            {
                int mid=l+(r-l)/2;

                if(nums[mid]==target)
                {
                    return mid;
                }
                
                if(nums[l] <= nums[mid]) //left sorted
                {
                    if(nums[l] <= target && target <= nums[mid])
                    {
                        r=mid-1;
                    }
                    else
                    {
                        l=mid+1;
                    }
                }
                else  // right sorted
                {
                    if(nums[mid] <= target && target <= nums[r])
                    {
                        l=mid+1;
                    }
                    else
                    {
                        r=mid-1;
                    }
                }
            }
            return -1;
        }
};

int main()
{
    vector<int> nums={4,5,6,7,0,1,2,};
    int target = 0;
    Solution s;
    cout << s.indexInRotatedSortedArray(nums, target) << endl;
}