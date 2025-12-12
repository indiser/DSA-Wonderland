#include<iostream>
#include<vector>
using namespace std;

void bubbleSort(vector<int> &nums)
{
    int len=nums.size();
    for (int i = 0; i < len-1; i++)
    {
        for (int j = 0; j < len-i-1; j++)
        {
            if(nums[j]>nums[j+1])
                swap(nums[j],nums[j+1]);
        }
    }
    
}

int main()
{
    vector<int> nums={9,8,7,6,5,4,3,2,1};
    int len=nums.size();
    bubbleSort(nums);
    for(int val:nums)
        cout<<val<<endl;
    return 0;
}