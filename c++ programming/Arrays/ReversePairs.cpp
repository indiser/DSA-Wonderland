#include<iostream>
#include<vector>
using namespace std;

// Solution-1:Naive approach
//Time Complexity:O(n^2)
//Space Complexity:O(1)
// class Solution
// {
//     public:
//         int reversePairs(vector<int> &nums)
//         {
//             int len=nums.size();
//             int count=0;
            
//             for (int i = 0; i < len; i++)
//             {
//                 for (int j = i+1; j < len; j++)
//                 {
//                     if((long)nums[i] > 2*(long)nums[j])
//                     {
//                         count++;
//                     }
//                 }
                
//             }
//             return count;
//         }
// };


// Solution-2:Optimal(MergeSort)
//Time Complexity:O(nlogn)
//Space Complexity:O(n)
class Solution
{
    public:
        void merge(vector<int> &arr, int l, int mid, int r)
        {
            int i=l,j=mid+1;
            vector<int> ans;
            while(i <= mid && j <= r)
            {
                if(arr[i] <= arr[j])
                {
                    ans.push_back(arr[i]);
                    i++;
                }
                else
                {
                    ans.push_back(arr[j]);
                    j++;
                }
            }

            while(i <= mid)
            {
                ans.push_back(arr[i]);
                i++;
            }

            while(j <= r)
            {
                ans.push_back(arr[j]);
                j++;
            }

            for(int index = 0, len = ans.size(); index < len; index++)
            {
                arr[l+index]=ans[index];
            }
        }

        int countPairs(vector<int> &arr, int l, int mid, int r)
        {
            int right=mid+1, count=0;

            for (int i = l; i <= mid; i++)
            {
                while (right <= r && arr[i] > 2 * arr[right])
                {
                    right++;
                }
                count+=(right - (mid+1));
            }
            return count;
        }

        int mergeSort(vector<int> &arr, int l, int r)
        {
            int count=0;
            if(l < r)
            {
                int mid=l+(r-l)/2;

                count+=mergeSort(arr,l,mid);
                count+=mergeSort(arr,mid+1,r);
                count+=countPairs(arr,l,mid,r);
                merge(arr,l,mid,r);
            }
            return count;
        }

        int reversePairs(vector<int> &nums)
        {
            int n = nums.size();
            return mergeSort(nums, 0, n-1);
        }
};

int main()
{
    vector<int> nums={40,25,19,12,9,6,2};

    Solution s;
    cout<<s.reversePairs(nums)<<endl;
}