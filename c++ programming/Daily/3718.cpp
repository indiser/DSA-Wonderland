// Date: 26/08/2026
#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<unordered_set>
using namespace std;


// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution
{
    public:
        int missingMultiple(vector<int> &nums, int k)
        {
            unordered_set<int> s(nums.begin(), nums.end());

            int i = 1;

            while(true)
            {
                if(s.contains(k * i))
                {
                    i++;
                    continue;
                }
                return k * i;
            }

        }
};

int main()
{
    // vector<int> nums = {8, 2, 3, 4, 6};
    vector<int> nums = {1, 4, 7, 10, 15};

    int k = 5;

    Solution s;
    cout << s.missingMultiple(nums, k)<<endl;

    return 0;
}
