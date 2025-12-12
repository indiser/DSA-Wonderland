#include<iostream>
#include<vector>
using namespace std;

bool linearSearch(vector<int> &nums,int key)
{
    for (int i = 0, len = nums.size(); i < len; i++)
    {
        if(nums[i]==key)
        {
            return true;
            break;
        }
    }
    return false;
    
}

int main()
{
    vector<int> nums={2,5,3,4,1,6,8,5,9};
    cout<<linearSearch(nums,10)<<endl;
    return 0;
}