#include<iostream>
#include<vector>
using namespace std;

void selectionSort(vector<int> &nums)
{
    int len=nums.size();
    for (int i = 0; i < len-1; i++)
    {
        for (int j = i+1; j < len; j++)
        {
            if(nums[i]>nums[j])
                swap(nums[i],nums[j]);
        }
    }
    
}

int main()
{
    vector<int> nums={9,8,7,6,5,4,3,2,1};
    int len=nums.size();
    selectionSort(nums);
    for(int val:nums)
        cout<<val<<endl;
    return 0;
}