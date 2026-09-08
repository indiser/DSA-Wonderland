// Date: 08/09/2026
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// Time Complexity: O(1)
// Space Complexity: O(1)
class Solution
{
    public:
        int countCommas(int n)
        {
            if(n < 1000) return 0;
            return (n - 999);
        }
};

int main()
{
    int n = 1001;

    Solution s;
    cout << s.countCommas(n)<<endl;
}