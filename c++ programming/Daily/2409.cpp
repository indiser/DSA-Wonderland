// Date: 24/10/2026
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution
{
    public:
        int countDays(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob)
        {
            int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
            auto toDays = [&](const string& s)
            {
                int month = (s[0] - '0') * 10 + (s[1] - '0');
                int day = (s[3] - '0') * 10 + (s[4] - '0');
                int res = day;
                for (int i = 0; i < month - 1; i++)
                {
                    res += days[i];
                }
                return res;
            };
            int start = max(toDays(arriveAlice), toDays(arriveBob));
            int end = min(toDays(leaveAlice), toDays(leaveBob));
            return start <= end ? end - start + 1 : 0;
        }
};

int main()
{
    string arriveAlice = "08-15";
    string leaveAlice = "08-18";
    string arriveBob = "08-16";
    string leaveBob = "08-19";

    Solution s;
    cout << s.countDays(arriveAlice, leaveAlice, arriveBob, leaveBob);
    return 0;
}