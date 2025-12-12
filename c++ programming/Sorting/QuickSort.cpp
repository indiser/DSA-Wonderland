#include<iostream>
#include<vector>
using namespace std;

int partition(vector<int> &nums,int low, int high)
{
    int pivot=nums[high];
    int i=low-1;
    for (int j = low; j < high; j++)
    {
        if(nums[j]<pivot)
        {
            i++;
            swap(nums[i],nums[j]);
        }
    }
    swap(nums[i+1],nums[high]);
    return i+1;
    
}

void quickSort(vector<int> &nums,int low,int high)
{
    if(low<high)
    {
        int pi=partition(nums,low,high);
        quickSort(nums,low,pi-1);
        quickSort(nums,pi+1,high);
    }
}

int main()
{
    vector<int> nums={9,8,7,6,5,4,3,2,1};
    int len=nums.size();
    quickSort(nums,0,len-1);
    for(int val:nums)
        cout<<val<<endl;
    return 0;
}