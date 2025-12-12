#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

//Time Complexity:O(K*C(N,K))
//Space Complexity:O(n)

// class Solution
// {
//     public:
//         void getAllElements(vector<int> &arr, int idx, int target,vector<vector<int>> &ans ,vector<int> &combine)
//         {
           
//             if(target == 0)
//             {
//                 ans.push_back(combine);
//                 return;
//             }

//             for (int i = idx; i < arr.size(); i++)
//             {
//                 if(i > idx && arr[i]==arr[i-1]) continue;
//                 if(arr[i]>target) break;
//                 combine.push_back(arr[i]);
//                 getAllElements(arr,i+1,target-arr[i],ans,combine);
//                 combine.pop_back();
//             }
//         }
//         vector<vector<int>> combinationSumTwo(vector<int> &candidtes, int target)
//         {
//             sort(candidtes.begin(), candidtes.end());
//             vector<vector<int>> ans;
//             vector<int> combine;

//             getAllElements(candidtes,0,target,ans,combine);
//             return ans;
//         }
// };

//Time Complexity:O(2^n * n * log M)
//Space Complexity:O(M*n)

class Solution
{
    public:
        set<vector<int>> st;
        void getAllElements(vector<int> &arr, int idx, int target,vector<vector<int>> &ans ,vector<int> &combine)
        {
           
            if(target == 0)
            {
                if(st.find(combine)==st.end())
                {
                    ans.push_back(combine);
                    st.insert(combine);
                }
                
                return;
            }
            if(idx >= arr.size()) return;
            if(arr[idx] > target) return;

            combine.push_back(arr[idx]);
            getAllElements(arr,idx+1,target-arr[idx],ans,combine);
            combine.pop_back();
            getAllElements(arr,idx+1,target,ans,combine);
        }
        vector<vector<int>> combinationSumTwo(vector<int> &candidtes, int target)
        {
            sort(candidtes.begin(),candidtes.end());
            vector<vector<int>> ans;
            vector<int> combine;

            getAllElements(candidtes,0,target,ans,combine);
            return ans;
        }
};
int main()
{
    vector<int> candidates={10,1,2,7,6,1,5};
    int target=8;
    Solution s;
    vector<vector<int>> ans=s.combinationSumTwo(candidates,target);
    for(const auto &combination:ans)
    {
        for(int val:combination)
        {
            cout<<val<<" ";
        }
        cout<<endl;
    }
    return 0;
}