// Date: 11/09/2026
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// Time Compelxity: O(n ^ 3)
// Space Compelxity: O(1)
class Solution
{
    public:
        int totalNumbers(vector<int> &digits)
        {
            int n = digits.size();
            vector<bool> visited(1000, false);
            int ans = 0;

            for (int i = 0; i < n; i++)
            {
                if(digits[i] == 0) continue; // if the first digit is zero continue
                for (int j = 0; j < n; j++)
                {
                    if(j == i) continue; // if both indexes are same continue
                    for (int k = 0; k < n; k++)
                    {
                        if(k == i || k == j || digits[k] % 2 != 0) continue; // if three indexes are same and the number is odd continue
                        int x = digits[i] * 100 + digits[j] * 10 + digits[k];
                        if(!visited[x])
                        {
                            visited[x] = true;
                            ans++;
                        }
                    }
                }
            }
            return ans;
        }
};

int main()
{
    vector<int> digits = {0, 2, 2};

    Solution s;
    cout << s.totalNumbers(digits)<< endl;

    return 0;
}