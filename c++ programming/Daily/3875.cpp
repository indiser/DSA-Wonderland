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
        bool oddEven(int num)
        {
            if(num % 2 == 0) return true;
            return false;
        }
        bool uniformArray(vector<int> &nums1)
        {
            int n = nums1.size();

            vector<int> nums2(n, 0);

            int i = 0, j = n - 1;

            for (int i = 0; i < n; i++)
            {
                for (int j = i + 1; j < n; j++)
                {
                    nums2[i] = nums1[i] - nums2[j];
                    if(oddEven(nums2[i])) return true; 
                }
            }

            for (int i = 0; i < n; i++)
            {
                if(oddEven(nums2[i])) return true;
            }
            
            
            return false;
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