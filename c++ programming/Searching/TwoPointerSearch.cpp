#include<iostream>
#include<vector>
using namespace std;

bool twoPointerSearch(vector<int> &nums, int L, int R, int key)
{
    while(L<=R)
    {
        int sum=nums[L]+nums[R];
        if(sum==key)
        {
            return true;
        }
        else if(sum<key)
        {
            L++;
        }
        else
        {
            R--;
        }
    }
    return false;
}

int main()
{
    vector<int> nums={2,5,3,4,1,6,8,5,9};
    int len=nums.size();
    cout<<twoPointerSearch(nums,0,len-1,10);
    return 0;
}

