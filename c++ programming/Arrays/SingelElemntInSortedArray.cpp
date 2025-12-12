#include<iostream>
#include<vector>
using namespace std;

//Time Complexity:O(logn)
//Space Complexity:O(1)

class Solution
{
    public:
        int indexInRotatedSortedArray(vector<int> &nums)
        {
            int len=nums.size();
            int l=0,r=len-1;
            if(len==1)
                return nums[0];

            while(l<=r)
            {
                int mid=l+(r-l)/2;

                if(mid==0 && nums[0] != nums[1])
                    return nums[mid];
                if(mid==len-1 && nums[len-1] != nums[len-2])
                    return nums[mid];

                if(nums[mid-1] != nums[mid] && nums[mid] != nums[mid+1])
                    return mid;

                if(mid%2==0)
                {
                    if(nums[mid-1] == nums[mid])
                    {
                        r=mid-1;
                    }
                    else
                    {
                        l=mid+1;
                    }
                }
                else
                {
                    if(nums[mid-1] == nums[mid])
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
    vector<int> nums={1,1,2,3,3,4,4,5,5};
    Solution s;
    cout << s.indexInRotatedSortedArray(nums) << endl;
}