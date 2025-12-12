#include<iostream>
#include<vector>
#include<deque>
#include<climits>
using namespace std;

//Time Complexity:O(n)
//Space Complexity:O(n)

class Solution
{
    public:
        vector<int> maxWindow(vector<int> &nums, int k)
        {
            vector<int> ans;
            deque<int> dq;
            int len=nums.size();

            for(int i = 0; i < k; i++)
            {
                while(dq.size() > 0 && nums[dq.back()] <= nums[i])
                {
                    dq.pop_back();
                }
                dq.push_back(i);
            }

            for (int i = k; i < len; i++)
            {
                ans.push_back(nums[dq.front()]);

                while(dq.size() > 0 && dq.front() <= i-k)
                {
                    dq.pop_front();
                }

                while(dq.size() > 0 && nums[dq.back()] <= nums[i])
                {
                    dq.pop_back();
                }

                dq.push_back(i);
            }

            ans.push_back(nums[dq.front()]);
            return ans;
        }

};

int main()
{
    // vector<int> nums={1,3,-1,-3,5,3,6,7};
    vector<int> nums={1, -1};
    int k = 1;
    Solution s;
    vector<int> answer=s.maxWindow(nums,k);

    for(int val: answer)
    {
        cout<<val<<endl;
    }
    return 0;
}