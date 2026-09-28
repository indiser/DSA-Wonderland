// Date: 28/09/2026
#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution
{
    public:
        int maxDeapth(string s)
        {
            int counter = 0;
            int maxCounter = INT_MIN;

            for (int i = 0; i < s.size(); i++)
            {
                if(s[i] == '(') counter++;
                else if(s[i] == ')') counter--;
                maxCounter = max(maxCounter, counter);
            }
            return maxCounter;
        }
};

int main()
{
    string str = "(1+(2*3)+((8)/4))+1";

    Solution s;
    cout << s.maxDeapth(str)<< endl;

    return 0;
}