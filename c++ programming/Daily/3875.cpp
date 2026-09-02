// Date: 02/09/2026
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// Time Complexity: O(n ^ 2)
// Space Complexity: O(n)
class Solution
{
    public:
        bool uniformArray(vector<int> &nums1)
        {
            return true;
        }
};

int main()
{
    vector<int> nums1 = {2, 3};

    Solution s;
    if(s.uniformArray(nums1) == true) cout<< "True"<<endl;
    else cout<< "False"<<endl;

    return 0;
}