#include<iostream>
#include<vector>
#include<unordered_map>
#include<stack>
#include<algorithm>
using namespace std;


// Time Complexity: O(n + m) where n = nums2.size(), m = nums1.size()
// Space Complexity: O(n) for map and stack
// class Solution
// {
//     public:
//         vector<int> nextGreater(vector<int> &nums1, vector<int> &nums2)
//         {
//             unordered_map<int, int> nextGreaterMap;
//             stack<int> s;
            
//             for(int num : nums2)
//             {
//                 while(!s.empty() && s.top() < num)
//                 {
//                     nextGreaterMap[s.top()] = num;
//                     s.pop();
//                 }
//                 s.push(num);
//             }
            
//             vector<int> ans;
//             for(int num : nums1)
//             {
//                 ans.push_back(nextGreaterMap.count(num) ? nextGreaterMap[num] : -1);
//             }
//             return ans;
//         }
// };

// Time Complexity: O(m * n^2) where m = nums1.size(), n = nums2.size()
// Space Complexity: O(n) for stack
// class Solution
// {
//     public:
//         vector<int> nextGreater(vector<int> &nums1, vector<int> &nums2)
//         {
//             vector<int> ans;
//             stack<int> s;
//             reverse(nums2.begin(),nums2.end());

//             for (int num:nums1)
//             {
//                 while(!s.empty()) s.pop();
//                 for(int i:nums2)
//                 {
//                     s.push(i);
//                 }
//                 while(!s.empty() && s.top() != num)
//                 {
//                     s.pop();
//                 }
//                 if(!s.empty()) s.pop();
//                 if(!s.empty() && s.top() > num) 
//                 {
//                     ans.push_back(s.top());
//                 }
//                 else
//                 {
//                     ans.push_back(-1);
//                 }
                
//             }
            
//             return ans;
//         }
// };

// Time Complexity: O(n + m) where n = nums2.size(), m = nums1.size()
// Space Complexity: O(n) for map and stack
class Solution
{
    public:
        vector<int> nextGreater(vector<int> &nums1, vector<int> &nums2)
        {
            unordered_map<int, int> mp;
            stack<int> s;
            
            for (int i = nums2.size() - 1; i >= 0; i--)
            {
                while (s.size() > 0 && s.top() <= nums2[i])
                {
                    s.pop();
                }
                if(!s.empty())
                {
                    mp[nums2[i]] = s.top();
                }
                else
                {
                    mp[nums2[i]] = -1;
                }

                s.push(nums2[i]);
                
            }

            vector<int> ans;
            for(int val:nums1)
            {
                ans.push_back(mp[val]);
            }
            return ans;
        }
};
int main()
{
    vector<int> nums1={1,3,5,2,4};
    vector<int> nums2={6,5,4,3,2,1,7};

    Solution s;
    vector<int> ans=s.nextGreater(nums1,nums2);

    for(int i:ans)
    {
        cout<<i<<endl;
    }
}