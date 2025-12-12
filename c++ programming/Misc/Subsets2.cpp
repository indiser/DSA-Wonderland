#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>
#include<algorithm>
using namespace std;

// Time Complexity:O(nlogn+(2^n)*n)
// Space Complexity:O(n^2)

class Solution
{
    public:
    set<vector<int>> st;
    void generateSubset(vector<int> &nums, int index,vector<int> &currentNum, vector<vector<int>> &ans)
    {
        int len=nums.size();
        if(index==len)
        {
            ans.push_back(currentNum);
            return;
        }

        currentNum.push_back(nums[index]);
        generateSubset(nums,index+1,currentNum,ans);
        currentNum.pop_back();
        int idx=index+1;
        while(idx<len && nums[idx]==nums[idx-1]) idx++;
        generateSubset(nums,idx,currentNum,ans);
    }
    vector<vector<int>> findSubsets(vector<int> &nums)
    {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> currentNum;

        generateSubset(nums,0,currentNum,ans);

        return ans;
    }

};

int main()
{
    // vector<int> nums={1,2,2};
    vector<int> nums={0};

    Solution s;
    vector<vector<int>> ans=s.findSubsets(nums);

    for(const auto& val:ans)
    {
        for(auto v:val)
        {
            cout<<v<<" ";
        }
        cout<<endl;
    }
}