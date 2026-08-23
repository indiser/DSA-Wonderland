#include<iostream>
#include<stdio.h>
#include<vector>
#include<set>
using namespace std;

class Solution
{
    public:
        void findSubsets(vector<int> &arr, int index,vector<int> &combine, vector<vector<int>> &ans)
        {
            int len=arr.size();
            if(index == len)
            {
                ans.push_back(combine);
                return;
            }

            findSubsets(arr,index+1,combine,ans);
            combine.push_back(arr[index]);
            findSubsets(arr,index+1,combine,ans);
            combine.pop_back();
        }
        vector<vector<int>> generateSubsets(vector<int> &nums)
        {
            vector<vector<int>> ans;
            vector<int> combine;

            findSubsets(nums,0,combine,ans);
            return ans;
        }

};

int main()
{
    vector<int> nums={1,2,3};
    Solution s;
    vector<vector<int>> ans=s.generateSubsets(nums);

    for(const auto &val:ans)
    {
        for(int v:val)
        {
            printf("[%d]",v);
        }
        cout<<endl;
    }
    return 0;
}