// Date: 09/09/2026
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// Time Complexity: O(n)
// Space Comeplexity: O(1)
class Solution
{
    public:
        long long countCommas(long long n)
        {
            long long p = 1000, res = 0;

            while(p <= n)
            {
                res += n - p + 1;
                p *= 1000;
            }
            return res;
        }
};

int main()
{
    long long n = 1001;

    Solution s;
    cout << s.countCommas(n) <<endl;

    return 0;
}