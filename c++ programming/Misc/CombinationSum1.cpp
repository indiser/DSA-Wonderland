#include<iostream>
#include<vector>
#include<set>
using namespace std;

//Time Complexity:O(2^N)
//Space Complexity:O(n)

class Solution
{
    public:
        set<vector<int>> st;
        void getAllCombinations(vector<int> &arr, int idx, int target, vector<vector<int>> &ans, vector<int> &combine)
        {
            if(target < 0 || idx == arr.size())
            {
                return;
            }
            if(target == 0)
            {
                if(st.find(combine) == st.end())
                {
                    ans.push_back(combine);
                    st.insert(combine);
                }
                return ;
            }

            combine.push_back(arr[idx]);
            getAllCombinations(arr,idx+1,target-arr[idx],ans,combine); //Single Element
            getAllCombinations(arr,idx,target-arr[idx],ans,combine); //Multiple Element
            combine.pop_back();
            getAllCombinations(arr,idx+1,target,ans,combine); //Exclusion
        }
        vector<vector<int>> combinationSum(vector<int> &candidates,int target)
        {
            vector<vector<int>> ans;
            vector<int> combine;
            
            getAllCombinations(candidates,0,target,ans,combine);

            return ans;
        }
};

int main()
{
    vector<int> candidates={2,3,5};
    int target=8;
    Solution s;
    vector<vector<int>> ans=s.combinationSum(candidates,target);

    for(const auto &combination : ans)
    {
        for(int v : combination)
        {
            cout << v << " ";
        }
        cout << endl;
    }
    return 0;
}