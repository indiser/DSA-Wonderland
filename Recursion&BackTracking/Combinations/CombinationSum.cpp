#include<iostream>
#include<vector>
using namespace std;

class Solution
{
    public:
        void findCombinationSums(vector<int> &arr,int index, int target, vector<int> &combine, vector<vector<int>> &ans)
        {
            if(target==0)
            {
                ans.push_back(combine);
                return;
            }
            if(target < 0 || index >= arr.size())
            {
                return;
            }
            
            combine.push_back(arr[index]);
            findCombinationSums(arr,index+1,target-arr[index],combine,ans);
            combine.pop_back();
            findCombinationSums(arr,index+1,target,combine,ans);
        }
        vector<vector<int>> generateCombinationSum(vector<int> &nums, int target)
        {
            vector<vector<int>> ans;
            vector<int> combine;
            findCombinationSums(nums,0,target,combine,ans);
            return ans;
        }
};

int main()
{
    vector<int> nums={2,3,4,5,6,7};
    int target=8;
    Solution s;
    vector<vector<int>> ans=s.generateCombinationSum(nums,target);

    for(const auto &val:ans)
    {
        for(int v:val)
        {
            cout<<v<<" ";
        }
        cout<<endl;
    }
    return 0;
}