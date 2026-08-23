// Date: 30/07/2026
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

/*
Arithmetic Progression: 

Let [q, r]=div(word.size(), 8)
8∑ 
i=0
q
 i=4q(q+1) by arithmetic progression. The rest is r(q+1)
the answer is r*(q+1)+q*(q+1)*4
*/

// Time Complexity: O(1)
// Space Comeplxity: O(1)
class Solution
{
    public:
        int minimumPush(string &word)
        {
            auto [q, r] = div(word.length(), 8);
            return r * (q + 1) + q * (q + 1) * 4;
        }
};

int main()
{
    string word = "xycdefghij";

    Solution s;
    cout << s.minimumPush(word) << endl;

    return 0;
}