// Date: 06/10/2026
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution
{
    public:
        int minAddToMakeValid(string s)
        {
            int open = 0;
            int count = 0;

            for (int i = 0; i < s.size(); i++)
            {
                if(s[i] == '(') open++;
                else
                {
                    open > 0 ? open-- : count++;
                }
            }
            return open + count;
        }
};

int main()
{
    string str = "())";
    // string str = "(((";

    Solution s;
    cout <<s.minAddToMakeValid(str)<< endl;

    return 0;
}