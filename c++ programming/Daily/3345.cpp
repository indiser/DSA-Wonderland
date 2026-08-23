// Date: 06/08/2026
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


// Time Complexity: O(n)
// Space Cmplexity: O(logn)
class Solution
{
    public:
        int getProduct(int n)
        {
            if(n == 0) return 1;
            return (n % 10) * getProduct(n / 10);
        }
        int smallestNumber(int n, int t)
        {
            int smallest = 0;

            while(n)
            {
                int product = getProduct(n);
                if(product % t == 0)
                {
                    smallest = n;
                    break;
                }
                n++;
            }

            return smallest;
        }
};

int main()
{
    int n = 15;
    int t = 3;

    Solution s;
    cout << s.smallestNumber(n, t)<< endl;
    return 0;
}