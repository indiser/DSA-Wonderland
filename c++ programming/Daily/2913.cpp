// Date: 15/10/2026
#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;

// Time Complexity: O(n^3)
// Space Compelxity: O(n)
// class Solution
// {
//     public:
//         int sumCounts(vector<int> &nums)
//         {
//             int len = nums.size();
//             int count = 0, sum = 0;

//             vector<vector<int>> ans;
//             unordered_set<int> s;
            
//             for (int i = 0; i < len; i++)
//             {
//                 for (int j = i; j < len; j++)
//                 {
//                     vector<int> subarray;
//                     for (int k = i; k <= j; k++)
//                     {
//                         subarray.push_back(nums[k]);
//                     }
//                     ans.push_back(subarray);
//                 }
//             }

//             for(auto val: ans)
//             {
//                 for(auto d: val)
//                 {
//                     s.insert(d);
//                 }
//                 count = s.size();
//                 sum += count * count;
//                 s.clear();
//             }

//             return sum;
//         }
// };

// Time Complexity: O(n ^ 2)
// Space Complexity: O(n)
class Solution
{
    public:
        int sumCounts(vector<int> &nums)
        {
            int len = nums.size();
            int sum = 0;

            for (int i = 0; i < len; i++)
            {
                unordered_set<int> s;
                for (int j = i; j < len; j++)
                {
                    s.insert(nums[j]);
                    sum += s.size() * s.size();
                }
                
            }
            return sum;
        }
};

int main()
{
    // vector<int> nums = {1, 2, 1};
    vector<int> nums = {1, 1};


    Solution s;
    cout << s.sumCounts(nums) << endl;

    return 0;
}