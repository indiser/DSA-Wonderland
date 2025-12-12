#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

//Time Complexity:O(log(m+n))
//Space Complexity:O(1)
class Solution
{
    public:
        double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
        {
            int m=nums1.size();
            int n=nums2.size();
            if(m>n)
            {
                return findMedianSortedArrays(nums2,nums1);
            }

            int low=0,high=m;
            int left=(m+n+1)/2.0;
            int len=m+n;
            
            while(low<=high)
            {
                int mid1=(low+high)/2;
                int mid2=left-mid1;
                int l1=INT_MIN,l2=INT_MIN;
                int r1=INT_MAX,r2=INT_MAX;

                if(mid1<m)
                    r1=nums1[mid1];
                if(mid2<n)
                    r2=nums2[mid2];
                if(mid1-1>=0)
                    l1=nums1[mid1-1];
                if(mid2-1>=0)
                    l2=nums2[mid2-1];
                
                if(l1<=r2 && l2<=r1)
                {
                    if(len%2==1)
                        return max(l1,l2);
                    return (double(max(l1,l2)+min(r1,r2)))/2.0;
                }
                else if (l1>r2)
                {
                    high=mid1-1;
                }
                else
                    low=mid1+1;
                
            }
            return 0;
        }
};



//Time Complexity:O(n*m)
//Space Complexity:O(n)
// class Solution
// {
//     public:
//         double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
//         {
//             int m=nums1.size();
//             int n=nums2.size();
//             vector<int> nums3;
//             int i=0,j=0;
//             while(i<m || j<n)
//             {
//                 if(i<=j)
//                 {
//                     nums3.push_back(nums1[i++]);
//                 }
//                 else
//                 {
//                     nums3.push_back(nums2[j++]);
//                 }
//             }

//             while(i<m)
//             {
//                 nums3.push_back(nums1[i++]);
//             }
//             while(j<n)
//             {
//                 nums3.push_back(nums2[j++]);
//             }

//             int len=nums3.size();

//             if(len%2==1)
//             {
//                 return nums3[len/2];
//             }
//             else
//             {
//                 return (double)((double)(nums3[len/2])+double(nums3[len/2-1]))/2.0;
//             }
//             return 0;
//         }
// };
int main()
{
    vector<int> nums1={1,3};
    vector<int> nums2={2};
    Solution s;
    cout<<s.findMedianSortedArrays(nums1,nums2)<<endl;
    return 0;
}