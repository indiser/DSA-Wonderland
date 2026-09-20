// Date: 20/09/2026
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution
{
    public:
        int reverseDegree(string s)
        {
            int sum = 0;

            for (int i = 1, len = s.size(); i <= len; i++)
            {
                sum += (26 - (s[i - 1] - 'a')) * i;
            }
            return sum;
        }
};

int main()
{
    string str = "abc";

    Solution s;
    cout << s.reverseDegree(str)<< endl;

    return 0;
}