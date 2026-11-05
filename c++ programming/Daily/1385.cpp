// Date: 05/11/2026
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// Time Complexity: O(n * m)
// Space Complexity: O(1)
class Solution
{
    public:
        int findTheDistanceValue(vector<int> &arr1, vector<int> &arr2, int d)
        {
            int count = 0;
            for(int x: arr1)
            {
                bool ok = true;

                for(int y: arr2)
                {
                    ok &= (abs(x - y) > d);
                }
                count += ok;
            }
            return count;
        }
};

int main()
{
    vector<int> arr1 = {4, 5, 8};
    vector<int> arr2 = {10, 8, 1, 9};
    int d = 2;

    Solution s;
    cout << s.findTheDistanceValue(arr1, arr2, d)<< endl;
    return 0;
}