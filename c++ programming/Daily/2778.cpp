// Date: 11/10/2026
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1)
class Soltuion
{
    public:
        int sumOfSquares(vector<int> &nums)
        {
            int n = nums.size();
            int sum = 0;
            for (int i = 1; i <= n; i++)
            {
                if(n % i == 0) sum += nums[i - 1] * nums[i - 1];
            }
            return sum;
        }
};

int main()
{
    // vector<int> nums = {1, 2, 3, 4};
    vector<int> nums = {2, 7, 1, 19, 18, 3};

    Soltuion s;
    cout << s.sumOfSquares(nums)<< endl;
}