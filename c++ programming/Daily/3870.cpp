// Date: 08/09/2026
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution
{
    public:
        int lengthNumber(int num)
        {
            int len = 0;
            while(num != 0)
            {
                num /= 10;
                len++;
            }
            return len;
        }
        int countCommas(int n)
        {
            int len = lengthNumber(n);
            
            if(len < 4) return 0;

            int commas = 1;
            for (int i = 1000; i < n; i++)
            {
                commas++;
            }
            return commas;
        }
};

int main()
{
    int n = 1001;

    Solution s;
    cout << s.countCommas(n)<<endl;
}