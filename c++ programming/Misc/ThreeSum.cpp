#include<iostream>
#include<vector>
#include<set>
#include <algorithm>
using namespace std;
// Leetcode-15:3Sum
//Brute-Force
// class Solution
// {
//     public:
//         vector<vector<int>> threeSum(vector<int>&nums)
//         {
//             int len=nums.size();
//             set<vector<int>> s;
//             vector<vector<int>> ans;

//             for (int i = 0; i < len; i++)
//             {
//                 for (int j = i+1; j < len; j++)
//                 {
//                     for (int k = j+1; k < len; k++)
//                     {
//                         if(nums[i]+nums[j]+nums[k]==0)
//                         {
//                             vector<int> trip={nums[i],nums[j],nums[k]};
//                             sort(trip.begin(),trip.end());

//                             if(s.find(trip)!=s.end())
//                             {
//                                 s.insert(trip);
//                                 ans.push_back(trip);
//                             }
//                         }
//                     }
//                 }
//             }
//             return ans;
//         }
// };
//Time complexity:O(n^3 * log(unique triplets))
//Space complexity:O(unique triplets)

//Hashing
// class Solution
// {
//     public:
//         vector<vector<int>> threeSum(vector<int>&nums)
//         {
//             int len=nums.size();
//             set<vector<int>> uniqueTriplets;

//             for (int i = 0; i < len; i++)
//             {
//                 int tar=-nums[i];
//                 set<int> s;
//                 for (int j = i+1; j < len; j++)
//                 {
//                     int toFind=tar-nums[j];
//                     if(s.find(toFind)!=s.end())
//                     {
//                         vector<int> trip={nums[i],nums[j],toFind};
//                         sort(trip.begin(),trip.end());
//                         uniqueTriplets.insert(trip);
//                     }
//                     s.insert(nums[j]);
//                 }
                
//             }
//             vector<vector<int>> ans(uniqueTriplets.begin(),uniqueTriplets.end());
//             return ans;
//         }
// };
// Time complexity:O(n^2 * log(unique triplets))
//Space complexity:O(unique triplets + n)


//Two Pointer(Most Optimal)
class Solution
{
    public:
        vector<vector<int>> threeSum(vector<int>&nums)
        {
            sort(nums.begin(),nums.end());
            int len=nums.size();
            vector<vector<int>> ans;
            for (int i = 0; i < len; i++)
            {
                if(i>0 && nums[i]==nums[i-1])
                {
                    continue;
                }
                int j = i+1,k=len-1;

                while(j<k)
                {
                    int sum=nums[i]+nums[j]+nums[k];
                    if(sum<0)
                    {
                        j++;
                    }
                    else if(sum>0)
                    {
                        k--;
                    }
                    else
                    {
                        ans.push_back({nums[i],nums[j],nums[k]});
                        j++,k--;

                        while(j<k && nums[j]==nums[j-1])
                            j++;
                    }
                }
            }
            return ans;
        }
};
//Time Complexity: O(nlogn+n^2)
//Space Complexity: O(1)

int main()
{
    vector<int> nums={-1,0,1,2,-1,-4};
    Solution s;
    vector<vector<int>> result=s.threeSum(nums);
    for(int i=0;i<result.size();i++)
    {
        cout<<"["<<result[i][0]<<","<<result[i][1]<<","<<result[i][2]<<"]"<<endl;
    }
}