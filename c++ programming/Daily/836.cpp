// Date: 14/09/2026
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// Time Compelxity: O(1)
// Space Compelxity: O(1)
class Solution
{
    public:
        bool isRectangleOverlap(vector<int> &rec1, vector<int> &rec2)
        {
            int rec1X1 = rec1[0];
            int rec1Y1 = rec1[1];
            int rec1X2 = rec1[2];
            int rec1Y2 = rec1[3];

            int rec2X1 = rec2[0];
            int rec2Y1 = rec2[1];
            int rec2X2 = rec2[2];
            int rec2Y2 = rec2[3];

            if(rec1X1 >= rec2X2 || rec1Y1 >= rec2Y2 || rec1X2 <= rec2X1 || rec1Y2 <= rec2Y1) return false;
            return true;
        }
};

int main()
{
    vector<int> rec1 = {0, 0, 2, 2};
    vector<int> rec2 = {1, 1, 3, 3};

    Solution s;
    if(s.isRectangleOverlap(rec1, rec2)) cout <<"True"<<endl;
    else cout <<"False" << endl;

    return 0;
}