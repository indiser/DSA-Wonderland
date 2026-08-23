// Date: 09/07/2026
#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;

// Time Complexity: O(n + q)
// Space Complexity: O(n)
class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> component(n, 0);
        int compNo = 0;
        for(int i = 1; i < n; i++){
            if(nums[i] - nums[i - 1] > maxDiff){
                compNo++;
            }
            component[i] = compNo;
        }
        vector<bool> sol;

        for(auto &it : queries){
            sol.push_back(component[it[0]] == component[it[1]]);
        }

        return sol;
    }
};

int main()
{
    int n = 2;
    vector<int> nums = {1, 3};
    int maxDiff = 1;
    vector<vector<int>> queries = {
        {0, 0},
        {0, 1}
    };

    Solution s;
    vector<bool> result = s.pathExistenceQueries(n, nums, maxDiff, queries);
    for(auto val: result)
    {
        if(val == true)
            cout<<"True"<<" ";
        else
            cout<<"False"<<" ";
    }

    return 0;
}