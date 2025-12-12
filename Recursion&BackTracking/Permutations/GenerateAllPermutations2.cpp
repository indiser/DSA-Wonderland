#include<iostream>
#include<vector>
#include<stdio.h>
#include<algorithm>
#include<set>
using namespace std;

class Solution
{
    public:
    set<vector<int>> st;
        void findPermutations(vector<int> &arr, int index, vector<vector<int>> &ans)
        {
            if(index == arr.size())
            {
                if(st.find(arr)==st.end())
                {
                    ans.push_back(arr);
                    st.insert(arr);
                }
                return;
            }

            for (int i = index; i < arr.size(); i++)
            {
                
                swap(arr[index],arr[i]);
                findPermutations(arr,index+1,ans);
                swap(arr[index],arr[i]);
            }
            
        }
        vector<vector<int>> generatePermutation(vector<int> &nums)
        {
            vector<vector<int>> ans;
            vector<int> combine;
            findPermutations(nums,0,ans);
            return ans;
        }

};

int main()
{
    vector<int> nums={1,1,2};
    Solution s;
    vector<vector<int>> ans=s.generatePermutation(nums);

    for(const auto &val:ans)
    {
        for(int v:val)
        {
            printf("[%d]",v);
        }
        cout<<endl;
    }
}
