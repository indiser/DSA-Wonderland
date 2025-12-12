#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
using namespace std;

// solution-1:Usng maps
// Time Complexity:O(n)
//Space Complexity:O(n)
// class Solution
// {
//     public:
//     int duplicateValues(vector<int> &nums)
//     {
//         int ans;
//         map<int,int> mp;

//         for(int val:nums)
//         {
//             mp[val]++;
//         }

//         for(auto it=mp.begin(); it != mp.end(); it++)
//         {
//             if(it->second >= 2)
//             {
//                 ans=it->first;
//             }
//         }
//         return ans;
//     }
// };

// Solution-2:Using set
//Time Complexity:O(n)
//Space Complexity:O(n)
// class Solution
// {
//     public:
//     int duplicateValues(vector<int> &nums)
//     {
//         set<int> s;
//         for(int val:nums)
//         {
//             if(s.find(val) != s.end())
//                 return val;
//             s.insert(val);
//         }
//         return -1;
//     }
// };

// Solution-3:Slow-Fast appraoch
//Time Complexity:O(n)
//Space Complexity:O(1)
class Solution
{
    public:
    int duplicateValues(vector<int> &nums)
    {
        int slow=nums[0],fast=nums[0];

        do
        {
            slow=nums[slow];
            fast=nums[nums[fast]];
        } while (slow != fast);

        slow=nums[0];

        while(slow != fast)
        {
            slow=nums[slow];
            fast=nums[fast];
        }
        return slow;
        
    }
};
int main()
{
    // vector<int> nums={1,3,4,2,2};
    // vector<int> nums={3,3,3,3,3};
    vector<int> nums={3,1,3,4,2};
    Solution s;
    cout<<s.duplicateValues(nums)<<endl;
    return 0;
}