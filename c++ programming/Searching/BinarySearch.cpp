#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// iterative method
// bool binarySearch(vector<int> &nums, int L, int R, int key)
// {
//     sort(nums.begin(),nums.end());
//     while(L<=R)
//     {
//         int mid=L+(R-L)/2;
//         if(nums[mid]==key)
//         {
//             return true;
//         }
//         else if(nums[mid]<key)
//         {
//             L=mid+1;
//         }
//         else
//         {
//             R=mid-1;
//         }
//     }
//     return false;
// }

//Recursive Method

bool binarySearch(vector<int> &nums, int L, int R, int key)
{
    sort(nums.begin(),nums.end());
    if(L<=R)
    {
        int mid=L+(R-L)/2;
        if(nums[mid]==key)
        {
            return true;
        }
        else if(nums[mid]<key)
        {
            binarySearch(nums,mid+1,R,key);
        }
        else
        {
            binarySearch(nums,L,mid-1,key);
        }
    }
    else
    {
        return false;
    }
}

int main()
{
    vector<int> nums={2,5,3,4,1,6,8,5,9};
    int len=nums.size();
    cout<<binarySearch(nums,0,len-1,10);
    return 0;

}