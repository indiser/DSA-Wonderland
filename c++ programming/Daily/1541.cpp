// Date: 09/10/2026
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution
{
    public:
        int minIntersection(string s)
        {
            int ans = 0, x = 0;
            
            for (int i = 0, len = s.size(); i < len; i++)
            {
                if(s[i] == '(') ++x;
                else
                {
                    if(i < len - 1 && s[i + 1] == ')') ++i;
                    else ans++;
                    if(x == 0) ++ans;
                    else --x;
                }
            }
            ans += x << 1;

            return ans;
        }
};

int main()
{
    string str = "))())(";

    Solution s;
    cout << s.minIntersection(str)<< endl;

    return 0;
}