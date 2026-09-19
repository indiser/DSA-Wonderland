// Date: 19/09/2026
#include<iostream>
#include<vector>
#include<unordered_map>
#include<math.h>
#include<algorithm>
using namespace std;

// Time Compelxity: O(1)
// Space Complexity: O(1)
class Solution
{
    public:
        bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2)
        {
            long long dist = 0;

            if(xCenter < x1 || xCenter > x2) dist += min(pow(x1 - xCenter, 2), pow(x2 - xCenter, 2));
            if(yCenter < y1 || yCenter > y2) dist += min(pow(y1 - yCenter, 2), pow(y2 - yCenter, 2));

            return dist <= radius * radius;
        }
};

int main()
{
    int radius = 1, xCenter = 0, yCenter = 0;
    int x1 = 1, y1 = -1, x2 = 3, y2 = 1;

    Solution s;
    if(s.checkOverlap(radius, xCenter, yCenter, x1, y1, x2, y2)) cout << "True"<< endl;
    else cout << "False"<< endl;

    return 0;
}