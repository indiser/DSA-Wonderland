// Date: 07/07/2026
#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<cmath>
using namespace std;

// Time complexity: O(logn)
// Space Complexity: O(1)
class Solution
{
    public:
        long long sumAndMultiply(int n)
        {
            if (n == 0) return 0;

            long long x = 0;
            long long multiplier = 1;
            long long sum = 0;

            while (n != 0) {
                int digit = n % 10;
                if (digit != 0) {
                    x += digit * multiplier;
                    multiplier *= 10;
                    sum += digit;
                }
                n /= 10;
            }
        
            return x * sum;
        }
        
};

int main()
{
    int n = 10203040;

    Solution s;
    cout<< s.sumAndMultiply(n)<<endl;

    return 0;
}