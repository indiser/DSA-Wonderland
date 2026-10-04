// Date: 04/10/2026
#include<iostream>
#include<vector>
#include<unordered_map>
#include<stack>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution
{
    public:
        bool checkValidString(string s)
        {
            int low = 0, high = 0;

            for(char c: s)
            {
                if(c == '(')
                {
                    low++;
                    high++;
                }
                else if(c == ')')
                {
                    low--;
                    high--;
                }
                else
                {
                    low--;
                    high++;
                }

                if(high < 0) return false;
                if(low < 0) low = 0;
            }

            return low == 0;
        }
};

int main()
{
    string str = "(*)";

    Solution s;
    if(s.checkValidString(str)) cout <<"TRUE"<< endl;
    else cout<<"FALSE"<< endl;

    return 0;
}