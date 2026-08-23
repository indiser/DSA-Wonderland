// Date: 12/07/2026
#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

// Time Complexity: O(nlogn)
// Space Complexity: O(n)
class Solution
{
    public:
        vector<int> arrayRankTransformation(vector<int> &arr)
        {
            vector<int> temp(arr);
            sort(temp.begin(), temp.end());
            temp.erase(unique(temp.begin(), temp.end()), temp.end());
            for (int i = 0; i < arr.size(); i++) {
                arr[i] = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin() + 1;
            }
            return arr;
        }
};

int main() 
{
    vector<int> arr = {40, 10, 20, 30};

    Solution s;
    vector<int> result = s.arrayRankTransformation(arr);
    for(int val: result) cout<< val <<" ";

    return 0;
}