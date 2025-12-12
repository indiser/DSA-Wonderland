#include<iostream>
#include<vector>
using namespace std;

class Solution
{
    public:
        int singleNumber(vector<int> &nums)
        {
            int a=0;
            for(int val: nums)
            {
                a^=val;
            }
            return a;
        }
};

int main()
{
    vector<int> nums={4,1,2,1,2};
    Solution s;
    cout<<s.singleNumber(nums);
    return 0;
}