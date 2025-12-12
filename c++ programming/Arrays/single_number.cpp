#include<iostream>
#include<vector>
#include<bits/c++config.h>
using namespace std;

// Leetcode-138(easy)

class Solution
{
    public:
        int singleNumber(vector<int> &nums)
        {
            int ans=0;
            for(int val : nums)
            {
                ans = ans^val; //XOR
            }
            return ans;
        }

};

int main()
{
    vector<int> nums={4,1,2,1,2};
    Solution s;
    cout<<"The result is: "<<s.singleNumber(nums)<<endl;
}
