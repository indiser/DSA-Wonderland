// Date: 23/08/2026
#include<iostream>
#include<vector>
#include<unordered_map>
#include<random>
using namespace std;

// Time Complexity: O(n)
// Space Compleity: O(n)
class Solution
{
    public:
        bool sumGame(string &num)
        {
            int n = num.size();

            auto get = [](string&& s) -> pair<int, int> {
                int nn = 0, qq = 0;
                for (char ch : s) {
                    if (ch == '?') {
                        ++qq;
                    } else {
                        nn += (ch - '0');
                    }
                }
                return {nn, qq};
            };

            auto [n0, q0] = get(num.substr(0, n / 2));
            auto [n1, q1] = get(num.substr(n / 2, n / 2));

            return ((q0 + q1) % 2 == 1) || (n0 - n1 != (q1 - q0) * 9 / 2);
        }
};

int main()
{
    string num = "5023";
    Solution s;

    if(s.sumGame(num) == true) cout<< "True";
    else cout<< "False";

    return 0;
}